
file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/src/")

# Bin
set(BIN "${PROJECT_NAME}")
add_executable(${BIN} ${SOURCES} ${HEADERS})
set_property(TARGET ${BIN} PROPERTY CXX_STANDARD 14)

#install(TARGETS ${BIN} DESTINATION bin)
