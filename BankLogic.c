#include <stdio.h>
#include "Account.h"

int wd(ACC *a, int m) {
    if (a->st == 1) {
        if (m > 0) {
            if (a->b >= m) {
                if (m <= 500000) { // 1日の上限
                    a->b -= m;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int chk_m(int m) {
    if(m % 1000 == 0 && m > 0) return 1;
    return 0;
}
