if(ENABLE_OPENMP STREQUAL "ON")
    find_package(OpenMP)
    if(NOT OPENMP_FOUND)
        message(FATAL_ERROR "Cannot find openmp")
    endif(NOT OPENMP_FOUND)
endif(ENABLE_OPENMP STREQUAL "ON")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/src/")

# Bin
set(BIN "${PROJECT_NAME}")
add_executable(${BIN} ${SOURCES} ${HEADERS})
#set_property(TARGET ${BIN} PROPERTY CXX_STANDARD 14)

#install(TARGETS ${BIN} DESTINATION bin)
