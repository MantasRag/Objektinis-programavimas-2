#Minimali CMake versija
cmake_minimum_required(VERSION 3.25)

# Projekto pavadinimas ir kalba
project(Studentu_Sistema LANGUAGES CXX)

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

# Surinkti visi .cpp failai
set(SOURCES
    main.cpp
    demonstracijos.cpp
    generavimas.cpp
    isvedimas.cpp
    ivestis.cpp
    pagalbines_funkcijos.cpp
    rezultatai.cpp
    rusiavimas_ir_rikiavimas.cpp
    vector_list_testavimas.cpp
    studentas.cpp
    zmogus.cpp
)

# Surinkti visi .h failai
set(HEADERS
    generavimas.h
    isvedimas.h
    ivestis.h
    pagalbines_funkcijos.h
    rezultatai.h
    rusiavimas_ir_rikiavimas.h
    studentas.h
    zmogus.h
    demonstracijos.h
    vector_list_testavimas.h
)

# Sukurtiama pagrindinė programa
add_executable(Studentu_Sistema ${SOURCES} ${HEADERS})

# GOOGLE TEST FRAMEWORK (Unit testams)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)

# Windows: užkirsti kelią gtest_force_shared_crt error
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Įjungti testus
enable_testing()


# UNIT TESTAI
# Šaltiniai naudojami ir testams
set(COMMON_SOURCES
    studentas.cpp
    zmogus.cpp
    pagalbines_funkcijos.cpp
)

# 1: Studentas klasės testai
add_executable(test_studentas 
    tests/test_studentas.cpp
    ${COMMON_SOURCES}
)
target_link_libraries(test_studentas gtest_main)
add_test(NAME StudentasTests COMMAND test_studentas)

# 2: Zmogus klasės testai
add_executable(test_zmogus 
    tests/test_zmogus.cpp
    ${COMMON_SOURCES}
)
target_link_libraries(test_zmogus gtest_main)
add_test(NAME ZmogusTests COMMAND test_zmogus)

# Kopijuojami .txt failai į build katalogą jei jų yra
file(GLOB TXT_FILES "${CMAKE_SOURCE_DIR}/*.txt")
if(TXT_FILES)
    foreach(txt_file ${TXT_FILES})
        get_filename_component(filename ${txt_file} NAME)
        configure_file(${txt_file} ${CMAKE_BINARY_DIR}/${filename} COPYONLY)
    endforeach()
endif()

# Informacija
message(STATUS "Projektas: ${PROJECT_NAME}")
message(STATUS "CMake versija: ${CMAKE_VERSION}")
message(STATUS "C++ standartas: C++${CMAKE_CXX_STANDARD}")
message(STATUS "Build tipas: ${CMAKE_BUILD_TYPE}")
message(STATUS "Kompiliatorius: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Unit testai: ĮJUNGTI (Google Test)")