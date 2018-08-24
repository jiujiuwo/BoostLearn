//
// Created by lihaifeng on 18-7-7.
//

#ifndef TESTBOOST_TEST_BOOST_H
#define TESTBOOST_TEST_BOOST_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <map>
#include <utility>


#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>

// init log from file
#include <boost/log/utility/setup/settings.hpp>
#include <boost/log/utility/setup/from_settings.hpp>

#include <boost/timer/timer.hpp>
#include <boost/tokenizer.hpp>
#include <boost/regex.hpp>

#include <boost/program_options/parsers.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include <csignal>
#include <boost/stacktrace.hpp>
#include <fstream>     // std::ifstream
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

int testRegex();
int testTokenizer();
int testTrivialLog();
int testTimer();
int testFileSystem();
void testStackTrace();
#endif //TESTBOOST_TEST_BOOST_H
