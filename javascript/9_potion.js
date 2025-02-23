// During Halloween night 🎃, a witch 🧙‍♀️ is preparing a magical brew. She has a list of potions, each with an 
// associated power, and she wants to combine two of them to achieve a specific total power. Given a list of 
// integers where each number represents the power of a potion 🧪 and an integer representing the target 
// power, you must find the index of the first two potions that add up to exactly the target power.

const potions = [1, 2, 3, 4]
const target = 5

const selectPotion = (arreglo, objetivo) => {
  let aux = []
  for (let i = 0; i < arreglo.length; i++) {
    for (let j = i + 1; j < arreglo.length; j++) {
      if (arreglo[i] + arreglo[j] == objetivo) {
        aux.push(i)
        aux.push(j)
        return aux
      }
    }
  }
}

console.log(selectPotion(potions, target))

