#ifndef _GRAPHICS_HPP
#define _GRAPHICS_HPP

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
	void victoryScreen();
	void creditsScreen();

};

#endif
