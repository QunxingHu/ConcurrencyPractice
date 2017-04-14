//
// Created by hqx on 17-4-14.
//

/**
 * 实现 子线程循环10次，主线程循环100次，回到子线程循环10次，回到主线程循环100次.....如此循环50次
 *
 */

#include "practice.h"

std::mutex m;
std::condition_variable cond;
int flag=10;    //10 代表子线程， 100代表主线程

void fun(int num)
{
    for(int i=0; i<50; i++) { //循环50次
        std::unique_lock<std::mutex> lk(m); //unique lock
        while(flag != num)
            cond.wait(lk);  //等待唤醒

        // 循环 num 次
        for(int j=0;j<num; j++)
            std::cout << "loop: " << j << " ";
        std::cout << std::endl;

        //切换flag
        if(flag == 10){
            std::cout << "Child thread." << std::endl;
            flag = 100;
        }else if(flag == 100){
            std::cout << "Main thread." << std::endl;
            flag = 10;
        }

        cond.notify_one();          //释放锁，唤醒一个线程
    }
}

int run_practice1()
{
    std::thread child(fun,10);
    fun(100);   //主线程
    child.join();   //子线程
    return 0;
}

