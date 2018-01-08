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
namespace scene
{
    template <typename ComponentType>
    ComponentPool<ComponentType>::ComponentPool()
    {
    }

    template <typename ComponentType>
    ComponentType& ComponentPool<ComponentType>::add_component_to_entity(const Entity& entity, ComponentType&& component)
    {
        _components.emplace_back(std::move(component));
        _entity_to_component[&entity] = &_components.back();
        return _components.back();
    }

    template <typename ComponentType>
    ComponentType* ComponentPool<ComponentType>::find_component_for_entity(const Entity& entity)
    {
        ComponentType* component = nullptr;
        auto it = _entity_to_component.find(&entity);
        if (it != _entity_to_component.end())
        {
            component = it->second;
        }
        return component;
    }

    template <typename ComponentType>
    const ComponentType* ComponentPool<ComponentType>::find_component_for_entity(const Entity& entity) const
    {
        const ComponentType* component = nullptr;
        auto it = _entity_to_component.find(&entity);
        if (it != _entity_to_component.end())
        {
            component = it->second;
        }
        return component;
    }
}