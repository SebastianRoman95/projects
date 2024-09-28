package com.example.ihmnewjavaupdate;

public class billListView {
    public String bedList;
    public String nightList;
    public String guestList;
    public String guestRoomNumberList;
    public String otherList;
    public String totalList;
    public String billGuestKeys;


    public billListView(String bedList, String nightList, String guestList, String guestRoomNumberList, String otherList, String totalList, String billGuestKeys){
        this.bedList = bedList;
        this.nightList = nightList;
        this.guestRoomNumberList = guestRoomNumberList;
        this.guestList = guestList;
        this.otherList = otherList;
        this.totalList = totalList;
        this.billGuestKeys=billGuestKeys;
    }
}
