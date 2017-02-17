#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

extern "C" {

using namespace cv;
using namespace std;

jintArray
Java_com_rokid_dchen23_opencv3_1demo_MainActivity_grayProc(
        JNIEnv *env,
        jobject /* this */,
        jintArray buf, jint w, jint h) {
    jboolean ptfalse = false;
    jint *srcBuf = env->GetIntArrayElements(buf, &ptfalse);
    if (srcBuf == NULL) {
        return 0;
    }
    int size = w * h;

    Mat srcImage(h, w, CV_8UC4, (unsigned char*)srcBuf);
    Mat grayImage;
    cvtColor(srcImage, grayImage, COLOR_BGRA2GRAY);
    cvtColor(grayImage, srcImage, COLOR_GRAY2BGRA);

    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, srcBuf);
    env->ReleaseIntArrayElements(buf, srcBuf, 0);

    return result;
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
}

}
