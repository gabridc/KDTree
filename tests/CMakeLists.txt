
cmake_minimum_required(VERSION 3.15)
project(readCities CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "~/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
set(Qt5_DIR "~/Qt/5.15.2/")

find_package(Qt5 REQUIRED COMPONENTS Core)

#add_executable(construction_time construction_time.cpp)
#target_link_libraries(construction_time KDTree)

#add_executable(error_test error_test.cpp)
#target_link_libraries(error_test KDTree)

#add_executable(toy_test toy_test.cpp)
#target_link_libraries(toy_test KDTree)

link_directories(/home/gabridc/Repositorio/KDE/KDTree)

include_directories(.)
include_directories(/home/gabridc/Repositorio/KDE/KDTree)
include_directories(~/Qt/5.15.2/gcc_64/include)


add_executable(readCities readCities.cpp)
target_link_libraries(readCities Qt5::Core KDTree)

