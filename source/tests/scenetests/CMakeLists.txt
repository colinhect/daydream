project(scenetests CXX)

set(SOURCE_FILES
    source/main.cpp
    source/component_pool_tests.cpp
    source/scene_tests.cpp
    )

add_executable(scenetests ${SOURCE_FILES})

if(MSVC)
    target_compile_options(scenetests PRIVATE /W3 /WX /wd)
else()
    target_compile_options(scenetests PRIVATE -std=c++1y -Wall -Wextra -Werror -pedantic)
endif()

target_link_libraries(scenetests PRIVATE scene catch)

set_target_properties(scenetests PROPERTIES
    PROJECT_LABEL scenetests
    LINKER_LANGUAGE CXX
    FOLDER "/tests"
    )

add_test(NAME scenetests
    WORKING_DIRECTORY ${DAYDREAM_OUTPUT_DIR}
    COMMAND scenetests)
