#include "birdflu.h"

// bool testfun(Entry e) {
//     return (e.type == file);
// }

bool iself(Entry e) {
    int32 fd;
    signed int ret;
    int8 path[4096];
    char buf[4];

    if (e.type != file)
        return false;
    
    bzero(path, 4096);
    snprintf((char *)path, sizeof(path), "%s/%s", (char *)e.dir, (char *)e.file);
    ret = open($c path, O_RDONLY);
    if (ret < 1) {
        return false;
    }
    else {
        fd = $4 ret;
    }
    bzero($1 buf, 4);
    read($i fd, buf, 4);
    close($i fd);

    // check if first 4 bytes are of elf file
    if (buf[0] == 0x7f && buf[1] == 0x45 && buf[2] == 0x4c && buf[3] == 0x46) {
        return true;
    }
    else {
        return false;
    }

}

Database *filter(Database *input, function f) {
    int32 n;
    Database *output;
    Entry *e;
    bool predicate;

    output = mkdatabase();
    for (n=0; n<input->num; n++) {
        e = &input->entries[n];
        predicate = f(*e);
        if (predicate) 
            addtodb(output, *e);
    }
    destroydb(input);
    return output;
}

Database *mkdatabase() {
    Database *db;
    Entry *p;
    int32 size;

    size = sizeof(struct s_database);
    db = (Database *)malloc($i size);
    assert(db);
    bzero($1 db, size);

    db->num = 0;
    size = Blocksize * sizeof(struct s_entry);
    p = (Entry *)malloc($i size);
    assert(p);
    bzero($1 p, size);
    db->entries = p;

    return db;
}

void destroydb(Database *db) {
    db->cap = 0;
    db->num = 0;
    free(db->entries);
    free(db);
    return;
}

void showdb(Database *db) {
    int32 n;
    printf("cap:\t%d\nnum:\t%d\n", db->cap, db->num);
    for (n=0; n < db->num; n++) {
        printf("%s/%s%c\n", db->entries[n].dir,db->entries[n].file,(db->entries[n].type == dir) ? '/' : 0);
    }
    return;
}

void addtodb(Database *db, Entry e) {
    int32 size, cap, idx;

    if (db->num == db->cap) {
        cap = db->cap + Blocksize;
        size = cap * sizeof(struct s_entry);

        db->entries = realloc(db->entries, size);
        assert(db->entries);
        db->cap = cap;
    }
    idx = db->num;
    memcpy(&db->entries[idx], &e, sizeof e);
    db->num++;
    return;
}

bool adddir(Database *db, int8 *path) {
    Entry e;
    int32 fd, n; // file descriptor,unique ID number for folder
    signed int ret;
    struct linux_dirent64 *p;
    int8 buf[102400], tmp[4096];
    int8 *filename;

    ret = open($c path, O_RDONLY|O_DIRECTORY);
    if (ret < 1) {
        return false;
    }
    else {
        fd = $4 ret;
    }
    do {
        memset($c buf, 0, sizeof(buf));
        // read directory entries from this file descriptor into buf
        ret = syscall(SYS_getdents64, $i fd, &buf[0], (sizeof(buf)-1));
        if (ret < 0) {
            close($i fd);
            return false;
        }
        else if (ret == 0)
            break;
        n = ret;

        // cast the pointer type
        for (p = (struct linux_dirent64 *)&buf[0]; n > 0;
            //(d_reclen in modern systems) exactly how many bytes long this specific record is
            n -= p->d_reclen, p = (struct linux_dirent64 *)(($1 p) + p->d_reclen)) {
                filename = (p->d_name);

                memset(&e, 0, sizeof e);
                filename = (p->d_name);
                if (onedot(filename) || twodots(filename))
                    continue;

                if (p->d_type & DT_REG) {
                    e.type = file;
                    strncpy($c e.dir, $c path, 63);
                    strncpy($c e.file, $c filename, 31);
                    addtodb(db, e);
                }
                else if (p->d_type & DT_DIR) {
                    e.type = dir;
                    strncpy($c e.dir, $c path, 63);
                    strncpy($c e.file, $c filename, 31);
                    addtodb(db, e);

                    bzero(tmp, 4096);
                    // prints to buffer the path and file name as path
                    snprintf($c tmp, 4095, "%s/%s", $c path, $c e.file);
                    adddir(db, tmp);
                }
            }
        } while (true);
    close($i fd);
    return true;
}

int main(int argc, char *argv[]) {
    Database *db, *db2;
    char path[64];

    printf("Birdflu scanner\n");
    printf("Enter directory path: ");
    if (fgets(path, sizeof(path), stdin) == NULL) {
        printf("Error\n");
        return 1;
    }
    path[strcspn(path, "\n")] = '\0'; // remove newline character

    if (path[0] == '\0') {
        printf("No directory path provided\n");
        return 1;
    }
    printf("Scanning directory: %s\n", path);

    db = mkdatabase();
    adddir(db, $1 path);
    db2 = filter(db, iself);
    showdb(db2);
    destroydb(db2);

    return 0;
}