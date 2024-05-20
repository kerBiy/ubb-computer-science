# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/produse_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/produse_autogen.dir/ParseCache.txt"
  "produse_autogen"
  )
endif()
