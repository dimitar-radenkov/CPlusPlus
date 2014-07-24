/**
 * CommonException.h
 *
 * $id$
 *
 * Description: Definition of CommonException class
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef __COMMON_EXCEPTION_H__
#define __COMMON_EXCEPTION_H__

#include <string>
#include <cerrno>

namespace utils
{

/**
 * The exception is thrown in a common cases (outside the device specific
 * calsses). It's usually catched in the program's main function to output
 * error message.
 */
class CommonException: public std::exception
{
public:
    /**
     * Constructor of the exception's class. Initializes the message text and
     * the code of an exception when it's created.
     * @param message The message text describing the nature of the problem and why it has occurred.
     * @param code Representation of the exception as number.
     */
    CommonException(const char *message_, unsigned long code_):
        _errMsg(message_),
        _errCode(code_)
    {
    }

    /**
     * Constructor of the exception's class. Initializes the message text and
     * the code of an exception when it's created. By default 'code' takes
     * the current 'errno' value.
     * @param message The message text describing the nature of the problem and why it has occurred.
     */
    CommonException(const char *message_):
        _errMsg(message_),
        _errCode(errno)
    {
    }

    /**
     * Exception's distruction method.
     */
    virtual ~CommonException() throw()
    {}

    /**
     * Retrieves the reason in readable form of why the exception was thrown.
     * @return Constant string of the error message.
     */
    virtual const char* what() const throw()
    { return _errMsg.c_str(); }
    /**
     * Retrieves the reason of exception's occurrence as number.
     * @return The code of the thrown exception.
     */
    virtual const int code() const throw()
    { return _errCode; }

private:
    /**
     * This is the error message of the exception.
     */
    std::string _errMsg;
    /**
     * This is the error code of the exception.
     */
	int _errCode;
};

}//namespace utils

#endif // __COMMON_EXCEPTION_H__
