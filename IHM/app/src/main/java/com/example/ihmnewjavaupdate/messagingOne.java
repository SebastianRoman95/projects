package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class messagingOne extends AppCompatActivity {
    Button messagingOneHome, sendMsgButton;
    EditText UserMessage;
    TextView messagedisplay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_messaging_one);
        messagingOneHome=findViewById(R.id.messagingOneHome);
        UserMessage=findViewById(R.id.UserMessage);
        sendMsgButton=findViewById(R.id.sendMsgButton);
        messagedisplay=findViewById(R.id.messagedisplay);

        messagingOneHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),GuestHome.class));
            }
        });

        sendMsgButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {}
        });
    }
}