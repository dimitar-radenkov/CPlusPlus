#ifndef IMACHINES_QUERYABLE_H_
#define IMACHINES_QUERYABLE_H_

#include <cstdint>
#include "Settings/Machines/Machine.h"

namespace database
{

/*
 * this class will allow 'CRUD' operation over machines collection
 */
class IMachinesQueryable
{
public:

	IMachinesQueryable()
	{

	}

	virtual ~IMachinesQueryable()
	{

	}

	/**
	 * create operation
	 */
	virtual void add(const std::shared_ptr<Machine> machine) const = 0;

	/*
	 * retrieve operations
	 */
	virtual std::shared_ptr<Machine> get(const uint64_t serialNumber) const = 0;
	virtual std::shared_ptr<Machine> get(const std::string& objectId) const = 0;

	/*
	 * update operations
	 */
	virtual void update(
			const uint64_t serialNumber,
			const std::shared_ptr<Machine> updatedMachine) const = 0;

	virtual void update(
			const std::string& objectId,
			const std::shared_ptr<Machine> updatedMachine) const = 0;

	/*
	 * delete operations
	 */
	virtual void remove(const uint64_t serialNumber) const = 0;
	virtual void remove(const std::string& objectId) const = 0;

	/*
	 Get all machines
	 */
	virtual std::vector<std::shared_ptr<Machine>> getAll() const = 0;

	/*
	 Remove all machines
	 */
	virtual void removeAll() const = 0;
};

}

#endif /* IMACHINES_QUERYABLE_H_ */
