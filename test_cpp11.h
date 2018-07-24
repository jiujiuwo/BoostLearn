//
// Created by lihaifeng on 18-7-7.
//

#ifndef TESTBOOST_TEST_CPP11_H
#define TESTBOOST_TEST_CPP11_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <regex>

using namespace std;

void testChrono();
void testToString();
void testThread();
void threadFunc(int a,string b);
void testMutex();
#endif //TESTBOOST_TEST_CPP11_H
