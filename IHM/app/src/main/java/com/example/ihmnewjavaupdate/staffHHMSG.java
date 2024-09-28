package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class staffHHMSG extends AppCompatActivity {
    Button HHhome, SmsgBtn;
    EditText SHHMsg;
    TextView SHHmsgView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_staff_hhmsg);
        HHhome=findViewById(R.id.HHhome);
        SHHMsg=findViewById(R.id.SHHMsg);
        SmsgBtn=findViewById(R.id.SmsgBtn);
        SHHmsgView=findViewById(R.id.SHHmsgView);

        HHhome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),HouseKeepingHome.class));
            }
        });

        SmsgBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {}
        });
    }
}