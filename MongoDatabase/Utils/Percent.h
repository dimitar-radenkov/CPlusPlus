/*
 * Percent.h
 *
 * Description: Percent, fixed decimal point class
 *
 * Author: Stamen Rakov
 * $Id: Percent.h,v 1.1 2011-07-11 11:30:29 stamen Exp $
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef PERCENT_H
#define PERCENT_H


namespace utils
{
/**
 */
class Percent
{
public:
    /**
     */
    Percent ()
    {
        _hundredths = 0;
    }

    /**
     */
    Percent (const int percents)
    {
        _hundredths = percents * 1000;
    }

    /**
     */
    Percent (const int64_t hundredths)
    {
        _hundredths = hundredths;
    }

    /**
     */
    Percent (const Percent & ref)
    {
        _hundredths = (int64_t) ref;
    }

public:
    /**
     */
    template <typename valueType>
    valueType calculate (valueType value)
    {
        return ((int64_t) value * _hundredths) / 100000;
    }

private:
    /**
     */
    operator double () const
    {
        // converting back to double
        return _hundredths / (double) 1000;
    }

public:
    /**
     */
    operator bool() const
    {
        return 0 != _hundredths;
    }

    /**
     */
    operator int64_t() const
    {
        return _hundredths;
    }

    /**
     */
    operator int() const
    {
        return _hundredths / 1000;
    }

    /**
     */
    operator std::string() const
    {
        char chBuffer[20];

        double dRes = (double) *this;
        sprintf(chBuffer, "%.3f", dRes);
        std::string strBuffer(chBuffer);

        return strBuffer;
    }

    /**
     */
    Percent& operator = (const Percent & ref)
    {
        _hundredths = (int64_t) ref;
        return *this;
    }

    /**
     */
    Percent& operator += (const Percent & ref)
    {
        _hundredths += (int64_t) ref;
        return *this;
    }

    /**
     */
    Percent& operator -= (const Percent & ref)
    {
        _hundredths -= (int64_t) ref;
        return *this;
    }

    /**
     */
    Percent operator + (const Percent & ref) const
    {
        return _hundredths + (int64_t) ref;
    }

    /**
     */
    Percent operator - (const Percent & ref) const
    {
        return _hundredths - (int64_t) ref;
    }
\
    /**
     */
    bool operator == (const Percent & ref) const
    {
        return (_hundredths == (int64_t) ref);
    }

    /**
     */
    bool operator != (const Percent & ref) const
    {
        return !(*this == ref);
    }

    /**
     */
    bool operator > (const Percent & ref) const
    {
        return (_hundredths > (int64_t) ref);
    }

    /**
     */
    bool operator >= (const Percent & ref) const
    {
        return (_hundredths >= (int64_t) ref);
    }

    /**
     */
    bool operator < (const Percent & ref) const
    {
        return !(*this >= ref);
    }

    /**
     */
    bool operator <= (const Percent & ref) const
    {
        return !(*this > ref);
    }

    /**
     */
    Percent& operator = (const int64_t & hundredths)
    {
        _hundredths = hundredths;
        return *this;
    }

    /**
     */
    Percent& operator += (const int64_t & hundredths)
    {
        _hundredths += hundredths;
        return *this;
    }

    /**
     */
    Percent& operator -= (const int64_t & hundredths)
    {
        _hundredths -= hundredths;
        return *this;
    }

    /**
     */
    Percent operator + (const int64_t & hundredths) const
    {
        return _hundredths + hundredths;
    }

    /**
     */
    Percent operator - (const int64_t & hundredths) const
    {
        return _hundredths - hundredths;
    }

    /**
     */
    bool operator == (const int64_t & hundredths) const
    {
        return _hundredths == hundredths;
    }

    /**
     */
    bool operator != (const int64_t & hundredths) const
    {
        return _hundredths != hundredths;
    }

    /**
     */
    bool operator > (const int64_t & hundredths) const
    {
        return _hundredths > hundredths;
    }

    /**
     */
    bool operator >= (const int64_t & hundredths) const
    {
        return _hundredths >= hundredths;
    }

    /**
     */
    bool operator < (const int64_t & hundredths) const
    {
        return _hundredths < hundredths;
    }

    /**
     */
    bool operator <= (const int64_t & hundredths) const
    {
        return _hundredths <= hundredths;
    }

    /**
     */
    Percent& operator = (const int & percents)
    {
        _hundredths = (int64_t) percents * 1000;
        return *this;
    }

    /**
     */
    Percent& operator += (const int & percents)
    {
        _hundredths += (int64_t) percents * 1000;
        return *this;
    }

    /**
     */
    Percent& operator -= (const int & percents)
    {
        _hundredths -= (int64_t) percents * 1000;
        return *this;
    }

