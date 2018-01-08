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
    template <typename ComponentType, typename... Args>
    ComponentType& Entity::add_component(Args&&..args)
    {
        return _scene.components<ComponentType>().add(ComponentType(*this, args..));
    }

    template <typename ComponentType>
    ComponentType& Entity::component()
    {
        ComponentType* component = _scene.components<ComponentType>().find_for_entity(*this);
        if (!component)
        {
            throw std::runtime_error();
        }
        return *component;
    }

    template <typename ComponentType>
    const ComponentType& Entity::component() const
    {
        const ComponentType* component = _scene.components<ComponentType>().find_for_entity(*this);
        if (!component)
        {
            throw std::runtime_error();
        }
        return *component;
    }
}