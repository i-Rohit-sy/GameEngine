# GameEngine

A modern C++ game engine built with OpenGL that provides a solid foundation for 2D and 3D game development. This engine offers a clean architecture with well-organized components for rendering, input handling, event systems, and more.

## Overview

GameEngine is designed to be both powerful and accessible for game developers. It leverages industry-standard libraries while providing a streamlined API to make game development more efficient.

### Key Features

- **Modern Rendering System**: Using OpenGL 4.5+ for high-performance graphics
- **Intuitive Window Management**: GLFW-based window creation and control
- **Developer Tools**: Built-in ImGui integration for real-time debugging and property editing
- **Mathematics Support**: Comprehensive vector/matrix operations via GLM
- **Event Architecture**: Flexible event system for clean communication between components
- **Optimized Build System**: Precompiled headers and efficient project organization
- **Platform Support**: Primary focus on Windows with architecture ready for cross-platform expansion

## System Requirements

- **IDE**: Visual Studio 2019 or newer
- **Build System**: Premake5 (included in repository)
- **Windows**: Windows 10 or 11 with SDK 10.0+
- **C++ Standard**: C++17 compatible compiler
- **Version Control**: Git (for repository cloning and management)

## Getting Started

Follow these steps to get the engine up and running on your system:

### 1. Clone the Repository

Clone the repository including all submodules:

```bash
git clone --recursive https://github.com/yourusername/GameEngine.git
cd GameEngine
```

If you already cloned without the `--recursive` flag, initialize the submodules separately:

```bash
git submodule update --init --recursive
```

### 2. Generate Project Files

Run the included batch script to generate Visual Studio project files:

```bash
GenerateProject.bat
```

This script uses Premake5 to create the solution and project files configured for your environment.

### 3. Open and Build the Project

1. Navigate to the project directory and open `GameEngine.sln` in Visual Studio
2. In the Solution Explorer, right-click on `Sandbox` and select "Set as Startup Project"
3. Select your desired build configuration (Debug/Release/Dist)
4. Press F5 or click the "Local Windows Debugger" button to build and run

### 4. Start Developing

Once the Sandbox application is running, you'll see a basic demo window. This serves as a starting point for your own game development.

## Project Architecture

The repository is organized into these main components:

- **GameEngine/**: Core engine library containing all engine functionality
  - `src/`: Source code for the engine
  - `include/`: Public headers for engine API
- **Sandbox/**: Example application demonstrating engine capabilities
  - Contains sample code showing how to use the engine API
  - Serves as a testing environment for new features
- **vendor/**: Third-party dependencies (managed as Git submodules)
  - GLFW: Window creation and input handling
  - Glad: OpenGL function loader
  - ImGui: Immediate-mode graphical interface library
  - GLM: Mathematics library optimized for graphics
  - stb_image: Image loading utilities
- **Scripts/**: Build scripts and development utilities
  - Premake configuration
  - Utility scripts for project maintenance

## Build Configurations

The engine supports multiple build configurations to suit different development needs:

- **Debug**:

  - Includes full debugging symbols
  - Minimal optimizations
  - Additional runtime checks and validations
  - Perfect for development and troubleshooting

- **Release**:

  - Optimized for performance while maintaining critical checks
  - Includes assertions for important error detection
  - Suitable for testing near-final versions

- **Dist** (Distribution):
  - Maximum optimization for performance
  - No debug features or assertions
  - Minimal logging and error checking
  - Intended for final deployment

## Core Dependencies

GameEngine integrates several battle-tested libraries:

- **[GLFW](https://www.glfw.org/)**: Handles window creation, context management, and input processing
- **[Glad](https://glad.dav1d.de/)**: Modern OpenGL function loading
- **[Dear ImGui](https://github.com/ocornut/imgui)**: Lightweight immediate-mode GUI for debugging tools and editor interfaces
- **[GLM](https://github.com/g-truc/glm)**: Mathematics library designed specifically for graphics programming
- **[stb_image](https://github.com/nothings/stb)**: Lightweight image loading and processing

All dependencies are included as submodules and don't require separate installation.

## Contributing Guidelines

Interested in contributing to the engine? Follow these steps:

1. Fork the repository to your GitHub account
2. Create a feature branch with a descriptive name (`git checkout -b feature/your-feature-name`)
3. Implement your changes following the existing code style
4. Write appropriate tests for your additions
5. Commit changes with clear, descriptive messages
6. Push to your branch and create a Pull Request with detailed description

### Coding Standards

- Follow the existing code style and naming conventions
- Ensure proper commenting of public API functions
- Write unit tests for new functionality
- Avoid introducing new dependencies without discussion

## License

This project is licensed under the terms found in the LICENSE file in the root directory.

## Acknowledgments

- Thanks to all contributors of the open-source libraries utilized in this project
- Special thanks to the game engine development community for resources and inspiration
- This project draws significant inspiration from [The Cherno's Game Engine Series](https://www.youtube.com/@TheCherno) - an excellent educational resource for game engine development

## Support and Contact

For questions, bug reports, or feature requests:

- Open an issue in the GitHub repository
- Provide detailed information about any problems encountered
- For major feature discussions, please open an issue first to discuss your ideas

---

**Happy Game Development!**
