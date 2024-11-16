// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

function pascalTri(numRows) {
  let triangle = []

  for (i = 0; i < numRows; i++) {
    let row = []
    for (let j = 0; j <= i; j++) {
      if (j == 0) {
        row.push(1)
      } else if (j == i) {
        row.push(1)
      } else {
        row.push(triangle[i - 1][j - 1] + triangle[i - 1][j])
      }
    }
    triangle.push(row)
  }
  return triangle
}
 
const numRows = 6
console.log(pascalTri(numRows)) //Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
