/*[RPGの説明]-------------------------------------------------------------------------*/
/* このRPGは、はじめに「ゲームをプレイしますか？」という質問にyを返すとゲームで遊ぶことが出来ます。*/
/* まずゲームを選択します。ゲームは以下2通りで、選択（a or b）によって選択できます。            */
/* ゲームa : サイコロを3回振り、合計値が10以上になれば終了というゲーム                        */
/* ゲームb : おみくじを引いて大吉が出たら終了というゲーム                                   */
/* 各ゲームを終了すると、引き続きゲームで遊ぶか終了するかを選択できます。                      */
/* 終了を選択するとプログラムを終了します。                                               */
/* 続けるを選択すると、ゲーム選択の質問に戻ります。                                        */
/*---------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NODE_1 0
#define NODE_2 1
#define NODE_3 2
#define NODE_A 3
#define NODE_END 100

typedef struct{
  int node;          /* current state */
  int yes;           /* next state for YES */
  int no;            /* next state for NO */
  char message[200]; /* Question text */
} game_trans;

game_trans gametable[] = {
    {NODE_1, NODE_2, NODE_A, "ゲームをプレイしますか？(y / n)"},
    {NODE_2, NODE_3, NODE_1, "どちらのゲームをプレイしますか？(a / b) \na : サイコロを3回振り、合計値が10以上になれば終了\nb : おみくじを引いて大吉が出たら終了"},
    {NODE_3, NODE_2, NODE_A, "引き続きゲームを続けますか？(y / n) "},
    {NODE_A, NODE_END, NODE_END, "[ n ]を選択したのでプログラムを終了します。"}};

//サイコロゲームを行う関数
void dice_make(){
  int num,ans = 0;  /*サイコロの値を代入するnum,3回振った合計値を代入するansを宣言*/
  char choice;  /*Enterキーを押したかを判断するための変数*/
  srand((unsigned int)time(NULL));  /*乱数生成のためにtime関数を使用*/

  while(1){
    for (int i = 0; i < 3; i++){  /*3回振るので3回ループ*/
      num = (1 + rand() % 6);   /*1〜6の乱数を生成*/
      printf(">Enterキーを押してサイコロを振ります。\n");
      scanf("%c", &choice);  /*Enterを押されるまで待機*/
      printf("%d回目 : サイコロの目は%dです。\n\n",i + 1,num);
      ans += num;  /*加算値をansに代入*/
    }
    if(ans >= 10){  /*合計値が10以上で終了*/
      printf("おめでとうございます。合計値は>> %d <<なのでゲームを終了します。\n\n",ans);
      return ;
    }else{  /*合計値が10未満の場合ansをリセットしてもう一度。*/
      printf("残念。合計値が>> %d <<なのでゲームをやり直します。\n\n",ans);
      ans = 0;
    }
  }
}

//おみくじゲームを行う関数
void omikuji_make(){
  int ans = 0;  /*おみくじの結果を代入するansを宣言*/
  char choice;  /*Enterキーを押したかを判断するための変数*/
  srand((unsigned int)time(NULL));  /*乱数生成のためにtime関数を使用*/

  printf("おみくじは大吉>吉>凶の3種類です。大吉を引くと終了となります。\n");
  while (1){
    printf(">Enterキーでおみくじを引きます。\n");
    scanf("%c", &choice); /*Enterを押されるまで待機*/
    ans = (0 + rand() % 3); /*1〜3の乱数を生成(0 = 大吉,1 = 吉,2 = 凶)*/
    if (ans == 0){
      printf("おみくじの結果は>> 大吉 <<です。\n");
      printf("おめでとうございます。大吉を引いたのでゲームを終了します。\n\n");
      return;  /*大吉なので関数を終了*/
      }else if(ans == 1)
        printf("おみくじの結果は>> 吉 <<です。\n");
      else if (ans == 2)
        printf("おみくじの結果は>> 凶 <<です。\n");
      printf("\n残念。大吉ではないのでもう一度おみくじを引きます。\n\n");/*大吉でないのでもう一度*/
  }
}

int main(){
  int state = NODE_1;  /*stateにNODE_1(0)を代入*/
  char input[256], *p;  /*キーボード入力のための変数を宣言*/

  for (;;){
    if (gametable[state].yes == NODE_END) /*gametable[state].yesがNODE_ENDになるまでループ*/
      break;
    printf("Question: %s\n", gametable[state].message);
    p = fgets(input, 255, stdin);
    if (p != NULL){
      if (input[0] == 'y')  /*yを選択した場合ノード2へ(ゲーム選択)*/
        state = gametable[state].yes;
      else if (input[0] == 'n')  /*nを選択した場合次のノードをA(END)にセット*/
        state = gametable[state].no;
      else if (input[0] == 'a'){  /*aを選択した場合サイコロのゲームへ*/
        dice_make();
        state = gametable[state].yes;  /*次のノードを3にセット*/
      }
      else if (input[0] == 'b'){  /*bを選択した場合おみくじのゲームへ*/
        omikuji_make();
        state = gametable[state].yes;  /*次のノードを3にセット*/
      }
    }
    else
      break;  /*文字が入力されなかった場合break*/
  }
  printf("%s\n", gametable[state].message);  /*プログラム終了のメッセージをprintして終了*/
  return 0;
}
