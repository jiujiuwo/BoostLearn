//
// Created by lihaifeng on 18-7-7.
//

#include "test_cpp11.h"

std::mutex myLock;

int testRegex(){

    std::cout<<"正则库测试......................"<<std::endl;

    regex reg1("\\w+day");
    string s1 = "saturday";
    string s2 = "saturday and sunday";
    smatch r1;
    smatch r2;
    cout << boolalpha << regex_match(s1, r1, reg1) << endl;
    cout << boolalpha << regex_match(s2, r2, reg1) << endl;
    cout << "s1匹配结果：" << r1.str() << endl;
    cout << "s2匹配结果：" << r2.str() << endl;
    cout << endl;

    smatch rr1;
    smatch rr2;
    cout << boolalpha << regex_search(s1, rr1, reg1) << endl;
    cout << "s1匹配结果：" << rr1.str() << endl;
    cout << boolalpha << regex_search(s2, rr2, reg1) << endl;
    cout << "s1匹配结果：" << rr2.str() << endl;
    cout << endl;
}

//测试chrono的一种用于,用于格式化显示时间
void testChrono(){

    cout<<"test chrono ***********************"<<endl;

    using namespace std::chrono;

    system_clock::time_point now = system_clock::now();

    std::time_t last = system_clock::to_time_t(now - hours(24));
    std::time_t next = system_clock::to_time_t(now + hours(24));

    std::cout<<"One day ago, the time was "<<std::put_time(std::localtime(&last),"%F %T")<<std::endl;
    std::cout<<"Next day, the time was "<<std::put_time(std::localtime(&next),"%F %T")<<std::endl;

}
/*

//测试计时器,发现gcc 5.4并没有实现Timer
void testTimer(){
    using namespace std::chrono;
    //Timer t;
}*/

void testToString(){
    cout<<"test to string *********************"<<endl;

    double f = 1.53;
    string sf = to_string(f);
    cout<< sf<<endl;

    string s1 = "10";
    string s2 = "3.14159";
    string s3 = "3135 with words";
    string s4 = "words with 1234";
    string s5 = "3.6";

    int num1 = atoi(s1.data());
    int num2 = atoi(s2.data());
    int num3 = atoi(s3.data());
    int num4 = atoi(s4.data());

    float num5 = atof(s2.data());
    int num6 = atoi(s5.data());

    cout<<s1<<":"<<num1<<", "<<s2<<":"<<num2<<", "<<s3<<":"<<num3<<", "<<s4<<":"<<num4<<endl;
    cout<<s2<<":"<<num5<<", "<<s5<<":"<<num6<<endl;
}

void threadFunc(int a,string b){
    myLock.lock();
    cout<<"thread function **************************"<<endl;
    cout<<"传入的参数"<<a<<","<<b<<std::endl;
    cout<<"当前线程id: "<<std::this_thread::get_id()<<endl;
    cout<<"线程休眠"<<5<<"s"<<endl;
    std::this_thread::sleep_for(chrono::seconds(1));
    myLock.unlock();
}

void testThread(){

    cout<<"test thread  *****************************"<<endl;

    string s1 = "test thread";
    thread thread1(threadFunc,1,s1);
    cout<<"线程 id: "<<thread1.get_id()<<endl;
    cout<<"CPU核心数量"<<thread1.hardware_concurrency()<<endl;
    thread1.join();
}

void testMutex(){

    cout<<"test mutex  *****************************"<<endl;
    thread thread1(threadFunc,1,"thread 1");
    thread thread2(threadFunc,2,"thread 2");
    thread thread3(threadFunc,3,"thread 3");

    thread1.join();
    thread2.join();
    thread3.join();

}