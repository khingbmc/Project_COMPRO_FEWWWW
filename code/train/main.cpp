#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/face.hpp"
#include <stdio.h>

using namespace cv;


//define recognizer
Ptr<face::FaceRecognizer> rec = createLBPHFaceRecognizer();

int getImage(){
    char imgpath[21][100];
    int i;
    for(i=1;i<21;i++){
        char path[100];
        sprintf(path, "../create_training/user/user%d.jpg", i);
        imgpath[i] = path;
    }
    return 0;
}
