function checkNumber() {
    let num = Number(document.getElementById("ifElseInput").value);
    let output = "";
    if (num > 0) {
        output = "The number is positive.";
    } else if (num < 0) {
        output = "The number is negative.";
    } else {
        output = "The number is zero.";
    }
    document.getElementById("ifElseOutput").innerText = output;
}

function checkDay() {
    let day = Number(document.getElementById("switchInput").value);
    let output = "";
    switch (day) {
        case 1: output = "Sunday"; break;
        case 2: output = "Monday"; break;
        case 3: output = "Tuesday"; break;
        case 4: output = "Wednesday"; break;
        case 5: output = "Thursday"; break;
        case 6: output = "Friday"; break;
        case 7: output = "Saturday"; break;
        default: output = "Invalid day number!";
    }
    document.getElementById("switchOutput").innerText = output;
}

function checkGrade() {
    let marks = Number(document.getElementById("marksInput").value);
    let output = "";
    if (marks >= 90) {
        output = "Grade: A";
    } else if (marks >= 80) {
        output = "Grade: B";
    } else if (marks >= 70) {
        output = "Grade: C";
    } else if (marks >= 60) {
        output = "Grade: D";
    } else {
        output = "Grade: F";
    }
    document.getElementById("gradeOutput").innerText = output;
}