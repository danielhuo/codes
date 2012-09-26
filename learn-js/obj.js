var arr = []
console.log(arr.length);        // 0
if("length" in arr) {
    console.log("arr has length property");
}
if(!arr.propertyIsEnumerable("length")) {
    console.log("arr length property cannot be enumerable");
}
for(var p in arr) {
    console.log(p);             // output nothing
}

arr[99] = 1;
console.log(arr.length);        // output 100

arr[-1] = 1;
console.log(arr.length);        // output 100

for(var p in arr) {             // ouput: 99 => 1, -1 => 1
    console.log(p + " => " + arr[p]);
}
for(var i = 0; i < arr.length; ++i) {       // only: 99 => 1
    if(arr[i]) console.log(i + " => " + arr[i]);
}
