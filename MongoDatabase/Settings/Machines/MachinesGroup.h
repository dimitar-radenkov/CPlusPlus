/**
 * MachinesGroup.h
 *
 * $id$
 *
 * Description: Base class definition of a machines group. Represents the
 *              list of machines that will be assigned to one or more
 *              progressive groups.
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef MACHINES_GROUP_H
#define MACHINES_GROUP_H


#include <memory>
#include <map>
#include <set>
#include <string>
#include <sstream>

/**
 */
class MachinesGroup
{
    /**
     * The default constructor is forbidden.
     */
    MachinesGroup():
        _groupId(0),
        _sessionId(0),
        _machinesNumberLimit(0)
    {}

public:
    /**
     */
    MachinesGroup(const unsigned int id,
                  const unsigned int sessionId,
                  const unsigned short machinesLimit,
                  const std::string name = "Unknown");

    /**
     */
    MachinesGroup(const MachinesGroup & machinesGroup);

    /**
     */
    ~MachinesGroup();

    /**
     */
    MachinesGroup & operator = (const MachinesGroup & machinesGroup);

    /**
     */
    bool operator== (const MachinesGroup & machinesGroup)
    {
        return (_groupId == machinesGroup.getId()) &&
               (_sessionId == machinesGroup.getSessionId()) &&
               (_machinesNumberLimit ==
                machinesGroup.getMachinesNumberLimit()) &&
               (0 == _name.compare(machinesGroup.getName())) &&
               (_machinesList == machinesGroup.getMachinesList());
    }

    /**
     */
    void resetMachines();

    /**
     */
    void addMachine(const uint64_t serialNumber);

    /**
     */
    bool deleteMachine(const uint64_t serialNumber);

#ifdef EGT_DEBUG
    /**
     */
    void dumpValues();
#endif // EGT_DEBUG

public:

    /**
     */
    const unsigned short getMachinesNumberLimit() const
    {
        return _machinesNumberLimit;
    }

    /**
     */
    void setId(const unsigned int id);

    /**
     */
    const unsigned int getId() const
    {
        return _groupId;
    }

    /**
     */
    void setSessionId(const unsigned int sessionId);

    /**
     */
    const unsigned int getSessionId() const
    {
        return _sessionId;
    }

    /**
     */
    void setName(const std::string name)
    {
        _name = name;
    }

    /**
     */
    const std::string & getName() const
    {
        return _name;
    }

    /**
     */
    const std::set<uint64_t> & getMachinesList() const
    {
        return _machinesList;
    }

    const std::string toString() const;


protected:
    /**
     */
    unsigned int _groupId;

    /**
     */
    unsigned int _sessionId;

    /**
     */
    unsigned short _machinesNumberLimit;

    /**
     */
    std::string _name;

    /**
     */
    std::set<uint64_t> _machinesList;
};

/**
 */
typedef std::map < unsigned int, std::shared_ptr<MachinesGroup> >
        MachinesGroupsList;

#endif // MACHINES_GROUP_H
