#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
	int id;      // 口座番号
	char name[20];  // 名前
	int password;       // パスワード
	int balance;       // 残高
	int status;      // 状態(1:通常, 0:ロック)
	int failure_times;       // 失敗回数
	} ACCOUNT;
	
void add_account(ACCOUNT account);      // 口座登録
void print_account(int id);     // 口座表示
	ACCOUNT* find(int id);        // 口座検索

int  withdrawal_execution(ACCOUNT *account, int money);   // 出金実行
int  check_money(int money);        // 金額検証
int  verification_password(ACCOUNT *account, int pw);// パスワード照合
int  get_fee(int h);        // 手数料計算

#define MAX_ACCOUNT 10

#endif
