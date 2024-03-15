#include "pch.h"
#include "SessionManager.h"
#if __has_include("SessionManager.g.cpp")
#include "SessionManager.g.cpp"
#endif

namespace winrt::Mile::Aria2::implementation
{
    int32_t SessionManager::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SessionManager::MyProperty(int32_t /*value*/)
    {
        throw hresult_not_implemented();
    }
}
