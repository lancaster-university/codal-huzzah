project(codal-huzzah)

include("${CODAL_UTILS_LOCATION}")

# find sources and headers
RECURSIVE_FIND_DIR(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/inc" "*.h")
RECURSIVE_FIND_FILE(SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source" "*.c??")

# set linker script here....
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -T\"${CMAKE_CURRENT_SOURCE_DIR}/ld/esp8266-app.ld\"" PARENT_SCOPE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T\"${CMAKE_CURRENT_SOURCE_DIR}/ld/esp8266-app.ld\"" PARENT_SCOPE)

# set processor type if required...
#set(CMAKE_SYSTEM_PROCESSOR "armv7-m" PARENT_SCOPE)

# add them
include_directories(${INCLUDE_DIRS})

# create our target
add_library(codal-huzzah ${SOURCE_FILES})

target_link_libraries(
    codal-huzzah
    codal-esp8266
)

# expose it to parent cmake.
target_include_directories(codal-huzzah PUBLIC ${INCLUDE_DIRS})
