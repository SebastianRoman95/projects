package com.example.tipcalcbutton;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;

import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    private final Object Tag= "Main";

    EditText UserInputBill;
    EditText userInputTip;
    EditText UserPeople;
    TextView UserTipFinalAmount;
    TextView userTotalFinalAmount;
    Button Cost_Amount;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        UserTipFinalAmount = findViewById(R.id.UserTipFinalAmount1);
        userTotalFinalAmount = findViewById(R.id.userTotalFinalAmount1);
        UserInputBill = findViewById(R.id.UserInputBill1);
        userInputTip = findViewById(R.id.userInputTip1);
        UserPeople = findViewById(R.id.UserPeople1);
        Cost_Amount = findViewById(R.id.Cost_Amount1);

        Cost_Amount.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                float bill = (float) Double.parseDouble(UserInputBill.getText().toString());
                float tip = (float) Double.parseDouble(userInputTip.getText().toString());
                int plp = Integer.parseInt(UserPeople.getText().toString());
                float tTotal = (float) (((bill/plp) * tip) / 100.0);
                float bTotal = (float) (((bill/plp)+ tTotal) * 1.0);
                UserTipFinalAmount.setText(Float.toString(tTotal));
                userTotalFinalAmount.setText(Float.toString((bTotal)));

            }
        });
    }
}