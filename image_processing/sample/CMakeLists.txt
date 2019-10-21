# 0------------------------ USUAL SETUP ------------------------
message("prefix is ${CMAKE_INSTALL_PREFIX}")
message("flags are ${CMAKE_CXX_FLAGS}")
message("${OpenCV_LIBS}")
set(FILENAMES DisplayImage ModifyImage)
cmake_minimum_required(VERSION 2.8)
project( sample )
find_package( OpenCV REQUIRED )
find_package( PkgConfig REQUIRED )

# ------------------------ COMPILERS SETUP --------------------------
add_compile_options("-lX11")
# ------------------------ FILES SETUP --------------------------
foreach(X IN LISTS FILENAMES)
	message("File : ${X}")
	add_executable( ${X} ${X}.cpp )
	target_link_libraries( ${X} ${OpenCV_LIBS} )
endforeach()
set(SCREENCAPTURE_FILE ScreenCapture)
add_custom_target(
  ${SCREENCAPTURE_FILE}
  COMMAND g++ ${SCREENCAPTURE_FILE}.cpp -lX11 -o ${SCREENCAPTURE_FILE} `pkg-config --cflags opencv` `pkg-config --libs opencv`
  COMMENT "compiling ScreenCapture.cpp"
  DEPENDS ${SCREENCAPTURE_FILE}.cpp
)
