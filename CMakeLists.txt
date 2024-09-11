cmake_minimum_required(VERSION 2.8)
project(arpinator)
add_executable(arpinator main.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(arpinator sfml-system sfml-window sfml-graphics sfml-audio)
include_directories( include )
add_library(arp_service_impl include/impl/ArpServiceImpl.cpp)
target_link_libraries(arpinator arp_service_impl)
