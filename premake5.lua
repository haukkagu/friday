workspace "friday"
	architecture "x86_64"
	configurations { "Debug", "Release" }
	platforms { "Windows", "Linux" }
	
	filter { "platforms:Windows" }
		system "Windows"
		defines { "FRIDAY_WINDOWS" }
	filter { "platforms:Linux" }
		system "Linux"
		defines { "FRIDAY_LINUX" }
	filter {}

	location "build"

project "friday"
	kind "ConsoleApp"
	language "C++"
	
	staticruntime "on"
	
	files {"src/**.h", "src/**.cpp"}
	
	includedirs { "src" }
	
	filter { "configurations:Debug" }
		defines { "FRIDAY_DEBUG" }
		runtime "Debug"
		symbols "on"

	filter { "configurations:Release" }
		defines { "FRIDAY_RELEASE" }
		runtime "Release"
		optimize "on"
	filter {}