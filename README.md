# Stock Geometizer

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

## What is Stock Geometizer?

![Example Usage](file:///Users/ericjin/Desktop/cinder_0.9.2_mac/my-projects/final-project-EricJ19/resources/example_usage.png)

Stock Geometizer is a data visualization tool to determine the desirability of stocks. A geometric shape is generated
based on various factors such as buy recommendations, 3 year growth rate, 26 week price return, and others. 

The inner shape and color represent expert advise for the stock while the outer shape represents trends in firm 
performance such as 3 year growth rate. The more green and the more edges, the more desirable; the more red and 
the less edges, the less desirable. These factors are weighed and scaled to create a wide range of geometry, making
stock data more easy to visualize than ever before.

Compare up to three different stocks using updating financial data to easily inform your investment decisions.

## Setting Up

This was developed on the Mac OS X system and may not work on other platforms. This project uses the Cinder
platform which can be downloaded from: https://libcinder.org/. Once the Cinder folder is downloaded, create the project from
within the Cinder folder. Beyond the general app platform, Cinder is used to dynamically generate

External libraries used: CPR and OpenSSL, nlohmann/json, and ImGui Cinder Block.

Instructions to integrate these libraries:

### Using CPR and OpenSSL

#### OpenSSL

Crucially, CPR does not support it's own Transport Layer Security (TLS), so it can be paired with OpenSSL.
To make requests using OpenSSL, link against libCURL. Do this by adding the following to the CMakeLists.txt:
```c++
find_package(CURL)
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(cinder-myapp ${CURL_LIBRARY})
```
Note: This should be done above CPR integration lines in the CMakeLists.txt file.

#### CPR

[CPR](https://github.com/whoshuu/cpr) is used to make API calls to [Finhub](https://finnhub.io/) for financial data.

From CPR documentation, it is easiest to add CPR as a submodule using these command in Terminal (for Mac):
```c++
git submodule add https://github.com/whoshuu/cpr.git 
git submodule update --init --recursive
```

In the CMakeList.txt file add this:
```c++
add_subdirectory(submodules/cpr)
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(cinder-myapp ${CPR_LIBRARIES})
```
Then, to use CPR in your project, add this to your source code file:

```c++
#include <cpr/cpr.h>
```

### Using nlohmann/json

[nlomann/json](https://github.com/nlohmann/json) is used to parse API response from Finhub.io.

Add the following into your CMakeLists.txt file:
```c++
# JSON Library. Header-only.
FetchContent_Declare(
        nlohmann_json
        URL https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip
)

# Adds nlohmann_json library.
FetchContent_GetProperties(nlohmann_json)
if(NOT nlohmann_json_POPULATED)
    FetchContent_Populate(nlohmann_json)
    add_library(nlohmann_json INTERFACE)
    target_include_directories(nlohmann_json INTERFACE ${nlohmann_json_SOURCE_DIR}/single_include)
endif()

target_link_libraries(cinder-myapp nlohmann_json)
```
Then, to use nlohmann/json in the project add this to your source code files:

```c++
#include <nlohmann/json.hpp>
```

### Using ImGui Cinder Block

ImGui is used primarily as a means to accept user inputs for custom API calls for different stock.

Add the following to your CMakeList.txt file:
```c++
# Links ImGui CinderBlock
FetchContent_GetProperties(Cinder-ImGui)
include_directories(igl::opengl_glfw_imgui)
target_link_libraries(cinder-myapp Cinder-ImGui)
```
Then, use #include to add the Cinder Block path into your source code. This path should lead to the "blocks" folder that 
comes with Cinder.

## Usage




**Author**: Eric Jin - [`ericjin2@illinois.edu`](mailto:ericjin2@illinois.edu)
