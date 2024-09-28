package com.example.ihmnewjavaupdate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class reset_password extends AppCompatActivity {
    EditText resetPassword,resetConfirmPassword;
    Button resetPasswordConfirm;
    FirebaseUser firebaseUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reset_password);
        //text
        resetPassword=findViewById(R.id.resetPassword);
        resetConfirmPassword=findViewById(R.id.resetConfirmPassword);
        //button
        resetPasswordConfirm=findViewById(R.id.resetPasswordConfirm);
        //firebase
        firebaseUser= FirebaseAuth.getInstance().getCurrentUser();

        //confirm new password
        resetPasswordConfirm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //password is empty
                if (resetPassword.getText().toString().isEmpty()) {
                    resetPassword.setError("Please enter your password!");
                    return;
                }
                //confirm password is empty
                if (resetConfirmPassword.getText().toString().isEmpty()) {
                    resetConfirmPassword.setError("Please enter your confirm password!");
                    return;
                }
                //confirm password and password match
                if (!resetPassword.getText().toString().equals(resetConfirmPassword.getText().toString())) {
                    resetPassword.setError("Password and confirm password do not match!");
                    return;
                }

                firebaseUser.updatePassword(resetPassword.getText().toString()).addOnSuccessListener(new OnSuccessListener<Void>() {
                    @Override
                    public void onSuccess(Void aVoid) {
                        Toast.makeText(reset_password.this, "Password has been updated", Toast.LENGTH_SHORT).show();
                        startActivity(new Intent(getApplicationContext(), FrontDeskHome.class));//change to login to have the user relog
                        finish();
                    }
                }).addOnFailureListener(new OnFailureListener() {
                    @Override
                    public void onFailure(@NonNull Exception e) {
                        Toast.makeText(reset_password.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                    }
                });
            }//onclick
        });//reset end
    }
}