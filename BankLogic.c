/*****************************************
ATM出金シミュレーター（残高・上限チェック付）

kato junya  2026/03/31

*****************************************/

#include <stdio.h>
#include "Account.h"

//出金処理関数 wd (Withdraw)
int wd ( ACCOUNT * account , int money ) {
    if ( account -> status == 1 ) {                         // 口座の状態をチェック (1: 稼働中であることを想定)
        if ( money > 0 ) {                                  // 出金額が正の数であることを確認
            if ( account -> balance >= money ) {            // 残高が出金額以上あるかを確認
                if ( money <= 500000 ) {                    // 1日の引き出し上限（500,000円）を超えていないか確認
                    account -> balance -= money;            // 残高から出金額を差し引く
                    return 1;                               // 出金成功として1を返す
                }
            }
        }
    }
    return 0;                                               // 上記のいずれかの条件を満たさない場合は出金失敗(0)
}

//入力金額の妥当性をチェックする関数(Check Money)
int chk_m( int money ) {
    if( money % 1000 == 0 && money > 0) return 1;          // 1000円単位（余り0）であり、かつ0より大きいかを判定
    return 0;                                              // 条件に合わない場合は0を返す
}
