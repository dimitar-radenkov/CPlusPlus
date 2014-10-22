#include <iostream>
#include <exception>
#include <functional>
#include <future>

double squareRoot(double number)
{
	if (number < 0)
	{
		throw std::out_of_range("number is less than 0.");
	}

	return std::sqrt(number);
}

void processFuture(std::future<double>& fut)
{
	try 
	{
		double n = fut.get();
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	//will raise exception
	/*std::future<double> fut = std::async(squareRoot, -1);

	try	
	{
		//wait for result
		double sqRoot = fut.get();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}	*/

	std::promise<double> sqRootPromise;

	try
	{
		sqRootPromise.set_value(squareRoot(-1));
	}
	catch (std::exception& ex)
	{
		sqRootPromise.set_exception(std::current_exception());
	}

	auto fut = sqRootPromise.get_future();
	processFuture(fut);
}