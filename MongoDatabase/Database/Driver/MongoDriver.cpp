/*
 * MongoDriver.cpp
 *
 *  Created on: May 12, 2014
 *      Author: root
 */

#include "MongoDriver.h"

namespace database
{

MongoDriver::MongoDriver()
{
	this->connected = false;
}

MongoDriver::~MongoDriver()
{

}

void MongoDriver::connect(const std::string hostName)
{
	try
	{
		this->connection.connect(hostName);
		this->connected = true;
	}
	catch(mongo::DBException &e)
	{
		throw utils::CommonException("Unable to connect to database.");
	}
}

bool MongoDriver::isConnected() const
{
	return this->connected;
}

mongo::DBClientConnection& MongoDriver::getConnection()
{
	return this->connection;
}

}


