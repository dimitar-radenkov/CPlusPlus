/*
 * Money.h
 *
 * Description: Money, fixed decimal point class
 *
 * Author: Dimitar Petrunov
 * Modification: Stamen Rakov
 * $Id: Money.h,v 1.1 2011-07-11 11:30:29 stamen Exp $
 *
 * Copyright (c) 2004-2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */


#ifndef MONEY_H
#define MONEY_H

#include "CommonException.h"

#include <math.h>
#include <stdio.h>

#include <string>
#include <float.h>

/**
 *
 * Work with Money type: Only money is hold by this type
 *
 * The follwoing is a list of forbidden operations for the money type. All
 * of the mentioned operators are implemented with a default behaviour to
 * give assertation failures.
 *
 * Forbidden operations:
 *     // no way to multiply money
 *     inline Money operator * (const Money& ref) const
 *     // no way to multiply money
 *     inline Money& operator *= (const Money& ref) const
 *
 *     // int is not dividable by money
 *     inline int& operator /= (int& nValue, const Money& ref)
 *     // int is not dividable by money
 *     inline Currency operator / (int& nValue, const Money& ref)
 *
 * IMPORTANT:
 *
 *     int nDollars= 1;
 *     // next line means that we set the total amount of money to 1 dollar
 *     Money MyMoney = nDollars;
 *     // get money as dollars
 *     nDollars = MyMoney;
 *
 *
 *     int64_t nMillionth= 1;
 *     // next line means that we set the total amount of
 *     // money to 1 millionth of the dollar
 *     Money MyMoney = (int64_t) nMillionth;
 *     // get money as millionths of the dollar
 *     nMillionth = (int64_t )MyMoney;
 */
namespace utils
{

class Money
{
public:
    /**
     */
    Money ()
    {
        _millionths = 0;
    }

    /**
     */
    Money (const Money & ref)
    {
        _millionths = (int64_t) ref;
    }

    /**
     */
    Money (const int dollars)
    {
        _millionths = (int64_t) dollars * 1000000;
    }

    /**
     */
    Money (const int64_t millionths)
    {
        _millionths = millionths;
    }

    /**
     */
    Money& setInCents(const int64_t cents)
    {
        _millionths = cents * 10000;
        return *this;
    }

    /**
     */
    int64_t getInCents() const
    {
        return _millionths / 10000;
    }

private:
    /**
     */
    operator double () const
    {
        // converting back to double
        return _millionths / (double) 1000000;
    }

public:
    /**
     */
    operator bool() const
    {
        return 0 != _millionths;
    }

    /**
     */
    operator int64_t() const
    {
        return _millionths;
    }

    /**
     */
    operator int() const
    {
        return _millionths / 1000000;
    }

    /**
     */
    operator std::string() const
    {
        char chBuffer[30];

        double dRes = (double)*this;
        sprintf(chBuffer, "%.6f", dRes);
        std::string strBuffer(chBuffer);

        return strBuffer;
    }

    /**
     */
    Money& operator = (const Money & ref)
    {
        _millionths = (int64_t) ref;
        return *this;
    }

    /**
     */
    Money& operator += (const Money & ref)
    {
        _millionths += (int64_t) ref;
        return *this;
    }

    /**
     */
    Money& operator -= (const Money & ref)
    {
        _millionths -= (int64_t) ref;
        return *this;
    }

    /**
     */
    Money& operator *= (const Money & ref)
    {
        throw CommonException("Money multiplication is forbidden.", 0);
        return *this;
    }

    /**
     */
    Money& operator /= (const Money & ref)
    {
        _millionths = _millionths / ((int) ref);
        return *this;
    }

    /**
     */
    Money operator + (const Money & ref) const
    {
        return _millionths + (int64_t) ref;
    }

    /**
     */
    Money operator - (const Money & ref) const
    {
        return _millionths - (int64_t) ref;
    }

    /**
     */
    Money operator * (const Money & ref) const
    {
        throw CommonException("Money multiplication is forbidden.", 0);
        return *this;
    }

    /**
     */
    Money operator / (const Money & ref) const
    {
        return _millionths / ((int) ref);
    }

    /**
     */
    bool operator == (const Money & ref) const
    {
        return (_millionths == (int64_t) ref);
    }

    /**
     */
    bool operator != (const Money & ref) const
    {
        return !(*this == ref);
    }

    /**
     */
    bool operator > (const Money & ref) const
    {
        return (_millionths > (int64_t) ref);
    }

