const express = require('express');
const https = require('https');
const path = require('path');
const fs = require('fs');

const app = express();

app.get('/',(req,res)=>{
    res.send("Hello from SSL");
})


const sslServer = https.createServer({
    key : fs.readFileSync(path.join(__dirname,'cert','key.pem')),
    cert: fs.readFileSync(path.join(__dirname,'cert','cert.pem'))
} , app)

sslServer.listen(3443,()=>{
    console.log("Secure server on port 3443");
})

app.listen(8080,()=>{
    console.log("server is running on port 8080");
})






