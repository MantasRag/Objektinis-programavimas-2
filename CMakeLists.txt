cmake_minimum_required(VERSION 3.25)

project(Studentai_v1 LANGUAGES CXX)

# C++ standartas
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Įjungti optimizaciją Release režime
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        add_compile_options(/O2)
    else()
        add_compile_options(-O3)
    endif()
endif()

# Surinkti visus .cpp failus
set(SOURCES
    v1.0.cpp
    generavimas.cpp
    ivestis.cpp
    pagalbines_funkcijos.cpp
    rezultatai.cpp
    rusiavimas_ir_rikiavimas.cpp
    vector_list_testavimas.cpp
)

# Surinkti visus .h failus (nėra būtina, bet gerai dokumentacijai)
set(HEADERS
    generavimas.h
    isvedimas.h
    ivestis.h
    pagalbines_funkcijos.h
    rezultatai.h
    rusiavimas_ir_rikiavimas.h
    studentas.h
    vector_list_testavimas.h
)

# Sukurti vykdomąjį failą
add_executable(Studentai_v1 ${SOURCES} ${HEADERS})

# Jei reikia kopijuoti .txt failus į build katalogą
file(GLOB TXT_FILES "${CMAKE_SOURCE_DIR}/*.txt")
if(TXT_FILES)
    foreach(txt_file ${TXT_FILES})
        get_filename_component(filename ${txt_file} NAME)
        configure_file(${txt_file} ${CMAKE_BINARY_DIR}/${filename} COPYONLY)
    endforeach()
endif()

# Informacija kompiliavimo metu
message(STATUS "Projektas: ${PROJECT_NAME}")
message(STATUS "CMake versija: ${CMAKE_VERSION}")
message(STATUS "C++ standartas: C++${CMAKE_CXX_STANDARD}")
message(STATUS "Kompiliatorius: ${CMAKE_CXX_COMPILER_ID}")