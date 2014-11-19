#include "cAddressBook.h"
#include <string>


cAddressBook::cAddressBook()
{
}


cAddressBook::~cAddressBook()
{
}

int cAddressBook::mcAddContact()
{
	cContactCard* mcNewContact = new cContactCard;

	mcNewContact->mcGetDataFromUser();
	cContactCard* pcCurrentTmpIterator = NULL;

	pcCurrentTmpIterator = pcFirstElement;


	if (NULL == pcCurrentTmpIterator)
	{
		pcFirstElement = mcNewContact;
		cout << endl << " New contact added!";
		return 0;
	}
	else
	{
		while (pcCurrentTmpIterator->mcGetNextPosition())
		{
			pcCurrentTmpIterator = pcCurrentTmpIterator->mcGetNextPosition();
		}

		pcCurrentTmpIterator->mcChangeNextPosition(mcNewContact);

		cout << endl << "New contact added!";
		return 0;

	}

	cout << endl << "Contact not added!";
	return 1;
}

int cAddressBook::mcRemoveContact()
{

	return 0;
}

int cAddressBook::mcShowAllContacts()
{

	return 0;
}

int cAddressBook::mcSearchForContact()
{


	return 0;
}

int cAddressBook::mcShowMenu()
{
	int iChoosenOption;
	string sChoosenOption;
	system("CLS");
	cout << "Address Book Menu:" << endl;
	cout << "1. Add new contact" << endl;
	cout << "2. Search for contact" << endl;
	cout << "3. Display all contacts" << endl;
	cout << "4. Remove contact" << endl;
	cout << "0. Exit" << endl << endl;

	cout << "Choosen option: ";
	cin >> sChoosenOption;


	if (1 == sChoosenOption.length() && isdigit(sChoosenOption[0]))
	{
		iChoosenOption = atoi(sChoosenOption.c_str());
	}
	else
	{
		iChoosenOption = -1;
	}

	return iChoosenOption;

}


void cAddressBook::mcDisplayAllContacts()
{
	cContactCard* pcTempPointer = pcFirstElement;
	int iNumberOfContact = 1;

	if (NULL == pcTempPointer)
	{
		cout << endl << "\tDatabase is empty!";
	}
	else
	{
		while (NULL != pcTempPointer)
		{
			cout << endl << "\t" << iNumberOfContact << ".";
			cout << endl << "\tName: " << pcTempPointer->mcGetName();
			cout << endl << "\tEmail: " << pcTempPointer->mcGetEmail();
			cout << endl << "\tPhone: " << pcTempPointer->mcGetPhone();
			cout << endl << endl;

			iNumberOfContact++;
			pcTempPointer = pcTempPointer->mcGetNextPosition();
		}
	}
	system("PAUSE");
}