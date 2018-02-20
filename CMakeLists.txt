project(MTGSim)
Cmake_minimum_required(VERSION 2.8)

set(MTGSim_sources
    # headers
    src/abilities.h
    src/creaturestrength.h
    src/datatypes.h
    src/enums.h
    src/magiccard.h
    src/manacost.h
    # sources
    src/abilities.cpp
    src/creaturestrength.cpp
    src/magiccard.cpp
    src/manacost.cpp
    # main
    src/main.cpp)

add_executable(MTGSim ${MTGSim_sources})
