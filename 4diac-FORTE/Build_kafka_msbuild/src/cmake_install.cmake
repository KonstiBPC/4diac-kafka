# Install script for directory: C:/FORTE_dev/forte-sourcecode/org.eclipse.4diac.forte/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/FORTE")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/Debug/forte.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/Release/forte.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/MinSizeRel/forte.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/RelWithDebInfo/forte.exe")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/core/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/modules/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/com/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/external/4diac-Kafka/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/external/VDMA/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/stdfblib/cmake_install.cmake")

endif()

