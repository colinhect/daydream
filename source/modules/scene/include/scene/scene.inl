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
    template <typename EntityType, typename... Args>
    std::shared_ptr<EntityType> Scene::create_entity(Args&&... args)
    {
        auto entity = std::make_shared<EntityType>(*this, args...);
        _entities.emplace_back(entity);
        return entity;
    }

    template <typename ComponentType>
    ComponentPool<ComponentType>& Scene::get_components()
    {
        auto it = _component_pools.find(typeid(ComponentType));
        if (it == _component_pools.end())
        {
            std::shared_ptr<ComponentPoolBase> component_pool(new ComponentPool<ComponentType>());
            _component_pools[typeid(ComponentType)] = std::move(component_pool);
            it = _component_pools.find(typeid(ComponentType));
        }
        return *reinterpret_cast<ComponentPool<ComponentType>*>(it->second.get());
    }

    template <typename ComponentType>
    const ComponentPool<ComponentType>& Scene::get_components() const
    {
        auto it = _component_pools.find(typeid(ComponentType));
        if (it == _component_pools.end())
        {
            std::unique_ptr<ComponentBase> component_pool(new ComponentPool<ComponentType>());
            auto result = _component_pools.emplace(typeid(ComponentType), std::move(component_pool));
            it = result.first;
        }
        return *reinterpret_cast<ComponentPool<ComponentType>*>(it->second.get());
    }
}