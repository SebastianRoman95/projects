package com.example.myapplication;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;

import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    private final Object Tag= "Main";

    EditText UserInputBill;
    EditText userInputTip;
    TextView UserTipFinalAmount;
    TextView userTotalFinalAmount;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        UserTipFinalAmount = findViewById(R.id.UserTipFinalAmount1);//text
        userTotalFinalAmount = findViewById(R.id.userTotalFinalAmount1);//text
        UserInputBill = findViewById(R.id.UserInputBill1);//edit
        userInputTip = findViewById(R.id.userInputTip1);//edit

        userInputTip.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {
            }
            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
            }
            @Override
            public void afterTextChanged(Editable s) {
                Log.i((String) Tag, String.valueOf(s));
                TipAndTotal();
            }
        });

        UserInputBill.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {
            }
            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
            }
            @Override
            public void afterTextChanged(Editable s) {
                Log.i((String) Tag, String.valueOf(s));
                TipAndTotal();
            }
        });

    }

    public void TipAndTotal() {
        if(UserInputBill.getText().toString().isEmpty()||userInputTip.getText().toString().isEmpty()){
            userInputTip.setText("");
            UserInputBill.setText("");
        }
        String BillAmount = UserInputBill.getText().toString();
        String TipsAmount = userInputTip.getText().toString();
        float TipTotal = (float) (Double.parseDouble(BillAmount) * Double.parseDouble(TipsAmount) / 100.0);
        float totalBillAmount = (float) Double.parseDouble(BillAmount)+ TipTotal;
        UserTipFinalAmount.setText((int) (0.1f* + TipTotal));
        userTotalFinalAmount.setText("" + totalBillAmount);
    }


}