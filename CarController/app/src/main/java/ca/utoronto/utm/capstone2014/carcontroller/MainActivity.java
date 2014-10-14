package ca.utoronto.utm.capstone2014.carcontroller;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

import butterknife.ButterKnife;
import butterknife.InjectView;
import butterknife.OnClick;


public class MainActivity extends Activity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.inject(this);
    }

    @OnClick(R.id.forward)
    public void forward() {
        Log.d(TAG, "Forward");


    }

    @OnClick(R.id.reverse)
    public void reverse() {
        Log.d(TAG, "Reverse");
    }
}
