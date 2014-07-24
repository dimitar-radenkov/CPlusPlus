/*
 * MongoDriver.h
 *
 *  Created on: May 12, 2014
 *      Author: root
 */

#ifndef MONGODRIVER_H_
#define MONGODRIVER_H_

#include <string>
#include "Utils/CommonException.h"
#include "mongo/client/dbclient.h"

namespace database
{

class MongoDriver
{
private:
	mongo::DBClientConnection connection;

	bool connected;

public:

	virtual ~MongoDriver();

	/*
	 Returns class instance.Singleton class
	 @return Mongo class instance;
	 */
	static MongoDriver& getInstance()
	{
		static MongoDriver instance;

		return instance;
	}

	/**
	 Connect to a Mongo database server. Throws CommonException if fails.
	 @param hostName host to connect to.
	 */
	void connect(const std::string hostName);

	/*
	 Get Driver connection state
	 */
	bool isConnected() const;

	/*
	 @return Driver connection object
	 */
	mongo::DBClientConnection& getConnection();

private:
	/*
	 Default Constructor is forbiden.It's a Singleton class
	 */
	MongoDriver();

	/*
	 Copy Constructor is forbiden.It's a Singleton class
	 */
	MongoDriver(MongoDriver const&);

	/*
	 Assigment operator is forbiden.It's a Singleton class
	 */
	void operator=(MongoDriver const&);
};

}

#endif /* MONGODRIVER_H_ */

