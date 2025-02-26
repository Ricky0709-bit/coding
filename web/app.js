const monthSelect = document.getElementById("month");
const yearSelect = document.getElementById("year");
const calendarDiv = document.getElementById("calendar");

for (let i = 1; i <= 12; i++) {
    let option = document.createElement("option");
    option.value = i;
    option.text = new Date(0, i - 1).toLocaleString("default", { month: "long" });
    monthSelect.appendChild(option);
}

const currentYear = new Date().getFullYear();
for (let i = currentYear; i <= currentYear + 10; i++) {
    let option = document.createElement("option");
    option.value = i;
    option.text = i;
    yearSelect.appendChild(option);
}

function generateCalendar() {
    const month = parseInt(monthSelect.value);
    const year = parseInt(yearSelect.value);
    const firstDay = new Date(year, month - 1, 1).getDay();
    const daysInMonth = new Date(year, month, 0).getDate();
    let calendarHTML = "<table><thead><tr>";
    calendarHTML += "<th>Sun</th><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th></tr></thead><tbody>";
    let dayCounter = 1;
    for (let week = 0; week < 6; week++) {
        calendarHTML += "<tr>";
        for (let day = 0; day < 7; day++) {
            if (week === 0 && day < firstDay) {
                calendarHTML += "<td></td>";
            } else if (dayCounter > daysInMonth) {
                calendarHTML += "<td></td>";
            } else {
                calendarHTML += `<td>${dayCounter}</td>`;
                dayCounter++;
            }
        }
        calendarHTML += "</tr>";
    }
    calendarHTML += "</tbody></table>";
    calendarDiv.innerHTML = calendarHTML;
}

document.getElementById("changeBgBtn").addEventListener("click", () => {
    const colors = ["#FFB6C1", "#ADD8E6", "#90EE90", "#FFD700", "#FFA07A", "#DDA0DD"];
    document.body.style.backgroundColor = colors[Math.floor(Math.random() * colors.length)];
});

monthSelect.addEventListener("change", generateCalendar);
yearSelect.addEventListener("change", generateCalendar);

function calculateBMI() {
    let height = parseFloat(document.getElementById("height").value) / 100;
    let weight = parseFloat(document.getElementById("weight").value);
    let bmi = weight / (height * height);
    let result = "";
    
    if (bmi < 18.5) {
        result = "Underweight";
    } else if (bmi >= 18.5 && bmi < 24.9) {
        result = "Normal weight";
    } else if (bmi >= 25 && bmi < 29.9) {
        result = "Overweight";
    } else {
        result = "Obese";
    }
    
    document.getElementById("bmiResult").innerText = `BMI: ${bmi.toFixed(2)} - ${result}`;
}