# 0------------------------ SYSTEM INFORMATION  ------------------------
message("prefix is ${CMAKE_INSTALL_PREFIX}")
message("flags are ${CMAKE_CXX_FLAGS}")
message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message("${OpenCV_LIBS}")
# ------------------------ SETTING EXECUTABLE FILES  -------------------------
set(FILENAMES
    DisplayImage
    ModifyImage
    Meanshift
    )
# ------------------------ SETTING COMPILATION OPTIONS  -------------------------
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/executable)
set(CODEDIR source_code)
set(EXECUTABLEDIR executables)
set(DATADIR image_data )
cmake_minimum_required(VERSION 2.8)
project( image_processing )
find_package( OpenCV REQUIRED )
find_package( PkgConfig REQUIRED )
# ------------------------ COMPILERS SETUP --------------------------
add_compile_options("-lX11")
# ------------------------ FILES SETUP --------------------------
foreach(X IN LISTS FILENAMES)
	message("File : ${CODEDIR}/${X}")
	add_executable( ${X} ${CODEDIR}/${X}.cpp )
	target_link_libraries( ${X} ${OpenCV_LIBS} )
endforeach()
set(SCREENCAPTURE_FILE ScreenCapture)
add_custom_target(
  ${SCREENCAPTURE_FILE}
  COMMAND g++ ${CODEDIR}/${SCREENCAPTURE_FILE}.cpp -lX11 -o ${EXECUTABLE_OUTPUT_PATH}/${SCREENCAPTURE_FILE} `pkg-config --cflags opencv` `pkg-config --libs opencv`
  COMMENT "compiling ScreenCapture.cpp"
  DEPENDS ${CODEDIR}/${SCREENCAPTURE_FILE}.cpp
)
