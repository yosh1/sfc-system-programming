#include <pthread.h>
#include <stdio.h>
​
#define NUM_THREADS 10
#define NUM_DATA 100000
unsigned long data[NUM_DATA][3];
unsigned long sum = 0;
​
void *thread1(void *pParam);  //スレッド1
void *thread2(void *pParam);  //スレッド2
void *thread3(void *pParam);  //スレッド3
void *thread4(void *pParam);  //スレッド4
void *thread5(void *pParam);  //スレッド5
void *thread6(void *pParam);  //スレッド6
void *thread7(void *pParam);  //スレッド7
void *thread8(void *pParam);  //スレッド8
void *thread9(void *pParam);  //スレッド9
void *thread10(void *pParam); //スレッド10
​
int ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9, ans10, roop;
int count[10];
​
pthread_mutex_t mutex; //2つのスレッド間で変数の保護を行う
​
//スレッド１
void *thread1(void *pParam)
{
  //mutex 間は他のスレッドから変数を変更できない
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 1;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド2
void *thread2(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 2;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド3
void *thread3(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 3;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド4
void *thread4(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 4;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド5
void *thread5(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 5;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド6
void *thread6(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 6;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド7
void *thread7(void *pParam)
{
  //mutex 間は他のスレッドから変数を変更できない
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 7;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド8
void *thread8(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 8;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド9
void *thread9(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 9;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
//スレッド10
void *thread10(void *pParam)
{
  //mutex で  count1 を保護
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < NUM_DATA; i++)
  {
    if (data[i][0] == 0)
    {
      sum += data[i][1];
      data[i][0] = 1;
      data[i][2] = 10;
    }
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
​
int main(int argc, char *argv[])
{
  pthread_t tid1, tid2, tid3, tid4, tid5, tid6, tid7, tid8, tid9, tid10; // スレッド識別変数
  long i;
  for (i = 0; i < NUM_DATA; i++)
  {
    data[i][0] = 0;
    data[i][1] = i;
    data[i][2] = NUM_THREADS;
  }
  pthread_mutex_init(&mutex, NULL);
  // スレッドの作成
  ans1 = pthread_create(&tid1, NULL, thread1, NULL);
  ans2 = pthread_create(&tid2, NULL, thread2, NULL);
  ans3 = pthread_create(&tid3, NULL, thread3, NULL);
  ans4 = pthread_create(&tid4, NULL, thread4, NULL);
  ans5 = pthread_create(&tid5, NULL, thread5, NULL);
  ans6 = pthread_create(&tid6, NULL, thread6, NULL);
  ans7 = pthread_create(&tid7, NULL, thread7, NULL);
  ans8 = pthread_create(&tid8, NULL, thread8, NULL);
  ans9 = pthread_create(&tid9, NULL, thread9, NULL);
  ans10 = pthread_create(&tid10, NULL, thread10, NULL);
  // スレッド終了待ち
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);
  pthread_join(tid4, NULL);
  pthread_join(tid5, NULL);
  pthread_join(tid6, NULL);
  pthread_join(tid7, NULL);
  pthread_join(tid8, NULL);
  pthread_join(tid9, NULL);
  pthread_join(tid10, NULL);
​
  pthread_mutex_destroy(&mutex);
  printf("ans: %lu\n", sum);
​
  for (i = 0; i < NUM_DATA; i++)
  {
    for (roop = 0; roop <= 10; roop++)
    {
      if (data[i][2] == roop + 1)
      {
        count[roop]++;
      }
    }
  }
​
  //ランダムなThread1つのみで合計加算数を表示します。
  for (int i = 0; i < 10; i++)
  {
    printf("Thread%d : %d\n", i + 1, count[i]);
  }
​
  return 0;
}
