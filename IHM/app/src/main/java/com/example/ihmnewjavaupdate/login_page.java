package com.example.ihmnewjavaupdate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.text.method.PasswordTransformationMethod;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class login_page extends AppCompatActivity {
    //login var
    EditText SignInEmail, SignInPassword;
    Button SignInSignUp,SignInLogin, SignInForgotPassword, ShowPassword, HidePassword, AboutUsLogin;
    //firebase var
    FirebaseAuth firebaseAuth;
    //forgot password var
    AlertDialog.Builder resetUser;
    LayoutInflater firebasePassword;
    //about us
    Dialog aboutus;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_page);
        //text
        SignInEmail=findViewById(R.id.SignInEmail);
        SignInPassword=findViewById(R.id.SignInPassword);
        //button
        SignInSignUp=findViewById(R.id.SignInSignUp);
        SignInLogin=findViewById(R.id.SignInLogin);
        SignInForgotPassword=findViewById(R.id.SignInForgotPassword);
        AboutUsLogin=findViewById(R.id.AboutUsLogin);
        HidePassword=findViewById(R.id.HidePassword);
        ShowPassword=findViewById(R.id.ShowPassword);
        //firebase
        firebaseAuth=FirebaseAuth.getInstance();
        //forgot password
        resetUser = new AlertDialog.Builder(this);
        firebasePassword=this.getLayoutInflater();
        //about us
        aboutus = new Dialog(this);

        //hide password
        HidePassword.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                HidePassword.setVisibility(View.INVISIBLE);
                SignInPassword.setTransformationMethod(null);
                ShowPassword.setVisibility(View.VISIBLE);
            }
        });

        //show password
        ShowPassword.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ShowPassword.setVisibility(View.INVISIBLE);
                HidePassword.setVisibility(View.VISIBLE);
                SignInPassword.setTransformationMethod(new PasswordTransformationMethod());
            }
        });

        //button for user sign up
        SignInSignUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),userSignUp.class));
            }
        });

        //about us
        AboutUsLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),about.class));
            }
        });
        //button for user forgot password
        SignInForgotPassword.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //grabs anything from forgot password
                View view=firebasePassword.inflate(R.layout.forgotpassword,null);
                resetUser.setTitle("Reset your password").setMessage("Please enter your email below.").setPositiveButton("Reset", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        //grabs Edittext from forgot password
                        EditText email = view.findViewById(R.id.forgotPassEmailPop);
                        //check if anything is in the box
                        if(email.getText().toString().isEmpty()){
                            email.setError("Please enter your email.");
                            return;
                        }
                        //sends reset password for forgot password
                        firebaseAuth.sendPasswordResetEmail(email.getText().toString()).addOnSuccessListener(new OnSuccessListener<Void>() {
                            @Override
                            public void onSuccess(Void unused) {
                                Toast.makeText(login_page.this,"Email has been sent.", Toast.LENGTH_SHORT).show();
                            }
                        }).addOnFailureListener(new OnFailureListener() {
                            @Override
                            public void onFailure(@NonNull Exception e) {
                                Toast.makeText(login_page.this,e.getMessage(), Toast.LENGTH_SHORT).show();
                            }
                        });//end send reset password for forgot password
                    }
                }).setNegativeButton("Cancel", null).setView(view).create().show();
            }
        });//end forgot password

        SignInLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //email if correct
                if(SignInEmail.getText().toString().isEmpty()){
                    SignInEmail.setError("Error Missing Email");
                    return;
                }
                //password if correct
                if(SignInPassword.getText().toString().isEmpty()){
                    SignInPassword.setError("Error Missing Password");
                    return;
                }
                //firebase check if login valid
                firebaseAuth.signInWithEmailAndPassword(SignInEmail.getText().toString(),SignInPassword.getText().toString()).addOnSuccessListener(new OnSuccessListener<AuthResult>() {
                    @Override
                    public void onSuccess(AuthResult authResult) {
                        startActivity(new Intent(getApplicationContext(),FrontDeskHome.class));
                        finish();
                    }
                }).addOnFailureListener(new OnFailureListener() {
                    @Override
                    public void onFailure(@NonNull Exception e) {
                        Toast.makeText(login_page.this, "Error", Toast.LENGTH_SHORT).show();
                    }
                });
            }
        });
    }
}