#ifndef ACC_H
#define ACC_H

typedef struct {
int id;      // 口座番号
char n[20];  // 名前
int p;       // パスワード
int b;       // 残高
int st;      // 状態(1:通常, 0:ロック)
int l;       // 失敗回数
} ACC;
void add_acc(ACC a);      // 口座登録
void prt_acc(int id);     // 口座表示
ACC* find(int id);        // 口座検索
int  wd(ACC *a, int m);   // 出金実行
int  chk_m(int m);        // 金額検証
int  auth(ACC *a, int pw);// パスワード照合
int  get_f(int h);        // 手数料計算
#define MAX_A 10
#endif
