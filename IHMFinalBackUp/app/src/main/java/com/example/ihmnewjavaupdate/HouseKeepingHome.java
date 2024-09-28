package com.example.ihmnewjavaupdate;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import com.google.firebase.auth.FirebaseAuth;

public class HouseKeepingHome extends AppCompatActivity {
    Button CleanRoom, MgsStaff, LogoutHH;
    //FirebaseAuth FireBA;
    //AlertDialog.Builder DeleteUser;
    //LayoutInflater FP;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_house_keeping_home);
        //button
        CleanRoom=findViewById(R.id.CleanRoom);
        MgsStaff=findViewById(R.id.MgsStaff);
        LogoutHH=findViewById(R.id.LogoutHH);

        //message page
        CleanRoom.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),rooms.class));
            }
        });

        //message page
        MgsStaff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),staffHHMSG.class));
            }
        });

        //log out
        LogoutHH.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),login_page.class));
            }
        });
    }
    //menu
    /*@Override
    public boolean onCreateOptionsMenu(Menu menu){
        MenuInflater pointMenu = getMenuInflater();
        pointMenu.inflate(R.menu.option_menu,menu);
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
                    FirebaseUser currUser = FireBA.getCurrentUser();
                    currUser.delete().addOnSuccessListener(new OnSuccessListener<Void>() {
                        @Override
                        public void onSuccess(Void unused) {
                            Toast.makeText(GuestHome.this, "Account has been deleted", Toast.LENGTH_SHORT).show();
                            FireBA.signOut();
                            startActivity(new Intent(getApplicationContext(),login_page.class));
                            finish();
                        }
                    }).addOnFailureListener(new OnFailureListener() {
                        @Override
                        public void onFailure(@NonNull Exception e) {
                            Toast.makeText(GuestHome.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                        }
                    });
                }
            }).setNegativeButton("No",null).create().show();
        }

        return super.onOptionsItemSelected(item);
    }*/
}