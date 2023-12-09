#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "tengine.hpp"
#include "constants.h"

int main(int argc, char *args[]){

	Tengine tengine = Tengine();
	while (tengine.is_running()) {
		tengine.getFPSTracker().handle_frames();
		tengine.process_input();
		tengine.update();
		tengine.render();
	}

	tengine.shutdown();

	return 0;
}