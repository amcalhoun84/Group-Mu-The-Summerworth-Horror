#include "../object.hpp"
#include "../object.cpp"
#include "legaldocs.hpp"

using namespace std;

LegalDocs::LegalDocs()
{
	this->itemID = 14;
	this->objName = "legal documentation";
	this->objDescription = "A series of legal docs with a will and papers lining up for the firing of the Valet";
	this->shortDesc = "legal documents";
	this->keywords = "documents";
	this->health = 1;
	this->scoreValue = 30;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

LegalDocs::~LegalDocs()
{
	cout << this->objName << " removed from the world." << endl;
}