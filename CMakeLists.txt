cmake_minimum_required(VERSION 3.16)
project(casino_polimorfismo)

# Usar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ejecutable y archivos fuente
add_executable(casino_polimorfismo
        main.cpp
        View/View.cpp
        Model/Casino.cpp
        Model/DosColores.cpp
        Model/Mayor13.cpp
        Model/Slots.cpp
        Model/Jugador.cpp
        Model/ParImpar.cpp
)

# Directorio de inclusión para encontrar los headers
target_include_directories(casino_polimorfismo PRIVATE
        ${PROJECT_SOURCE_DIR}
)
