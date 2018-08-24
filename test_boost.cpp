//
// Created by lihaifeng on 18-7-7.
//
#include "test_boost.h"
#include "test_cpp11.h"
using namespace std;

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

    boost::log::core::get()->set_filter
            (
                    boost::log::trivial::severity >= boost::log::trivial::trace
            );

    //boost::log::core::get()->add_global_attribute();

    boost::log::add_file_log(boost::log::keywords::file_name = "../log/sample_%N.log",
                             boost::log::keywords::format =  boost::log::expressions::stream
                                     << boost::log::expressions::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
                                     <<" [" << boost::log::expressions::attr<boost::log::attributes::current_thread_id::value_type>("ThreadID") <<"] <" << boost::log::trivial::severity
                                     << "> " << boost::log::expressions::smessage,
                             boost::log::keywords::auto_flush = true);

    boost::log::add_common_attributes();
  //  boost::log::expressions::attribute_keyword

    //该函数为线程安全的日志
    BOOST_LOG_TRIVIAL(trace) <<"A trace severity message";
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

int testFileSystem(){

    string fileName = "../config/media_search.cfg";
    cout<<fileName<<" size: "<<boost::filesystem::file_size(fileName)<<endl;
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.is_open()){
        string tmp;
        while(getline(inFile,tmp)){
            if(tmp.find('#')!=string::npos){

            }else{
                cout<<tmp<<endl;
                map<string,string> configMap;
                boost::trim(tmp);
                vector<string> tokens;
                boost::split(tokens, tmp, boost::is_any_of("="), boost::token_compress_on);
                for(int i= 0;i < tokens.size();i++){
                    if(tokens.size()!=2 && tokens.size() > 0){
                        BOOST_LOG_TRIVIAL(error)<<"配置文件错误"<< tokens[i];
                    }else{
                        configMap.insert(pair<string,string>(tokens[i],tokens[i+1]));
                        BOOST_LOG_TRIVIAL(debug)<< tokens[i]<<" : "<<tokens[i+1];
                        break;
                    }
                }
                //configMap.insert()
            }
        }
    }else{
        cout<<"open file "<<fileName<<" failed"<<endl;
    }
}


void mySignalHandler(int signalType){

    BOOST_LOG_TRIVIAL(error)<<"错误信号"<< signalType;
    boost::stacktrace::safe_dump_to("./backtrace.dump");
    if (boost::filesystem::exists("./backtrace.dump")) {
        // there is a backtrace
        std::ifstream ifs("./backtrace.dump");

        boost::stacktrace::stacktrace st = boost::stacktrace::stacktrace::from_dump(ifs);
        std::cout << "Previous run crashed:\n" << st << std::endl;
        BOOST_LOG_TRIVIAL(error)<<st;

        // cleaning up
        ifs.close();
        boost::filesystem::remove("./backtrace.dump");
    }
}

void testStackTrace(){
    BOOST_LOG_TRIVIAL(debug)<<"test boost stack trace ";
    std::signal(SIGABRT,&mySignalHandler);
    std::signal(SIGSEGV,&mySignalHandler);
    int* a = new int[5];
    delete [] a;
    delete [] a;
}