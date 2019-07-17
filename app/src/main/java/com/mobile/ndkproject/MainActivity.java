package com.mobile.ndkproject;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    private JNI jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jni = new JNI();
        String result = jni.sayHello();
        System.out.println("result==="+result);
    }

    public void add(View view){
        int result = jni.add(99,1);
        Log.e(MainActivity.class.getSimpleName(),"result========="+result);
    }

    public void dealStr(View view){
        String result = jni.dealStr("I am from java");
        Log.e(MainActivity.class.getSimpleName(),"result========="+result);
    }

    public void increaseArrayEles(View view){
        int[] array = {1,2,3,4,5};
        jni.increaseArrayEles(array);
        for (int i =0;i<array.length;i++){
            Log.e(MainActivity.class.getSimpleName(),"array["+i+"]========="+array[i]);
        }
    }

    public void checkPwd(View view){

    }
}
