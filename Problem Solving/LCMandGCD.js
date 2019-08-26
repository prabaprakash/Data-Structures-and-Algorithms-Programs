function gcd(a,b){
  while(b!=0){
    let gcd = a % b;
    a = b;
    b = gcd;
  }
  return a;
}

function lcm(a,b) {
 return (a*b) / gcd(a,b);
}
function main() {
  let arr = [2, 7, 3, 9, 4];
  let l = arr[0];
  for(let i=1; i<arr.length; i++){
    l = lcm(l, arr[i]);
    console.log(arr[i]);
  }
  console.log(l);
}
main();
