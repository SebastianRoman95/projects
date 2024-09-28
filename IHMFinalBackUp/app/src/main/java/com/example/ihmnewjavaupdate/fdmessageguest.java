package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class fdmessageguest extends AppCompatActivity {
    Button FDhomeG, FDSendG;
    EditText FDmsgG;
    TextView FDmessageRG;
    RecyclerView fdgchat;
    DatabaseReference reference;
    FirebaseAuth FB;
    FirebaseUser FBUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fdmessageguest);
        FDhomeG=findViewById(R.id.FDhomeG);
        FDmsgG=findViewById(R.id.FDmsgG);
        FDSendG=findViewById(R.id.FDSendG);
        FDmessageRG=findViewById(R.id.FDmessageRG);
        FB = FirebaseAuth.getInstance();
        FBUser = FB.getCurrentUser();
        reference = FirebaseDatabase.getInstance().getReference("Name");

        FDhomeG.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),FrontDeskHome.class));
            }
        });

        FDSendG.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                reference = FirebaseDatabase.getInstance().getReference().child("Name").child(FBUser.getUid()).child("Chat Log");
                String key = reference.push().getKey();
                reference.child(key).child("Chat Log").setValue(FDmsgG.getText().toString());

            }
        });
    }
}