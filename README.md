# CGALLearning
学习CGAL

## 依赖工具
[vcpkg](https://github.com/microsoft/vcpkg)

visual studio

visual studio code:

    cmake tools插件
    cmake插件

cmake 工具

## 安装cgal
``x64-windows-static``具体平台可以自己指定
```bash
vcpkg install cgal[qt]:x64-windows-static
```

## cmake预定义
```json
"cmake.configureArgs": ["-DCMAKE_TOOLCHAIN_FILE=D:/codes/vcpkg/scripts/buildsystems/vcpkg.cmake", 
        "-DVCPKG_TARGET_TRIPLET=x64-windows-static",
        "-DVCPKG_INCLUDE_DIR=D:/codes/vcpkg/installed/x64-windows-static/include",
        "-DCGAL_DATA=D:/codes/cgal/Data/data",
        "-DTEST_DATA_DIR=D:/codes/Editor/Resources/Models/",
    ]
```
