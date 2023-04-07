# Mile.Aria2 Release Notes

**Mile.Aria2 1.0 (1.0.8.0)**

- Improve Windows version detection and display. (Contributed by ElemenTP.)
- Fix the TLS renegotiation handling. (Contributed by ElemenTP.)
- Add TLS 1.3 support for WinTLS backend. (Contributed by ElemenTP.)
- Adjust target framework setting for NuGet package. (Thanks to 高怡飞.)

**Mile.Aria2 1.0 (1.0.7.0)**

- Fix command line parsing issue.
- Make NuGet package support .NET platform.

**Mile.Aria2 1.0 (1.0.6.0)**

- Remove the GMP dependency.
- Update third-party dependencies.
- Update the manifest definition.
- Add NuGet packaging support.

**Mile.Aria2 1.0 (1.0.5.0)**

- Remove the CommandLineToArgvW API dependency. (Suggested by Bas Timmer and
  Rafael Rivera.)
- Make 64-Bit a2_off_t to fix the maximum 4GB file limitation.
- Use MinGW's getopt_long implementation instead of PostgreSQL‘s to resolve the
  command line parsing issues. (Thanks to 高怡飞.)

**Mile.Aria2 1.0 (1.0.3.0)**

- Initial release.
- Inherited all features provided in the official Windows binaries from aria2
  1.36.0.
- Use VC-LTL 5.x toolchain to make the binary size smaller.
