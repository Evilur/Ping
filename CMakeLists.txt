CMAKE_MINIMUM_REQUIRED(VERSION 4.2)
SET(CMAKE_CXX_STANDARD 23)
PROJECT(Ping)

# Set compile options
IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(CMAKE_CXX_FLAGS "-g3 -O0")
    SET(QT_QML_GENERATE_QMLLS_INI ON)
    SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
ELSE ()
    SET(CMAKE_CXX_FLAGS "-g0 -O2")
ENDIF ()

# Find Qt6 package
FIND_PACKAGE(Qt6 REQUIRED COMPONENTS
    Quick
    Qml
    LinguistTools
)

# Search header files in the 'src' directory
INCLUDE_DIRECTORIES(src)

# Enable auto Qt file generation
SET(CMAKE_AUTOMOC ON)

# Get all *.cpp files
FILE(GLOB_RECURSE SOURCES "src/*.cpp")

# Get all *.ts files
FILE(GLOB_RECURSE TS_FILES "assets/locale/*.ts")

# Build all *.cpp and *.qrc files
QT_ADD_EXECUTABLE(Ping ${SOURCES} ${SOURCES_QRC})

# Add locale files
QT_ADD_TRANSLATIONS(Ping TS_FILES ${TS_FILES})

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
