package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

public class donotdisturb extends AppCompatActivity {
    LinearLayout changebg;
    Button DoNotClean, homeDND, DoClean;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_donotdisturb);
        setContentView(R.layout.activity_donotdisturb);
        DoClean = findViewById(R.id.DoClean);
        homeDND = findViewById(R.id.homeDND);
        DoNotClean = findViewById(R.id.DoNotClean);
        changebg = findViewById(R.id.changebg);

        //button for user sign up
        homeDND.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),GuestHome.class));
            }
        });

        //clean
        DoClean.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DoClean.setVisibility(View.INVISIBLE);
                changebg.setBackgroundResource(R.color.green);
                DoNotClean.setVisibility(View.VISIBLE);
            }
        });

        //do not clean
        DoNotClean.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DoNotClean.setVisibility(View.INVISIBLE);
                changebg.setBackgroundResource(R.color.red);
                DoClean.setVisibility(View.VISIBLE);
            }
        });
    }
}