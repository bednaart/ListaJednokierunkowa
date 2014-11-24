#pragma once
#include <chrono>
#include <thread>
#include "cContactCard.h"

using namespace std;

class cAddressBook
{
public:
	cAddressBook();
	~cAddressBook();
	int mcAddContact();
	int mcRemoveContact();
	void mcSearchForContact();
	int mcShowMenu();
	void mcDisplayAllContacts();
	void mcSwapTwoCards(cContactCard* pcPointerToCurrentCard, cContactCard* pcPointerToNextCard);
	void mcSortEntriesInDatabase();
	int mcGetNumerOfEntries();

private:

	cContactCard* pcFirstElement = NULL;
	int iNumberOfEntries = 0;

};

