
# Opencv setup :

1.  Install the OpenCV2 on linux (build from source can take time). Useful Link : [https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html](https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html)
2. `sudo apt-get install libopencv-dev cmake`

3.  `cd sample`
Defacto project name. If want to change, change this directory and change project() argument in sample/CMakeLists.txt

4.  `cmake .`
   Compile all the Build files

5.  `make`
	compiles all the executables under `NORMAL FILES `

6.  `make [TARGET_FILE_NAME]`
	compiles custom target files. For instance `make ScreenCapture`


`NORMAL FLAGS`:
 DisplayImage
 ModifyImage
 `TARGET_FILE_NAME` :
  ScreenCapture

**Note** : DisplayImage,ModifyImage are example codes from docs.opencv.org/2.4/doc/tutorials/introduction

**Useful Links** :

 - OpenCV here [https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html](https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html)
 - Main Opencv docs : [https://docs.opencv.org/4.1.1/](https://docs.opencv.org/4.1.1/)
 - Good tutorials : https://www.pyimagesearch.com/start-here/
 -  Cross compilation for ARM : https://docs.opencv.org/2.4/doc/tutorials/introduction/crosscompilation/arm_crosscompile_with_cmake.html]
 -  CMake introduction : [https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b](https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b)
 - CMake style : [https://community.kde.org/Policies/CMake_Coding_Style](https://community.kde.org/Policies/CMake_Coding_Style)
