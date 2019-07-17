//
// Created by cym on 2019/7/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <string.h>

jstring Java_com_mobile_ndkproject_JNI_sayHello(JNIEnv* env,jobject jobj){

    char* text = "I am from c";
    return (*env)->NewStringUTF(env,text);
}

jint Java_com_mobile_ndkproject_JNI_add(JNIEnv *env, jobject instance, jint x, jint y) {
    int result = x + y;
    return result;
}

JNIEXPORT jintArray JNICALL
Java_com_mobile_ndkproject_JNI_increaseArrayEles(JNIEnv *env, jobject instance,
                                                 jintArray intArray_) {
    //1、得到数组的长度
    jint size = (*env)->GetArrayLength(env,intArray_);
    //2、得到数组元素
    jint *intArray = (*env)->GetIntArrayElements(env, intArray_, JNI_FALSE);
    //3、遍历数组，给每个元素加上10
    for (int i = 0; i < size; ++i) {
        *(intArray+i) += 10;
    }
    //4、返回结果
    return intArray_;
}

JNIEXPORT jint JNICALL
Java_com_mobile_ndkproject_JNI_checkPwd(JNIEnv *env, jobject instance, jstring pwd_) {
    const char *pwd = (*env)->GetStringUTFChars(env, pwd_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, pwd_, pwd);
}

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}

jstring Java_com_mobile_ndkproject_JNI_dealStr(JNIEnv *env, jobject instance, jstring s_) {

    char* fromJava = _JString2CStr(env,s_);
    char* fromC = "add I am from C";
    strcat(fromJava,fromC);//把拼接的结果放在第一个参数里面

    return (*env)->NewStringUTF(env, fromJava);
}

