# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/Cellar/cmake/3.30.3/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "example_gravity built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "Bundle")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/build;example_gravity;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "GeographicLib-2.4")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "GeographicLib-2.4")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJDUMP_EXECUTABLE "/Library/Developer/CommandLineTools/usr/bin/objdump")
set(CPACK_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "karney@alum.mit.edu")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/Cellar/cmake/3.30.3/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GeographicLib library, utilities, and documentation")
set(CPACK_PACKAGE_FILE_NAME "GeographicLib-2.4-darwin")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "GeographicLib-2.4")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "GeographicLib-2.4")
set(CPACK_PACKAGE_NAME "example_gravity")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "GeographicLib")
set(CPACK_PACKAGE_VERSION "2.4")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "4")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "/opt/homebrew/Cellar/cmake/3.30.3/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/opt/homebrew/Cellar/cmake/3.30.3/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES "#;~$;/\\.git;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/BUILD;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/man/(.*\\.pod|makeusage\\.sh|dummy\\..*)$;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/cmake/maintainer-.*\\.cmake$;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/(develop|cgi-bin|.*\\.cache)/;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/(data-distrib|data-installer)/;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/(archive|scratch|mpfr_mpir_x86_x64_msvc2010)/;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/.*\\.(zip|tar\\.gz|bak|lsp)$;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/(autogen|biblio)\\.sh$;/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/GeographicLib/(makefile-admin|HOWTO-RELEASE.txt)$")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "GeographicLib-2.4")
set(CPACK_SYSTEM_NAME "Darwin")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Darwin")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/example_gravity/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
