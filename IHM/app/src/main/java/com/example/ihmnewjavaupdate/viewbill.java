package com.example.ihmnewjavaupdate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import java.util.ArrayList;

public class viewbill extends AppCompatActivity implements recyclerViewInterface{
    Button AddBill, viewBillHomeIcon, viewBillMessageIcon;
    RecyclerView BillList;
    //firebase
    DatabaseReference reference;
    FirebaseAuth firebaseAuth;
    FirebaseUser firebaseUser;
    //recycler
    MyAdapter myAdapter;
    ArrayList<BillGuestData> list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_viewbill);
        viewBillHomeIcon=findViewById(R.id.viewBillHomeIcon);
        AddBill=findViewById(R.id.AddBill);
        viewBillMessageIcon=findViewById(R.id.viewBillMessageIcon);
        BillList=findViewById(R.id.BillList);
        //firebase
        firebaseAuth = FirebaseAuth.getInstance();
        firebaseUser = firebaseAuth.getCurrentUser();
        reference = FirebaseDatabase.getInstance().getReference("Bill Information");
        //recycler onclick
        BillList.setHasFixedSize(true);
        BillList.setLayoutManager(new LinearLayoutManager(this));

        list = new ArrayList<>();
        myAdapter = new MyAdapter(this,list, this);
        BillList.setAdapter(myAdapter);

        reference.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                for(DataSnapshot dataSnapshot: snapshot.getChildren()){
                    BillGuestData billGuestData = dataSnapshot.getValue(BillGuestData.class);
                    list.add(billGuestData);
                }
                myAdapter.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {}
        });

        //home icon button
        viewBillHomeIcon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),FrontDeskHome.class));
            }
        });

        //add bill button
        AddBill.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),editbillFD.class));
            }
        });

        //message icon button
        viewBillMessageIcon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),fdstaffmessage.class));
            }
        });
    }

    @Override
    public void onItemClicked(BillGuestData billGuestData) {}
}