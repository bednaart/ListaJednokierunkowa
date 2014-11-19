#include "main.h"
#include "cAddressBook.h"
using namespace std;

int main()
{
	int iMenuOption = -1;
	cAddressBook* pcAddressBookInstance = new cAddressBook;
	int iReturnValue;

	while (0 != iMenuOption)
	{

		iMenuOption = pcAddressBookInstance->mcShowMenu();

		switch (iMenuOption)
		{
		case 1:
			iReturnValue = pcAddressBookInstance->mcAddContact();

			break;

		case 2:
			iReturnValue = pcAddressBookInstance->mcSearchForContact();

			break;

		case 3:
			iReturnValue = pcAddressBookInstance->mcRemoveContact();

			break;

		case 4:
			pcAddressBookInstance->mcDisplayAllContacts();

			break;

		case 0:
			cout << endl << "Shuting down..." << endl;
			//cout << string(100, '\n');
			break;

		default:
			cout << endl << "Wrong option! Choose correct option" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			//cout << string(100, '\n');
			break;

		}

	}

	delete pcAddressBookInstance;


	return 0;

}