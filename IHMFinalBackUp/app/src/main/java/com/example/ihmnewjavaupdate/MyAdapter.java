package com.example.ihmnewjavaupdate;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;
import org.checkerframework.checker.nullness.qual.NonNull;
import java.util.ArrayList;

public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder> {
    Context context;
    ArrayList<BillGuestData> list;
    recyclerViewInterface RecyclerViewInterface;


    public MyAdapter(Context context, ArrayList<BillGuestData> list, recyclerViewInterface RecyclerViewInterface){
        this.context = context;
        this.list = list;
        this.RecyclerViewInterface = RecyclerViewInterface;
    }

    @androidx.annotation.NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@androidx.annotation.NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item,parent,false);
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@androidx.annotation.NonNull MyViewHolder holder, int position) {
        BillGuestData billGuestData= list.get(position);

        holder.RoomNumberUser.setText(list.get(position).getGuestRoomNumberList());
        holder.NameViewUser.setText(list.get(position).getGuestList());
        holder.NightViewUser.setText(list.get(position).getNightList());
        holder.totalViewUser.setText(list.get(position).getTotalList());

        holder.constraintlayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                RecyclerViewInterface.onItemClicked(billGuestData);
                Intent intent = new Intent(context, updateBill.class);
                intent.putExtra("guestRoomNumberList", list.get(holder.getAdapterPosition()).getGuestRoomNumberList());
                intent.putExtra("guestList", list.get(holder.getAdapterPosition()).getGuestList());
                intent.putExtra("nightList", list.get(holder.getAdapterPosition()).getNightList());
                intent.putExtra("totalList", list.get(holder.getAdapterPosition()).getTotalList());
                intent.putExtra("billGuestKeys", list.get(holder.getAdapterPosition()).getBillGuestKeys());
                context.startActivity(intent);
            }
        });
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public static class MyViewHolder extends RecyclerView.ViewHolder{

        public TextView RoomNumberUser, NameViewUser, NightViewUser, totalViewUser;
        public ConstraintLayout constraintlayout;

        public MyViewHolder(@NonNull View itemView){
            super(itemView);
            RoomNumberUser = itemView.findViewById(R.id.RoomNumberUser);
            NameViewUser = itemView.findViewById(R.id.NameViewUser);
            NightViewUser = itemView.findViewById(R.id.NightViewUser);
            totalViewUser = itemView.findViewById(R.id.totalViewUser);
            constraintlayout = itemView.findViewById(R.id.billBoxInfo);
        }
    }
}
