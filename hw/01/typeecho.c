/*
課題１：TYPECHO
キーボードからの入力された文字を、ターミナルに出力せよ！

$ ./typecho
This is a pen !
This is a pen !
*/

#include <stdio.h>

int main(int argc, char *argv[]){
    char str[800];
    gets(str);
    printf("%s", str);
   return 0;
}