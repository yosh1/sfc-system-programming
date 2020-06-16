#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 2
#define NUM_DATA 100000
unsigned long data[NUM_DATA][2];
unsigned long sum = 0;

void *thread1(void *pParam); //スレッド１
void *thread2(void *pParam); //スレッド２
int ans, ans2;

pthread_mutex_t mutex; //2つのスレッド間で変数の保護を行う

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
    }
  }
  pthread_mutex_unlock(&mutex);
  printf("Running: thread1\n");
  return NULL;
}

//スレッド２
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
    }
  }
  pthread_mutex_unlock(&mutex);
  printf("Running: thread2\n");
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t tid1, tid2; // スレッド識別変数

  pthread_mutex_init(&mutex, NULL);
  // スレッドの作成
  ans = pthread_create(&tid1, NULL, thread1, NULL);
  ans2 = pthread_create(&tid2, NULL, thread2, NULL);

  // スレッド終了待ち
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  pthread_mutex_destroy(&mutex);
  printf("Ans: %lu\n", sum);
  return 0;
}
