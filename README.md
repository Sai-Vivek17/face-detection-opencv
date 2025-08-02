Real-Time Face Detection with OpenCV
https://img.shields.io/badge/OpenCV-5.0%252B-blue
https://img.shields.io/badge/License-MIT-green
https://img.shields.io/badge/C%252B%252B-17-red

A robust C++ implementation of real-time face detection using OpenCV's Haar Cascade classifier. Designed for both educational purposes and practical computer vision applications.

Table of Contents
Features

Installation

Usage

Project Structure

Technical Details

Troubleshooting

Future Improvements

License

🌟 Features
Real-time face detection from webcam or video files

Dual-classifier system (faces and eyes)

Adjustable detection parameters

Cross-platform compatibility

Clean, well-documented codebase

💻 Installation
Prerequisites
OpenCV 4.x or newer

C++17 compatible compiler

CMake 3.10+

Step-by-Step Setup
Clone the repository:

bash
git clone https://github.com/your-username/face-detection-opencv.git
cd face-detection-opencv
Build the project:

bash
mkdir build && cd build
cmake ..
make
Install OpenCV (if not installed):

bash
# Ubuntu/Debian
sudo apt install libopencv-dev

# MacOS
brew install opencv
🚀 Usage
bash
# For webcam detection (default)
./face_detector

# For video file processing
./face_detector path/to/video.mp4

# Command line controls:
# Q - Quit application
# +/- - Adjust detection scale
📂 Project Structure
text
.
├── CMakeLists.txt           # Build configuration
├── LICENSE
├── README.md
├── models/                  # Haar Cascade models
│   ├── haarcascade_eye_tree_eyeglasses.xml
│   └── haarcascade_frontalcatface.xml
└── src/
    └── face_detector.cpp    # Core detection logic
🔧 Technical Details
Detection Pipeline
Frame capture → Grayscale conversion → Histogram equalization

Multi-scale detection using Haar features

Post-processing with non-maximum suppression

Visualization with bounding circles

Key Parameters
scale=1.1: Detection scale factor

minNeighbors=3: Minimum neighbors for detection

minSize=(30,30): Minimum object size

🛠 Troubleshooting
Common Issues
Cascade files not found:

Verify XML files are in models/ directory

Use absolute paths if needed during development

Webcam not opening:

Check camera permissions

Try different video sources (e.g., cv::VideoCapture(1))

OpenCV linking errors:

bash
sudo apt install pkg-config
pkg-config --modversion opencv4
🚧 Future Improvements
Implement face recognition

Add GPU acceleration

Develop GUI controls

Support multiple face tracking

📜 License
This project is licensed under the MIT License - see the LICENSE file for details.
