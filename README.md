# ParticleEngine

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/190315010-0a84e171-a2bc-42a4-91c8-bb850960209c.png" alt="openglLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/190315147-ec9dc33f-0090-4f0d-98ab-514eb1463e01.png" alt="glfwLogo" style="height:60px;"/>
</p>

## Description

This is a simple physics engine written in C++ using Glad, GLFW, OpenGl3 and Dear ImGui.

It is implemented using Fixed Framerate and Component Oriented Programming.

> **Note**  
> The project is a work in progress and is not yet complete.

## Images

| User Interface view                                                                                                         |
|-----------------------------------------------------------------------------------------------------------------------------|
| ![previw_screenshot](https://user-images.githubusercontent.com/59691442/196303021-781cf236-4bab-4523-9f08-2a85c7dd491c.png) |

[//]: # (|                                                    Mesh view                                                     |                                                  Wireframe view                                                  |)
[//]: # (|:----------------------------------------------------------------------------------------------------------------:|:----------------------------------------------------------------------------------------------------------------:|)
[//]: # (| ![image1]&#40;https://user-images.githubusercontent.com/59691442/192190493-f1191715-268e-43e4-8f27-5ed0c2823dfa.png&#41; | ![image2]&#40;https://user-images.githubusercontent.com/59691442/192190499-457463ae-7a34-432a-bb0b-063771021275.png&#41; |)

<!--
## Videos

PLACEHOLDER
-->

## Report

You can find a journal log [here](report/development_log_MOREL_REBOUL_CLAVEL.pdf).  
It is also located in the `report` folder.

## Quickstart

To download the app, you can click one of the icons below (depending on your operating system). You can also click the
release section of the GitHub page.

Depending on you `operating system` you will need to install some libs, they are installed differently depending on your
system, please follow one of the section below `Windows` or `Linux` or `MacOs`.

> **Warning**
> Be sure to put the `imgui.ini` file in the same folder as the executable.
> You can find it in the `root` of the project. If you don't do this, the UI will not be displayed correctly.

### Windows

<a href="https://github.com/Im-Rises/ParticleEngine/releases/latest"><img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For Windows users you don't need to install the libs. You can just download the app and run it.

```bash
.\ParticleEngine.exe
```

> **Warning**  
> The project is set up to be built using CMake and vc2019 for Windows. If you want to modify the
> compiler for vc2022 or other you will need to change the CMakeLists.txt .lib linking file accordingly to your vc20**
> version.

### Linux

<a href="https://github.com/Im-Rises/ParticleEngine/releases/latest"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="cmakeLogo" style="height:40px;"/></a>

For Linux users, you need to install the GLFW lib, to do so type one of the following commands:

```bash
sudo apt-get install libglfw3
```

or if you're a developer and want to compile the app, please install this version of GLFW:

```bash
sudo apt-get install libglfw3-dev
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./ParticleEngine
```

### MacOs

<a href="https://github.com/Im-Rises/ParticleEngine/releases/latest"><img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For macOS users you will need to install Brew, please follow the instruction in the link below:  
<https://brew.sh>

Once it is installed, you can type the following command to install GLFW.

```bash
brew install glfw
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./ParticleEngine
```

## Controls

### Camera controls

TO modify the speed value, you can use the ImGui window named `Speed handler`.

| Action                 | Key |
|------------------------|-----|
| Add speed to the left  | ←   |
| Add speed to the right | →   |
| Add speed forwardly    | ↑   |
| Add speed rearward     | ↓   |

### User controls

| Action            | Key |
|-------------------|-----|
| Toggle fullscreen | F11 |

<!--
| Description        | Keyboard | Mouse                           |
|--------------------|----------|---------------------------------|
| Translate left     | ←        |                                 |
| Translate right    | →        |                                 |
| Translate forward  | ↑        |                                 |
| Translate rearward | ↓        |                                 |
| Rotate camera      |          | Middle click and mouse movement |

### Game controls

| Action        | Key |
|---------------|-----|
| Move forward  | `W` |
| Move backward | `S` |
| Move left     | `A` |
| Move right    | `D` |
-->

## Project Architecture

~~~
ParticleEngine
├── .github
|  ├── labels.yml
|  ├── release.yml
│  ├── workflows
│  │   |── cmake.yml
│  │   |── codeql.yml
│  │   |── cpp-cmake-publish.yml
│  │   |── cpp-linter.yml
│  │   |── dependency-review.yml
│  │   |── flawfinder.yml
│  │   |── greetings.yml
│  │   |── label.yml
│  │   |── msvc.yml
│  │   |── stale.yml
├── dependencies
|  ├── glad
|  ├── glfw
|  ├── glfwglm
|  ├── imgui
|  ├── stb
├── ParticleEngine
│  │   |── *
|  ├── Particule
│  │   |── *
|  ├── Scene
│  │   |── *
|  ├── CMakeLists.txt
|  ├── InputManager.cpp
|  ├── InputManager.h
|  ├── main.cpp
|  ├── ParticleEngine.cpp
|  ├── ParticleEngine.h
├── test
|  ├── TestParticule
│  │   |── *
|  ├── CMakeLists.txt
|  ├── integratorTest.cpp
|  ├── physicHandlerTest.cpp
|  ├── particuleTest.cpp
├── .clang-format
├── .editorconfig
├── .gitattributes
├── .gitignore
├── CMakelists.txt
├── CMakePresets.json
├── CMakeSettings.json
├── imgui.ini
├── README.md
~~~

## Dependencies

- C++14
- CMake
- C++ compiler (MSVC, Mingw, ...)
- Glad
- GLFW
- OpenGl 3.3
- Dear ImGui

## Compilation

To compile the app, the first thing you need to do is install a C++ compiler:

- Visual Studio (MSVC)
- Mingw
- ...

You also need to install Cmake:  
<https://cmake.org>

Once your environment is set up, depending on your operating system you'll need to install some libs before compiling
the project. Refer to the section below `Windows` or `Linux` or `MacOs`.

### Windows

Windows users can directly compile the project by typing the following command at the project root folder:

```bash
cmake .
```

> **Note**  
> If you're using Visual Studio, you can install CMake directly from the IDE (Visual Studio Installer).
> Then you need to open the Project as a CMake Project, not a Visual Studio Project!

### Linux

Linux's users need to install some libs before compiling the project:

First thing to do is to install CMake, type the following command to install it.

```bash
sudo apt-get install cmake
```

You also need to install the GLFW lib. Type the following command at the project root.

```bash
sudo apt-get install libglfw3-dev
```

You are now able to compile the project. Go to the project root and type the following command:

```bash
cmake .
```

### MacOs

For macOS user, you should install brew package manager by following the instructions in the link below:  
<https://brew.sh>

Then type the following command to install cmake:

```bash
brew install cmake
```

and this one to install GLFW

```bash
brew install glfw
```

You are now able to compile the project. Go to the project root and type the following command:

```bash
cmake .
```

## Run tests

A CMake test is set up to directly test the program. You can find it in the `test`folder and start it by typing the
command below at the project root folder.

```bash
ctest
```

## Github-Actions

[![CodeQL](https://github.com/Im-Rises/ParticleEngine/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleEngine/actions/workflows/codeql.yml)
[![CMake](https://github.com/Im-Rises/ParticleEngine/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleEngine/actions/workflows/cmake.yml)
[![Cpp Cmake Publish](https://github.com/Im-Rises/ParticleEngine/actions/workflows/cpp-cmake-publish.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleEngine/actions/workflows/cpp-cmake-publish.yml)
[![flawfinder](https://github.com/Im-Rises/ParticleEngine/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleEngine/actions/workflows/flawfinder.yml)
[![Microsoft C++ Code Analysis](https://github.com/Im-Rises/ParticleEngine/actions/workflows/msvc.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleEngine/actions/workflows/msvc.yml)
[![cpp-linter](https://github.com/Im-Rises/ParticleEngine/actions/workflows/cpp-linter.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleEngine/actions/workflows/cpp-linter.yml)

The project is set with a set of different scripts:

- CodeQL: This script is used to check the code for security issues.
- CMake: This script is used to build the project.
- Cpp Cmake Publish: This script is used to publish the project on GitHub.
- Flawfinder: This script is used to check the code for security issues.
- Microsoft C++ Code Analysis: This script is used to check the code for security issues.
- Cpp Linter: This script is used to check the code for security issues.

## Documentations

OpenGL:  
<https://www.khronos.org/registry/OpenGL-Refpages/gl4/>

OpenGL loading library:  
<https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library>

GLFW:  
<https://www.glfw.org/docs/latest/>

Dear ImGui:  
<https://github.com/ocornut/imgui>

GLAD:  
<https://glad.dav1d.de/>

GLM:  
<https://glm.g-truc.net/0.9.8/index.html>

STB:  
<https://github.com/nothings/stb>

ImPlot:  
<https://github.com/epezent/implot>

Learn OpenGL:  
<https://learnopengl.com/Getting-started/Hello-Triangle>

Developpez Learn OpenGL (French):  
<https://opengl.developpez.com/tutoriels/apprendre-opengl/?page=creer-une-fenetre#L4-5>  
<https://opengl.developpez.com/tutoriels/opengl-tutorial/>

Sphere OpenGL:  
<http://www.songho.ca/opengl/gl_sphere.html>

## Contributors

Quentin MOREL:

- @Im-Rises
- <https://github.com/Im-Rises>

Gabriel REBOUL:

- @spiryti
- <https://github.com/spiryti>

Clémence CLAVEL:

- @clemos38
- <https://github.com/clemos38>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/ParticleEngine)](https://github.com/Im-Rises/ParticleEngine/graphs/contributors)
