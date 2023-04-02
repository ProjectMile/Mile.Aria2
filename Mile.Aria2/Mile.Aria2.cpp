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

int main(int argc, char** argv)
{
    return aria2_main(argc, argv);
}
