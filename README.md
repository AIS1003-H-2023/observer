# Separating concerns

This is a standalone demo project that uses `threepp` as a dependency 
through a custom [vcpkg](https://vcpkg.io/en/index.html) registry located [here](https://github.com/Ecos-platform/vcpkg-registry).

### Building
As `vcpkg` is used, you need to tell CMake about it in order for dependency resolution to work: 

`-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`

###### Building under MinGW

Under MinGW you'll need to additionally specify the vcpkg triplet:
```shell
-DVCPKG_TARGET_TRIPLET=x64-mingw-[static|dynamic]  # choose either `static` or `dynamic`.
-DVCPKG_HOST_TRIPLET=x64-mingw-[static|dynamic]    # <-- needed only if MSVC cannot be found. 
```
