#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

public:
	static void ShowUpdateCurrencyRateScreen()
	{
        _DrawScreenHeader("\t  Update Currency Screen");

        cout << "\nEnter Currency Code: ";
        string Code = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCode(Code);

        if (!Currency.IsEmpty())
        {
            _PrintCurrency(Currency);
            char Answer = 'n';
            cout << "\n\nAre you sure you want to update the rate of this Currency y/n? ";
            cin >> Answer;

            if (tolower(Answer) == 'y')
            {
                cout << "\n\nUpdate Currency Rate: ";
                cout << "\n________________________";

                cout << "\n\nEnter New Rate: ";
                double Rate = clsInputValidate::ReadDblNumber();

                Currency.clsCurrency::UpdateRate(Rate);

                cout << "\nCurrency Updated Successfully!\n";
                _PrintCurrency(Currency);
            }
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }

	}
};

