cmake_minimum_required(VERSION 3.0)

project(BuscaRaices)

# Configura los archivos fuente del proyecto
set(SOURCES
    main.cpp
    Ecuacion.cpp
)

# Agrega un ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Agrega las cabeceras del proyecto
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


