# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/Raspi4_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Raspi4_autogen.dir/ParseCache.txt"
  "Raspi4_autogen"
  )
endif()
