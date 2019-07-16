package com.mobile.ndkproject;

public class JNI {

    static {
        System.loadLibrary("native-lib");
    }

    public native String sayHello();
}
