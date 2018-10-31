
package com.example.app.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity
{

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    TextView getUser;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getUser = findViewById(R.id.getUser);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        User user = setUserName("DAIN");
        Log.i("TAG", "onCreate: " + user.toString());

        final ArrayList<Integer> list = new ArrayList<>();
        list.add(12);
        list.add(12);
        list.add(12);
        list.add(12);




        getUser.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                User user = getUser();
                Log.i("TAG", "onClick: " + user.getName());

            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native User getUser();
    public native User getUserClassName(User user);

    public native User setUserName(String name);
}
