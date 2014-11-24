#pragma once
#include <chrono>
#include <thread>
#include "cContactCard.h"
#include "tinyxml2-master\tinyxml2.h"
#include <vector>

using namespace std;
using namespace tinyxml2;

class cAddressBook
{
public:
	cAddressBook();
	~cAddressBook();
	int mcAddContact();
	int mcAddContact(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile);
	int mcRemoveContact();
	void mcSearchForContact();
	int mcShowMenu();
	void mcDisplayAllContacts();
	void mcSwapTwoCards(cContactCard* pcPointerToCurrentCard, cContactCard* pcPointerToNextCard);
	void mcSortEntriesInDatabase();
	int mcGetNumerOfEntries();
	int mcLoadDatabaseFromFile();

private:

	cContactCard* pcFirstElement = NULL;
	int iNumberOfEntries = 0;

};

