function hideString(str, done) {
    process.nextTick(()=>{
     done(str);
    });
}

hideString("hello world", (hidden)=>{
    console.log(hidden);
})

console.log('end');