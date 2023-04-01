# Mile.Aria2.Dependencies

Prebuilt binaries for aria2 dependencies

## Build

Note: You can do some modifications for vcpkg libssh package for using Secure
Channel instead of OpenSSL like me.

```
vcpkg install zlib:x86-windows-static zlib:x64-windows-static zlib:arm-windows-static zlib:arm64-windows-static
vcpkg install sqlite3[zlib]:x86-windows-static sqlite3[zlib]:x64-windows-static sqlite3[zlib]:arm-windows-static sqlite3[zlib]:arm64-windows-static
vcpkg install c-ares:x86-windows-static c-ares:x64-windows-static c-ares:arm-windows-static c-ares:arm64-windows-static
vcpkg install expat:x86-windows-static expat:x64-windows-static expat:arm-windows-static expat:arm64-windows-static
vcpkg install gmp:x86-windows-static gmp:x64-windows-static gmp:arm-windows-static gmp:arm64-windows-static
vcpkg install libssh2:x86-windows-static libssh2:x64-windows-static libssh2:arm-windows-static libssh2:arm64-windows-static
```
