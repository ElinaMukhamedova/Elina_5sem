# Install script for directory: /Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/GeographicLib-dev" TYPE FILE FILES
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/CMakeLists.txt"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Accumulator.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-AlbersEqualArea.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-AuxAngle.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-AuxLatitude.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-AzimuthalEquidistant.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-CassiniSoldner.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-CircularEngine.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Constants.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-DMS.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-DST.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Ellipsoid.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-EllipticFunction.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GARS.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GeoCoords.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Geocentric.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Geodesic.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Geodesic-small.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GeodesicExact.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GeodesicLine.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GeodesicLineExact.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GeographicErr.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Geohash.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Geoid.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Georef.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Gnomonic.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GravityCircle.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-GravityModel.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Intersect.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-LambertConformalConic.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-LocalCartesian.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-MGRS.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-MagneticCircle.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-MagneticModel.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Math.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-NearestNeighbor.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-NormalGravity.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-OSGB.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-PolarStereographic.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-PolygonArea.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Rhumb.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-RhumbLine.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-SphericalEngine.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-SphericalHarmonic.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-SphericalHarmonic1.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-SphericalHarmonic2.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-TransverseMercator.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-TransverseMercatorExact.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-UTMUPS.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/example-Utility.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/GeoidToGTX.cpp"
    "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/examples/make-egmcof.cpp"
    )
endif()

