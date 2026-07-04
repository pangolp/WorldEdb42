add_library(qtlockedfile STATIC
    qtlockedfile.cpp
    $<$<PLATFORM_ID:Windows>:qtlockedfile_win.cpp>
    $<$<NOT:$<PLATFORM_ID:Windows>>:qtlockedfile_unix.cpp>
)

target_include_directories(qtlockedfile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(qtlockedfile PUBLIC Qt6::Core)

if(MSVC)
    target_compile_options(qtlockedfile PRIVATE /W3)
endif()
