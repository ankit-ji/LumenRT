# LumenRT

LumenRT is a real-time ray tracing and rendering engine written in C++. The project focuses on physically based rendering, modern graphics programming, and interactive scene visualization.

Built with a modular architecture, LumenRT combines a runtime renderer, an editor layer, and sample assets to experiment with rendering pipelines, ray tracing techniques, materials, lighting, and scene management.

---

## Features

* Real-time ray tracing pipeline
* Physically based rendering (PBR)
* Runtime rendering engine
* Separate editor module for scene interaction
* Skybox and environment rendering
* Sample 3D models and assets included
* Modular C++ architecture
* CMake build system
* Cross-platform friendly structure

---

## Project Structure

```bash
LumenRT/
├── LumenRT/             # Core engine source
├── LumenRTEditor/       # Editor application
├── LumenRTRuntime/      # Runtime executable
├── SampleModels/        # Sample 3D assets
├── SampleSkyboxes/      # Environment textures and skyboxes
├── CMakeLists.txt       # Root build configuration
└── .gitmodules          # External dependencies
```

---

## Technologies Used

* C++
* CMake
* Modern Graphics APIs
* Ray Tracing Techniques
* Physically Based Rendering Concepts

---

## Getting Started

### Prerequisites

Make sure you have the following installed:

* C++17 compatible compiler
* CMake 3.16+
* Git
* Graphics drivers supporting modern rendering APIs

Recommended:

* GCC / Clang on Linux
* Visual Studio 2022 on Windows

---

## Clone the Repository

```bash
git clone --recursive https://github.com/ankit-ji/LumenRT.git
cd LumenRT
```

If submodules are not initialized:

```bash
git submodule update --init --recursive
```

---

## Build Instructions

### Linux

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

### Windows

```bash
mkdir build
cd build
cmake ..
```

Open the generated Visual Studio solution and build the project.

---

## Running the Engine

After building, run either:

```bash
./LumenRTRuntime
```

or launch the editor:

```bash
./LumenRTEditor
```

---

## Screenshots

Add screenshots or rendered scenes here.

```md
![Render Preview](path/to/image.png)
```

---

## Goals of the Project

LumenRT was created as a rendering and ray tracing project to explore:

* Modern rendering architecture
* Real-time global illumination concepts
* GPU rendering pipelines
* Ray-object intersection systems
* Material and lighting workflows
* Scene management and rendering optimization

---

## Future Improvements

* Advanced global illumination
* Vulkan/DXR backend improvements
* Denoising techniques
* Material editor
* Animation support
* Post-processing stack
* Better scene serialization
* Performance profiling tools

---

## Contributing

Contributions, suggestions, and feedback are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a pull request

---

## License

This project is currently not licensed.

You can add a license later depending on how you want the project to be used.

---

## Author

Developed by Ankit.

GitHub: [https://github.com/ankit-ji](https://github.com/ankit-ji)
