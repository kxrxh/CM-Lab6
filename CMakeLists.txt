cmake_minimum_required(VERSION 3.5)

project(lab2_cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets Charts Core WebView WebEngineWidgets)
find_package(Qt5 REQUIRED COMPONENTS Widgets Charts Core WebView WebEngineWidgets)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB PROJECT_SOURCES ${SOURCE_DIR}/*.cpp ${SOURCE_HEADER_DIR}/*.hpp)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab2_cpp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()  
    add_executable(lab2_cpp
        ${PROJECT_SOURCES}
    )
endif()

include_directories(include)
target_link_libraries(lab2_cpp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::WebView Qt${QT_VERSION_MAJOR}::WebEngineWidgets)



set_target_properties(lab2_cpp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


include(GNUInstallDirs)
install(TARGETS lab2_cpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab2_cpp)
endif()