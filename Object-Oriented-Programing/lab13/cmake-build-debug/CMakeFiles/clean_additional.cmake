# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/lab13_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/lab13_autogen.dir/ParseCache.txt"
  "lab13_autogen"
  )
endif()
