package com.mobile.ccalljava;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {

    private JNI jni;

    public native void callbackShowToast();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jni = new JNI();
    }

    public void onClick(View view){
//        jni.callbackAdd();
//        jni.callbackHelloFromJava();
//        jni.callbackPrintString();
//        jni.callbackSayHello();
        callbackShowToast();
    }

    public void showToast(){
        System.out.println("showToast============");
        Toast.makeText(MainActivity.this,"showToast============",Toast.LENGTH_SHORT).show();
    }
}
