workspace "Min"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Min"
	location "Min"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mnpch.h"
	pchsource "Min/src/mnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"MN_PLATFORM_WINDOWS",
		"MN_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "MN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Min/vendor/spdlog/include",
		"Min/src/"
	}

	links
	{
		"Min"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"MN_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "MN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MN_DIST"
		optimize "On"	