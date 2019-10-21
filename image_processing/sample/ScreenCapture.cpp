//g++ ScreenCapture.cpp -lX11 `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstdint>
#include <cstring>
#include <vector>

using namespace cv;

struct screenCapture
{
  Display* display;
  Window root;
  int startingPosition_X,startingPosition_Y,windowWidth,windowHeight;
  XImage* image;
  bool created;
  //constructor
  screenCapture(int startingPosition_X, int startingPosition_Y, int windowWidth, int windowHeight):
  startingPosition_X(startingPosition_X),
  startingPosition_Y(startingPosition_Y),
  windowWidth(windowWidth),
  windowHeight(windowHeight)
  {
    //connect to X server
    display = XOpenDisplay(NULL);
    // returns the current window to display
    root = DefaultRootWindow(display);
    //window is created successfully
    created = true;
  }

  void operator() (Mat& openCVImage)
  {
    if(created){
      created = false;
    }
    else{
      XDestroyImage(image);
    }
    //XImage structure with specified window width, height, starting X & Y position
    image = XGetImage(display, root, startingPosition_X, startingPosition_Y, windowWidth, windowHeight, AllPlanes, ZPixmap);
    //creates a Mat object
    openCVImage = Mat(windowHeight, windowWidth, CV_8UC4, image->data);
  }

  //deconstructor
  ~screenCapture()
  {
    if(!created){
      //deallocates the memory
      XDestroyImage(image);
    }
    //closes the connection to the x server
    XCloseDisplay(display);
  }


};

int main()
{

  while(1){
    screenCapture screen(0,0,1400,700);
    Mat image;
    screen(image);
    imshow("image", image);
    waitKey(1);
}

}
