
cmake_minimum_required(VERSION 3.10)

project(GStreamerOpenCVExample)

find_package(OpenCV REQUIRED)

add_executable(server server.cpp)
add_executable(client client.cpp)

target_link_libraries(server ${OpenCV_LIBS})
target_link_libraries(client ${OpenCV_LIBS})

add_executable(server_tcp server_tcp.cpp)
add_executable(client_tcp client_tcp.cpp)

target_link_libraries(server_tcp ${OpenCV_LIBS})
target_link_libraries(client_tcp ${OpenCV_LIBS})
