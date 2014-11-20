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


int cAddressBook::mcShowMenu()
{
	int iChoosenOption;
	string sChoosenOption;
	//system("CLS");
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
		this_thread::sleep_for(chrono::seconds(1));
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
		system("PAUSE");
	}

}

void cAddressBook::mcSearchForContact()
{
	string sTextToFind;
	cContactCard* pcTempPointer = pcFirstElement;
	int iNumberOfContact = 1;

	cout << endl << "Type part of name, email or phone to find." << endl << "Find: ";
	cin >> sTextToFind;

	if (NULL == pcTempPointer)
	{
		cout << endl << "Database is empty!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	else
	{
		while (NULL != pcTempPointer)
		{
			if ((string::npos != (pcTempPointer->mcGetName()).find(sTextToFind)) || (string::npos != (pcTempPointer->mcGetEmail()).find(sTextToFind)) || (string::npos != (pcTempPointer->mcGetPhone()).find(sTextToFind)) )
			{	
				cout << endl << "\t" << iNumberOfContact << ".";
				cout << endl << "\tName: " << pcTempPointer->mcGetName();
				cout << endl << "\tEmail: " << pcTempPointer->mcGetEmail();
				cout << endl << "\tPhone: " << pcTempPointer->mcGetPhone();
				cout << endl;
			}

			iNumberOfContact++;
			pcTempPointer = pcTempPointer->mcGetNextPosition();
		}

		if (2 == iNumberOfContact)
		{
			cout << "No matches found!";
		}

		cout << endl;
		system("PAUSE");
	}



}

void cAddressBook::mcSwapTwoCards(cContactCard& pcPointerToCurrentCard, cContactCard& pcPointerToNextCard)
{
	cout << "pcPointerToCurrentCard: " << &pcPointerToCurrentCard << endl << "pcPointerToNextCard: " << &pcPointerToNextCard << endl;
	//cContactCard pcFirstTempPointer = pcPointerToCurrentCard, pcSecondTempPointer = &pcPointerToNextCard;
	system("PASUE");
	pcPointerToCurrentCard.mcChangeNextPosition(pcPointerToNextCard.mcGetNextPosition());

	pcPointerToNextCard.mcChangeNextPosition(&pcPointerToCurrentCard);

	pcPointerToCurrentCard = pcPointerToNextCard;

}

void cAddressBook::mcSortEntriesInDatabase()
{

	if (NULL != pcFirstElement->mcGetNextPosition())
	{
		cContactCard* pcTempPointerToPreviousCard = pcFirstElement, *pcTempPointerToCurrentCard = pcFirstElement->mcGetNextPosition();
		cContactCard* pcIterator = pcFirstElement;
		int iNumberOfChangesMade = 0;

		for (pcIterator; NULL != pcIterator; pcIterator = pcIterator->mcGetNextPosition())
		{
			cout << "1." << endl;
			pcTempPointerToCurrentCard = pcFirstElement;
			pcTempPointerToNextCard = pcFirstElement->mcGetNextPosition();

			while (NULL != pcTempPointerToNextCard)
			{
				if (pcTempPointerToCurrentCard->mcGetName() > pcTempPointerToNextCard->mcGetName())
				{
					mcSwapTwoCards(*pcTempPointerToCurrentCard, *pcTempPointerToNextCard);
					cout << "2." << endl;
					//iNumberOfChangesMade++;

				}

				cout << "3." << endl;
				pcTempPointerToCurrentCard = pcTempPointerToCurrentCard->mcGetNextPosition();
				pcTempPointerToNextCard = pcTempPointerToNextCard->mcGetNextPosition();

			}

		}
		/*
		while (NULL != pcTempPointerToNextCard->mcGetNextPosition())
		{
			do
			{
				pcTempPointerToCurrentCard = pcFirstElement;
				pcTempPointerToNextCard = pcTempPointerToCurrentCard->mcGetNextPosition();
				iNumberOfChangesMade = 0;

				while (NULL != pcTempPointerToNextCard->mcGetNextPosition())
				{
					cout << "1." << endl;
					if (pcTempPointerToCurrentCard->mcGetName() > pcTempPointerToNextCard->mcGetName())
					{
						cout << "2." << endl;
						//mcSwapTwoCards(*pcTempPointerToCurrentCard, *pcTempPointerToNextCard);
						iNumberOfChangesMade++;

						//pcTempPointerToNextCard = pcTempPointerToCurrentCard->mcGetNextPosition();
					}

					cout << "3." << endl;
					cout << "pcTempPointerToCurrentCard: " << (&pcTempPointerToCurrentCard) << endl;
					cout << "pcTempPointerToNextCard: " << (&pcTempPointerToNextCard) << endl;
					pcTempPointerToCurrentCard = pcTempPointerToCurrentCard->mcGetNextPosition();
					pcTempPointerToNextCard = pcTempPointerToNextCard->mcGetNextPosition();


				}
			} while (0 < iNumberOfChangesMade);
		}*/
	
	
	}
}