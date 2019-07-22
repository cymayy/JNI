//
// Created by cym on 2019/7/18.
//


#include <jni.h>
#include <stdio.h>

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
    //4、调用方法

    const char *chars = "mNativeContext";
    const char *chars2 = "J";
    jfieldID  context = (*env)->GetFieldID(env,jclazz,chars,chars2);
}

