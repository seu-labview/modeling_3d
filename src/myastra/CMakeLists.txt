set(SUB_PROJNAME myastra)

# Astra
include_directories($ENV{ASTRA_SDK_INCLUDE})
# message("include $ENV{ASTRA_SDK_INCLUDE}!")
link_directories($ENV{ASTRA_SDK_LIB})
set(ASTRA_LIBS libastra.so libastra_core.so libastra_core_api.so)

set(${SUB_PROJNAME}_SOURCES main.cpp ColorListener.cpp DepthListener.cpp)
add_executable(${SUB_PROJNAME} ${${SUB_PROJNAME}_SOURCES})

target_link_libraries(${SUB_PROJNAME} ${OpenCV_LIBS} ${ASTRA_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
