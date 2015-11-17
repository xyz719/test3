//#include "stdafx.h"
#include <opencv2/opencv.hpp>  
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  
//using namespace std;  
using namespace cv; 

int main( int argc, char** argv )  
{  
    Mat src, edge,color_edge;  
    src=imread("f:\\beauty.jpg");  
    if( !src.data )    
        return -1;    
  
    Canny(src,edge,50,200,3);  
    cvtColor( edge, color_edge, CV_GRAY2BGR );  
    vector<Vec4i> lines;  
    HoughLinesP(edge, lines, 1, CV_PI/180, 80, 30, 10 );  
    for( size_t i = 0; i < lines.size(); i++ )  
    {  
        Vec4i l = lines[i];  
        line( color_edge, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 2);  
    }    
    namedWindow( "lines", CV_WINDOW_AUTOSIZE );  
    imshow( "lines", color_edge );  
    waitKey(0);  
    return 0;  
}
