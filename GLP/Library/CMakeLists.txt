file(GLOB_RECURSE SOURCES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.cpp"
    "*.h"
    "*.hh"
)

add_library(glp SHARED ${SOURCES})
set_target_properties(glp PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(glp PROPERTIES VERSION ${GLP_VERSION_MAJOR}.${GLP_VERSION_MINOR} SOVERSION ${GLP_VERSION_MAJOR})

add_library(glp_static STATIC ${SOURCES})
set_target_properties(glp_static PROPERTIES OUTPUT_NAME "glp")
set_target_properties(glp_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

install(TARGETS glp glp_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include
        FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hh")
