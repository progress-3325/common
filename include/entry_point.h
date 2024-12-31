#pragma once
#include "application.h"

#ifdef CM_PLATFORM_WINDOWS

extern corecommon::application* corecommon::CreateApplication();

int main(int argc, char** argv) {
	corecommon::log::Init();
	CM_CORE_WARN("Initialized Log!");
	CM_INFO("Hello World!");

	auto app = corecommon::CreateApplication();
	app->run();
	delete app;
}

#endif