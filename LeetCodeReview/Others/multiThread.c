/*************************************************************************

 美团笔试题，判断下面两个线程运行后x的可能取值
 可能的取值有1 , -1, -4,2,4
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int x = 0;
volatile int y = -2;
volatile int z = -2;

void method1() {
    if (z > 0) {
        x = y - z;
    }else{
        x = y + z;
    }
}

void method2() {
    y = 3;
    z = 1;
}

int main()
{
    
    
    for (int i = 0; i < 1000000; i++) {
        x = 0;
        y = -2;
        z = -2;
        int ret_thrd1, ret_thrd2;
        pthread_t thread1, thread2;
        ret_thrd1 = pthread_create(&thread1, NULL, (void *)&method1, NULL);
        ret_thrd2 = pthread_create(&thread2, NULL, (void *)&method2, NULL);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        if (x != 4 && x != -4 && x!= 2 && x!= -1 && x!= 1)
            printf("%d\n",x);

    }
    
}

