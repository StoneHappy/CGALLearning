macro(AddCGALExecutable exeName src)
    add_executable(${exeName}
                                    ${src}
    )

    target_link_libraries(${exeName}
                            PUBLIC
                                CGAL::CGAL CGAL::CGAL_Core
    )
    message("Add exe :${exeName}")
endmacro()