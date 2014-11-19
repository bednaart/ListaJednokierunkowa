#pragma once
#include <iostream>
#include <string>

using namespace std;

class cContactCard
{
public:

	cContactCard();
	~cContactCard();
	string cContactCard::mcGetName();
	string cContactCard::mcGetEmail();
	string cContactCard::mcGetPhone();
	cContactCard* mcGetNextPosition();
	void mcChangeNextPosition(cContactCard* pcNewNextPosition);
	void cContactCard::mcGetDataFromUser();

private:

	string sName;
	string sEmail;
	string sPhone;

	cContactCard* pcNextPosition = NULL;

};

