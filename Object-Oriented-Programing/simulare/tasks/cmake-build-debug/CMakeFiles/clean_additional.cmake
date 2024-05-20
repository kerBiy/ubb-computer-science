# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/tasks_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tasks_autogen.dir/ParseCache.txt"
  "tasks_autogen"
  )
endif()
