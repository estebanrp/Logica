// You are climbing a staircase. It takes n steps to reach the top. Each time you can either 
// climb 1 or 2 steps. In how many distinct ways can you climb to the top?

function howWays(steps){
    if(steps == 1) {
        return 1
    } else if (steps == 2) {
        return 2
    } else {
        return howWays(steps-2) + howWays(steps-1)
    }
}

const steps = 5
console.log(howWays(steps))
