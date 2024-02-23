function collecting(rowsizeA, colsizeA, rowsizeB, colsizeB) {
    let A = [];
    let B = [];
    for (let i = 0; i < rowsizeA; i++) {
        console.log(`For A give the values for row ${i + 1}.`);
        let v1 = [];
        for (let j = 0; j < colsizeA; j++) {
            // In JavaScript, you would typically collect input from the DOM or a prompt
            // Here we'll just simulate it with a placeholder function
            let num1 = getInputElementValue(); // Placeholder for input collection
            v1.push(num1);
        }
        A.push(v1);
    }
    console.log();
    for (let i = 0; i < rowsizeB; i++) {
        console.log(`For B give the values for row ${i + 1}.`);
        let v2 = [];
        for (let j = 0; j < colsizeB; j++) {
            let num2 = getInputElementValue(); // Placeholder for input collection
            v2.push(num2);
        }
        B.push(v2);
    }
    console.log();
    return { A, B };
}

function displaying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B) {
    console.log("\nYour matrix A");
    for (let i = 0; i < rowsizeA; i++) {
        console.log(A[i].join(" "));
    }
    console.log("\nYour matrix B");
    for (let i = 0; i < rowsizeB; i++) {
        console.log(B[i].join(" "));
    }
    console.log();
}

function multiplying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B) {
    let C = [];
    for (let i = 0; i < rowsizeA; i++) {
        C.push(new Array(colsizeB).fill(0));
    }
    for (let n = 0; n < rowsizeA; n++) {
        for (let m = 0; m < colsizeB; m++) {
            let sum = 0;
            for (let i = 0; i < colsizeA; i++) {
                sum += A[n][i] * B[i][m];
            }
            C[n][m] = sum;
        }
    }
    console.log("Multiplied matrix C:");
    for (let i = 0; i < rowsizeA; i++) {
        console.log(C[i].join(" "));
    }
    console.log();
}

// Example usage:
// let { A, B } = collecting(rowsizeA, colsizeA, rowsizeB, colsizeB);
// displaying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
// multiplying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);

// Note: The function getInputElementValue() is a placeholder for actual input collection logic.
// In a real-world scenario, you would replace this with code to get input from the user, such as prompt() or from an HTML form.
