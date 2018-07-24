//
// Created by lihaifeng on 18-7-7.
//

#include "test_boost.h"

int testTokenizer(){

    std::cout<<"测试分词器库..........................."<<std::endl;
    std::string s = "This is,  a test";
    boost::tokenizer<> tok(s);
    for(auto& token:tok){
        std::cout<<token<<" ";
    }

    std::cout<<std::endl;

    std::string str = ";;Hello|world||-foo--bar;yow;baz|";
    typedef boost::tokenizer<boost::char_separator<char> >
            tokenizer;
    boost::char_separator<char> sep("-;|");
    tokenizer tokens(str, sep);
    for(auto& token:tokens){
        std::cout<<token<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

int testTrivialLog(){

    std::cout<<"test boost log ..................."<<std::endl;

    boost::log::add_file_log(boost::log::keywords::file_name = "../log/sample_%N.log",
                             boost::log::keywords::format = "[%TimeStamp%]: [%ProcessID%] [%ThreadID%] %Message%");
    boost::log::add_common_attributes();

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    return 0;
}

int testTimer(){

    std::cout<<"test timer ....................."<<std::endl;

    boost::timer::auto_cpu_timer t;
    for (long i = 0; i < 100000000; ++i)
        std::sqrt(123.456L); // burn some time

    return 0;
}