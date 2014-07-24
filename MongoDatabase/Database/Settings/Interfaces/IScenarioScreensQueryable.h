/*
 * IScreensQueryable.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef ISCENARIOSCREENSQUERYABLE_H_
#define ISCENARIOSCREENSQUERYABLE_H_

#include <cstdint>
#include "Settings/Displays/ScreenDescription.h"

namespace database
{

/*
 * this class will allow 'CRUD' operation over screens collection
 */
class IScenarioScreensQueryable
{
public:

    IScenarioScreensQueryable()
    {

    }

    virtual ~IScenarioScreensQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add(const std::shared_ptr<ScreenDescription> screen) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<ScreenDescription> get(
            const uint16_t screenId) const = 0;

    virtual std::shared_ptr<ScreenDescription> get(
            const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void update(
            const uint16_t screenId,
            const std::shared_ptr<ScreenDescription> updatedScreen) const = 0;

    virtual void update(
            const std::string& objectId,
            const std::shared_ptr<ScreenDescription> updatedScreen) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint16_t screenId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all screens
     */
    virtual std::vector<std::shared_ptr<ScreenDescription>> getAll() const = 0;

    /*
     Remove all screens
     */
    virtual void removeAll() const = 0;
};

}


#endif /* ISCENARIOSCREENSQUERYABLE_H_ */
