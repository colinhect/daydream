project(client CXX)

set(SOURCE_FILES
    source/main.cpp
    )

add_executable(client ${SOURCE_FILES})

if(MSVC)
    target_compile_options(client PRIVATE /W3 /WX /wd)
else()
    target_compile_options(client PRIVATE -std=c++1y -Wall -Wextra -Werror -pedantic)
endif()

target_link_libraries(client PRIVATE game)

set_target_properties(client PROPERTIES
    PROJECT_LABEL client
    LINKER_LANGUAGE CXX
    FOLDER "/modules"
    )
