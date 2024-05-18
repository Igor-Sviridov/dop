cmake_minimum_required(VERSION 3.22.0)

set(REMOTE_IP "rockmiet10")                                                  #IP адрес скифа
set(REMOTE_PATH "/home/")  

set(HOST_DIR "/home/minion/Downloads/mcom03-nn-dev-buildroot-build/toolchain/ubuntu/aarch64-buildroot-linux-gnu_sdk-buildroot")
set(STAGING_DIR "${HOST_DIR}/aarch64-buildroot-linux-gnu/sysroot")          #путь до sysroot
set(CMAKE_TOOLCHAIN_FILE ${HOST_DIR}/share/buildroot/toolchainfile.cmake)
set(ELCORE_CMAKE_TOOLCHAIN_FILE
    ${HOST_DIR}/opt/toolchain-elcore50/share/cmake/elcore50-toolchain.cmake)
set(ElcoreRuntime_DIR ${STAGING_DIR}/usr/lib/cmake/ElcoreRuntime)
set(ElcoreCL_DIR ${STAGING_DIR}/usr/lib/cmake/ElcoreCL)
set(elcorenn_DIR ${STAGING_DIR}/usr/lib/cmake/elcorenn)

project(yunet_detector)

set(OPENCV_VERSION "4.5.4")
set(OPENCV_INSTALLATION_PATH "" CACHE PATH "Where to look for OpenCV installation")

# Find OpenCV
find_package(OpenCV ${OPENCV_VERSION} REQUIRED HINTS ${OPENCV_INSTALLATION_PATH})
find_package(elcorenn REQUIRED)


add_executable(yunet main.cpp ElFaceDetectorYN.cpp)
target_link_libraries(yunet ${OpenCV_LIBS} elcorenn)

install(CODE "execute_process(COMMAND scp ${CMAKE_BINARY_DIR}/yunet root@${REMOTE_IP}:${REMOTE_PATH})")
install(CODE "execute_process(COMMAND scp -r ${CMAKE_BINARY_DIR}/../model root@${REMOTE_IP}:${REMOTE_PATH})")
install(CODE "execute_process(COMMAND scp -r ${CMAKE_BINARY_DIR}/../images root@${REMOTE_IP}:${REMOTE_PATH})")