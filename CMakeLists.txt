cmake_minimum_required(VERSION 2.8.12)
project(YUN)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})


include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${ROOT_INCLUDE_DIRS})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB header ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(YUN yun.cc ${sources} ${header})
target_link_libraries(YUN ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

set(COPY_FILES
        yun.cc
        init_vis.mac
        vis.mac
)

foreach(_script ${COPY_FILES})
    configure_file(
        ${PROJECT_SOURCE_DIR}/${_script}
        ${PROJECT_BINARY_DIR}/${_script}
        COPYONLY
    )
endforeach()

