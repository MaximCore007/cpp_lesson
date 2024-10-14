/* blabla */

#include "table.h"
#include "string.h"
#include "err_hdl.h"

const int TABLE_SIZE = 24;
name *table[TABLE_SIZE];

name* look(const char* str, int ins)
{
    int hash_code = 0;
    const char *pp = str;
    
    while (*pp) {
        hash_code = hash_code << 1 ^ *pp++;

        if (hash_code < 0) {
            hash_code = -hash_code;
        }
        hash_code %= TABLE_SIZE;
        
        for (name *n = table[hash_code]; n; n = n->next)
            if (strcmp(str, n->string) == 0)
                return n;

        if (ins == 0) { 
            error("Name not found");
            return 0;
        }
        
        name *nn = new name;
        nn->string = new char[strlen(str) + 1];
        strcpy(nn->string, str);
        nn->value = 1;
        nn->next = table[hash_code];
        table[hash_code] = nn;
        return nn;
    }
    return 0;
}