    /**
     */
    bool operator >= (const Money & ref) const
    {
        return (_millionths >= (int64_t) ref);
    }

    /**
     */
    bool operator < (const Money & ref) const
    {
        return !(*this >= ref);
    }

    /**
     */
    bool operator <= (const Money & ref) const
    {
        return !(*this > ref);
    }

    /**
     */
    Money & operator = (const int64_t & millionths)
    {
        _millionths = millionths;
        return *this;
    }

    /**
     */
    Money & operator += (const int64_t & millionths)
    {
        _millionths += millionths;
        return *this;
    }

    /**
     */
    Money& operator -= (const int64_t & millionths)
    {
        _millionths -= millionths;
        return *this;
    }

    /**
     */
    Money& operator *= (const int64_t & millionths)
    {
        throw CommonException("Money multiplication is forbidden.", 0);
        return *this;
    }

    /**
     */
    Money& operator /= (const int64_t & millionths)
    {
        throw CommonException("Money division is forbidden.", 0);
        return *this;
    }

    /**
     */
    Money operator + (const int64_t & millionths) const
    {
        return _millionths + millionths;
    }

    /**
     */
    Money operator - (const int64_t & millionths) const
    {
        return _millionths - millionths;
    }

    /**
     */
    Money operator * (const int64_t & millionths) const
    {
        throw CommonException("Money multiplication is forbidden.", 0);
        return *this;
    }

    /**
     */
    Money operator / (const int64_t & millionths) const
    {
        throw CommonException("Money division is forbidden.", 0);
        return *this;
    }

    /**
     */
    bool operator == (const int64_t & millionths) const
    {
        return _millionths == millionths;
    }

    /**
     */
    bool operator != (const int64_t & millionths) const
    {
        return _millionths != millionths;
    }

    /**
     */
    bool operator > (const int64_t & millionths) const
    {
        return _millionths > millionths;
    }

    /**
     */
    bool operator >= (const int64_t & millionths) const
    {
        return _millionths >= millionths;
    }

    /**
     */
    bool operator < (const int64_t & millionths) const
    {
        return _millionths < millionths;
    }

    /**
     */
    bool operator <= (const int64_t & millionths) const
    {
        return _millionths <= millionths;
    }

    /**
     */
    Money& operator = (const int & dollars)
    {
        _millionths = (int64_t) dollars * 1000000;
        return *this;
    }

    /**
     */
    Money& operator += (const int & dollars)
    {
        _millionths += (int64_t) dollars * 1000000;
        return *this;
    }

    /**
     */
    Money& operator -= (const int & dollars)
    {
        _millionths -= (int64_t) dollars * 1000000;
        return *this;
    }

    /**
     */
    Money& operator *= (const int & dollars)
    {
        _millionths *= (int64_t) dollars;
        return *this;
    }

    /**
     */
    Money& operator /= (const int & dollars)
    {
        _millionths /= (int64_t) dollars;
        return *this;
    }

    /**
     */
    Money operator + (const int & dollars) const
    {
        return _millionths + (int64_t) dollars * 1000000;
    }

    /**
     */
    Money operator - (const int & dollars) const
    {
        return _millionths - (int64_t) dollars * 1000000;
    }

    /**
     */
    Money operator * (const int & dollars) const
    {
        return _millionths * (int64_t) dollars;
    }

    /**
     */
    Money operator / (const int & dollars) const
    {
        return _millionths / (int64_t) dollars;
    }

    /**
     */
    bool operator == (const int & dollars) const
    {
        return _millionths == (int64_t) dollars * 1000000;
    }

    /**
     */
    bool operator != (const int & dollars) const
    {
        return _millionths != (int64_t) dollars * 1000000;
    }

    /**
     */
    bool operator > (const int & dollars) const
    {
        return _millionths > (int64_t) dollars * 1000000;
    }

    /**
     */
    bool operator >= (const int & dollars) const
    {
        return _millionths >= (int64_t) dollars * 1000000;
    }

    /**
     */
    bool operator < (const int & dollars) const
    {
        return _millionths < (int64_t) dollars * 1000000;
    }

    /**
     */
    bool operator <= (const int & dollars) const
    {
        return _millionths <= (int64_t) dollars * 1000000;
    }

    /**
     */
    Money operator - () const
    {
        return -_millionths;
    }

    /**
     */
    Money operator ! () const
    {
        return !_millionths;
    }

