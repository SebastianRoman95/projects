package com.example.ihmnewjavaupdate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import java.util.HashMap;

public class updateBill extends AppCompatActivity {
    Button editFinish;
    EditText updateRoom, updateFullName, updateNights, updateTotal;
    String guestKey;
    //firebase
    DatabaseReference reference;
    FirebaseAuth firebaseAuth;
    FirebaseUser firebaseUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update_bill);
        editFinish=findViewById(R.id.editFinish);
        updateRoom=findViewById(R.id.updateRoom);
        updateFullName=findViewById(R.id.updateFullName);
        updateNights=findViewById(R.id.updateNights);
        updateTotal=findViewById(R.id.updateTotal);
        //firebase
        firebaseAuth = FirebaseAuth.getInstance();
        firebaseUser = firebaseAuth.getCurrentUser();
        reference = FirebaseDatabase.getInstance().getReference("Bill Information");

        Bundle bundle = getIntent().getExtras();
        if(bundle!=null){
            updateRoom.setText(bundle.getString("guestRoomNumberList"));
            updateFullName.setText(bundle.getString("guestList"));
            updateNights.setText(bundle.getString("nightList"));
            updateTotal.setText(bundle.getString("totalList"));
            guestKey = bundle.getString("billGuestKeys");
        }

        editFinish.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String room = updateRoom.getText().toString();
                String name = updateFullName.getText().toString();
                String night = updateNights.getText().toString();
                String total = updateTotal.getText().toString();

                updateBillData(room, name, night, total);
                startActivity(new Intent(getApplicationContext(),viewbill.class));
            }
        });
    }

    private void updateBillData(String room, String name, String night, String total){
        String key = reference.push().getKey();
        HashMap guestUser = new HashMap();
        guestUser.put("guestRoomNumberList",room);
        guestUser.put("guestList",name);
        guestUser.put("nightList",night);
        guestUser.put("totalList",total);
        reference.child(guestKey).updateChildren(guestUser).addOnCompleteListener(new OnCompleteListener() {
            @Override
            public void onComplete(@NonNull Task task) {
                if(task.isSuccessful()){
                    Toast.makeText(updateBill.this,"Updated Info", Toast.LENGTH_SHORT).show();
                }
                else{
                    Toast.makeText(updateBill.this,"Failed to Updated Info", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}