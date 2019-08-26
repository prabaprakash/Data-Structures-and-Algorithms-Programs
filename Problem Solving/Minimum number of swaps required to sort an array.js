 
 function sortByKey(array, key) {
    return array.sort(function(a, b) {
        var x = a[key]; var y = b[key];
        return ((x < y) ? -1 : ((x > y) ? 1 : 0));
    });
}

 function minimumSwaps(arr) {
  let arrPos = [];
  let vis = {};
    for (let i = 0; i < arr.length; i++){
        arrPos[i] = { first: arr[i], second: i };
        vis[i] = false;
    }
    arrPos = sortByKey(arrPos, "first");
   

   let ans = 0; 

	// Traverse array elements 
	for (let i = 0; i < arr.length; i++) 
	{ 
     console.log(arrPos[i])
		// already swapped and corrected or 
		// already present at correct pos 
		if (vis[i] || arrPos[i].second == i) 
			continue; 

		// find out the number of node in 
		// this cycle and add in ans 
		let cycle_size = 0; 
		let j = i; 
    console.log(arrPos);
    console.log("-------------------------------------------");
		while (!vis[j]) 
		{ 
      console.log(arrPos[j])
			vis[j] = 1; 

			// move to next node 
			j = arrPos[j].second; 
			cycle_size++; 
		} 
    console.log("-------------------------------------------");

		// Update answer by adding current cycle. 
		if (cycle_size > 0) 
		{ 
			ans += (cycle_size - 1); 
		} 
	} 
  return ans;
 }
 minimumSwaps([2, 3, 4, 1, 5]);
