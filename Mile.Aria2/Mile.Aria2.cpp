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

#include <array>

int main(int argc, char** argv)
{
    //std::array<unsigned char, 16384> buf_;

    //auto x = std::end(buf_)._Unwrapped();


    return aria2_main(argc, argv);
}
