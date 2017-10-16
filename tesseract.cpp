#include "tesseract.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <fstream>
using namespace std;

void doit()
{
    char *outText;
    const char *path="/home/namdo/Downloads";
    std::ofstream myfile(path);

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
            fprintf(stderr, "Could not initialize tesseract.\n");
            exit(1);
    }
    myfile.open("result.txt");

    // Open input image with leptonica library
    Pix *image = pixRead("/home/namdo/build-LabelScanner-Desktop_Qt_5_7_0_GCC_64bit-Debug/Label/img.png");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
   //printf("OCR output:\n%s", outText);
    myfile<<outText;
    // Destroy used object and release memory
    api->End();
    myfile.close();
    delete [] outText;
    pixDestroy(&image);
}
