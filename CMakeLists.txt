cmake_minimum_required(VERSION 3.16)
project(iwip_coverage C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS_DEBUG "-O0 -g --coverage")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "--coverage")

file(GLOB_RECURSE LWIP_SRC
  src/core/*.c
  src/core/ipv4/*.c
  src/core/ipv6/*.c
  src/api/*.c
  src/netif/*.c
)

add_executable(coverage_main
  coverage_main.c
  sys_now_stub.c
  ${LWIP_SRC}
)


target_include_directories(coverage_main PRIVATE
  src/include
  test/unit   # for arch/cc.h
)
