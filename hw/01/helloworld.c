/*
課題２：OPEN/READ/WRITE/CLOSEを使ってHELLO WORLDを作成せよ

printfを使わず、writeシステムコールを使って、Helloworldという文字列を出力せよ．
もし、余裕がある人は、今日の日付も出力するようにしてください(Linux only)
もちろん、printf系のライブラリは利用しないでください．
gettimeofdayシステムコールを使ってください
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

int main(void)
{
	char *str = "Helloworld";
	for (int i = 0; i < strlen(str); i++)
	{
			write(1, &str[i], 1);
	}

  struct timeval tv;
  gettimeofday(&tv, NULL);
  
	return 0;
}