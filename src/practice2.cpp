//
// Created by hqx on 17-4-14.
//
#include "practice.h"

std::mutex m_2;
std::condition_variable con;
const int Loop = 10;
int flag_2 = 0;

void fun_2(int id)
{
    for(int i=0; i<Loop; i++){
        std::unique_lock<std::mutex> lk(m_2);
        while(id!=flag_2)
            con.wait(lk);
        std::cout<< ('A'+id);
        flag_2 = (flag_2+1)%3;
        con.notify_all();
    }
}

void run_practice2()
{
    std::thread B(fun_2,1);
    std::thread C(fun_2,2);
    fun_2(0);
    B.join();
    C.join();
}

