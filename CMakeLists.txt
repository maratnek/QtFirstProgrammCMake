cmake_minimum_required(VERSION 3.1.0)

#template for Qt5 build
#project(demo C CXX)
project(demo)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5LinguistTools)

# Populate a CMake variable with the sources
set(SOURCES 
	main.cpp 
	mainwindow.cpp
	MainWindow.ui
	)

set(QON_TS_FILES
	demo_ru.ts
	demo_fr.ts	
	)

find_program(LUPDATE lupdate.exe)

add_custom_command(
	OUTPUT ${QON_TS_FILES}
	COMMAND lupdate -silent -I . ${SOURCES} -ts ${QON_TS_FILES} 
	WORKING_DIRECTORY .
	)


qt5_add_translation(QON_QM_FILES ${QON_TS_FILES})
#add_custom_target(translations DEPENDS ${QON_QM_FILES})

#qt5_create_translation(${SOURCES} demo_ru.ts demo_fr.ts demo_ch.ts)

#add_custom_target(translations DEPENDS demo.qm)
# qt4_add_translation(demo_ru.qm mainwindow.cpp ${MOC_SRCS} ${UI_HEADERS} demo_ru.ts)
#qt5_add_translation(demo.qm demo.ts)
#qt5_create_translation(${SOURCES} demo_ru.ts)


# Tell CMake to create the helloworld executable
add_executable(demo WIN32 ${SOURCES} ${QON_QM_FILES} ${QON_TS_FILES})
# Use the Widgets module from Qt 5
target_link_libraries(demo Qt5::Widgets)


#qt5_create_translation(qm_files directories ... sources ... ts_files ... OPTIONS ...)