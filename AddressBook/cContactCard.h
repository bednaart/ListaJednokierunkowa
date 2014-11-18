#pragma once
#include <iostream>
#include <string>

using namespace std;

class cContactCard
{
public:

	cContactCard();
	~cContactCard();
	int mAddContact();
	int mRemoveContact();
	int mShowAllContacts();
	int mSearchForContact();

private:

	string sName;
	string sEmail;
	string sPhone;

	cContactCard* pcNextPosition;

};

