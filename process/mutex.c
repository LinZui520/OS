#include <stdio.h>
#include <threads.h>
#include <unistd.h>

int sum = 0;

//定义互斥锁
mtx_t mutex;

int thread_func(void* arg){
    int id = *(int*) arg;
    for(int i=1;i<=100000;i++){
        //加锁
        mtx_lock(&mutex);
        sum ++;
        //解锁
        mtx_unlock(&mutex);
    }
    return 0;
}

int main(){
    thrd_t thread1,thread2;
    int id1=1, id2=2;
    //初始化互斥锁
    mtx_init(&mutex, mtx_plain);
    thrd_create(&thread1, thread_func, &id1);
    thrd_create(&thread2, thread_func, &id2);
    sleep(1);
    //销毁互斥锁
    mtx_destroy(&mutex);
    printf("sum = %d\n", sum);
    return 0;
}