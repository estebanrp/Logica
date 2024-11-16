// Given an integer array nums, return true if any value appears at least twice in the array, and 
// return false if every element is distinct.

function isDuplicated(nums){
    let duplicated = false
    for (let i=0; i < nums.length; i++){
        for (let k=i+1; k < nums.length; k++){
            if (nums[i] == nums[k]){
                duplicated = true
            }
        }
    }
    return duplicated
}

const nums = [1,2,3,3,5,3,8,7]
const duplicated = isDuplicated(nums)
if (duplicated == true) {
    console.log(`contiene elementos repetidos`)    
} else {
    console.log(`todos los elementos son unicos`)
}
