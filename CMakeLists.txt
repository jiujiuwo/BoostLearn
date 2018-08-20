cmake_minimum_required(VERSION 3.10)
project(TestBoost)

#使用boost log 动态库必须加这个编译选项
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE debug)

link_directories(lib lib/boost)

include_directories(include include/boost)

add_executable(TestBoost main.cpp test_boost.cpp test_boost.h test_cpp11.cpp test_cpp11.h testAsio.cpp testAsio.h)

target_link_libraries(TestBoost glog pthread boost_thread boost_regex boost_log boost_log_setup
        boost_system boost_filesystem boost_timer)