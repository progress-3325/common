workspace "Common Engine"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
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
		src .. "**.cpp",
		src .. "**.h"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/included"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


	defines {
		"CM_PLATFORM_WINDOWS",
		"CM_BUILD_DLL"
	}
	
	postbuildcommands {
		("{COPYFILE} %{cfg.buildtarget.relpath} ../bin" .. outputdir ..	"/Sandbox")
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
