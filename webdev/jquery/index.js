$("h1").css("color","red");
$("h1").addClass("big-title margin");

$("button").text("Don't click me");
$("button").html("<em>hey</em>");

$("a").attr("href","https://www.yahoo.com");

$("h1").click(function (){
    $("h1").css("color","purple");
});

$("button").click(function (){
    $("h1").css("color","purple");
});

$("input").keypress(function (event){
    console.log(event.key);
});
$(document).keypress(function (event){
    $("h1").text(event.key);
});
$("h1").on("mouseover", function (event){
    $("h1").css("color","purple");
});

before("<button>new</button>") //after or prepend

$("button").click(function (){
    $("h1").fadeToggle();//fade, hidden, slide, animate and they all have a toggle
});
/*use this if the script is in the header
$(document).ready(function(){
    $("h1").css("color","red");
});
*/

/* $("h1"); works for one single and all selectors
document.querySelector("h1");
document.querySelectorAll("h1");

$("button").text("Don't click me");
this does not allow for tags while using html does

$("a").attr("href","https://www.yahoo.com");
attr is for attributes first one is for getting so href and setting is yahoo
$("img").attr("src")

$("button").click(function (){});
this is used for eventlisteners
for(var i=0;i<5;i++){
    document.querySelectorAll("button")[i].addEventListener("click", function (){
        document.querySelector("h1").style.color = "purple";
    });
}

this is for keypress
$("input").keypress(function (event){
    console.log(event.key);
});
*/
