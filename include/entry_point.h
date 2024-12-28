#pragma once
#include "application.h"

#ifdef CM_PLATFORM_WINDOWS

extern corecommon::application* corecommon::CreateApplication();

int main(int argc, char** argv) {
	corecommon::log::Init();
	corecommon::log::getCoreLogger()->warn("Initialized Log!");
	corecommon::log::getClientLogger()->info("Hello World!");

	auto app = corecommon::CreateApplication();
	app->run();
	delete app;
}

#endif