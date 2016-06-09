#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>

// #include "worldEngine.hpp"

class Graphics
{

private:
	// no need, we just transmit images.

public:
	Graphics();
	~Graphics();

	void splashScreen();
	void introScreen();
	void murderScene();
	void deathScreen();
	void insanityScreen();
	void oneWhoSleeps();
	void noncursialBook();
	void noncursialAmulet();
	void wallText();
	void wallTextdeCipher();
	void victoryScreen();
	void creditsScreen();


};

#endif	// graphics_h
