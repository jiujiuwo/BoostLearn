//
// Created by lihaifeng on 18-7-7.
//

#ifndef TESTBOOST_TEST_BOOST_H
#define TESTBOOST_TEST_BOOST_H

#include <iostream>
#include <string>

#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


#include <boost/timer/timer.hpp>
#include <boost/tokenizer.hpp>
#include <boost/regex.hpp>

int testRegex();
int testTokenizer();
int testTrivialLog();
int testTimer();

#endif //TESTBOOST_TEST_BOOST_H
