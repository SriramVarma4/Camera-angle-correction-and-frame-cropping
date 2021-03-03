 
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
class Pt{
	public:
		int x1,y1,x2, y2, x3, y3, x4, y4;
		int n;
};

static void click( int event, int a, int b, int d, void *ptr )
{
	if (event == EVENT_LBUTTONDOWN ){
    	Pt*p = (Pt*)ptr;
    	if((p->n)==0){
    		p->x1 = a;
    		p->y1 = b;
    		cout<<"select left bottom\n";
    	}
    	else if((p->n)==1){
    		p->x2 = a;
    		p->y2 = b;
    		cout<<"select right bottom\n";
    	}else if((p->n)==2){
    		p->x3 = a;
    		p->y3 = b;
    		cout<<"select right up\n";
    	}else if((p->n)==3){
    		p->x4 = a;
    		p->y4 = b;
    		cout<<"hit esc\n";
    	}
    	p->n = (p->n)+1;
	}
}

int main( int argc, char** argv)
{
    //pass a pointer to `p` as parameter
    Pt p;
    p.n=0;
    
    // Read input image which is passed as argument.
    string infile = argv[1];
    string name = infile.substr (0,infile.length()-4);
    string proj = name + "_projected.jpg";//name of output files
    string crop = name + "_cropped.jpg";
    Mat image = imread(infile, IMREAD_GRAYSCALE);
    if ( image.empty() ) 
    { 
        cout << "Error loading the image" << endl;
        return -1; 
    }
    
    // original image window will be opened
    namedWindow("original image", WINDOW_AUTOSIZE);
    imshow("original image",image);
    
    //set the callback function for any mouse event
    setMouseCallback("original image", click, &p);
    cout<<"select left up\n";
    

    //show the image

    // Wait until user press some key
    waitKey(0);

    vector<Point2f> pts_src;
    pts_src.push_back(Point2f(p.x1, p.y1));//left up
    pts_src.push_back(Point2f(p.x2, p.y2));//left bottom
    pts_src.push_back(Point2f(p.x3, p.y3));//right bottom
    pts_src.push_back(Point2f(p.x4, p.y4));//right up
    destroyWindow("original image");
    
    // Four corners of the road in destination image.
    vector<Point2f> pts_dst;
    pts_dst.push_back(Point2f(480, 40));//left up
    pts_dst.push_back(Point2f(480, 835));//left bottom
    pts_dst.push_back(Point2f(820, 835));//right bottom
    pts_dst.push_back(Point2f(820, 40));//right up

    // Calculate Homography
    Mat h = findHomography(pts_src, pts_dst);

    // Output image
    Mat im_out = Mat(900,1300,0);
    
    // Warp source image to destination based on homography
    warpPerspective(image, im_out, h, im_out.size());
    
    // Display image

    Mat cropped = im_out(Rect(480, 40, 340, 795));

    imwrite(proj, im_out);
    namedWindow(proj, WINDOW_AUTOSIZE);
    imshow(proj, im_out);
    waitKey(0);

    imwrite(crop, cropped);
    imshow(crop, cropped);
    waitKey(0);
    destroyAllWindows();
}



//-----------------------------------------------------
