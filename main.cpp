#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int new_width = 300;
int new_height = 400;
int threshold_value = 128;
//https://opencv.org/blog/resizing-and-rescaling-images-with-opencv/
//https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html
//https://docs.opencv.org/4.x/d7/d4d/tutorial_py_thresholding.html
void thresold_transfer(Mat image)
{
    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            (
                0.114 * image.at<Vec3b>(i, j)[0] +
                0.587 * image.at<Vec3b>(i, j)[1] +
                0.299 * image.at<Vec3b>(i, j)[2]) >
                (threshold_value) ? image.at<Vec3b>(i, j) = Vec3b(255, 255, 255) : image.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
        }
    }
}

int main() {
    using namespace std;
    using namespace std::chrono;
    auto start = high_resolution_clock::now();//Program zamanlayýcýsý baþlatýr

    Mat image = imread("C:/Users/mrshn/Desktop/Parrot.jpg");
    //Dosyayý klasör üzerinden okur 
    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }
    
    Mat resized_image;
    
	resize(image, resized_image, Size(new_width, new_height));
    //okunmuþ resmi boyutlandýrýr 
    thresold_transfer(resized_image);
    //grayscale ölçeðine göre boyutlanmýþ bir resmin parlaklýk referansýna göre beyaz mý siyah mý olacaðýný belirler
	imshow("Resized Image", resized_image);
    //ekranda resmi gösterir
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    //Programýn çalýþma süresini hesaplar
    cout << "Program Time : " << duration << " ms" << endl;
    waitKey(0);
    return 0;
}

