##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.0)
project(SP3Koordinator)

##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS qt_build roscpp)
include_directories(${catkin_INCLUDE_DIRS})
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything. 
catkin_package()

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically 
# included via the dependency call in package.xml
rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# mysqlclient
##############################################################################
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

foreach(FLAG ${LIBMYSQLCLIENT_CFLAGS_OTHER})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAG}")
endforeach()

#link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})
####### #######################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.hpp /usr/local/include/*.h)

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS} )
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}  /us/local/lib ${LIBMYSQLCLIENT_LIBRARY_DIRS})
##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

##############################################################################
# Binaries
##############################################################################
add_executable(SP3Koordinator ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
set_property(TARGET SP3Koordinator PROPERTY CXX_STANDARD 11)
target_link_libraries(SP3Koordinator ${QT_LIBRARIES} ${catkin_LIBRARIES} ${CMAKE_BINARY_DIR} paho-mqtt3c ${LIBMYSQLCLIENT_LIBRARIES})
install(TARGETS SP3Koordinator RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

