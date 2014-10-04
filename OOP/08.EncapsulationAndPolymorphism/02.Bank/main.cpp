#include <iostream>
#include <vector>
#include <algorithm>

#include "Models\Accounts\DepositAccount.h"
#include "Models\Accounts\LoanAccount.h"
#include "Models\Accounts\MortgageAccount.h"
#include "Models\Customers\CompanyCustomer.h"
#include "Models\Customers\IndividualCustomer.h"

int main()
{
	std::shared_ptr<Customer> megalan(new CompanyCustomer("Megalan"));
	std::shared_ptr<Customer> mitko(new IndividualCustomer("Dimitar Radenkov"));

	std::shared_ptr<Account> depositAccount(
		new DepositAccount(mitko, 15000, 2.5));

	std::shared_ptr<Account> loanAccount(
		new LoanAccount(mitko, 15000, 5));

	std::shared_ptr<Account> mortgageAccount(
		new MortgageAccount(mitko, 15000, 8));

	std::vector<std::shared_ptr<Account>> accounts = 
		{ loanAccount, mortgageAccount };

	std::for_each(accounts.begin(), accounts.end(),
		[](std::shared_ptr<Account> account)
	{ 
		std::cout << "Interest rate " << account->calculateInterestRate(6) << std::endl;
	});


	system("pause");
	return 0;
}