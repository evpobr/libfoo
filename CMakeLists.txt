cmake_minimum_required(VERSION 3.11..3.18)

project(foo VERSION 0.2.0 LANGUAGES C)

include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)

add_library(foo
    include/foo/foo.h
    src/foo_priv.h
    src/foo.c)

generate_export_header(foo EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/foo/foo_export.h)
target_include_directories(foo
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/foo>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
set(foo_PUBLIC_HDRS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/foo/foo.h
  ${CMAKE_CURRENT_BINARY_DIR}/include/foo/foo_export.h)

set_target_properties(foo PROPERTIES
  VERSION 0.2.0
  SOVERSION 0
  C_VISIBILITY_PRESET hidden
  PUBLIC_HEADER "${foo_PUBLIC_HDRS}")

install(TARGETS foo
  EXPORT foo-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  FRAMEWORK DESTINATION ${CMAKE_INSTALL_PREFIX}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/foo)

install(EXPORT foo-config
  NAMESPACE Foo::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

write_basic_package_version_file(foo-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMinorVersion)
  
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/foo-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
