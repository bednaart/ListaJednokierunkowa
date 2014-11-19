#pragma once
#include "cContactCard.h"

using namespace std;

class cAddressBook
{
public:
	cAddressBook();
	~cAddressBook();
	int mcAddContact();
	int mcGetDataAndFillForm(cContactCard* mcNewContact);
	int mcRemoveContact();
	int mcShowAllContacts();
	int mcSearchForContact();
	int mcShowMenu();
	void mcDisplayAllContacts();

private:

	cContactCard* pcFirstElement = NULL;


};

