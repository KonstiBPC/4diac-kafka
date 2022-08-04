# Install script for directory: C:/FORTE_dev/forte-sourcecode/org.eclipse.4diac.forte/src/arch

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/be_m1/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/ecos/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/freeRTOS/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/macos/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/netos/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/pikeos_posix/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/plcnext/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/posix/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/rcX/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/vxworks/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/win32/cmake_install.cmake")
  include("C:/FORTE_dev/forte-sourcecode/build/Build_kafka_msbuild/src/arch/utils/cmake_install.cmake")

endif()

