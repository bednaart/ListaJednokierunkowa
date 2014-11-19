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
	int mcShowAllContacts();
	void mcSearchForContact();
	int mcShowMenu();
	void mcDisplayAllContacts();

private:

	cContactCard* pcFirstElement = NULL;


};

