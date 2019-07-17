package com.mobile.ndkproject;

public class JNI {

    static {
        System.loadLibrary("native-lib");
    }

    public native String sayHello();

    public native int add(int x,int y);

    public native String dealStr(String s);

    public native int[] increaseArrayEles(int[] intArray);

    public native int checkPwd(String pwd);
}
