/**
 * MachinesGroup.cpp
 *
 * $id$
 *
 * Description: Implementation of MachinesGroup class
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#include "MachinesGroup.h"
#include "Utils/CommonException.h"

#ifdef EGT_DEBUG
#include <iostream>
#endif // EGT_DEBUG

MachinesGroup::MachinesGroup(const unsigned int id,
                             const unsigned int sessionId,
                             const unsigned short machinesLimit,
                             const std::string name):
    _groupId(id),
    _sessionId(sessionId),
    _machinesNumberLimit(machinesLimit),
    _name(name)
{
}

MachinesGroup::MachinesGroup(const MachinesGroup & machinesGroup)
{
    *this = machinesGroup;
}

MachinesGroup::~MachinesGroup()
{
}

MachinesGroup & MachinesGroup::operator = (const MachinesGroup & machinesGroup)
{
    _groupId = machinesGroup.getId();
    _sessionId = machinesGroup.getSessionId();
    _machinesNumberLimit = machinesGroup.getMachinesNumberLimit();
    _name = machinesGroup.getName();
    _machinesList = machinesGroup.getMachinesList();

    return *this;
}

void MachinesGroup::resetMachines()
{
    _machinesList.clear();
}

void MachinesGroup::addMachine(const uint64_t serialNumber)
{
    if ( _machinesNumberLimit <= _machinesList.size() )
    {
        // error! the machine group is full
        throw utils::CommonException("Attempt to add machine in a full group.", 0);
    }

    std::set<uint64_t>::iterator machineIt = _machinesList.begin();
    for ( ;_machinesList.end() != machineIt; ++machineIt )
    {
        if ( serialNumber == *machineIt )
        {
            // error! the machine already exist in the group
            throw utils::CommonException("Machine with the same serial number "
                                  "already exist in the group.", 0);
        }
    }

    // we can add the machine into the group
    _machinesList.insert(serialNumber);
}

bool MachinesGroup::deleteMachine(const uint64_t serialNumber)
{
    std::set<uint64_t>::iterator machineIt = _machinesList.find(serialNumber);

    if ( _machinesList.end() == machineIt )
    {
        // machine with the specified serial number wasn't found in this group
        return false;
    }

    // delete the machine from the group
    _machinesList.erase(machineIt);

    return true;
}


void MachinesGroup::setId(const unsigned int id)
{
    _groupId = id;
}

void MachinesGroup::setSessionId(const unsigned int sessionId)
{
    _sessionId = sessionId;
}

const std::string MachinesGroup::toString() const
{
    std::stringstream ss;

    ss << "Machines Group " << this->_groupId << std::endl;
    ss << "session id " << this->_sessionId << std::endl;
    ss << "machines number limit " << this->_machinesNumberLimit << std::endl;
    ss << "name " << this->_name << std::endl;
    ss << "machines list : ";
    auto itMachines = this->_machinesList.begin();
    for( ; itMachines != this->_machinesList.end(); ++itMachines )
    {
        ss << "  "<< *itMachines;
    }
    ss << std::endl;

    return ss.str();
}
