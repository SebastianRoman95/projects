package com.example.ihmnewjavaupdate;


import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Locale;


public class fdstaffmessage extends AppCompatActivity{
    Button staffMessageHome, staffMessageSent, staffMessageBillIcon;
    EditText staffMessage;
    RecyclerView messagesLog;
    DatabaseReference reference, ref;
    FirebaseAuth firebaseAuth;
    FirebaseUser firebaseUser;
    MyAdapterChat myAdapterChat;
    ArrayList<userChatLog> list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fdstaffmessage);
        //buttons for other pages
        staffMessageHome=findViewById(R.id.staffMessageHome);
        staffMessageBillIcon=findViewById(R.id.staffMessageBillIcon);
        //messaging
        staffMessage=findViewById(R.id.staffMessage);
        staffMessageSent=findViewById(R.id.staffMessageSent);
        messagesLog=findViewById(R.id.messagesLog);
        //firebase
        firebaseAuth = FirebaseAuth.getInstance();
        firebaseUser = firebaseAuth.getCurrentUser();
        reference = FirebaseDatabase.getInstance().getReference("User");
        ref = FirebaseDatabase.getInstance().getReference("Chat Log");
        //recycler
        messagesLog.setHasFixedSize(true);
        messagesLog.setLayoutManager(new LinearLayoutManager(this));

        list = new ArrayList<>();
        myAdapterChat = new MyAdapterChat(this,list);
        messagesLog.setAdapter(myAdapterChat);

        ref.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                ref.orderByChild("dateOfMessage").addChildEventListener(new ChildEventListener() {
                    @Override
                    public void onChildAdded(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {}

                    @Override
                    public void onChildChanged(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {}

                    @Override
                    public void onChildRemoved(@NonNull DataSnapshot snapshot) {}

                    @Override
                    public void onChildMoved(@NonNull DataSnapshot snapshot, @Nullable String previousChildName) {}

                    @Override
                    public void onCancelled(@NonNull DatabaseError error) {}
                });
                for(DataSnapshot dataSnapshot: snapshot.getChildren()){
                    userChatLog UserChatLog = dataSnapshot.getValue(userChatLog.class);
                    list.add(UserChatLog);
                }
                myAdapterChat.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {}
        });

        //home
        staffMessageHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),FrontDeskHome.class));
            }
        });

        //billing
        staffMessageBillIcon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),viewbill.class));
            }
        });

        staffMessageSent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                reference = FirebaseDatabase.getInstance().getReference();
                String key = reference.push().getKey();
                ref = FirebaseDatabase.getInstance().getReference("User");

                ref.child(firebaseUser.getUid()).child("userFullName").get().addOnCompleteListener(new OnCompleteListener<DataSnapshot>() {
                    @Override
                    public void onComplete(@NonNull Task<DataSnapshot> task) {
                        if (!task.isSuccessful()) {
                            Log.e("firebase", "Error getting data", task.getException());
                        }
                        else {
                            SimpleDateFormat time = new SimpleDateFormat("h:mm a dd/MM/yyyy", Locale.getDefault());
                            Calendar calendar = Calendar.getInstance();
                            String date = time.format(calendar.getTime());
                            reference.child("Chat Log").child(key).setValue(new chatLog(staffMessage.getText().toString(), String.valueOf
                                    (task.getResult().getValue()), date));
                        }
                    }
                });
            }
        });
    }
}
