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

int main()
{
    std::vector<std::string> Arguments = Mile::SplitCommandLineString(
        Mile::ToString(CP_UTF8, ::GetCommandLineW()));

    int argc = static_cast<int>(Arguments.size());
    std::vector<char*> argv;
    for (int i = 0; i < argc; ++i)
    {
        argv.push_back(Arguments[i].data());
    }
    argv.push_back(nullptr);

    return ::aria2_main(argc, argv.data());
}
