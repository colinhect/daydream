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
#pragma once
#include <deque>
#include <unordered_map>
#include "export.h"
#include "component.hpp"

namespace scene
{
    class Entity;

    class SCENE_EXPORT ComponentPoolBase
    {
    public:
        virtual ~ComponentPoolBase() { }
    };

    template <typename ComponentType>
    class ComponentPool :
        public ComponentPoolBase
    {
    public:
        ComponentPool();

        ComponentPool(ComponentPool&&) = default;
        ComponentPool& operator=(ComponentPool&&) = default;
        ComponentPool(const ComponentPool&) = delete;
        ComponentPool& operator=(const ComponentPool&) = delete;

        ComponentType& add_component_to_entity(const Entity& entity, ComponentType&& component);

        ComponentType* find_component_for_entity(const Entity& entity);
        const ComponentType* find_component_for_entity(const Entity& entity) const;

    private:
        std::deque<ComponentType> _components;
        std::unordered_map<const Entity*, ComponentType*> _entity_to_component;
    };
}

#include "component_pool.inl"