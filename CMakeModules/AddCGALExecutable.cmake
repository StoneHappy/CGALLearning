macro(AddCGALExecutable exeName src)
    add_executable(${exeName}
                                    ${src}
    )

    target_link_libraries(${exeName}
                            PUBLIC
                                CGAL::CGAL CGAL::CGAL_Core
                                Core
    )

    target_include_directories(${exeName}
                            PUBLIC
                                ${CMAKE_SOURCE_DIR}
    )
    message("Add exe :${exeName}")
endmacro()