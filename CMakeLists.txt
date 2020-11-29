cmake_minimum_required(VERSION 3.17)
project(larry)

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


find_package(cpprestsdk REQUIRED)

include_directories(include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -lcurl")
add_executable(larry main.cpp)
target_link_libraries(larry ${CMAKE_DL_LIBS})
target_link_libraries(larry PRIVATE nlohmann_json::nlohmann_json)
