workspace "GameEngine"
        architecture "x64"
        startproject "SandBox"
        
        configurations {
            "Debug",
            "Release",
            "Dist"
        }


    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
--Include directory related to root folder
    IncludeDir = {}
    IncludeDir["GLFW"] = "GameEngine/vendor/GLFW/include"
    IncludeDir["Glad"]="GameEngine/vendor/Glad/include"
    IncludeDir["ImGui"]="GameEngine/vendor/imgui"
    IncludeDir["glm"]="GameEngine/vendor/glm"


include "GameEngine/vendor/GLFW"
include "GameEngine/vendor/Glad"
include "GameEngine/vendor/imgui"

project "GameEngine"
    location "GameEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "GameEngine/src/hzpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"

    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"

    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL",
            "GLFW_INCLUDE_NONE",

        }


    filter "configurations:Debug"
        defines "GE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GE_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "GE_DIST"
        runtime "Release"
        optimize "On"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "GameEngine/vendor/spdlog/include",
        "GameEngine/src",
        "GameEngine/vendor",
        "%{IncludeDir.glm}"

    }

    links {

        "GameEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "GE_PLATFORM_WINDOWS"
        }
        
    filter "configurations:Debug"
        defines "GE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "GE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "GE_DIST"
        runtime "Release"
        optimize "on"
