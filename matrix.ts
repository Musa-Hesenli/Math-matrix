// const element = document.createElement("div");
// element.className = "block";
// element.style = "background-color:red; width:200px; height:100px"
// document.body.appendChild(element);
// console.log(element);
const triangleMatrix = [
    [1, 4, 3],
    [-2, 0, -1],
    [0, 8, 5]
];

const tr_left = (triangleMatrix[0][0] * triangleMatrix[1][1] * triangleMatrix[2][2]) + (triangleMatrix[0][1] * triangleMatrix[1][2] * triangleMatrix[2][0]) + (triangleMatrix[1][0] * triangleMatrix[0][2] * triangleMatrix[2][1]);
const tr_right = (triangleMatrix[0][2] * triangleMatrix[1][1] * triangleMatrix[2][0]) + (triangleMatrix[0][1] * triangleMatrix[1][0] * triangleMatrix[2][2]) + (triangleMatrix[0][0] * triangleMatrix[2][1] * triangleMatrix[1][2]);
const determinant = tr_left - tr_right;
console.log("Determinant by triangle method:", determinant);

// Finding determinant using upper matrix
const matrix = [
    [1, 4, 3],
    [-2, 0, -1],
    [0, 8, 5]
];
console.log("Original matrix:");
matrix.forEach(el => {
    console.log(el);
});
const lowerMatrix = Array(matrix.length).fill(null).map(() => Array(matrix[0].length));
for(let i = 0; i < matrix.length; i++) {
    for(let j = 0; j < matrix[0].length; j++) {
        i ==j ? lowerMatrix[i][j] = 1 :lowerMatrix[i][j] = 0;
    }
}
const lenOfColumn = matrix[0].length - 1;



for(let s = 0; s < lenOfColumn; s++) {
    for(let i = s + 1; i < matrix.length; i++) {
        const divider = - (matrix[i][s] / matrix[s][s]);
        // matrix.forEach(el => {
        //     // console.log(el);
        // });
        // console.log("");
        lowerMatrix[i][s] = -(divider);
        for(let j = 0; j < matrix[i].length; j++) {
            const value = matrix[i][j] + divider * (matrix[s][j]);
            matrix[i][j] = value;
        };
    };
    // console.log("");
}
console.log("*****************Upper matrix********************")
matrix.forEach(el => {
    console.log(el);
});
console.log("*****************Lower matrix********************")
lowerMatrix.forEach(el => {
    console.log(el);
});


// Finding determinant according to the upper matrix
let determinant2 = 1;
for(let i = 0; i < matrix.length; i++) {
    // console.log(matrix[i][i]);
    determinant2 = determinant2 * matrix[i][i];

};
console.log('--------------------');
console.log("%cResult according to the upper matrix:", 'color:red', determinant2);