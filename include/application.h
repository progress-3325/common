#pragma once

#include "core.h"

namespace corecommon{

	class COMMON_API application
	{
	public:
		application();
		virtual ~application();
		void run();

	};

	application* CreateApplication();

}