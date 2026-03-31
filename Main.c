/*********************************************/
/*                                           */
/*       プログラム名：銀行口座のアカウント照合            */
/*                                           */
/*       作成者：のぶ太郎                      */
/*       作成日：2026/03/31                   */
/*                                           */
/*********************************************/
#include <stdio.h>
#include "Account.h"
/* 関数プロトタイプ宣言 */
void add_acc(ACCOUNT account); 
void prt_acc(int id); 
ACCOUNT* find(int id);
int wd(ACCOUNT *account, int money); 
int chk_m(int money);
int auth(ACCOUNT *account, int pw); 
int get_f(int handringfee);

int main() {
    // --- 1. 初期設定（口座情報の登録） ---
    ACCOUNT a1 = {101, "Taro", 1234, 50000, 1, 0};
    add_acc(a1);

    // --- 2. カード挿入と本人確認（ID入力） ---
    int cur_id;
    int p, sel, amt;    //if文や、while分の内部で宣言されていたため、ローカル変数としてmain関数内の別の場所へ移動
    int f = get_f(19); // 19時固定 if文の中で宣言されていたため、ローカル変数としてmain関数内の別の場所へ移動

    printf("CARD IN (ID): "); scanf("%d", &cur_id);
    ACCOUNT *user = find(cur_id);

    //ユーザー名の照合をする
    if (user != NULL && user->st == 1) {
         printf("PASS: "); scanf("%d", &p);

        //パスワードの判定をする
        if (auth(user, p)) {
            
            //ブレイクするまで（EXITが選択されるまでループする）
            while (1) {
                
                printf("\n1:BALANCE 2:WITHDRAW 3:EXIT\n>");
                scanf("%d", &sel);
                
                //1が入力された場合、ユーザーidに紐づいた口座を表示する
                if (sel == 1) {
                    prt_acc(user->id);
                }
                
                //2が入力された場合、金額を入力する
                else if (sel == 2) {
                    printf("AMOUNT: "); scanf("%d", &amt);
                    
                    //金額が1000で割り切れるかどうかを判定する
                    if (chk_m(amt)) {

                        //出金を実行する（手数料+出金金額）    
                        if (wd(user, amt + f)) printf("SUCCESS. FEE:%d\n", f);    
                    }
                }

                //3が入力された場合
                else if (sel == 3) break;

                //1,2,3でもない数字が入力されたとき
                else printf("FAILED\n");
            }
        }
        
        //間違ったパスワードが入力された場合
        else { printf("AUTH ERR\n"); }

    } 
    
    //間違ったユーザー名が入力された場合
    else { printf("INVALID CARD\n"); }

    return 0;
}
