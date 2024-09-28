package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import java.io.IOException;

public class guestbill extends AppCompatActivity {
    //button
    Button GBhome;
    //text view
    TextView billnumbers;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_guestbill);
        //var
        GBhome=findViewById(R.id.GBhome);
        billnumbers=findViewById(R.id.billnumbers);

        //housekeeping dashboard
        GBhome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),GuestHome.class));
            }
        });
    }
    public void updatebill(View view) throws IOException {

    }
}