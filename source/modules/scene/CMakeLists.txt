project(scene CXX)

set(SOURCE_FILES
    include/scene/component.hpp
    include/scene/component.inl
    include/scene/component_pool.hpp
    include/scene/component_pool.inl
    include/scene/entity.hpp
    include/scene/entity.inl
    source/entity.cpp
    include/scene/scene.hpp
    include/scene/scene.inl
    source/scene.cpp
    )

add_library(scene SHARED ${SOURCE_FILES})

target_include_directories(scene PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(scene PRIVATE /W3 /WX /wd)
    target_compile_definitions(scene PRIVATE _CRT_SECURE_NO_WARNINGS SCENE_EXPORTS)
else()
    target_compile_options(scene PRIVATE -std=c++1y -Wall -Wextra -Werror -pedantic)
endif()

target_link_libraries(scene PRIVATE
    )

if(MSVC)
    target_link_libraries(scene PRIVATE ws2_32 winmm)
else()
    target_link_libraries(scene PRIVATE pthread)
endif()

set_target_properties(scene PROPERTIES
    PROJECT_LABEL scene
    LINKER_LANGUAGE CXX
    FOLDER "/modules"
    )
