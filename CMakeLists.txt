cmake_minimum_required(VERSION 3.24.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(bookshelf_coinflipper)

target_sources(app PRIVATE src/main.c)
