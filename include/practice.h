//
// Created by hqx on 17-4-14.
//

#ifndef CONCURRENCYPRACTICE_PRACTICE_H
#define CONCURRENCYPRACTICE_PRACTICE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// practice 1
void fun_1(int num);
int run_practice1();

// practice 2
void fun_2(int id);
void run_practice2();

// practice3
void fun_3(int id);
void run_practice3();


#endif //CONCURRENCYPRACTICE_PRACTICE_H
