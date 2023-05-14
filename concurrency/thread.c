#include <threads.h>
#include <stdio.h>

int thread_func(void* arg){
    int* id = (int*) arg;
    printf("正在执行线程%d\n", *id);
    thrd_exit(0);
}

int main(){
    //定义线程
    thrd_t thread;

    int id=1;
    int ret;
    
    //创建线程
    //函数原型 int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
    ret = thrd_create(&thread, thread_func, &id);

    //判断线程是否创建成功
    if(ret != thrd_success){
        printf("线程创建失败\n");
        return -1;
    }

    //等待线程结束
    //函数原型 int thrd_join(thrd_t thr, int *res);
    ret = thrd_join(thread, NULL);

    //判断线程是否等待成功
    if(ret != thrd_success){
        printf("线程等待失败\n");
        return -1;
    }

    return 0;
}