#!/usr/bin/env bash

# Delete CMake cache directories and files in the current directory and all subdirectories

# Define array of files and directories to delete
declare -a to_delete=(
  "CMakeCache.txt*"
  "CMakeLists.txt.user"
  "CMakeFiles"
  "CMakeScripts"
  "Testing"
  "Makefile"
  "cmake_install.cmake"
  "install_manifest.txt"
  "compile_commands.json"
  "CTestTestfile.cmake"
  "_deps"
  ".cmake"
  "*.cbp"
  "cmake-build-*"
)

# Loop through array and delete files and directories
for pattern in "${to_delete[@]}"
do
  find . -type f -name "${pattern}" -delete -o -type d -name "${pattern}" -exec rm -rf {} \; # -prune
done
