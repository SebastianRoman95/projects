package com.example.ihmnewjavaupdate;

public class BillGuestData {
    private String guestRoomNumberList, nightList, totalList, guestList, billGuestKeys;

    public String getGuestRoomNumberList(){
        return guestRoomNumberList;
    }

    public String getNightList(){
        return nightList;
    }

    public String getTotalList(){
        return totalList;
    }

    public String getGuestList(){
        return guestList;
    }

    public String getBillGuestKeys(){
        return billGuestKeys;
    }


    public BillGuestData(String guestRoomNumberList, String nightList, String totalList, String guestList, String billGuestKeys){
        this.guestRoomNumberList = guestRoomNumberList;
        this.nightList = nightList;
        this.totalList = totalList;
        this.guestList = guestList;
        this.billGuestKeys = billGuestKeys;
    }

    public BillGuestData(){}
}
