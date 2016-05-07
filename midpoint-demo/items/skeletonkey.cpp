#include "skeletonkey.hpp"

using namespace std;

SkeletonKey::SkeletonKey()
{
	this->itemID = 22;
	this->objName = "A key with a skeleton design";
	this->objDescription = "An otherwise normal looking key with a skeleton design on the body.";
	this->shortDesc = "A skeleton key";
	this->keywords = "key";
	this->health = 1;
	this->scoreValue = 10;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

SkeletonKey::~SkeletonKey()
{
	cout << this->objName << " removed from the world." << endl;
}