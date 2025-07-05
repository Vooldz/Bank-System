#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"

class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber(string Message = "Please Enter Account Number: ")
	{
		string AccountNumber;
		cout << Message;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nInvalid Account Number";
			cout << "\n" << Message;
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;

	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAccount Number   : " << Client.AccountNumber();
		cout << "\nAccount Balance   : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static double _ReadTransferAmount(double Balance)
	{
		double Amount = 0;
		cout << "Enter Transfer Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > Balance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another amount? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}


public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient ClientFrom = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer From: "));

		_PrintClient(ClientFrom);

		cout << endl;

		clsBankClient ClientTo = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer To: "));

		_PrintClient(ClientTo);

		cout << "\n";

		double Amount = _ReadTransferAmount(ClientFrom.AccountBalance);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (ClientFrom.Transfer(Amount, ClientTo))
			{
				cout << "\nTransfer Done Successfully!\n";
			}

			else
			{
				cout << "\nTransfer Failed!\n";
			}

			_PrintClient(ClientFrom);

			_PrintClient(ClientTo);

		}

	}
};

