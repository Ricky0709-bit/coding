<?php
$error = "";
$weatherTable = "";
$defaultCity = "Pune";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $city = trim($_POST["city"]);

    if (empty($city)) {
        $city = $defaultCity;
    }

    $apiKey = "73508b2289cc58199a62be52af1f97a5"; 
    $apiUrl = "https://api.openweathermap.org/data/2.5/weather?q={$city}&units=metric&appid={$apiKey}";

    $response = file_get_contents($apiUrl);
    $weatherData = json_decode($response, true);
    
    if ($weatherData && $weatherData['cod'] == 200) {
        $temp = $weatherData['main']['temp'];
        $feels_like = $weatherData['main']['feels_like'];
        $humidity = $weatherData['main']['humidity'];
        $pressure = $weatherData['main']['pressure'];
        $wind_speed = $weatherData['wind']['speed'];
        $wind_direction = $weatherData['wind']['deg'];
        $visibility = $weatherData['visibility'] / 1000; // Convert to km
        $weather_desc = ucfirst($weatherData['weather'][0]['description']);
        $country = $weatherData['sys']['country'];
        $city_name = $weatherData['name'];


        $weatherTable = "
            <table>
                <tr><th colspan='2'>Weather in {$city_name}, {$country}</th></tr>
                <tr><td>Temperature</td><td>{$temp}°C</td></tr>
                <tr><td>Feels Like</td><td>{$feels_like}°C</td></tr>
                <tr><td>Humidity</td><td>{$humidity}%</td></tr>
                <tr><td>Pressure</td><td>{$pressure} hPa</td></tr>
                <tr><td>Wind Speed</td><td>{$wind_speed} m/s</td></tr>
                <tr><td>Wind Direction</td><td>{$wind_direction}°</td></tr>
                <tr><td>Visibility</td><td>{$visibility} km</td></tr>
                <tr><td>Weather</td><td>{$weather_desc}</td></tr>
            </table>";
    } else {
        $error = "City not found. Please enter a valid city name.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Weather App</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            text-align: center;
            margin-top: 50px;
        }
        .container {
            background: white;
            padding: 20px;
            border-radius: 10px;
            width: 400px;
            margin: auto;
            box-shadow: 0px 0px 10px gray;
        }
        input, button {
            padding: 10px;
            margin: 5px;
            width: 80%;
            border-radius: 5px;
            border: 1px solid #ccc;
        }
        button {
            background-color: #007BFF;
            color: white;
            cursor: pointer;
            width: 85%;
        }
        .error {
            color: red;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 15px;
        }
        th, td {
            padding: 10px;
            border: 1px solid #ddd;
            text-align: left;
        }
        th {
            background-color: #007BFF;
            color: white;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>Weather App</h2>
        <form method="POST">
            <input type="text" name="city" placeholder="Enter city name (Default: Pune)">
            <button type="submit">Get Weather</button>
        </form>

        <?php if ($weatherTable): ?>
            <div class="weather"><?php echo $weatherTable; ?></div>
        <?php endif; ?>

        <?php if ($error): ?>
            <div class="error"><?php echo $error; ?></div>
        <?php endif; ?>
    </div>

</body>
</html>
