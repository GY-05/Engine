workspace "Mar"
    architecture   "x64"
    configurations{
        "Debug",
        "Release",
        "Dist"
    }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mar"
    location "Mar"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")
    files
    {
        "%{prj.name}/Src/**.h",
        "%{prj.name}/Src/**.cpp"
    }
    includedirs
    {
       "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

    defines
    {
        "MAR_PLATFORM_WINDOWS",
        "MAR_BUILD_DLL",
        "_WINDLL"
    }
    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
    }

    filter "configurations:Debug"
		defines "MAR_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "MAR_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "MAR_DIST"
		optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")
    files
    {
        "%{prj.name}/Src/**.h",
        "%{prj.name}/Src/**.cpp"
    }
    includedirs
    {
        "Mar/vendor/spdlog/include",
        "Mar/Src"
    }
    links
    {
        "Mar"
    }
    
    filter "system:windows"
        cppdialect  "C++17"
        staticruntime "On"
        systemversion "10.0"
    
    defines
    {
        "MAR_PLATFORM_WINDOWS"
    }
    filter "configurations:Debug"
        defines "MAR_DEBUG"
        symbols "on"
    
    filter "configurations:Release"
        defines "MAR_RELEASE"
        optimize "on"
    
    filter "configurations:Dist"
        defines "MAR_DIST"
         optimize "on"