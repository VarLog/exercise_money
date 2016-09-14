# FIXME Make a library
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.cpp")
list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/main.cpp")
include_directories("${PROJECT_SOURCE_DIR}/src/")

file(GLOB TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/${PROJECT_NAME}/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/test/${PROJECT_NAME}/")

set(TEST "${PROJECT_NAME}_test")
add_executable(${TEST} ${SOURCES} ${TEST_SOURCES})
target_link_libraries(${TEST} libgtest)

add_test(NAME ${TEST} COMMAND ${TEST})

