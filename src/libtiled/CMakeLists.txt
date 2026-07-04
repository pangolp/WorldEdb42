add_library(tiled STATIC
    compression.cpp
    gidmapper.cpp
    imagelayer.cpp
    isometricrenderer.cpp
    layer.cpp
    map.cpp
    mapobject.cpp
    mapreader.cpp
    maprenderer.cpp
    mapwriter.cpp
    objectgroup.cpp
    orthogonalrenderer.cpp
    properties.cpp
    staggeredrenderer.cpp
    texture_atlas.c
    tile.cpp
    tilelayer.cpp
    tileset.cpp
    zlevelrenderer.cpp
    ztilelayergroup.cpp
)

target_include_directories(tiled PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(tiled PUBLIC TILED_STATIC)

target_link_libraries(tiled PUBLIC Qt6::Core Qt6::Gui Qt6::Xml zlib qtlockedfile)
