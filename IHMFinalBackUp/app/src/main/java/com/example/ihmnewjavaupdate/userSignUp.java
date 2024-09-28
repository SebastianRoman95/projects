package com.example.ihmnewjavaupdate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.text.method.PasswordTransformationMethod;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class userSignUp extends AppCompatActivity {
    //var
    EditText SignUpName, SignUpEmail, SignUpPassword, SignUpConfirmPassword;
    Button createAccount, SignUpLogin, signUpHiddenPass, signUpShowPassword;
    FirebaseAuth firebaseAuth;
    FirebaseUser firebaseUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_sign_up);
        //text var
        SignUpName = findViewById(R.id.SignUpName);
        SignUpEmail = findViewById(R.id.SignUpEmail);
        SignUpPassword = findViewById(R.id.SignUpPassword);
        SignUpConfirmPassword = findViewById(R.id.SignUpConfirmPassword);
        //buttons var
        createAccount = findViewById(R.id.createAccount);
        SignUpLogin = findViewById(R.id.SignUpLogin);
        signUpHiddenPass = findViewById(R.id.signUpHiddenPass);
        signUpShowPassword = findViewById(R.id.signUpShowPassword);
        //firebase
        firebaseAuth=FirebaseAuth.getInstance();
        firebaseUser = firebaseAuth.getCurrentUser();

        createAccount.setBackgroundColor(Color.BLUE);
        //button to login page
        SignUpLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(getApplicationContext(),login_page.class));
                finish();
            }
        });

        //hide pass
        signUpHiddenPass.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                signUpHiddenPass.setVisibility(View.INVISIBLE);
                SignUpPassword.setTransformationMethod(null);
                SignUpConfirmPassword.setTransformationMethod(null);
                signUpShowPassword.setVisibility(View.VISIBLE);
            }
        });

        //show pass
        signUpShowPassword.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                signUpShowPassword.setVisibility(View.INVISIBLE);
                signUpHiddenPass.setVisibility(View.VISIBLE);
                SignUpPassword.setTransformationMethod(new PasswordTransformationMethod());
                SignUpConfirmPassword.setTransformationMethod(new PasswordTransformationMethod());
            }
        });
        //creating an account
        createAccount.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //string var
                String FullName = SignUpName.getText().toString();
                String UserEmail = SignUpEmail.getText().toString();
                String UserPassword = SignUpPassword.getText().toString();
                String UserConfirmPass = SignUpConfirmPassword.getText().toString();

                //check if nothing is in the text
                if(FullName.isEmpty()){
                    SignUpName.setError("Please enter your full name!");
                    return;
                }
                if(UserEmail.isEmpty()){
                    SignUpEmail.setError("Please enter your email!");
                    return;
                }
                if(UserPassword.isEmpty()){
                    SignUpPassword.setError("Please enter your password!");
                    return;
                }
                if(UserConfirmPass.isEmpty()){
                    SignUpConfirmPassword.setError("Please enter your password confirm!");
                    return;
                }

                //check if they are the same
                if(!UserPassword.equals(UserConfirmPass)){
                    SignUpConfirmPassword.setError("Password and confirm password do not match!");
                    return;
                }
                //size
                Toast.makeText(userSignUp.this,"Account has been created!",Toast.LENGTH_SHORT).show();//fix

                //succ and fail
                firebaseAuth.createUserWithEmailAndPassword(UserEmail,UserPassword).addOnSuccessListener(new OnSuccessListener<AuthResult>() {
                    @Override
                    public void onSuccess(AuthResult authResult) {
                        firebaseAuth.getCurrentUser().sendEmailVerification().addOnSuccessListener(new OnSuccessListener<Void>() {
                            @Override
                            public void onSuccess(Void unused) {
                                Toast.makeText(userSignUp.this,"Verification Email Sent.", Toast.LENGTH_SHORT).show();
                            }
                        });//sends email

                        //create account
                        StoreUser UserInfo = new StoreUser(SignUpName.getText().toString(), SignUpEmail.getText().toString());
                        DatabaseReference reference = FirebaseDatabase.getInstance().getReference("User");
                        reference.child(firebaseUser.getUid()).setValue(UserInfo).addOnCompleteListener(new OnCompleteListener<Void>() {
                            @Override
                            public void onComplete(@NonNull Task<Void> task) {
                                startActivity(new Intent(getApplicationContext(),login_page.class));//change to login page
                                finish();
                            }
                        });
                    }
                }).addOnFailureListener(new OnFailureListener() {
                    @Override
                    public void onFailure(@NonNull Exception e) {
                        Toast.makeText(userSignUp.this,e.getMessage(),Toast.LENGTH_SHORT).show();
                    }
                });//end succ and fail
            }//create account onlistener end
        });//create account end
    }//oncreate end
}//sign up class end

