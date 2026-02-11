# Mile.Aria2.Dependencies

Prebuilt binaries for aria2 dependencies

Libraries: zlib/1.3.1 expat/2.7.4 sqlite3/3.51.2 c-ares/1.34.6 libssh2/1.11.1_DEV

## Build

```
vcpkg install zlib:x86-windows-static zlib:x64-windows-static zlib:arm64-windows-static
vcpkg install sqlite3[zlib]:x86-windows-static sqlite3[zlib]:x64-windows-static sqlite3[zlib]:arm64-windows-static
vcpkg install c-ares:x86-windows-static c-ares:x64-windows-static c-ares:arm64-windows-static
vcpkg install expat:x86-windows-static expat:x64-windows-static expat:arm64-windows-static
vcpkg install libssh2[core,zlib]:x86-windows-static libssh2[core,zlib]:x64-windows-static libssh2[core,zlib]:arm64-windows-static
```
