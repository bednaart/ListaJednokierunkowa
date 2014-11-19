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
	cContactCard* pcPreviousTmpIterator = NULL;
	cContactCard* pcCurrentTmpIterator = NULL;

	pcCurrentTmpIterator = pcFirstElement;


	if (NULL == pcCurrentTmpIterator)
	{
		pcFirstElement = mcNewContact;
		cout << endl << "New contact added!";
		return 0;
	}
	else
	{
		for (pcPreviousTmpIterator, pcCurrentTmpIterator; pcCurrentTmpIterator != NULL; pcCurrentTmpIterator = pcPreviousTmpIterator->mcGetNextPosition())
		{
			if (NULL == pcFirstTmpIterator)
			{
				pcFirstTmpIterator->mcChangeNextPosition(mcNewContact);

				cout << endl << "New contact added!";
				return 0;
			}
		}
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

	cout << "Address Book Menu:" << endl;
	cout << "1. Add new contact" << endl;
	cout << "2. Search for contact" << endl;
	cout << "3. Display all contacts" << endl;
	cout << "4. Remove contact" << endl;
	cout << "0. Exit" << endl << endl;

	cout << "Choosen option: ";
	cin >> sChoosenOption;
	//cout << string(100, '\n');

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

int cAddressBook::mcGetDataAndFillForm(cContactCard* mcNewContact)
{
	mcNewContact->mcGetDataFromUser();
	cContactCard* pcFirstTmpIterator = NULL;
	cContactCard* pcSecondTmpIterator = NULL;

	pcFirstTmpIterator = pcFirstElement;

	if (NULL == pcFirstTmpIterator)
	{
		pcFirstTmpIterator->mcChangeNextPosition(mcNewContact);
		cout << endl << "New contact added!";
		return 0;
	}
	else
	{
		for (pcFirstTmpIterator; pcFirstTmpIterator != NULL; pcFirstTmpIterator = pcFirstElement->mcGetNextPosition())
		{
			if (NULL == pcFirstTmpIterator)
			{
				pcFirstTmpIterator->mcChangeNextPosition(mcNewContact);

				cout << endl << "New contact added!";
				return 0;
			}
		}
	}

	cout << endl << "Contact not added!";
	return 1;
}
void cAddressBook::mcDisplayAllContacts()
{
	cContactCard* pcTempPointer = pcFirstElement;
	int iNumberOfContact = 1;

	for (pcTempPointer, iNumberOfContact; pcTempPointer != NULL; pcTempPointer = pcTempPointer->mcGetNextPosition(), iNumberOfContact++)
	{
		cout << endl << iNumberOfContact << ".";
		cout << endl << "Name: " << pcTempPointer->mcGetName();
		cout << endl << "Email: " << pcTempPointer->mcGetEmail();
		cout << endl << "Phone: " << pcTempPointer->mcGetPhone();
		cout << endl;
	}

}