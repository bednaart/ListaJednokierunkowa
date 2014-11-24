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
	cContactCard* pcCurrentTmpIterator = pcFirstElement;


	if (NULL == pcCurrentTmpIterator)
	{
		pcFirstElement = mcNewContact;
		cout << endl << " New contact added!";
		iNumberOfEntries++;
		return 0;
	}
	else
	{
	
		mcNewContact->mcChangeNextPosition(pcFirstElement);
		pcFirstElement = mcNewContact;

		cout << endl << "New contact added!";
		iNumberOfEntries++;
		return 0;

	}

	cout << endl << "Contact not added!";
	return 1;
}

int cAddressBook::mcAddContact(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile)
{
	cContactCard* mcNewContact = new cContactCard(sNameFromFile, sEmailFromFile, sPhoneFromFile);
	cContactCard* pcCurrentTmpIterator = pcFirstElement;

	if (NULL == pcCurrentTmpIterator)
	{
		pcFirstElement = mcNewContact;
		return 0;
	}
	else
	{
		mcNewContact->mcChangeNextPosition(pcFirstElement);
		pcFirstElement = mcNewContact;;
		return 0;

	}
	return 1;
}

int cAddressBook::mcRemoveContact()
{
	mcDisplayAllContacts();
	string sContactToRemove;
	cContactCard* pcTempPointer = pcFirstElement, *pcTempAddressToDeleteCard = NULL;
	int iIsAnythingFound = 0;

	if (NULL != pcTempPointer)
	{
		cout << "Type contact name to remove: ";
		cin >> sContactToRemove;

		if (pcTempPointer->mcGetName() == sContactToRemove)
		{
			pcFirstElement = pcTempPointer->mcGetNextPosition();
			delete pcTempPointer;
		}
		else
		{
			while (NULL != pcTempPointer->mcGetNextPosition())
			{
				if ((pcTempPointer->mcGetNextPosition())->mcGetName() == sContactToRemove)
				{
					pcTempAddressToDeleteCard = pcTempPointer->mcGetNextPosition();
					pcTempPointer->mcChangeNextPosition(pcTempPointer->mcGetNextPosition()->mcGetNextPosition());
					delete pcTempAddressToDeleteCard;

					cout << endl << "\tContact " << sContactToRemove << " removed!" << endl;
					iIsAnythingFound++;
					break;
				}

				pcTempPointer = pcTempPointer->mcGetNextPosition();
			}

			if (0 == iIsAnythingFound)
			{
				cout << "No matches found! Contact not removed!";
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
	}
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
	cout << "5. Load contacts from file database.xml" << endl;
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
		cout << endl;

		pcFirstElement = pcPointerToNextCard;
		pcPointerToCurrentCard->mcChangeNextPosition(pcPointerToNextCard->mcGetNextPosition());
		pcPointerToNextCard->mcChangeNextPosition(pcPointerToCurrentCard);

		cout << endl;
	}
	else
	{
		cout << endl;

		while (pcTempPointer->mcGetNextPosition() != pcPointerToCurrentCard)
		{
			pcTempPointer = pcTempPointer->mcGetNextPosition();
		}

		pcTempPointer->mcChangeNextPosition(pcPointerToNextCard);
		pcPointerToCurrentCard->mcChangeNextPosition(pcPointerToNextCard->mcGetNextPosition());
		pcPointerToNextCard->mcChangeNextPosition(pcPointerToCurrentCard);

		cout << endl;
	}

}

void cAddressBook::mcSortEntriesInDatabase()
{
	cContactCard* pcFirstLoopIterator, *pcSecondLoopIterator, *pcThirdIterator = NULL, *pcFourthIterator = NULL;
	

	if (NULL != pcFirstElement->mcGetNextPosition())
	{
		for (pcFirstLoopIterator = pcFirstElement; NULL != pcFirstLoopIterator->mcGetNextPosition(); pcFirstLoopIterator = pcFirstLoopIterator->mcGetNextPosition())
		{
			cout << endl;
			for (pcSecondLoopIterator = pcFirstElement; NULL != pcSecondLoopIterator->mcGetNextPosition(); pcSecondLoopIterator = pcSecondLoopIterator->mcGetNextPosition())
			{
				cout << endl;
				if (pcSecondLoopIterator->mcGetName() > (pcSecondLoopIterator->mcGetNextPosition())->mcGetName())
				{		
					cout << endl;
					
					if (pcFirstLoopIterator == pcSecondLoopIterator)
					{
						pcThirdIterator = pcFirstLoopIterator->mcGetNextPosition();
					}
					
					pcFourthIterator = pcSecondLoopIterator->mcGetNextPosition();

					mcSwapTwoCards(pcSecondLoopIterator, pcSecondLoopIterator->mcGetNextPosition());

					if (pcFirstLoopIterator == pcSecondLoopIterator)
					{
						pcFirstLoopIterator = pcThirdIterator;
					}

					pcSecondLoopIterator = pcFourthIterator;

					cout << endl;
					pcSecondLoopIterator->mcGetNextPosition();
					cout << endl;
				}
			}
		}
	}
	
	
}

int cAddressBook::mcGetNumerOfEntries()
{
	return iNumberOfEntries;
}

int cAddressBook::mcLoadDatabaseFromFile()
{
	XMLDocument* xmlDatabase = new XMLDocument;

	if (!xmlDatabase->LoadFile("database.xml"))
	{
		XMLElement* xmlContactsIterator, *xmlContactsDataIterator;
		vector<string>* vNewContactFromFile = new vector<string>;

		xmlContactsIterator = xmlDatabase->FirstChildElement("AddressBook")->FirstChildElement("Contact");

		for (xmlContactsIterator; xmlContactsIterator != NULL; xmlContactsIterator = xmlContactsIterator->NextSiblingElement())
		{
			for (xmlContactsDataIterator = xmlContactsIterator->FirstChildElement(); xmlContactsDataIterator != NULL; xmlContactsDataIterator = xmlContactsDataIterator->NextSiblingElement())
			{
				vNewContactFromFile->push_back(xmlContactsDataIterator->GetText());
			}
			mcAddContact(vNewContactFromFile->at(0), vNewContactFromFile->at(1), vNewContactFromFile->at(2));
			vNewContactFromFile->clear();
		}

		xmlDatabase->Clear();
	}

	
	return 0;
}