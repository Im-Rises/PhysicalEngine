@echo off

REM Delete CMake cache directories and files in the current directory and all subdirectories

REM Define array of files and directories to delete
set "to_delete=CMakeCache.txt* CMakeLists.txt.user CMakeFiles CMakeScripts Testing Makefile cmake_install.cmake install_manifest.txt compile_commands.json CTestTestfile.cmake _deps .cmake *.cbp cmake-build-*"

REM Loop through array and delete files and directories
for %%a in (%to_delete%) do (
  for /d /r %%b in (*) do (
    if exist "%%b\%%a" (
      del /f /s /q "%%b\%%a" >nul 2>&1
      rd /s /q "%%b\%%a" >nul 2>&1
    )
  )
  for /r %%c in ("%%a") do (
    del /f /s /q "%%c" >nul 2>&1
    rd /s /q "%%c" >nul 2>&1
  )
)
