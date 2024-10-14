/* blabla */

#ifndef TABLE_H
#define TABLE_H

struct name {
    char* string;
    name* next;
    double value;
};

name* look(const char* str, int ins = 0);
inline name* insert(const char* str) {
    return look(str, 1);
};

#endif /* TABLE_H */
