//You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a 
// different day in the future to sell that stock. Return the maximum profit you can achieve 
// from this transaction. If you cannot achieve any profit, return 0.

function profit(prices) {
    let lowerPrice = Infinity
    let indexLower = 0
    for (let i=0; i < prices.length; i++){
        if (prices[i] < lowerPrice) {
            lowerPrice = prices[i]
            indexLower = i
        }
    }

    let higherPrice = lowerPrice
    for (let i = indexLower + 1; i < prices.length; i++) {
        if (prices[i] > higherPrice) {
            higherPrice = prices[i]
        }
    }

    if (higherPrice != prices[indexLower]) {
        return (higherPrice - lowerPrice)
    } else {
        return 0
    }
}

const lista = [7,1,5,3,20,4]
const maxProfit = profit(lista)
console.log(`El mayo profit posible es: ${maxProfit}`)
