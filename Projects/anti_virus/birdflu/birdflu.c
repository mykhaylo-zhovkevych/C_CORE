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
    printf("cap:\t%d\nnum:%d\n", db->cap, db->num);
    for (n=0; n < db->num; n++) {
        printf("%s/%s\n", db->entries[n].dir,db->entries[n].file);
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
    struct linux_dirent *p;
    int8 buf[102400];

    ret = open($c path, O_RDONLY|O_DIRECTORY);
    if (ret < 1) {
        return false;
    }
    else {
        fd = $4 ret;
    }

    memset($c buf, 0, sizeof(buf));
    ret = syscall(SYS_getdents, $i fd, buf, (sizeof(buf)-1));
    if (ret < 0) {
        close($i fd);
        return false;
    }
    n = ret;

    for (p = (struct linux_dirent *)buf; n > 0;
        //(d_reclen in modern systems) exactly how many bytes long this specific record is
        n -= p->d_reclen, p = (struct linux_dirent *)(($1 p) + p->d_reclen)) {
            bzero($1 &e, sizeof(struct s_entry));
            strncpy($c e.dir, $c path, 63);
            strncpy($c e.file, $c p->d_name, 31);
            addtodb(db, e);
        }
    close($i fd);
    return true;
}

int main(int argc, char *argv[]) {
    Database *db;
    // Entry e1, e2;
    // strncpy($c e1.dir, "/tmp", 63);
    // strncpy($c e2.dir, "/tmp", 63);
    // strncpy($c e1.file, "FILE1.txt", 31);
    // strncpy($c e2.file, "anotherfile.txt", 31);

    db = mkdatabase();
    adddir(db, $1 "/tmp");
    showdb(db);
    destroydb(db);

    return 0;
}