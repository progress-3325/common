#include "application.h"
#include <iostream>

namespace corecommon{

	application::application() {
		std::cout << "\nApplication is starting\n";
	}

	application::~application() {
		std::cout << "\nProcess ended\n";
	}

	void application::run() {
		while (true);
	}


}