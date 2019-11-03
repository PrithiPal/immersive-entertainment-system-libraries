# gaming-libraries

Header files and libraries shared by the programs used for both the HOST and TARGET pc.

## Opencv setup :

1.  Install the OpenCV2 on linux (build from source can take time).   
    1. Useful Links  
	   1. https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html  
	   2. https://stackoverflow.com/a/44488374  
2. `apt-get install libopencv-dev`
3.  `./build.sh`
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

### To specify a specific target
```shell
cd build
make <target_file_name>
```
targets to specify:
 - ScreenCapture


**Note** : DisplayImage,ModifyImage are example codes from docs.opencv.org/2.4/doc/tutorials/introduction

**File-Structure**
1. ./CMakeLists.txt : Configuration for the project including directories, compilation and library bindings.
1. ./source_code/ : all the C++/C code for testing.
2. ./build/executable/ : all the executables from code/ formed here.

**Useful Links** :

 - OpenCV here [https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html](https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html)
 - Main Opencv docs : [https://docs.opencv.org/4.1.1/](https://docs.opencv.org/4.1.1/)
 - Good tutorials : https://www.pyimagesearch.com/start-here/
 -  Cross compilation for ARM : https://docs.opencv.org/2.4/doc/tutorials/introduction/crosscompilation/arm_crosscompile_with_cmake.html]
 -  CMake introduction : [https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b](https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b)
 - CMake style : [https://community.kde.org/Policies/CMake_Coding_Style](https://community.kde.org/Policies/CMake_Coding_Style)
