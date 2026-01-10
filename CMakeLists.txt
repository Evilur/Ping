CMAKE_MINIMUM_REQUIRED(VERSION 4.2)
SET(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
PROJECT(Ping)

# Set compile options
IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(CMAKE_CXX_FLAGS "-g3 -O0 -fdiagnostics-color=always")
    SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    SET(QT_QML_GENERATE_QMLLS_INI ON CACHE BOOL "" FORCE)
ELSE ()
    SET(CMAKE_CXX_FLAGS "-g0 -O2")
ENDIF ()

# Find Qt6 package
FIND_PACKAGE(Qt6 REQUIRED COMPONENTS
    Core5Compat
    LinguistTools
    Qml
    Quick
)

# Search header files in the 'src' directory
INCLUDE_DIRECTORIES(src)

# Enable auto Qt file generation
SET(CMAKE_AUTOMOC ON)

# Get all *.cpp files except main.cpp
FILE(GLOB_RECURSE SOURCES "src/*.cpp")
LIST(FILTER SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

# Build the client
QT_ADD_EXECUTABLE(Ping ${SOURCES} src/client/main.cpp)

# Add locale files
FILE(GLOB_RECURSE TS_FILES "assets/locale/*.ts")
QT_ADD_TRANSLATIONS(Ping TS_FILES ${TS_FILES})

# Build the server
ADD_EXECUTABLE(Pings ${SOURCES} src/server/main.cpp)

# Build all *.cpp files for tests
FILE(GLOB_RECURSE SOURCES_TEST "test/*.cpp")
ADD_EXECUTABLE(Test ${SOURCES_TEST}
    src/util/hash.cpp
)

# Copy tests directory
ADD_CUSTOM_COMMAND(TARGET Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/test/units $<TARGET_FILE_DIR:Ping>/test/units
)

# Add QML modules
ADD_SUBDIRECTORY(assets/component/control)
ADD_SUBDIRECTORY(assets/component/visual)
ADD_SUBDIRECTORY(assets/core/MainWindow)
ADD_SUBDIRECTORY(assets/core)
ADD_SUBDIRECTORY(assets/img)
ADD_SUBDIRECTORY(assets/js)
TARGET_LINK_LIBRARIES(AppCore PRIVATE
    AppMainWindow
    AppControl
    AppVisual
    AppJS
    AppImage
)

# Link all dependencies
TARGET_LINK_LIBRARIES(Ping PRIVATE
    AppCore
    Qt6::Quick
    Qt6::Qml
)
