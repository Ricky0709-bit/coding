function forLoop() {
    let output = "";
    for (let i = 1; i <= 10; i++) {
        output += i + " ";
    }
    document.getElementById("for-loop").innerText = output;
}

function whileLoop() {
    let output = "";
    let i = 1;
    while (i <= 5) {
        output += i + " ";
        i++;
    }
    document.getElementById("while-loop").innerText = output;
}

function doWhileLoop() {
    let output = "";
    let j = 1;
    do {
        output += j + " ";
        j++;
    } while (j <= 12);
    document.getElementById("do-while-loop").innerText = output;
}

function breakLoop() {
    let output = "";
    for (let k = 1; k <= 10; k++) {
        if (k === 5) {
            break;
        }
        output += k + " ";
    }
    document.getElementById("break-loop").innerText = output;
}

function runLoops() {
    forLoop();
    whileLoop();
    doWhileLoop();
    breakLoop();
}

runLoops();