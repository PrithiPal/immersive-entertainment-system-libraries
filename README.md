# gaming-libraries

Header files and libraries shared by the programs used for both the HOST and TARGET pc.

## Opencv setup :

1.  Install the OpenCV2 on linux (build from source can take time).   
    1. Useful Links  
	   1. https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html  
	   2. https://stackoverflow.com/a/44488374  
2. `apt-get install libopencv-dev`
3.  `cd image_processing`
Defacto project name. If want to change, change this directory and change project() argument in sample/CMakeLists.txt
4.  `cmake .`
   Compile all the Build files.
   Succesfull compilation looks like this :

```shell
> flags are
> CMAKE_BINARY_DIR = /Users/prithipalsingh/desktop/beagle_host/project/gaming-libraries/image_processing
>

> -- The C compiler identification is AppleClang 10.0.1.10010046
> -- The CXX compiler identification is AppleClang 10.0.1.10010046
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
> -- works
> -- Detecting C compiler ABI info
> -- Detecting C compiler ABI info - done
> -- Detecting C compile features
> -- Detecting C compile features - done
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
> -- works
> -- Detecting CXX compiler ABI info
> -- Detecting CXX compiler ABI info - done
> -- Detecting CXX compile features
> -- Detecting CXX compile features - done
> -- Found OpenCV: /usr/local (found version "3.2.0")
> -- Found PkgConfig: /usr/local/bin/pkg-config (found version "0.29.2")
>
> File : code/DisplayImage
> File : code/ModifyImage
> -- Configuring done
> -- Generating done
> -- Build files have been written to: /Users/prithipalsingh/desktop/beagle_host/project/gaming-libraries/image_processing
```

5.  `make`
	compiles all the executables under `NORMAL FILES `. Successfull compilation look likes this :
```shell
> 	Scanning dependencies of target ModifyImage
> [ 25%] Building CXX object
> CMakeFiles/ModifyImage.dir/code/ModifyImage.cpp.o
> clang: warning: -lX11: 'linker' input unused
> [-Wunused-command-line-argument]
> [ 50%] Linking CXX executable executable/ModifyImage
> [ 50%] Built target ModifyImage
> Scanning dependencies of target DisplayImage
> [ 75%] Building CXX object
> CMakeFiles/DisplayImage.dir/code/DisplayImage.cpp.o
> clang: warning: -lX11: 'linker' input unused
> [-Wunused-command-line-argument]
> [100%] Linking CXX executable executable/DisplayImage
> [100%] Built target DisplayImage
```

6.  `make [TARGET_FILE_NAME]`
	compiles custom target files. For instance `make ScreenCapture`


`NORMAL FILES`:
 DisplayImage
 ModifyImage

 `TARGET_FILE_NAME` :
  ScreenCapture

**Note** : DisplayImage,ModifyImage are example codes from docs.opencv.org/2.4/doc/tutorials/introduction

**File-Structure**
1. ./CMakeLists.txt : Configuration for the project including directories, compilation and library bindings.
1. ./code/ : all the C++/C code for testing.
2. ./executable/ : all the executables from code/ formed here.

**Troubleshooting**
1.When doing `cmake .` inside image_processing dir, you encouter err message such as

>CMake Error: The current CMakeCache.txt directory /home/prithi/Desktop/mac/beagle_host/project/gaming-libraries/image_processing2/CMakeCache.txt is different than the directory /home/prithi/Desktop/mac/beagle_host/project/gaming-libraries/image_processing where CMakeCache.txt was created. This may result in binaries being created in the wrong place. If you are not sure, reedit the CMakeCache.txt

It probably arises because the name of parent directory is change or the path has been changed. If name is changed, then change the `project (image_processing)` in CMakeLists.txt to new name. Otherwise, just clear CMakeCache.txt (`rm CMakeCache.txt`) and then `cmake .`

**Useful Links** :

 - OpenCV here [https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html](https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html)
 - Main Opencv docs : [https://docs.opencv.org/4.1.1/](https://docs.opencv.org/4.1.1/)
 - Good tutorials : https://www.pyimagesearch.com/start-here/
 -  Cross compilation for ARM : https://docs.opencv.org/2.4/doc/tutorials/introduction/crosscompilation/arm_crosscompile_with_cmake.html]
 -  CMake introduction : [https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b](https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b)
 - CMake style : [https://community.kde.org/Policies/CMake_Coding_Style](https://community.kde.org/Policies/CMake_Coding_Style)
