/*
 * PROJECT:   Mile.Aria2
 * FILE:      Mile.Aria2.WinRT.cpp
 * PURPOSE:   Implementation for Mile.Aria2.WinRT
 *
 * LICENSE:   The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#include <Windows.h>
#include <roapi.h>
#include <winstring.h>

#include <clocale>
#include <cstdio>
#include <cwchar>

#include <winrt/Windows.Foundation.h>

EXTERN_C HRESULT WINAPI DllGetActivationFactory(
    _In_ HSTRING activatableClassId,
    _Out_ IActivationFactory** factory)
{
    return ::WINRT_GetActivationFactory(
        activatableClassId,
        reinterpret_cast<void**>(factory));
}

int main()
{
    winrt::init_apartment();

    std::vector<winrt::hstring> ActivatableClassIds;
    ActivatableClassIds.push_back(L"Mile.Aria2.SessionManager");
    
    std::vector<PFNGETACTIVATIONFACTORY> ActivationFactoryCallbacks;
    for (size_t i = 0; i < ActivatableClassIds.size(); ++i)
    {
        ActivationFactoryCallbacks.push_back(&::DllGetActivationFactory);
    }

    RO_REGISTRATION_COOKIE RegistrationCookie;

    winrt::check_hresult(::RoRegisterActivationFactories(
        reinterpret_cast<HSTRING*>(&ActivatableClassIds[0]),
        &ActivationFactoryCallbacks[0],
        static_cast<UINT32>(ActivatableClassIds.size()),
        &RegistrationCookie));

    std::wprintf(
        L"Mile.Aria2.WinRT\n"
        L"================================================================\n"
        L"Hello World!\n");

    std::getchar();

    return 0;
}
