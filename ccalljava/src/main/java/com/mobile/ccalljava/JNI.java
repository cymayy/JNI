package com.mobile.ccalljava;

import android.util.Log;

public class JNI {

    static {
        System.loadLibrary("ccalljava");
    }

    //当执行这个方法的时候，让c代码调用
    public native void callbackAdd();
    public native void callbackHelloFromJava();
    public native void callbackPrintString();
    public native void callbackSayHello();

    public int add(int x,int y){
        Log.e("TAG","add() x=" + x + " y=" + y);
        return x+y;
    }

    public void helloFromJava(){
        Log.e("TAG","helloFromJava()");
    }

    public void printString(String s){
        Log.e("TAG","c中输入的：" + s);
    }

    public static void sayHello(String s){
        Log.e("TAG","我是java代码中的JNI。java中的sayHello静态方法，我被C调用了" + s);
    }
}
