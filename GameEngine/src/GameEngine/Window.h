#pragma once

#include "hzpch.h" // Precompiled header
#include "GameEngine/Core.h"
#include "GameEngine/Events/Event.h"

namespace GameEngine {

    // Struct to hold window properties
    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        // Constructor with default values
        WindowProps(const std::string& title = "GameEngine",
            unsigned int width = 1280,
            unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    // Interface for representing a desktop system-based window
    class GAMEENGINE_API Window {
    public:
        // Alias for event callback function
        using EventCallbackFn = std::function<void(Event&)>;

        // Destructor
        virtual ~Window() {}

        // Pure virtual function for updating the window
        virtual void OnUpdate() = 0;

        // Virtual functions for getting width and height of the window
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Virtual functions for setting event callback and enabling VSync
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        // Static function to create a window
        static Window* Create(const WindowProps& props = WindowProps());
    };

}
