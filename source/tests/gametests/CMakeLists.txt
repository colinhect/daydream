project(gametests CXX)

set(SOURCE_FILES
    source/main.cpp
    source/gametests.cpp
    source/daydream_scene_tests.cpp
    )

add_executable(gametests ${SOURCE_FILES})

if(MSVC)
    target_compile_options(gametests PRIVATE /W3 /WX /wd)
else()
    target_compile_options(gametests PRIVATE -std=c++1y -Wall -Wextra -Werror -pedantic)
endif()

target_link_libraries(gametests PRIVATE
	game
	scene
	catch
	)

set_target_properties(gametests PROPERTIES
    PROJECT_LABEL gametests
    LINKER_LANGUAGE CXX
    FOLDER "/tests"
    )

add_test(NAME gametests
    WORKING_DIRECTORY ${DAYDREAM_OUTPUT_DIR}
    COMMAND gametests)
