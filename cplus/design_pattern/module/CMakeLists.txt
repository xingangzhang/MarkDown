file(GLOB_RECURSE design_pattern_files_header include/*.hpp include/*.h)
file(GLOB_RECURSE design_pattern_files_cpp source/*.cpp source/*.c)

add_library(design_pattern_module ${design_pattern_files_header} ${design_pattern_files_cpp})

target_include_directories(design_pattern_module PUBLIC include)
