# Using external packages demo

This is an example of how to use vcpkg and cmake files for building c++ projects
for my future reference

Step 1: Make project repo
```
mkdir example-project
cd example-project
git init
git remode add origin <example url>
git branch -M main
git pull
```

Step 2: Create scaffold
```
touch CMakeLists.txt
main.cpp
```

Step 3: Create project as you would normally

Step 4: Install vcpkg
```
git clone https://github.com/microsoft/vcpkg ~/dev/tools/vcpkg
cd ~/dev/tools/vcpkg
./bootstrap-vcpkg.sh --disableMetrics
# Microsoft uses telemtry to get usage data, I opted out
```

Step 5: Install packages
```
brew install pkg-config # I use max arm64-osx so I need to do this
cd ~/dev/tools/vcpkg
./vcpkg install fmt
export VCPKG_ROOT=~/dev/tools/vcpkg
```

Step 6: Write CmakeLists.txt
```
cmake_minimum_required(VERSION 3.20)
project(hello_fmt)

# Use C++17 or newer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable vcpkg integration if provided externally
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
endif()

# Define the executable
add_executable(hello_fmt main.cpp)

# Find and link fmt (assumes installed via vcpkg)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(hello_fmt PRIVATE fmt::fmt)
```

Step 7: Buil Project
```
cd hello-fmt
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
./bin/hello_fmt
```