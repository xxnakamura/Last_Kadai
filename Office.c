#include <stdio.h>
#include <string.h>
#include "Account.h"

static ACCOUNT db[MAX_ACCOUNT];   //登録可能な口座数
static int total = 0;             //現在の口座数

/*口座登録が可能か判別する*/
void add_account(ACCOUNT account) {
    if(total < MAX_ACCOUNT){
        db[total++]=account;
    }
}

/*口座表示_処理*/
void print_account(int id) {
    for(int i=0; i<total; i++){
        if(db[i].id==id){
            printf("--- INFO ---\n");
            printf("ID: %d\nNAME: %s\nBAL: %d\n", db[i].id, db[i].name, db[i].balance);
        }
    }
}

/*口座検索*/
ACCOUNT* find(int id) {
    for(int i=0; i<total; i++) {
        if(db[i].id==id){ 
            return &db[i];
        }
    }
    return NULL;
}
