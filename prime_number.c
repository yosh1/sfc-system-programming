#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 100000
#define THREAD_NUM 2

void thread1(unsigned char ch[]); //スレッド1
void thread2(unsigned char ch[]); //スレッド2

pthread_mutex_t mutex; //2つのスレッド間で変数の保護を行うためにmutexを定義

void thread1(unsigned char ch[])
{

    pthread_mutex_lock(&mutex); // 排他制御のためにlock

    int j, num;
    num = MAX_NUM; // numに調べる数字の範囲を代入

    for (int i = 0; 0 < num; i++, num--)
    { // numが0になるまでループ
        for (j = 2; num % j != 0 && num > 1; j++)
            ; // 素数の場合j == numになるfor文を用意
        if (j == num)
        {
            ch[num - 1] = 1; // 素数の場合配列に1を代入
        }
        else
        {
            ch[num - 1] = 0; // 素数でない場合配列に0を代入
        }
    }
    pthread_mutex_unlock(&mutex); // 排他制御のためにunlock
}

void thread2(unsigned char ch[])
{

    pthread_mutex_lock(&mutex); // 排他制御のためにlock

    int j, num;
    num = MAX_NUM; // numに調べる数字の範囲を代入

    for (int i = 0; 0 < num; i++, num--)
    { // numが0になるまでループ
        for (j = 2; num % j != 0 && num > 1; j++)
            ; // 素数の場合j == numになるfor文を用意
        if (j == num)
        {
            ch[num - 1] = 1; // 素数の場合配列に1を代入
        }
        else
        {
            ch[num - 1] = 0; // 素数でない場合配列に0を代入
        }
    }
    pthread_mutex_unlock(&mutex); // 排他制御のためにunlock
}

int main(void)
{
    pthread_t tid1, tid2;             // スレッド識別子用にtid1,tid2を定義
    pthread_mutex_init(&mutex, NULL); // 排他制御用のmutexを初期化
    unsigned char check[MAX_NUM + 1]; // 判定を代入する配列を定義

    pthread_create(&tid1, NULL, (void *)thread1, check); // スレッド1を作成
    pthread_create(&tid2, NULL, (void *)thread2, check); // スレッド2を作成

    pthread_join(tid1, NULL); // 指定されたスレッドが終了するのを待機
    pthread_join(tid2, NULL); // 指定されたスレッドが終了するのを待機

    for (int i = 0; i < MAX_NUM; i++)
    {
        if (check[i] == 1)
            printf("%d\n", check[i]); // 値が1の時のみprint
    }

    pthread_mutex_destroy(&mutex); // 排他制御用のmutexを削除

    return 0;
}
