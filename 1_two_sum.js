//Given an array of integers nums and an integer target, return indices of the two numbers such that 
// they add up to target. You may assume that each input would have exactly one solution, and you may 
// not use the same element twice. You can return the answer in any order.
//

function twoSum(nums, target) {
    // Creamos un objeto para almacenar los índices de los números vistos
    const numIndices = {};
  
    // Iteramos sobre el array de números
    for (let i = 0; i < nums.length; i++) {
      // Calculamos el complemento que necesitamos para llegar al target
      const complement = target - nums[i];
  
      // Si el complemento ya está en numIndices, devolvemos el par de índices
      if (numIndices[complement] !== undefined) {
        return [numIndices[complement], i];
      }
  
      // Guardamos el índice del número actual en numIndices
      numIndices[nums[i]] = i;
    }
  
    // Si no se encuentra una solución, devolvemos un array vacío
    return [];
  }
  
  // Ejemplo de uso
  const nums = [3, 12, 7, 15];
  const target = 10;
  const result = twoSum(nums, target);
  console.log("Índices de los elementos que suman el target:", result);