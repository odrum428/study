/*リストのサーチプログラム*/

#include <stdio.h>
#include <stdlib.h>

/*リストのノードを表す構造体*/
typedef struct tagListNode{
  struct tagListNode *prev; /*前の要素へのポインタ*/
  struct tagListNode *next; //次のノードへのポインタ
  int data; /*このノードが持っているデータ*/
} ListNode;

int main(){
  int buf;
  ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;

  firstnode = lastnode = NULL;

  do{
    printf("整数を入力してください（0を入力すると終了）:");
    scanf("%d", &buf);

    if(buf){ /*新たな入力があったら*/
      /*新しいノードを作成*/
      newnode = (ListNode*)malloc(sizeof(ListNode)); /*新しいノードのメモリをListNode分確保*/
      newnode->data = buf; /*受け取った値を格納*/
      newnode->next = NULL; //新しい配列の次はまだない

      if(lastnode != NULL){ //最初のノードじゃないとき
        lastnode->next = newnode;
        newnode->prev = lastnode;
        lastnode = newnode; //中身を渡す
      } else { /*最初のノードをなら*/
        firstnode = lastnode = newnode;
        newnode->prev = NULL;
      }
    }
  }while(buf != 0);

  /*検索値を入力*/
  do{
    printf("検索する値を入力してください");
    scanf("%d", &buf);

    if(buf != 0){
      //最初に入力した値の中から検索し、見つかったら削除
      for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next) {
        if(thisnode->data == buf){
          printf("入力されたデータの中に%dが見つかりました。ノードを削除します.",buf);

          //対象の前結合を無くす．
          if(thisnode->prev != NULL){ //先頭ノードではなければ
            thisnode->prev->next = thisnode->next;
          } else {
            firstnode = thisnode ->next;
          }

          //対象の次結合を無くす
          if(thisnode->next != NULL) {
            thisnode->next->prev = thisnode ->prev;
          }

          free(thisnode); //メモリを解放
          break;
        }
      }

      if(thisnode == NULL){
        printf("%dは入力されていないか、あるいはすでに削除されています。", buf);
      }
    }
  }while(buf != 0);

  /*残ったノードはすべて削除*/
  for(thisnode = firstnode; thisnode != NULL;){
    removenode = thisnode;
    thisnode = thisnode->next;
    free(removenode);
  }

  return EXIT_SUCCESS;
}
