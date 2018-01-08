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
#include <scene/entity.hpp>
#include <scene/component_pool.hpp>

#include <catch.hpp>

class TestComponent :
    public scene::Component<TestComponent>
{
public:
    TestComponent(scene::Entity& entity, int value) :
        scene::Component<TestComponent>(entity),
        _value(value)
    {
    }

    int get_value()
    {
        return _value;
    }

private:
    int _value;
};

TEST_CASE("Add a component to a component pool")
{
    scene::Entity entity;
    scene::ComponentPool<TestComponent> component_pool;
    TestComponent& test_component = component_pool.add(TestComponent(entity, 23));
    REQUIRE(test_component.get_value() == 23);
}

TEST_CASE("Remove a component to a component pool")
{
    scene::Entity entity;
    scene::ComponentPool<TestComponent> component_pool;
    TestComponent& test_component = component_pool.add(TestComponent(entity, 23));
    REQUIRE(test_component.get_value() == 23);
}
