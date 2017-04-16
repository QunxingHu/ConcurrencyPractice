//
// Created by quincy on 17-4-16.
//

/*
 * 题目：有四个线程1、2、3、4。线程1的功能就是输出1，线程2的功能就是输出2，以此类推.........现在有四个文件ABCD。初始都为空。现要让四个文件呈如下格式：
A：1 2 3 4 1 2....
B：2 3 4 1 2 3....
C：3 4 1 2 3 4....
D：4 1 2 3 4 1....
 */

#include "practice.h"

std::mutex m_3;
std::condition_variable cond_3;
int flag_3;
void fun_3(int num)
{
    for(int i=0; i< 10; i++)
    {
        std::unique_lock<std::mutex> lk(m_3);
        while(flag_3 != num){
            cond_3.wait(lk);
        }
        std::cout << num + 1 << std::endl;
        flag_3 = (flag_3+1)%4;
        cond_3.notify_all();
    }
}

void run_practice3()
{
    // flag_3 = 1; 表示输出第一个文件， flag_3 = 2输出第二个文件
    // flag_3 只是改变第一个输出的数字
    std::thread one(fun_3,1);
    std::thread two(fun_3,2);
    std::thread three(fun_3,3);
    fun_3(0);
    one.join();
    two.join();
    three.join();
    std::cout << std::endl;
}