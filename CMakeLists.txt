cmake_minimum_required(VERSION 3.1)
project(WBC2_EXTENDED VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

### Project options
option(WBC2_EXTENDED_BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/third_party)
set(EIGEN3_INCLUDE_DIR ${THIRD_PARTY_DIR}/eigen-3.3.7)
set(WBC2_DIR ${PROJECT_SOURCE_DIR}/../wbc2)
set(WBC2_INCLUDE_DIR ${WBC2_DIR}/include)
set(WBC2_LIBRARIES ${WBC2_DIR}/build/libwbc2.a)

file(GLOB_RECURSE sources "src/[a-zA-Z]*.cpp")
file(GLOB_RECURSE test_sources "test/[a-zA-Z]*.cpp")

if(VERBOSE)
  message(STATUS "sources: ${sources}")
  message(STATUS "test_sources: ${test_sources}")
endif()

if (WBC2_EXTENDED_BUILD_SHARED_LIBS)
  add_library(wbc2_extended SHARED ${sources})
else()
  add_library(wbc2_extended STATIC ${sources})
endif()

target_include_directories(wbc2_extended
  PUBLIC ${PROJECT_SOURCE_DIR}/include
         ${WBC2_INCLUDE_DIR}
         ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries(wbc2_extended
  ${WBC2_LIBRARIES})

set_target_properties(wbc2_extended PROPERTIES
  VERSION "WBC2_EXTENDED_VERSION"
)

###
### Extras
###
add_subdirectory(test)
