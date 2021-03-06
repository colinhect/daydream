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
#include <map>
#include <memory>
#include <vector>
#include <typeindex>
#include <typeinfo>

#include "export.h"
#include "entity.hpp"
#include "component_pool.hpp"

namespace scene
{
    class SCENE_EXPORT Scene
    {
    public:

        ///
        /// Creates an 
        template <typename EntityType, typename... Args>
        std::weak_ptr<EntityType> create_entity(Args&&... args);

        template <typename ComponentType>
        ComponentPool<ComponentType>& get_components();

        template <typename ComponentType>
        const ComponentPool<ComponentType>& get_components() const;

    private:
        std::vector<std::shared_ptr<Entity>> _entities;
        mutable std::map<std::type_index, std::shared_ptr<ComponentPoolBase>> _component_pools;
    };
}

#include "entity.inl"
#include "scene.inl"