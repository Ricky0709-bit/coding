function CtF(cel) {
    return (cel * 9/5) + 32;
}

function FtC(farh) {
    return (farh - 32) * 5/9;
}

function convert() {
    let temp = document.getElementById('temperature').value;
    let unit = document.getElementById('unit').value;
    let result = "";

    if(temp === "") {
        result = "Please enter a temperature.";
    }
    else {
        temp = parseFloat(temp);

        if(unit === "C") {
            result = `${temp}°C = ${CtF(temp).toFixed(2)}°F`;
        } else {
            result = `${temp}°F = ${FtC(temp).toFixed(2)}°C`;
        }
    }

    document.getElementById("result").innerText = result;
}
     