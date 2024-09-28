const express = require("express");
const bodyParser = require("body-parser");
const date = require(__dirname + "/date.js");
//console.log(date());

const app = express();
const items = ["Cook", "Eat", "Sleep"];
const workItems = [];
app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static("public"));

app.get("/", function(req, res){
    const day = date.getDate();
    res.render("list", {listTitle: day, items: items});
});

app.post("/", function(req, res){
    const item = req.body.newItem;
    if(req.body.list === "Work"){
        workItems.push(item);
        res.redirect("/work");
    }
    else{
        items.push(item);
        res.redirect("/");
    }
    
});

app.get("/work", function(req, res){
    res.render("list", {listTitle: "Work List", items: workItems});
});

app.get("/about", function(req, res){
    res.render("about");
});

app.listen(3000, function(){
    console.log("server 3000")
});
//the lets can be a const, let, or var

/*
app.get("/", function(req, res){
    var today = new Date();
    if(today.getDay() === 6||today.getDay()===0){
        res.write("<h1>weekend!</h1>");
    }
    else{
        res.write("<h1>work day!</h1>");
    }
    res.send();
});

app.get("/", function(req, res){
    var today = new Date();
    var currentDay =today.getDay();
    var day = "";
    if(currentDay === 6||currentDay===0){
        day = "weekend";
        res.write("<h1>weekend!</h1>");
        res.send();
    }
    else{
        day = "weekday";
        res.sendFile(__dirname + "/index.html");
    }
    
});


//switch
    if(currentDay === 0){
        day = "sun";
    }
    else if (currentDay === 1){
        day = "mon";
    }
    else if (currentDay === 2){
        day = "tue";
    }
    else if (currentDay === 3){
        day = "wed";
    }
    else if (currentDay === 4){
        day = "thur";
    }
    else if (currentDay === 5){
        day = "fri";
    }
    else {
        day = "sat";
    }


    
*/