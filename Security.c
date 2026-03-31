//////////////////////////////////////
//プログラムの機能：アカウント確認
//作成者：terao
//作成日：2026/03/31
//////////////////////////////////////

#include <stdio.h>
#include "Account.h"

//パスワード確認
int verification_password(ACCOUNT *account, int pw) {
    if (account -> password == pw) {
        account ->l = 0;
        return 1;
    } 
	else {
        account -> l++;
        if (account -> l >= 3){
			account -> status = 0; 
		}
        return 0;
    }
}

//手数料払い出し
int get_fee(int h) {
    if (h < 9 || h >= 18) {
        return 110; 
    }
    return 0;
}
