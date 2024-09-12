cmake_minimum_required(VERSION 2.8)
project(arpnator)
add_executable(arpnator main.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories( include )
add_library(arp_service_impl include/impl/ArpServiceImpl.cpp)
add_library(ui_service_impl include/impl/UiServiceImpl.cpp)

target_link_libraries(ui_service_impl sfml-system sfml-window sfml-graphics sfml-audio)

target_link_libraries(ui_service_impl arp_service_impl)
target_link_libraries(arpnator ui_service_impl)
