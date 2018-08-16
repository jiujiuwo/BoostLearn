//
// Created by lihaifeng on 18-8-9.
//

#include <iostream>
#include "testAsio.h"

using namespace std;

int asioFunc(const boost::system::error_code& e){

    cout<<" Asio asyn callback function"<<endl;
    cout<<e.message()<<endl;
}

int testAsio(){
    cout<<"test Asio .........................."<<endl;
    boost::asio::io_context io;

    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(10));
    t.wait();

    cout << "Hello, Asio!" <<endl;

    return 0;
}

int testAsio2(){
    boost::asio::io_context io;

    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.async_wait(&asioFunc);

    io.run();

    cout<<"after wait"<<endl;
    return 0;
}

void print(const boost::system::error_code& /*e*/,
           boost::asio::steady_timer* t, int* count)
{
    if (*count < 5)
    {
        std::cout << *count << std::endl;
        ++(*count);

        t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
        t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
    }
}

int testAsio3()
{
    boost::asio::io_context io;

    int count = 0;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
    t.async_wait(boost::bind(print,boost::asio::placeholders::error, &t, &count));

    io.run();

    std::cout << "Final count is " << count << std::endl;

    return 0;
}