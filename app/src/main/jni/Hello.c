//
// Created by cym on 2019/7/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>

jstring Java_com_mobile_ndkproject_JNI_sayHello(JNIEnv* env,jobject jobj){

    char* text = "I am from c";
    return (*env)->NewStringUTF(env,text);
}

