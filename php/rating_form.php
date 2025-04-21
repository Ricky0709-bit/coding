<?php
$conn = mysqli_connect("localhost", "root", "", "lab_6");

if (!$conn) {
    die("Database connection failed: " . mysqli_connect_error());
}

if (isset($_POST['rate'])) {
    $rating = $_POST['rating'];
    $item_id = $_POST['item_id'];

    $sql = "INSERT INTO ratings (item_id, rating) VALUES (?, ?)";
    $stmt = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($stmt, "ii", $item_id, $rating);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);

    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}

$item_id = 1; 
$result = mysqli_query($conn, "SELECT AVG(rating) AS average FROM ratings WHERE item_id = '$item_id'");
$row = mysqli_fetch_assoc($result);
$average_rating = round($row['average'], 1);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Rating System</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .container {
            width: 40%;
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
            text-align: center;
        }
        h2 {
            color: #333;
        }
        .rating-box {
            font-size: 24px;
            margin: 10px 0;
            color: #ffcc00;
        }
        .rating-input {
            display: flex;
            justify-content: center;
            gap: 5px;
            margin-top: 10px;
        }
        input[type="number"] {
            width: 50px;
            text-align: center;
            padding: 5px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        button {
            background-color: #007bff;
            color: white;
            padding: 10px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            margin-top: 10px;
            width: 100%;
        }
        button:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>Rate This Item</h2>
        <p>Average Rating:</p>
        <div class="rating-box">
            ⭐ <?php echo $average_rating ? $average_rating : "No ratings yet"; ?>
        </div>

        <form method="POST">
            <input type="hidden" name="item_id" value="1">
            <div class="rating-input">
                <label>Rate (1-5):</label>
                <input type="number" name="rating" min="1" max="5" required>
            </div>
            <button type="submit" name="rate">Submit Rating</button>
        </form>
    </div>

</body>
</html>
