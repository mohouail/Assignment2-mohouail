project(Code_lib)

set(HEADER_FILES
        DEQ.h
        Plane.h
        Simulation.h
)

set(SOURCE_FILES
        DEQ.cpp
        Plane.cpp
        Simulation.cpp
)

add_library(Code_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})