/* si tengo una matriz n por m en la que cada celsa tiene un numero que equivale al costo de 
pasar por esa casilla y debo encontrar el camino menos costoso desde la posición 0,0 
hasta m-1,m-1 y solo puedo desplazarme hacia la derecha y hacia abajo. Como resolverias 
este problema en JS */

function caminoMinimo(matriz) {
  const n = matriz.length;
  const m = matriz[0].length;
  const costos = Array.from({ length: n }, () => Array(m).fill(0));
  costos[0][0] = matriz[0][0];

  for (let j = 1; j < m; j++) {
    costos[0][j] = costos[0][j - 1] + matriz[0][j];
  }
  for (let i = 1; i < n; i++) {
    costos[i][0] = costos[i - 1][0] + matriz[i][0];
  }
  for (let i = 1; i < n; i++) {
    for (let j = 1; j < m; j++) {
      costos[i][j] =
        matriz[i][j] + Math.min(costos[i - 1][j], costos[i][j - 1]);
    }
  }

  return costos[n - 1][m - 1];
}

const matriz = [
  [1, 3, 1, 2],
  [1, 5, 1, 3],
  [4, 2, 1, 4],
];

console.log(caminoMinimo(matriz)); 
