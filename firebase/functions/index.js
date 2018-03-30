// const functions = require('firebase-functions');

// // // Create and Deploy Your First Cloud Functions
// // // https://firebase.google.com/docs/functions/write-firebase-functions
// //
// // exports.alert = functions.https.onRequest((request, response) => {
    
// //     response.send("Hello from " + name);
// // });

const TelegramBot = require('node-telegram-bot-api');
const token = '572017543:AAFy1s2YoJf9a6kcUryIaoCKN9jUn9ftV_k';
const bot = new TelegramBot(token, {polling: true});

bot.on('message', (msg) => {
    var check = "check";
    if (msg.text.toString().toLowerCase().includes(check)) {
        bot.sendMessage(msg.chat.id, "check");
    } 
    
    var bye = "bye";
    if (msg.text.toString().toLowerCase().includes(bye)) {
        bot.sendMessage(msg.chat.id, "Hope to see you around again , Bye");
    } 
    
    var robot = "robot";
    if (msg.text.toString().toLowerCase().includes(robot)) {
        bot.sendMessage(msg.chat.id, "http://www.google.com");
    }

    var swar = "line";
    if (msg.text.includes(swar)) {
        bot.kickChatMember(msg.chat.id,  msg.from.id);
    }
    
    var bye = "bye";
    if (msg.text.toString().toLowerCase().includes(bye)) {
    bot.sendMessage(msg.chat.id, "Have a nice day " + msg.from.first_name); 
    } 
    
});

bot.onText(/\/start/, (msg) => {

    bot.sendMessage(msg.chat.id, "Welcome");
        
    });

bot.onText(/\/keyboard/, (msg) => {
    
    bot.sendMessage(msg.chat.id, "Select Option", {
        "reply_markup": {
            "keyboard": [["Alert", "Call 911"], ["Ignore"]]
            }
        });
        
    });

// bot.onText(/\/sendpic/, (msg) => {

//     bot.sendPhoto(msg.chat.id,"https://www.somesite.com/image.jpg",{caption : "Here we go ! \nThis is just a caption "} );
    
        
//     });
