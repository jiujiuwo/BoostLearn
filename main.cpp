#include <iostream>
#include <pthread.h>
#include <memory>
#include <glog/logging.h>
#include <ctime>
#include <sys/time.h>

#include "test_boost.h"
#include "test_cpp11.h"

int main() {

    std::string logName = "mylog1";

    //输出日志的程序名字
    google::InitGoogleLogging(logName.data());

    //it will dump useful information when the program crashes on certain signals such as SIGSEGV
    google::InstallFailureSignalHandler();

    //输出日志文件的位置
    google::SetLogDestination(google::INFO, "../log/");

    //FLAGS_logtostderr = true;  //设置日志消息是否转到标准输出而不是日志文件
    FLAGS_alsologtostderr = true;  //设置日志消息除了日志文件之外是否去标准输出
    FLAGS_colorlogtostderr = true;  //设置记录到标准输出的颜色消息（如果终端支持）
    FLAGS_log_prefix = true;  //设置日志前缀是否应该添加到每行输出
    FLAGS_logbufsecs = 0;  //设置可以缓冲日志的最大秒数，0指实时输出
    FLAGS_max_log_size = 100;  //设置最大日志文件大小（以MB为单位）
    FLAGS_stop_logging_if_full_disk = true;  //设置是否在磁盘已满时避免日志记录到磁盘

    DLOG(INFO)<<"hello world!!!";
    DLOG(INFO)<< "error";
    //std::cout << "Hello, World!" << std::endl;

    google::ShutdownGoogleLogging();

    //ctime
    time_t time1;
    time(&time1);
    std::cout<<time1<<std::endl;

    //sys.time
    timeval timeval1;
    gettimeofday(&timeval1,NULL);
    std::cout<<timeval1.tv_sec<<","<<timeval1.tv_usec<<std::endl;

    std::cout<<"test boost ++++++++++++++++++++++++++++++++"<<std::endl;
    testRegex();
    testTokenizer();
    testTrivialLog();
    testTimer();

    std::cout<<"test cpp 11 ------------------------------"<<std::endl;
    testChrono();
    testToString();
    testThread();
    testMutex();

    return 0;
}