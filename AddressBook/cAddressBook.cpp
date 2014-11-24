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
		iNumberOfEntries++;
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
		iNumberOfEntries++;
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
	int iNumberOfContact = 1, iIsAnythingFound = 0;

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
				iIsAnythingFound++;
			}

			iNumberOfContact++;
			pcTempPointer = pcTempPointer->mcGetNextPosition();
		}

		if (0 == iIsAnythingFound)
		{
			cout << "No matches found!";
		}

		cout << endl;
		system("PAUSE");
	}



}

void cAddressBook::mcSwapTwoCards(cContactCard* pcPointerToCurrentCard, cContactCard* pcPointerToNextCard)
{

	cContactCard* pcTempPointer = pcFirstElement;

	if (pcPointerToCurrentCard == pcFirstElement)
	{
		cout << endl << "pcPointerToCurrentCard: " << pcPointerToCurrentCard << endl << "Next: " << pcPointerToCurrentCard->mcGetNextPosition();
		cout << endl << "pcPointerToNextCard: " << pcPointerToNextCard << endl << "Next: " << pcPointerToNextCard->mcGetNextPosition();
		cout << endl;

		pcFirstElement = pcPointerToNextCard;
		pcPointerToCurrentCard->mcChangeNextPosition(pcPointerToNextCard->mcGetNextPosition());
		pcPointerToNextCard->mcChangeNextPosition(pcPointerToCurrentCard);

		cout << endl << "pcPointerToCurrentCard: " << pcPointerToCurrentCard << endl << "Next: " << pcPointerToCurrentCard->mcGetNextPosition();
		cout << endl << "pcPointerToNextCard: " << pcPointerToNextCard << endl << "Next: " << pcPointerToNextCard->mcGetNextPosition();
		cout << endl;
	}
	else
	{
		cout << endl << "pcPointerToCurrentCard: " << pcPointerToCurrentCard << endl << "Next: " << pcPointerToCurrentCard->mcGetNextPosition();
		cout << endl << "pcPointerToNextCard: " << pcPointerToNextCard << endl << "Next: " << pcPointerToNextCard->mcGetNextPosition();
		cout << endl;

		while (pcTempPointer->mcGetNextPosition() != pcPointerToCurrentCard)
		{
			pcTempPointer = pcTempPointer->mcGetNextPosition();
		}

		pcTempPointer->mcChangeNextPosition(pcPointerToNextCard);
		pcPointerToCurrentCard->mcChangeNextPosition(pcPointerToNextCard->mcGetNextPosition());
		pcPointerToNextCard->mcChangeNextPosition(pcPointerToCurrentCard);

		//mcDisplayAllContacts();

		cout << endl << "pcPointerToCurrentCard: " << pcPointerToCurrentCard << endl << "Next: " << pcPointerToCurrentCard->mcGetNextPosition();
		cout << endl << "pcPointerToNextCard: " << pcPointerToNextCard << endl << "Next: " << pcPointerToNextCard->mcGetNextPosition();
		cout << endl;
	}

}

void cAddressBook::mcSortEntriesInDatabase()
{
	//cContactCard* pcTempPointerToPreviouseCard, *pcTempPointerToCurrentCard, *pcTempPointerToNextCard;
	cContactCard* pcFirstIterator, *pcSecondIterator, *pcThirdIterator, *pcFourthIterator;
	

	//if (NULL != pcFirstElement->mcGetNextPosition())
	{
		for (pcFirstIterator = pcFirstElement; NULL != pcFirstIterator->mcGetNextPosition(); pcFirstIterator = pcFirstIterator->mcGetNextPosition())
		{
			for (pcSecondIterator = pcFirstElement; NULL != pcSecondIterator->mcGetNextPosition(); pcSecondIterator = pcSecondIterator->mcGetNextPosition())
			{
				cout << endl << "pcSecondIterator->mcGetName(): " << pcSecondIterator->mcGetName() << endl;
				cout << endl << "pcSecondIterator->mcGetNextPosition()->mcGetName(): " << pcSecondIterator->mcGetNextPosition()->mcGetName() << endl;
				if (pcSecondIterator->mcGetName() > (pcSecondIterator->mcGetNextPosition())->mcGetName())
				{		
					cout << endl << "pcPointerToCurrentCard: " << (pcSecondIterator) << endl << "Next: " << pcSecondIterator->mcGetNextPosition();
					cout << endl << "pcPointerToNextCard: " << (pcSecondIterator->mcGetNextPosition()) << endl << "Next: " << (pcSecondIterator->mcGetNextPosition())->mcGetNextPosition();
					cout << endl;
					
					pcThirdIterator = pcFirstIterator->mcGetNextPosition();
					pcFourthIterator = pcSecondIterator->mcGetNextPosition();

					mcSwapTwoCards(pcSecondIterator, pcSecondIterator->mcGetNextPosition());

					pcFirstIterator = pcThirdIterator;
					pcSecondIterator = pcFourthIterator;

					mcDisplayAllContacts();
					cout << endl;
					//cout << endl << "pcPointerToCurrentCard: " << pcSecondIterator << endl << "Next: " << pcSecondIterator->mcGetNextPosition();
					//cout << endl << "pcPointerToNextCard: " << (pcSecondIterator->mcGetNextPosition()) << endl << "Next: " << (pcSecondIterator->mcGetNextPosition())->mcGetNextPosition();
					//cout << endl;
				}
			}
		}
	}
	
	
}

int cAddressBook::mcGetNumerOfEntries()
{
	return iNumberOfEntries;
}