    /**
     */
    bool operator || (const Money& ref) const
    {
        return _millionths || (int64_t) ref;
    }

    /**
     */
    bool operator && (const Money & ref) const
    {
        return _millionths && (int64_t) ref;
    }

    /**
     */
    friend inline int& operator += (int & dollars, const Money & ref)
    {
        return dollars += (int) ref;
    }

    /**
     */
    friend inline int& operator -= (int & dollars, const Money & ref)
    {
        return dollars -= (int) ref;
    }

    /**
     */
    friend inline int& operator *= (int & dollars, const Money & ref)
    {
        throw CommonException("Money used as multiplier.", 0);
        // nominal return
        return dollars;
    }

    /**
     */
    friend inline int& operator /= (int & dollars, const Money & ref)
    {
        throw CommonException("Money used as divider.", 0);
        // nominal return
        return dollars;
    }

    /**
     */
    friend inline Money operator + (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 + (int64_t) ref;
    }

    /**
     */
    friend inline Money operator - (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 - (int64_t) ref;
    }

    /**
     */
    friend inline Money operator * (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * (int64_t) ref;
    }

    /**
     */
    friend inline Money operator / (const int & dollars, const Money & ref)
    {
        throw CommonException("Money used as divider.", 0);
        // nominal return
        return dollars;
    }

    /**
     */
    friend inline int64_t& operator += (int64_t & millionths,
                                        const Money & ref)
    {
        return millionths += (int64_t) ref;
    }

    /**
     */
    friend inline int64_t& operator -= (int64_t & millionths,
                                        const Money & ref)
    {
        return millionths -= (int64_t) ref;
    }

    /**
     */
    friend inline int64_t& operator *= (int64_t & millionths,
                                        const Money & ref)
    {
        throw CommonException("Money used as multiplier.", 0);
        // nominal return
        return millionths;
    }

    /**
     */
    friend inline int64_t& operator /= (int64_t & millionths,
                                        const Money & ref)
    {
        throw CommonException("Money used as divider.", 0);
        // nominal return
        return millionths;
    }

    /**
     */
    friend inline Money operator + (const int64_t & millionths,
                                    const Money & ref)
    {
        return millionths + (int64_t) ref;
    }

    /**
     */
    friend inline Money operator - (const int64_t & millionths,
                                    const Money & ref)
    {
        return millionths - (int64_t) ref;
    }

    /**
     */
    friend inline Money operator * (const int64_t & millionths,
                                    const Money & ref)
    {
        throw CommonException("Money used as multiplier.", 0);
        // nominal return
        return millionths;
    }

    /**
     */
    friend inline Money operator / (const int64_t & millionths,
                                    const Money & ref)
    {
        throw CommonException("Money used as divider.", 0);
        // nominal return
        return millionths;
    }

    /**
     */
    friend inline bool operator == (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 == (int64_t) ref;
    }

    /**
     */
    friend inline bool operator != (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 != (int64_t) ref;
    }

    /**
     */
    friend inline bool operator > (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 > (int64_t) ref;
    }

    /**
     */
    friend inline bool operator >= (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 >= (int64_t) ref;
    }

    /**
     */
    friend inline bool operator < (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 < (int64_t) ref;
    }

    /**
     */
    friend inline bool operator <= (const int & dollars, const Money & ref)
    {
        return (int64_t) dollars * 1000000 <= (int64_t) ref;
    }

    /**
     */
    friend inline bool operator == (const int64_t & millionths,
                                    const Money & ref)
    {
        return millionths == (int64_t) ref;
    }

    /**
     */
    friend inline bool operator != (const int64_t & millionths,
                                    const Money & ref)
    {
        return millionths != (int64_t) ref;
    }

    /**
     */
    friend inline bool operator > (const int64_t & millionths,
                                   const Money & ref)
    {
        return millionths > (int64_t) ref;
    }

    /**
     */
    friend inline bool operator >= (const int64_t & millionths,
                                    const Money & ref)
    {
        return millionths >= (int64_t) ref;
    }

    /**
     */
    friend inline bool operator < (const int64_t & millionths,
                                   const Money & ref)
    {
        return millionths < (int64_t) ref;
    }

    /**
     */
    friend inline bool operator <= (const int64_t & millionths,
                                    const Money & ref)
    {
        return millionths <= (int64_t) ref;
    }

private:
    /**
     */
    int64_t _millionths;
};

} //namespace utils

#endif // MONEY_H
