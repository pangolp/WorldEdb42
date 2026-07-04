add_library(zlib STATIC
    adler32.c
    compress.c
    crc32.c
    deflate.c
    gzclose.c
    gzlib.c
    gzread.c
    gzwrite.c
    infback.c
    inffast.c
    inflate.c
    inftrees.c
    trees.c
    uncompr.c
    zutil.c
)

target_include_directories(zlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Suppress warnings from third-party code
if(MSVC)
    target_compile_options(zlib PRIVATE /W0)
else()
    target_compile_options(zlib PRIVATE -w)
endif()
