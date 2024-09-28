package com.example.ihmnewjavaupdate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class FrontDeskHome extends AppCompatActivity {
    Button logoutFrontDesk, EditBill, messageStaff, FrontDeskBillIcon, FrontDeskMessageIcon;
    //messageGuest
    FirebaseAuth firebaseAuth;
    AlertDialog.Builder DeleteUser;
    LayoutInflater layoutInflater;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_front_desk_home);
        //button
        logoutFrontDesk=findViewById(R.id.logoutFrontDesk);
        EditBill=findViewById(R.id.EditBill);
        FrontDeskBillIcon=findViewById(R.id.FrontDeskBillIcon);
        messageStaff=findViewById(R.id.messageStaff);
        FrontDeskMessageIcon=findViewById(R.id.FrontDeskMessageIcon);
        //Firebase
        firebaseAuth = FirebaseAuth.getInstance();
        //delete account
        DeleteUser = new AlertDialog.Builder(this);
        layoutInflater=this.getLayoutInflater();

        //log in page button
        logoutFrontDesk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),login_page.class));
                finish();
            }
        });

        //edit guest bill button
        EditBill.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),viewbill.class));
                finish();
            }
        });

        //bill icon button
        FrontDeskBillIcon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),viewbill.class));
                finish();
            }
        });

        //message staff button
        messageStaff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),fdstaffmessage.class));
                finish();
            }
        });

        //message staff icon button
        FrontDeskMessageIcon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),fdstaffmessage.class));
                finish();
            }
        });
    }


    //menu
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.option_menu,menu);
        return super.onCreateOptionsMenu(menu);
    }

    //send user to reset password page
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item){
        if(item.getItemId()==R.id.ResetPasswordMenu){
            startActivity(new Intent(getApplicationContext(),reset_password.class));
        }

        if(item.getItemId()==R.id.DeleteUserMenu){
            DeleteUser.setTitle("Would you like to delete account?").setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    FirebaseUser currUser = firebaseAuth.getCurrentUser();
                    currUser.delete().addOnSuccessListener(new OnSuccessListener<Void>() {
                        @Override
                        public void onSuccess(Void unused) {
                            Toast.makeText(FrontDeskHome.this, "Account has been deleted", Toast.LENGTH_SHORT).show();
                            firebaseAuth.signOut();
                            startActivity(new Intent(getApplicationContext(),login_page.class));
                            finish();
                        }
                    }).addOnFailureListener(new OnFailureListener() {
                        @Override
                        public void onFailure(@NonNull Exception e) {
                            Toast.makeText(FrontDeskHome.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                        }
                    });
                }
            }).setNegativeButton("No",null).create().show();
        }
        return super.onOptionsItemSelected(item);
    }
}