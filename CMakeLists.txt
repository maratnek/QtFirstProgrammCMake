#template for Qt4 build
project(demo C CXX)
cmake_minimum_required(VERSION 2.6.0)
set(CMAKE_IN_SOURCE_BUILD TRUE)
set(SOURCES main.cpp mainwindow.cpp)
set(UIS MainWindow.ui)
set(MOC_HEADERS mainwindow.h)
set(demo_RCCS demo.qrc)
# set(QM_FILES demo_ru.qm)
add_definitions(-Wall -g)
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
qt4_wrap_ui(UI_HEADERS ${UIS})
qt4_wrap_cpp(MOC_SRCS ${MOC_HEADERS})
qt4_add_resources(demo_RCC_SRCS ${demo_RCCS})
include_directories(${CMAKE_BINARY_DIR})
add_executable(demo ${SOURCES} ${UI_HEADERS} ${MOC_SRCS} ${demo_RCC_SRCS})
# add_executable(demo ${SOURCES} ${UI_HEADERS} ${MOC_SRCS} ${demo_RCC_SRCS} ${QM_FILES})
target_link_libraries(demo ${QT_LIBRARIES})
# add_custom_target(translations DEPENDS ${QM_FILES})
# qt4_add_translation(demo_ru.qm mainwindow.cpp ${MOC_SRCS} ${UI_HEADERS} demo_ru.ts)