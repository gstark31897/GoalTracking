#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int objX = 0;
int objY = 0;
string file = "";

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        objX = x;
        objY = y;
    }
    else if  ( event == EVENT_LBUTTONUP )
    {
        cout << file << " 1 " << objX << ' ' << objY << ' ' << x - objX << ' ' << y - objY << endl;
    }
}

int main(int argc, char** argv)
{
    namedWindow("Crop", 1);
    setMouseCallback("Crop", CallBackFunc, NULL);

    for (int i = 1; i < argc; ++i)
    {
        file = argv[i];
        Mat img = imread(argv[i]);
        if ( img.empty() ) 
        { 
            cout << "Error loading the image" << endl;
            return -1; 
        }

        imshow("Crop", img);
        waitKey(0);
    }
    return 0;
}
