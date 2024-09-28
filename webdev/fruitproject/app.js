//outdated
const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');

const url = 'mongodb://localhost:27017';
const dbName = 'fruitsDB';

const client = new MongoClient(url, {useNewUrlParser: true});

client.connect(function(err){
    assert.equal(null, err);
    console.log("Connected");
    const db = client.db(dbName);
    insertDocuments(db, function(){
        client.close();
    });
});

const insertDocuments = function(db, callback){
    const collection = db.collection('fruits');
    collection.insertMany([
        {name : apple}, {name : orange}, {name : banana}
    ], function(err, result){
        assert.equal(err, null);
        assert.equal(3, result.result.n);
        assert.equal(3, result.ops.length);
        console.log("Inserted 3 items");
        callback(result);
    });
};

const findDocuments = function(db, callback){
    const collection = db.collection('fruits');
    collection.find({}).toArray(function(err, fruits){
        assert.equal(err, null);
        console.log("Found the following records");
        console.log(fruits);
        callback(fruits);
    });
};

