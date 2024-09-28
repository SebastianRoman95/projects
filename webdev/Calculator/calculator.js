const express = require("express");
const app = express();

app.get("/", function(req, res){
    res.sendFile(__dirname + "/index.html");
});

app.post("/", function(req, res){
    res.send("");
});

app.listen(3000, function(req, res){
    console.log("server 3000");
});
