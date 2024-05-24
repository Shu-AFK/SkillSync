cmake_minimum_required(VERSION 3.10)
set(LIBRARY_NAME SkillSyncDLL) # Replace MyDLL with your dll's name

# Add all the cpp files you want to compile into your library
add_library(${LIBRARY_NAME} SHARED
        main.cpp
        features/features.cpp
        features/movement/movement.cpp
        globals.cpp
)

target_include_directories(${LIBRARY_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(${LIBRARY_NAME} PROPERTIES OUTPUT_NAME "SkillSync" PREFIX "")

target_link_libraries(${LIBRARY_NAME} PRIVATE user32.lib)