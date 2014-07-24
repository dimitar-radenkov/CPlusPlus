#ifndef IMACHINES_GROUPS_QUERYABLE_H_
#define IMACHINES_GROUPS_QUERYABLE_H_

#include <cstdint>
#include "Settings/Machines/MachinesGroup.h"

namespace database
{

/*
 * this class will allow 'CRUD' operation over machines groups collection
 */
class IMachinesGroupsQueryable
{
public:

	IMachinesGroupsQueryable()
	{

	}

	virtual ~IMachinesGroupsQueryable()
	{

	}

	/**
	 * create operation
	 */
	virtual void add(
	        const std::shared_ptr<MachinesGroup> machinesGroup) const = 0;

	/*
	 * retrieve operations
	 */
	virtual std::shared_ptr<MachinesGroup> get(const uint32_t id) const = 0;
	virtual std::shared_ptr<MachinesGroup> get(const std::string& objectId) const = 0;

	/*
	 * update operations
	 */
	virtual void update(
	        const uint32_t id,
	        const std::shared_ptr<MachinesGroup> machinesGroup) const = 0;

	virtual void update(
	        const std::string& objectId,
	        const std::shared_ptr<MachinesGroup> machinesGroup) const = 0;

	/*
	 * delete operations
	 */
	virtual void remove(const uint32_t id) const = 0;
	virtual void remove(const std::string& objectId) const = 0;

	/*
     Get all machines
     */
    virtual std::vector<std::shared_ptr<MachinesGroup>> getAll() const = 0;

    /*
     Remove all machines
     */
    virtual void removeAll() const = 0;
};

}

#endif /* IMACHINES_GROUPS_QUERYABLE_H_ */
