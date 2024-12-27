#pragma once
#include "application.h"

#ifdef CM_PLATFORM_WINDOWS

extern corecommon::application* corecommon::CreateApplication();

int main(int argc, char** argv) {
	auto app = corecommon::CreateApplication();
	app->run();
	delete app;
}

#endif