function generateMatrixInputs() {
    const rowsizeA = parseInt(document.getElementById('rowsizeA').value);
    const colsizeA = parseInt(document.getElementById('colsizeA').value);
    const rowsizeB = parseInt(document.getElementById('rowsizeB').value);
    const colsizeB = parseInt(document.getElementById('colsizeB').value);

    generateMatrixInputsFor('matrixInputsA', 'A', rowsizeA, colsizeA);
    generateMatrixInputsFor('matrixInputsB', 'B', rowsizeB, colsizeB);
}

function generateMatrixInputsFor(containerId, matrixName, rows, cols) {
    const container = document.getElementById(containerId);
    container.innerHTML = ''; // Clear existing content

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            const inputId = `${matrixName}_${i}_${j}`;
            const label = document.createElement('label');
            label.setAttribute('for', inputId);
            label.textContent = `${matrixName}[${i}][${j}]: `;
            
            const input = document.createElement('input');
            input.setAttribute('type', 'number');
            input.setAttribute('id', inputId);
            input.setAttribute('name', inputId);
            input.setAttribute('required', 'true');

            container.appendChild(label);
            container.appendChild(input);
        }
        container.appendChild(document.createElement('br'));
    }
}

function collectAndMultiply() {
    const rowsizeA = parseInt(document.getElementById('rowsizeA').value);
    const colsizeA = parseInt(document.getElementById('colsizeA').value);
    const rowsizeB = parseInt(document.getElementById('rowsizeB').value);
    const colsizeB = parseInt(document.getElementById('colsizeB').value);

    const A = collecting(rowsizeA, colsizeA, 'matrixInputsA');
    const B = collecting(rowsizeB, colsizeB, 'matrixInputsB');

    displaying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
    multiplying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
}

function collecting(rowsize, colsize, containerId) {
    const matrixInputs = document.getElementById(containerId).getElementsByTagName('input');
    const matrix = [];

    let currentIndex = 0;
    for (let i = 0; i < rowsize; i++) {
        const row = [];
        for (let j = 0; j < colsize; j++) {
            row.push(parseInt(matrixInputs[currentIndex].value));
            currentIndex++;
        }
        matrix.push(row);
    }

    return matrix;
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

    const resultDiv = document.getElementById('result');
    resultDiv.innerHTML = "<h2>Multiplied Matrix C:</h2>";

    const resultTable = document.createElement('table');
    for (let i = 0; i < rowsizeA; i++) {
        const row = document.createElement('tr');
        for (let j = 0; j < colsizeB; j++) {
            const cell = document.createElement('td');
            cell.textContent = C[i][j];
            row.appendChild(cell);
        }
        resultTable.appendChild(row);
    }
    resultDiv.appendChild(resultTable);
}
