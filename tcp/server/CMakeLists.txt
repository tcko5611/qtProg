find_package(Qt5 COMPONENTS Core Network REQUIRED)
add_executable(server main.cpp mythread.cpp myserver.cpp)
qt5_use_modules(server Core Network)
