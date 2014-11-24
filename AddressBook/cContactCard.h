#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cContactCard
{
public:

	cContactCard();
	cContactCard(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile);
	~cContactCard();
	string cContactCard::mcGetName();
	string cContactCard::mcGetEmail();
	string cContactCard::mcGetPhone();
	cContactCard* mcGetNextPosition();
	void mcChangeNextPosition(cContactCard* pcNewNextPosition);
	void mcGetDataFromUser();

private:

	string sName;
	string sEmail;
	string sPhone;

	cContactCard* pcNextPosition = NULL;

};

