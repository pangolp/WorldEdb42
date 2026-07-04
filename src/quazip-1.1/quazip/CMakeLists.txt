# Simplified quazip CMakeLists — integrated build, no install/packaging.
# Relies on Qt6 and zlib targets already available from the root project.

add_library(quazip STATIC
    JlCompress.cpp
    qioapi.cpp
    quaadler32.cpp
    quachecksum32.cpp
    quacrc32.cpp
    quagzipfile.cpp
    quaziodevice.cpp
    quazip.cpp
    quazipdir.cpp
    quazipfile.cpp
    quazipfileinfo.cpp
    quazipnewinfo.cpp
    unzip.c
    zip.c
)

target_include_directories(quazip PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}          # quazip/ headers
    ${CMAKE_CURRENT_SOURCE_DIR}/..       # parent dir (for #include "quazip/quazip.h")
)

target_compile_definitions(quazip PUBLIC QUAZIP_STATIC)

find_package(Qt6 QUIET COMPONENTS Core5Compat)
if(Qt6Core5Compat_FOUND)
    target_link_libraries(quazip PUBLIC Qt6::Core Qt6::Core5Compat zlib)
else()
    target_link_libraries(quazip PUBLIC Qt6::Core zlib)
endif()

if(MSVC)
    target_compile_options(quazip PRIVATE /W0)
else()
    target_compile_options(quazip PRIVATE -w)
endif()
