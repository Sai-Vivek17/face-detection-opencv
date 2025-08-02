#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void detectFace(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale);

int main() {
    VideoCapture capture;
    Mat frame, image;
    CascadeClassifier cascade, nestedCascade;
    double scale = 1;

    // Load Haar Cascade files (place these in a 'models' folder)
    nestedCascade.load("models/haarcascade_eye_tree_eyeglasses.xml");
    cascade.load("models/haarcascade_frontalcatface.xml");

    // Start webcam (0) or use a video file ("test.mp4")
    capture.open(0);  
    if (!capture.isOpened()) {
        cout << "Error: Could not open camera/video!" << endl;
        return -1;
    }

    cout << "Face Detection Started. Press 'Q' to quit." << endl;
    while (true) {
        capture >> frame;
        if (frame.empty()) break;

        Mat frameCopy = frame.clone();
        detectFace(frameCopy, cascade, nestedCascade, scale);

        if (waitKey(10) == 'q') break;
    }
    return 0;
}

void detectFace(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale) {
    vector<Rect> faces;
    Mat gray, smallImg;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    resize(gray, smallImg, Size(), 1/scale, 1/scale, INTER_LINEAR);
    equalizeHist(smallImg, smallImg);

    cascade.detectMultiScale(smallImg, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++) {
        Rect r = faces[i];
        Scalar color = Scalar(255, 0, 0); // Blue color
        Point center(r.x + r.width/2, r.y + r.height/2);
        circle(img, center, r.width/2, color, 3, 8, 0);
    }
    imshow("Face Detection", img);
}