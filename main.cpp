#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp> 

using namespace std;

void showMatrix(const vector<vector<int>>& matrix){
    ofstream fout("output.txt");
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
}

void checkImgValue(const cv::Mat& img, vector<vector<int>>& matrix){
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            cv::Vec3b pixel =img.at<cv::Vec3b>(i, j);
            int b = pixel[0];
            int g = pixel[1];
            int r = pixel[2];

            if (r > 240 && g > 240 && b > 240) {
                matrix[i][j] = 0;
            }
            else if(r > g && r > b){
                matrix[i][j] = 1;
            }
            else if(b > g && b > r){
                matrix[i][j] = 2;
            }
            else if(g > b && g > r){
                matrix[i][j] = 3;
            }
            

        }
    }
}

int main() {
    cv::Mat img = cv::imread("test1.jpg", cv::IMREAD_COLOR);
    int n = img.rows, m = img.cols;

    // 1 = red, 2 = blue, 3 = green, 0 = bg
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    checkImgValue(img, matrix);
    showMatrix(matrix);

    return 0;
}









// https://opencv.org/read-display-and-write-an-image-using-opencv/#h-import-cv2