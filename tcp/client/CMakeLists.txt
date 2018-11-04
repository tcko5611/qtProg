find_package(Qt5 COMPONENTS Core Network REQUIRED)
add_executable(client main.cpp mytcpsocket.cpp)
qt5_use_modules(client Core Network)
