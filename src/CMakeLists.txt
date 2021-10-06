set(LIBRARY_NAME "libtinycompiler")
set(EXEC_NAME "tinycompiler")

include(GenerateExportHeader)

set(Header_Files
        "asm.h"
        "ast.h"
        "codes.h"
        "defs.h"
        "func.h"
        "gen.h"
        "input.h"
        "lex.h"
        "parser.h"
        "stack.h"
        "sym.h"
        "vm.h"
)
source_group("Header Files" FILES "${Header_Files}" "${_export_file}")

set(Source_Files
        "asm.c"
        "ast.c"
        "func.c"
        "gen.c"
        "input.c"
        "lex.c"
        "parser.c"
        "stack.c"
        "sym.c"
        "vm.c"
)
source_group("Source Files" FILES "${Source_Files}" "main.c")

add_library("${LIBRARY_NAME}" "${Header_Files}" "${_export_file}" "${Source_Files}")

set(_export_file "${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_NAME}_export.h")
generate_export_header("${LIBRARY_NAME}" EXPORT_FILE_NAME "${_export_file}")

target_include_directories(
        "${LIBRARY_NAME}"
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:include>"
)
set_target_properties(
        "${LIBRARY_NAME}"
        PROPERTIES
        LINKER_LANGUAGE
        C
)

# install rules
set(installable_libs "${LIBRARY_NAME}" "${PROJECT_NAME}_compiler_flags")
install(FILES "${Header_Files}" DESTINATION "include")


set(Source_Files "main.c")
source_group("${EXEC_NAME} Source Files" FILES "${Source_Files}")

add_executable("${EXEC_NAME}" "${Source_Files}")
target_link_libraries("${EXEC_NAME}" PRIVATE "${LIBRARY_NAME}")

target_include_directories(
        "${EXEC_NAME}"
        PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:include>"
)
set_target_properties(
        "${EXEC_NAME}"
        PROPERTIES
        LINKER_LANGUAGE
        C
)

# setup the version numbering
set_property(TARGET "${LIBRARY_NAME}" PROPERTY VERSION "1.0.0")
set_property(TARGET "${LIBRARY_NAME}" PROPERTY SOVERSION "1")

# install rules
set(installable_libs "${LIBRARY_NAME}" "${EXEC_NAME}" "${PROJECT_NAME}_compiler_flags")
if (TARGET "${DEPENDANT_LIBRARY}")
    list(APPEND installable_libs "${DEPENDANT_LIBRARY}")
endif ()

install(TARGETS ${installable_libs}
        DESTINATION "${INSTALL_DEST}"
        EXPORT "${LIBRARY_NAME}Targets")
install(FILES "${_export_file}" "${Header_Files}" DESTINATION "include")
