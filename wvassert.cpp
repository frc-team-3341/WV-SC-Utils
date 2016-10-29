/*
 * wvassert.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: nidhi
 */

#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include "wvassert.h"

namespace wvrobotics {

unsigned int WVAssert::count = 0;
unsigned int WVAssert::TIME_DELAY_MS = 50; //enough time to display error message if program crashes
WVAssert::WVAssert() {
	// TODO Auto-generated constructor stub

}


void WVAssert::wvassert(std::string fileName, unsigned int line, std::string function, std::string expression)
{
	 std::cerr << fileName << ": " << line << ": " << function << ", " << expression << std::endl;
	 count++;
	 std::this_thread::sleep_for(std::chrono::milliseconds(TIME_DELAY_MS));
}
void WVAssert::wvassertM(std::string fileName, unsigned int line, std::string function, std::string expression, std::string message)
	{
	 std::cerr << fileName << ": " << line << ": " << function << ", " << expression <<  std::endl;
	 std::cerr << message << std::endl;
	 count++;
	 std::this_thread::sleep_for(std::chrono::milliseconds(TIME_DELAY_MS));
	}

unsigned int WVAssert::getCount()
{
	return count;
}

WVAssert::~WVAssert() {
	// TODO Auto-generated destructor stub
}

} /* namespace wvrobotics */
