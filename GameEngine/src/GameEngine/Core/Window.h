#pragma once

#include "hzpch.h" // Precompiled header
#include "GameEngine/core/Base.h"
#include "GameEngine/Events/Event.h"

namespace GameEngine {

    // Struct to hold window properties
    struct WindowProps {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        // Constructor with default values
        WindowProps(const std::string& title = "GameEngine",
            uint32_t width = 1280,
            uint32_t height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    // Interface for representing a desktop system-based window
    class Window {
    public:
        // Alias for event callback function
        using EventCallbackFn = std::function<void(Event&)>;

        // Destructor
        virtual ~Window() = default;

        // Pure virtual function for updating the window
        virtual void OnUpdate() = 0;

        // Virtual functions for getting width and height of the window
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        // Virtual functions for setting event callback and enabling VSync
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        // Static function to create a window
        static Scope<Window> Create(const WindowProps& props = WindowProps());
    };

}
