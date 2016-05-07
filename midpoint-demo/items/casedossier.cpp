#include "casedossier.hpp"

using namespace std;

CaseDossier::CaseDossier()
{
	this->itemID = 8;
	this->objName = "case dossier";
	this->objDescription = "This is the case dossier. It has a profile on all of the important people in the Summerworth Case";
	this->shortDesc = "The case dossier";
	this->keywords = "dossier";
	this->health = 1;
	this->scoreValue = 10;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = false;

}

CaseDossier::~CaseDossier()
{
	cout << this->objName << " removed from the world." << endl;
}