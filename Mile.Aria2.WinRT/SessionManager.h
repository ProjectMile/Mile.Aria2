#pragma once

#include "SessionManager.g.h"

namespace winrt::Mile::Aria2::implementation
{
    struct SessionManager : SessionManagerT<SessionManager>
    {
        SessionManager() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Mile::Aria2::factory_implementation
{
    struct SessionManager : SessionManagerT<SessionManager, implementation::SessionManager>
    {
    };
}
