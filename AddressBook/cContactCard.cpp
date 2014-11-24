#pragma once
#include "cContactCard.h"


cContactCard::cContactCard()
{
}

cContactCard::cContactCard(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile)
{
	sName = sNameFromFile;
	sEmail = sEmailFromFile;
	sPhone = sPhoneFromFile;
}
cContactCard::~cContactCard()
{
}

string cContactCard::mcGetName()
{
	return sName;
}

string cContactCard::mcGetEmail()
{
	return sEmail;
}

string cContactCard::mcGetPhone()
{
	return sPhone;
}

cContactCard* cContactCard::mcGetNextPosition()
{
	return pcNextPosition;
}

void cContactCard::mcChangeNextPosition(cContactCard* pcNewNextPosition)
{
	pcNextPosition = pcNewNextPosition;
}
void cContactCard::mcGetDataFromUser()
{

	cout << "Adding new contact:" << endl;
	cout << "Name: ";
	cin >> sName;
	cout << "Email: ";
	cin >> sEmail;
	cout << "Phone: ";
	cin >> sPhone;

}