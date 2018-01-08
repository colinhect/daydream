///////////////////////////////////////////////////////////////////////////////
// This source file is part of Daydream.
//
// Copyright (c) 2018 Colin Hill
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
///////////////////////////////////////////////////////////////////////////////
#include <scene/scene.hpp>

#include <catch.hpp>

class TestComponent :
    public scene::Component<TestComponent>
{
public:
    int value = 0;

};

class TestEntity :
    public scene::Entity
{
public:
    TestEntity(scene::Scene& scene) :
        Entity(scene),
        test_component(add_component<TestComponent>())
    {
        test_component.value = 12;
    }

    TestComponent& test_component;
};

TEST_CASE("Create a test entity with a test component")
{
    scene::Scene scene;
    auto entity = scene.create_entity<TestEntity>();
    REQUIRE(entity->test_component.value == 12);
    REQUIRE(entity->get_component<TestComponent>().value == 12);
    REQUIRE(&entity->test_component== &entity->get_component<TestComponent>());
}

