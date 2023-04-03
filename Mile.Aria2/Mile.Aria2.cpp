/*
 * PROJECT:   Mile.Aria2
 * FILE:      Mile.Aria2.cpp
 * PURPOSE:   Implementation for Mile.Aria2
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <Windows.h>

#pragma comment(lib,"secur32.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"iphlpapi.lib")

extern "C" int aria2_main(int argc, char** argv);

#include <cstdint>
#include <string>
#include <vector>

namespace
{
    std::string ToMultiByteString(
        std::uint32_t CodePage,
        std::wstring_view const& InputString)
    {
        std::string OutputString;

        int OutputStringLength = ::WideCharToMultiByte(
            CodePage,
            0,
            InputString.data(),
            static_cast<int>(InputString.size()),
            nullptr,
            0,
            nullptr,
            nullptr);
        if (OutputStringLength > 0)
        {
            OutputString.resize(OutputStringLength);
            OutputStringLength = ::WideCharToMultiByte(
                CodePage,
                0,
                InputString.data(),
                static_cast<int>(InputString.size()),
                &OutputString[0],
                OutputStringLength,
                nullptr,
                nullptr);
            OutputString.resize(OutputStringLength);
        }

        return OutputString;
    }
}

int wmain(int argc, wchar_t** argv)
{
    std::vector<std::string> utf8_strings;
    std::vector<char*> utf8_argv;

    for (int i = 0; i < argc; ++i)
    {
        utf8_strings.push_back(::ToMultiByteString(CP_UTF8, argv[i]));
        utf8_argv.push_back(const_cast<char*>(utf8_strings[i].c_str())); 
    }
    utf8_argv.push_back(nullptr);

    return aria2_main(argc, &utf8_argv[0]);
}
