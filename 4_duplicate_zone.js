// Given an integer array nums and an integer k, return true if there are two distinct 
// indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

function isDuplicated(nums, zone){
    let duplicated = false
    for (let i=0; i < nums.length; i++){
        for (let k=i+1; k < nums.length; k++){
            if (nums[i] == nums[k] && (Math.abs(i - k) <= zone)){
                duplicated = true
            }
        }
    }
    return duplicated
}

const nums = [1,2,3,1,2,3]
const zone = 2
const duplicated = isDuplicated(nums, zone)
if (duplicated == true) {
    console.log(`contiene elementos repetidos en el rango especificado`)    
} else {
    console.log(`NO contiene elementos repetidos en el rango especificado`)    
}