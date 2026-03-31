#include <stdio.h>
#include "Account.h"

int auth(ACC *a, int pw) {
    if (a->p == pw) {
        a->l = 0;
        return 1;
    } else {
        a->l++;
        if (a->l >= 3) a->st = 0; 
        return 0;
    }
}

int get_f(int h) {
    if (h < 9 || h >= 18) {
        return 110; 
    }
    return 0;
}
