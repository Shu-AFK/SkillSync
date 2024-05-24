cmake_minimum_required(VERSION 3.10)
set(EXEC_NAME SkillSyncInjector)

add_executable(${EXEC_NAME}
    injector_main.cpp
    injector.cpp
)