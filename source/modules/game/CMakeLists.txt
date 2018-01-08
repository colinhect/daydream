project(game CXX)

set(SOURCE_FILES
    include/game/game.hpp
    source/game.cpp
    )

add_library(game SHARED ${SOURCE_FILES})

target_include_directories(game PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(game PRIVATE /W3 /WX /wd)
    target_compile_definitions(game PRIVATE _CRT_SECURE_NO_WARNINGS GAME_EXPORTS)
else()
    target_compile_options(game PRIVATE -std=c++1y -Wall -Wextra -Werror -pedantic)
endif()

target_link_libraries(game PRIVATE
    )

if(MSVC)
    target_link_libraries(game PRIVATE ws2_32 winmm)
else()
    target_link_libraries(game PRIVATE pthread)
endif()

set_target_properties(game PROPERTIES
    PROJECT_LABEL game
    LINKER_LANGUAGE CXX
    FOLDER "/modules"
    )
