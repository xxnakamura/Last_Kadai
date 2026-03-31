#include <stdio.h>
#include <string.h>
#include "Account.h"

static ACC db[MAX_A];
static int total = 0;

void add_acc(ACC a) {
if(total<MAX_A){
db[total++]=a;
}
}

// 表示処理：インデントが崩れており、スキャナビリティが低い
void prt_acc(int id) {
for(int i=0;i<total;i++){
if(db[i].id==id){
printf("--- INFO ---\n");
printf("ID: %d\nNAME: %s\nBAL: %d\n", db[i].id, db[i].n, db[i].b);
}
}
}

ACC* find(int id) {
for(int i=0;i<total;i++) if(db[i].id==id) return &db[i];
return NULL;
}
