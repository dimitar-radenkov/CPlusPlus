/*
 * ITextMessagesQueryable.h
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#ifndef ITEXTMESSAGESQUERYABLE_H_
#define ITEXTMESSAGESQUERYABLE_H_

#include <cstdint>
#include <memory>
#include <vector>

#include "Settings/Displays/StatusLineText.h"

namespace database
{
/*
 * this class will allow 'CRUD' operation over text messages collection
 */
class ITextMessagesQueryable
{
public:

    ITextMessagesQueryable()
    {

    }

    virtual ~ITextMessagesQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add(const std::shared_ptr<StatusLineText> text) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<StatusLineText> get(
            const uint16_t uniqueId) const = 0;

    virtual std::shared_ptr<StatusLineText> get(
            const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void update(
            const uint16_t uniqueId,
            const std::shared_ptr<StatusLineText> updatedTextMessage) const = 0;

    virtual void update(
            const std::string& objectId,
            const std::shared_ptr<StatusLineText> updatedTextMessage) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint16_t uniqueId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all status line texts
     */
    virtual std::vector<std::shared_ptr<StatusLineText>> getAll() const = 0;

    /*
     Remove all status line texts
     */
    virtual void removeAll() const = 0;
};

} /*namespace database*/

#endif /* ITEXTMESSAGESQUERYABLE_H_ */
