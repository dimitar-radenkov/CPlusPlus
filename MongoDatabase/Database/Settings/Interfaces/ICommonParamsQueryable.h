/*
 * ICommonParamsQueryable.h
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#ifndef ICOMMONPARAMSQUERYABLE_H_
#define ICOMMONPARAMSQUERYABLE_H_

#include <memory>
#include "Settings/Common/CommonParams.h"

class ICommonParamsQueryable
{
public:

    ICommonParamsQueryable()
    {}

    virtual ~ICommonParamsQueryable()
    {}

    virtual void
    add(const std::shared_ptr<CommonParams> commonParams) const = 0;

    virtual void remove() const = 0;

    virtual std::shared_ptr<CommonParams> get() const = 0;
};


#endif /* ICOMMONPARAMSQUERYABLE_H_ */
