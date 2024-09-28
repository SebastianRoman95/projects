const mongoose = require("mongoose");
mongoose.connect("mongodb://localhost:27017/todolistDB", {useNewUrlParser: true});

const fruitSchema = new mongoose.Schema({
    name:{
        type: String,
        require:[true, "check name"]
    },
    rating: {
        type: Number,
        min: 1,
        max: 10
    },
    review: String
});

const Fruit = mongoose.model("Fruit", fruitSchema);
const fruit = new Fruit({
    name: "Apple",
    rating: 2,
    review: "Bad"
});
fruit.save();



const personSchema = new mongoose.Schema({
    name:String,
    age: Number,
    favouriteFruit: fruitSchema
});

const Person = mongoose.model("Person", personSchema);
const person = new Person({
    name: "john",
    rating: 22
    //favouriteFruit: Apple
});

 //person.updateOne({name: "john"},{favouriteFruit: Apple}, function(err){
//    if(err){
  //      console.log(err);
//    }
 //   else{
   //     console.log("success");
 //   }  
//});

person.save();

Fruit.find(function(err, fruits){
    if(err){
        console.log(err);
    }
    else{
        mongoose.connect.close();
        //console.log(fruits);
        fruits.forEach(function(fruit){
            console.log(fruit.name);
        });
    }   
});

Fruit.updateOne({_id: ""}, {name: "Peach"}, function(err){
    if(err){
        console.log(err);
    }
    else{
        console.log("success");
    }   
});

Fruit.deleteOne({name: "Peach"}, function(err){
    if(err){
        console.log(err);
    }
    else{
        console.log("success");
    }   
});

Person.deleteMany({name: "John"}, function(err){
    if(err){
        console.log(err);
    }
    else{
        console.log("success");
    }   
});