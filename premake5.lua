workspace "common"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	includedirs {
		"include",
		"include/vendor/spdlog/include"
	}

	files {
		"include/application.h",
		"include/CCommon.h",
		"include/core.h",
		"include/entry_point.h",
		"include/log.h",
		"premake5.lua"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
src = "%{prj.name}/src/"

project "common"
	location "Common"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files {
		src .. "**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/included"
	}

	filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"
    buildoptions { "/utf-8" }



	defines {
		"CM_PLATFORM_WINDOWS",
		"CM_BUILD_DLL"
	}
	
	postbuildcommands {
    ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
}

	prebuildcommands {
	  ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox")
	}



	filter "configurations:Debug"
		defines "CM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIST"
		symbols "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files {
		src .. "**.cpp",
		src .. "**.h"
	}

	removefiles {
		"include/application.h",
		"include/CCommon.h",
		"include/core.h",
		"include/entry_point.h",
		"include/log.h",
		"premake5.lua"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/included",
		"Common/src"
	}

	links {
		"common"
	}

	filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"
    buildoptions { "/utf-8" }


	defines {
		"CM_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "CM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIST"
		symbols "On"
