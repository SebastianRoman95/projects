package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class rooms extends AppCompatActivity {
    Button HHHome;
    TextView roomsClean;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rooms);
        HHHome=findViewById(R.id.HHHome);
        roomsClean=findViewById(R.id.roomsClean);

        //housekeeping dashboard
        HHHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),HouseKeepingHome.class));
            }
        });
    }
}