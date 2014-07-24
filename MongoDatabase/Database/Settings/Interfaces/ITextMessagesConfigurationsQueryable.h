/*
 * ITextMessagesConfigurationsQueryable.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef ITEXTMESSAGESCONFIGURATIONSQUERYABLE_H_
#define ITEXTMESSAGESCONFIGURATIONSQUERYABLE_H_

#include <cstdint>
#include <memory>
#include <vector>

#include "Settings/Displays/StatusLineTextsConfiguration.h"

namespace database
{
/*
 * this class will allow 'CRUD' operation over text messages configurations
 * collection
 */
class ITextMessagesConfigurationsQueryable
{
public:

    ITextMessagesConfigurationsQueryable()
    {

    }

    virtual ~ITextMessagesConfigurationsQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add(const std::shared_ptr<StatusLineTextsConfiguration> configuration) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<StatusLineTextsConfiguration>
    get(const uint16_t uniqueId) const = 0;

    virtual std::shared_ptr<StatusLineTextsConfiguration>
    get(const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void
    update(const uint16_t uniqueId,
           const std::shared_ptr<StatusLineTextsConfiguration> updatedConfiguration) const = 0;

    virtual void
    update(const std::string& objectId,
           const std::shared_ptr<StatusLineTextsConfiguration> updatedConfiguration) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint16_t uniqueId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all status line texts configurations
     */
    virtual std::vector<std::shared_ptr<StatusLineTextsConfiguration>>
    getAll() const = 0;

    /*
     Remove all status line texts configurations
     */
    virtual void removeAll() const = 0;
};

} /*namespace database*/


#endif /* ITEXTMESSAGESCONFIGURATIONSQUERYABLE_H_ */
