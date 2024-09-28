package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.text.DecimalFormat;

public class editbillFD extends AppCompatActivity {
    Button FDHomeBill, totalBtn, billListHome, editBillMessageIcon;
    EditText nightStayed, guestName, otherAmount, bed1, guestRoomNumbers;
    TextView totalAmount;
    DatabaseReference reference;
    FirebaseAuth FB;
    FirebaseUser FBUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_editbill_fd);
        //buttons for other parts of the app
        FDHomeBill=findViewById(R.id.FDHomeBill);
        billListHome=findViewById(R.id.billListHome);
        editBillMessageIcon=findViewById(R.id.editBillMessageIcon);
        //bill var
        totalBtn=findViewById(R.id.totalBtn);
        bed1=findViewById(R.id.bed1);
        nightStayed=findViewById(R.id.nightStayed);
        guestName=findViewById(R.id.guestName);
        guestRoomNumbers=findViewById(R.id.guestRoomNumbers);
        otherAmount=findViewById(R.id.otherAmount);
        totalAmount=findViewById(R.id.totalAmount);
        //firebase
        FB = FirebaseAuth.getInstance();
        FBUser = FB.getCurrentUser();
        reference = FirebaseDatabase.getInstance().getReference("User");

        //FrontDesk dashboard
        FDHomeBill.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),FrontDeskHome.class));
            }
        });

        //view bill
        billListHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),viewbill.class));
            }
        });

        //message staff
        editBillMessageIcon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),fdstaffmessage.class));
            }
        });

        //adds total
        totalBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int beds = 0, nights;
                float oAmount;
                int beds2 = Integer.parseInt(bed1.getText().toString());
                boolean checkBed=false, checkNight=false, checkOther=false;

                //guest name empty
                if(guestName.getText().toString().isEmpty()){
                    guestName.setError("Error Missing Guest Name");
                    return;
                }

                //room number empty
                if(guestRoomNumbers.getText().toString().isEmpty()){
                    guestRoomNumbers.setError("Error Missing Room Number");
                    return;
                }

                //check if bed is empty
                if (bed1.getText().toString().isEmpty()) {
                    beds = 0;
                    Toast.makeText(editbillFD.this, "Error Missing Bed.", Toast.LENGTH_LONG).show();
                    checkBed=true;
                }
                else{
                    beds = Integer.parseInt(bed1.getText().toString());
                    checkBed=false;
                }

                //check if night is empty
                if (nightStayed.getText().toString().isEmpty()) {
                    nights = 0;
                    checkNight=true;
                    Toast.makeText(editbillFD.this, "Error Missing Nights.", Toast.LENGTH_LONG).show();
                }
                else{
                    nights = Integer.parseInt(nightStayed.getText().toString());
                    checkNight=false;
                }

                //check if other is empty
                if (otherAmount.getText().toString().isEmpty()) {
                    oAmount = 0;
                    checkOther=true;
                    Toast.makeText(editbillFD.this, "Error Missing Other.", Toast.LENGTH_LONG).show();
                }
                else{
                    oAmount = (float) Double.parseDouble(otherAmount.getText().toString());
                    checkOther=false;
                }

                float total = 0;
                total += ((beds * 50)* nights) + oAmount;
                DecimalFormat decimalFormat = new DecimalFormat("#.##");
                String finalAmount= decimalFormat.format(total);
                totalAmount.setText(finalAmount);

                if(checkBed==false&&checkNight==false&&checkOther==false){
                    reference = FirebaseDatabase.getInstance().getReference().child("Bill Information");
                    String key = reference.push().getKey();
                    reference.child(key).setValue(new billListView(bed1.getText().toString(), nightStayed.getText().toString(),
                            guestName.getText().toString(), guestRoomNumbers.getText().toString(), otherAmount.getText().toString(),
                            finalAmount, key));

                }
            }
        });
    }
}