    /**
     */
    Percent operator + (const int & percents) const
    {
        return _hundredths + (int64_t) percents * 1000;
    }

    /**
     */
    Percent operator - (const int & percents) const
    {
        return _hundredths - (int64_t) percents * 1000;
    }

    /**
     */
    bool operator == (const int & percents) const
    {
        return _hundredths == (int64_t) percents * 1000;
    }

    /**
     */
    bool operator != (const int & percents) const
    {
        return _hundredths != (int64_t) percents * 1000;
    }

    /**
     */
    bool operator > (const int & percents) const
    {
        return _hundredths > (int64_t) percents * 1000;
    }

    /**
     */
    bool operator >= (const int & percents) const
    {
        return _hundredths >= (int64_t) percents * 1000;
    }

    /**
     */
    bool operator < (const int & percents) const
    {
        return _hundredths < (int64_t) percents * 1000;
    }

    /**
     */
    bool operator <= (const int & percents) const
    {
        return _hundredths <= (int64_t) percents * 1000;
    }

    /**
     */
    Percent operator ! () const
    {
        return !_hundredths;
    }

    /**
     */
    bool operator || (const Percent & ref) const
    {
        return _hundredths || (int64_t) ref;
    }

    /**
     */
    bool operator && (const Percent & ref) const
    {
        return _hundredths && (int64_t) ref;
    }

    /**
     */
    friend inline int& operator += (int & percents, const Percent & ref)
    {
        return percents += (int) ref;
    }

    /**
     */
    friend inline int& operator -= (int & percents, const Percent & ref)
    {
        return percents -= (int) ref;
    }

    /**
     */
    friend inline Percent operator + (const int & percents,
                                      const Percent & ref)
    {
        return (int64_t) percents * 1000 + (int64_t) ref;
    }

    /**
     */
    friend inline Percent operator - (const int & percents,
                                      const Percent & ref)
    {
        return (int64_t) percents * 1000 - (int64_t) ref;
    }

    /**
     */
    friend inline int64_t& operator += (int64_t & hundredths,
                                        const Percent & ref)
    {
        return hundredths += (int64_t) ref;
    }

    /**
     */
    friend inline int64_t& operator -= (int64_t & hundredths,
                                        const Percent & ref)
    {
        return hundredths -= (int64_t) ref;
    }

    /**
     */
    friend inline Percent operator + (const int64_t & hundredths,
                                      const Percent & ref)
    {
        return hundredths + (int64_t) ref;
    }

    /**
     */
    friend inline Percent operator - (const int64_t & hundredths,
                                      const Percent & ref)
    {
        return hundredths - (int64_t) ref;
    }

    /**
     */
    friend inline bool operator == (const int & percents, const Percent & ref)
    {
        return (int64_t) percents * 1000 == (int64_t) ref;
    }

    /**
     */
    friend inline bool operator != (const int & percents, const Percent & ref)
    {
        return (int64_t) percents * 1000 != (int64_t) ref;
    }

    /**
     */
    friend inline bool operator > (const int & percents, const Percent & ref)
    {
        return (int64_t) percents * 1000 > (int64_t) ref;
    }

    /**
     */
    friend inline bool operator >= (const int & percents, const Percent & ref)
    {
        return (int64_t) percents * 1000 >= (int64_t) ref;
    }

    /**
     */
    friend inline bool operator < (const int & percents, const Percent & ref)
    {
        return (int64_t) percents * 1000 < (int64_t) ref;
    }

    /**
     */
    friend inline bool operator <= (const int & percents, const Percent & ref)
    {
        return (int64_t) percents * 1000 <= (int64_t) ref;
    }

    /**
     */
    friend inline bool operator == (const int64_t & hundredths,
                                    const Percent & ref)
    {
        return hundredths == (int64_t) ref;
    }

    /**
     */
    friend inline bool operator != (const int64_t & hundredths,
                                    const Percent & ref)
    {
        return hundredths != (int64_t) ref;
    }

    /**
     */
    friend inline bool operator > (const int64_t & hundredths,
                                   const Percent & ref)
    {
        return hundredths > (int64_t) ref;
    }

    /**
     */
    friend inline bool operator >= (const int64_t & hundredths,
                                    const Percent & ref)
    {
        return hundredths >= (int64_t) ref;
    }

    /**
     */
    friend inline bool operator < (const int64_t & hundredths,
                                   const Percent & ref)
    {
        return hundredths < (int64_t) ref;
    }

    /**
     */
    friend inline bool operator <= (const int64_t & hundredths,
                                    const Percent & ref)
    {
        return hundredths <= (int64_t) ref;
    }

private:
    /**
     */
    int64_t _hundredths;
};

}//namespace utils

#endif // PERCENT_H
