#include <iostream>
#include <future>
#include <thread>

int trySend100Mails()
{
	int sendMailCount = 0;
	for (size_t i = 0; i < 100; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		bool sendSuccessfull = true;
		if (sendSuccessfull)
		{
			sendMailCount++;
		}
	}

	return sendMailCount;
}

void doSmthElse()
{
	std::cout << "do smth else..." << std::endl;
}

int main()
{
	//will run in thread
	std::future<int> mailsSent = std::async(trySend100Mails);
	
	doSmthElse();

	//this will block execution until result is ready
	std::cout << "sent mails are : " << mailsSent.get() << std::endl;

	doSmthElse();
}