//
// Created by cym on 2019/7/18.
//


#include <jni.h>
#include <stdio.h>

#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_mobile_ccalljava_JNI_callbackAdd
(JNIEnv * env, jobject jobj){
    //1、得到字节码
    jclass  jclazz = (*env)->FindClass(env,"com/mobile/ccalljava/JNI");
    //2、得到方法
    //最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env,jclazz,"add","(II)I");
    jobject  jobject = (*env)->AllocObject(env,jclazz);
    //3、实例化该类
    jint value = (*env)->CallIntMethod(env,jobject,jmethodIDs,99,1);
    printf("value=====%d",value);
    LOGE("value===%d\n",value);
    //4、调用方法
}


JNIEXPORT void JNICALL Java_com_mobile_ccalljava_JNI_callbackHelloFromJava
        (JNIEnv * env, jobject jobj){
    //1、得到字节码
    jclass  jclazz = (*env)->FindClass(env,"com/mobile/ccalljava/JNI");
    //2、得到方法
    //最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env,jclazz,"helloFromJava","()V");
    jobject  jobject = (*env)->AllocObject(env,jclazz);
    //3、实例化该类
    (*env)->CallVoidMethod(env,jobject,jmethodIDs);
}

JNIEXPORT void JNICALL Java_com_mobile_ccalljava_JNI_callbackPrintString
        (JNIEnv * env, jobject jobj){
    //1、得到字节码
    jclass  jclazz = (*env)->FindClass(env,"com/mobile/ccalljava/JNI");
    //2、得到方法
    //最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env,jclazz,"printString","(Ljava/lang/String;)V");
    jobject  jobject = (*env)->AllocObject(env,jclazz);
    //3、实例化该类
    jstring jst = (**env).NewStringUTF(env,"I am cym!!!");
    (*env)->CallVoidMethod(env,jobject,jmethodIDs,jst);
}

JNIEXPORT void JNICALL Java_com_mobile_ccalljava_JNI_callbackSayHello
        (JNIEnv * env, jobject jobj){
    //1、得到字节码
    jclass  jclazz = (*env)->FindClass(env,"com/mobile/ccalljava/JNI");
    //2、得到方法
    //最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetStaticMethodID(env,jclazz,"sayHello","(Ljava/lang/String;)V");
    jstring jst = (*env)->NewStringUTF(env,"I am android");
    (*env)->CallStaticVoidMethod(env,jclazz,jmethodIDs,jst);
}

JNIEXPORT void JNICALL
Java_com_mobile_ccalljava_MainActivity_callbackShowToast(JNIEnv *env, jobject instance) {

    //1、得到字节码
    jclass  jclazz = (*env)->FindClass(env,"com/mobile/ccalljava/MainActivity");
    //2、得到方法
    //最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env,jclazz,"showToast","()V");
    //3、实例化该类
//    jobject  jobject = (*env)->AllocObject(env,jclazz);
    //4、调用方法
    (*env)->CallVoidMethod(env,instance,jmethodIDs);
}

