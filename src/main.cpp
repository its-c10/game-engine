#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "tengine.hpp"
#include "constants.h"

// TODO: Change smart pointers to unique pointers. 
int main(int argc, char *args[]){

	Tengine tengine = Tengine();
	while (tengine.isRunning()) {
		tengine.getFPSTracker().handleFrames();
		tengine.processInput();
		tengine.update();
		tengine.render();
	}

	tengine.shutdown();

	return 0;
}