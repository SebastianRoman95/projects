package com.example.ihmnewjavaupdate;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.recyclerview.widget.RecyclerView;
import java.util.ArrayList;

public class MyAdapterChat extends RecyclerView.Adapter<MyAdapterChat.MyViewHolder> {
    Context context;
    ArrayList<userChatLog> list;

    public MyAdapterChat(Context context, ArrayList<userChatLog> list){
        this.context = context;
        this.list = list;
    }

    @androidx.annotation.NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@androidx.annotation.NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.itemchat,parent,false);
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@androidx.annotation.NonNull MyViewHolder holder, int position) {
        userChatLog UserChatLog= list.get(position);
        holder.TimeOfMessage.setText(UserChatLog.getDateOfMessage());
        holder.messageChatBox.setText(UserChatLog.getMessageOfUser());
        holder.userNameLog.setText(UserChatLog.getMessageUsers());
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public static class MyViewHolder extends RecyclerView.ViewHolder{
        TextView messageChatBox, userNameLog, TimeOfMessage;
        public MyViewHolder(@org.checkerframework.checker.nullness.qual.NonNull View itemView){
            super(itemView);
            TimeOfMessage = itemView.findViewById(R.id.TimeOfMessage);
            messageChatBox = itemView.findViewById(R.id.messageChatBox);
            userNameLog = itemView.findViewById(R.id.userNameLog);
        }
    }
}
