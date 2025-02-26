function generateFibo(n) {
    let a = 0, b = 1, next;
    let result = "";

    if (n < 1) return "0";
    result += "0";
    
    if (n >= 1) result += ", 1";
    
    next = a + b;
    while (next <= n) {
        result += ", " + next;
        a = b;
        b = next;
        next = a + b;
    }

    return result;
}

function displayFibo() {
    const input = document.getElementById('Input').value;
    const n = parseInt(input);

    if (isNaN(n) || n < 0) {
        alert('Please enter a non-negative integer.');
        return;
    }

    const result = document.getElementById('Output');
    result.innerHTML = `Fibonacci Series up to ${n}: <strong>${generateFibo(n)}</strong>`;
}
