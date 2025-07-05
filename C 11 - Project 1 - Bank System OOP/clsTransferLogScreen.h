#pragma once

#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{
private:

	static void _PrintTransferLogRecord(clsBankClient::stTransferLog TransferLog)
	{
        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLog.DateTime;
        cout << "| " << setw(10) << left << TransferLog.ClientFromAccountNumber;
        cout << "| " << setw(10) << left << TransferLog.ClientToAccountNumber;
        cout << "| " << setw(10) << left << TransferLog.Amount;
        cout << "| " << setw(12) << left << TransferLog.ClientFromBalance;
        cout << "| " << setw(12) << left << TransferLog.ClientToBalance;
        cout << "| " << setw(10) << left << TransferLog.UserName;
	}

public:
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLog> vTransferLogs = clsBankClient::GetTransferLogData();

		string Title = "\t  Transfer Log Screen";
		string Subject = "\t(" + to_string(vTransferLogs.size()) +  ") Transfer Log(s)";

		_DrawScreenHeader(Title, Subject);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << setw(10) << left << "Amount";
        cout << "| " << setw(12) << left << "s.Balance";
        cout << "| " << setw(12) << left << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vTransferLogs.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLog TransferLog : vTransferLogs)
            {
                _PrintTransferLogRecord(TransferLog);
                cout << "\n";
            }
            
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

	}

};

