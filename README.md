# Real-Time Face Detection with OpenCV

A C++ program that detects faces in real-time using OpenCV's Haar Cascade classifier.

## Features
- Real-time detection from webcam or video
- Adjustable detection parameters
- Visual feedback with circles around faces

## How to Run
1. Install OpenCV:
   ```bash
   # For Ubuntu/Debian:
   sudo apt install libopencv-dev
   ```
2. Compile & run:
   ```bash
   g++ face_detector.cpp -o detector `pkg-config --cflags --libs opencv4`
   ./detector
   ```

## Project Structure
- `face_detector.cpp` - Main detection code
- `models/` - Contains Haar Cascade XML files

## Future Improvements
- Add face recognition
- Improve performance with GPU

## License
MIT License - Free to use and modify
