#include <stdio.h>
#include "Account.h"
/* 関数プロトタイプ宣言 */
void add_acc(ACC a); 
void prt_acc(int id); 
ACC* find(int id);
int wd(ACC *a, int m); 
int chk_m(int m);
int auth(ACC *a, int pw); 
int get_f(int h);

int main() {
    // --- 1. 初期設定（口座情報の登録） ---
    ACC a1 = {101, "Taro", 1234, 50000, 1, 0};
    add_acc(a1);

    // --- 2. カード挿入と本人確認（ID入力） ---
    int cur_id;
    printf("CARD IN (ID): "); scanf("%d", &cur_id);
    ACC *user = find(cur_id);

    if (user != NULL && user->st == 1) {
        int p; printf("PASS: "); scanf("%d", &p);
        if (auth(user, p)) {
            while (1) {
                int sel;
                printf("\n1:BALANCE 2:WITHDRAW 3:EXIT\n>"); scanf("%d", &sel);
                if (sel == 1) {
                    prt_acc(user->id);
                } else if (sel == 2) {
                    int amt; printf("AMOUNT: "); scanf("%d", &amt);
                    if (chk_m(amt)) {
                        int f = get_f(19); // 19時固定
                        if (wd(user, amt + f)) printf("SUCCESS. FEE:%d\n", f);
                        else printf("FAILED\n");
                    }
                } else if (sel == 3) break;
            }
        } else { printf("AUTH ERR\n"); }
    } else { printf("INVALID CARD\n"); }
    return 0;
}
