/*
 * wvassert.h
 *
 *  Created on: Sep 17, 2016
 *      Author: nidhi
 */

#ifndef SRC_WVASSERT_H_
#define SRC_WVASSERT_H_


namespace wvrobotics {

class WVAssert {


private:
	static unsigned int count;
	static unsigned int TIME_DELAY_MS;
public:
	WVAssert();
	virtual ~WVAssert();

	static void wvassert(std::string fileName, unsigned int line, std::string function, std::string expression);
	static void wvassertM(std::string fileName, unsigned int line, std::string function, std::string expression, std::string message);
	static unsigned int getCount();
};


#if defined(WVNDEBUG)
#define WVASSERT(_expr) ;
#define WVASSERTM(_expr, _message) ;
#else
#define WVASSERT(_expr) if(_expr == 0) \
  { \
    wvrobotics::WVAssert::wvassert(__FILE__, __LINE__, __FUNCTION__, #_expr);\
  };

#define WVASSERTM(_expr, _message) if(_expr == 0) \
  { \
    wvrobotics::WVAssert::wvassertM(__FILE__, __LINE__, __FUNCTION__, #_expr, _message);\
  };

#endif


} /* namespace wvrobotics */

#endif /* SRC_WVASSERT_H_ */
