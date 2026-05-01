#include "birdflu.h"

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
    int8 buf[102400];
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
        // Read directory entries from this file descriptor into buf
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
            filename = p->d_name;
            // Aliases not defined
            if (onedot(filename) || twodots(filename))
                continue;
            //(d_reclen in modern systems) exactly how many bytes long this specific record is
            n -= p->d_reclen, p = (struct linux_dirent64 *)(($1 p) + p->d_reclen)) {
                memset(&e, 0, sizeof e);

                if (p->d_type & DT_REG) {
                    e.type = file;
                    strncpy($c e.dir, $c path, 63);
                    strncpy($c e.file, $c p->d_name, 31);
                    addtodb(db, e);
                }
                else if (p->d_type & DT_DIR) {
                    e.type = dir;
                    strncpy($c e.dir, $c path, 63);
                    strncpy($c e.file, $c p->d_name, 31);
                    addtodb(db, e);
                }
            }
        } while (true);
    close($i fd);
    return true;
}

int main(int argc, char *argv[]) {
    Database *db;

    db = mkdatabase();
    adddir(db, $1 "/tmp");
    showdb(db);
    destroydb(db);

    return 0;
}
