/*
 * PROJECT:   Mile.Aria2
 * FILE:      Mile.Aria2.cpp
 * PURPOSE:   Implementation for Mile.Aria2
 *
 * LICENSE:   The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#include <Windows.h>

#pragma comment(lib,"secur32.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"iphlpapi.lib")

extern "C" int aria2_main(int argc, char** argv);

#include <Mile.Helpers.CppBase.h>

int wmain(int argc, wchar_t** argv)
{
    std::vector<char*> utf8_argv;

    for (int i = 0; i < argc; ++i)
    {
        utf8_argv.push_back(::_strdup(
            Mile::ToString(CP_UTF8, argv[i]).c_str()));
    }
    utf8_argv.push_back(nullptr);

    return aria2_main(argc, &utf8_argv[0]);
}
