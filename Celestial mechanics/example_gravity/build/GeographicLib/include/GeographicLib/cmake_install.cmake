# Install script for directory: /Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GeographicLib" TYPE FILE FILES
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Accumulator.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/AlbersEqualArea.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/AuxAngle.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/AuxLatitude.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/AzimuthalEquidistant.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/CassiniSoldner.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/CircularEngine.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Constants.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/DAuxLatitude.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/DMS.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/DST.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Ellipsoid.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/EllipticFunction.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GARS.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GeoCoords.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Geocentric.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Geodesic.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GeodesicExact.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GeodesicLine.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GeodesicLineExact.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Geohash.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Geoid.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Georef.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Gnomonic.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GravityCircle.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/GravityModel.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Intersect.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/LambertConformalConic.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/LocalCartesian.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/MGRS.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/MagneticCircle.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/MagneticModel.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Math.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/NearestNeighbor.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/NormalGravity.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/OSGB.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/PolarStereographic.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/PolygonArea.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Rhumb.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/SphericalEngine.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/SphericalHarmonic.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/SphericalHarmonic1.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/SphericalHarmonic2.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/TransverseMercator.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/TransverseMercatorExact.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/UTMUPS.hpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/include/GeographicLib/Utility.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GeographicLib" TYPE FILE FILES "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/build/GeographicLib/include/GeographicLib/Config.h")
endif()

