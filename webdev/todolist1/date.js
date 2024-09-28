//console.log(module);
exports.getDate = function (){
    const today = new Date();
    //var currentDay =today.getDay(); 
    //first day is in list
    const options = {
        weekday: "long",
        day: "numeric",
        month: "long"
    };
    return today.toLocaleDateString("en-US", options);
};

exports.getDay = function (){
    const today = new Date();
    //var currentDay =today.getDay(); 
    //first day is in list
    const options = {
        weekday: "long",
    };
    return today.toLocaleDateString("en-US", options);
};

/*
simple
module.exports.getDate = getDate;
function getDate(){
    let today = new Date();
    //var currentDay =today.getDay(); 
    //first day is in list
    let options = {
        weekday: "long",
        day: "numeric",
        month: "long"
    };
    return today.toLocaleDateString("en-US", options);
}

module.exports.getDay = getDay;
function getDay(){
    let today = new Date();
    //var currentDay =today.getDay(); 
    //first day is in list
    let options = {
        weekday: "long",
    };
    return today.toLocaleDateString("en-US", options);
}

simple 2nd
module.exports.getDate = function (){
    let today = new Date();
    //var currentDay =today.getDay(); 
    //first day is in list
    let options = {
        weekday: "long",
        day: "numeric",
        month: "long"
    };
    return today.toLocaleDateString("en-US", options);
};
*/