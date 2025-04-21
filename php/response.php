<?php
$conn = mysqli_connect("localhost", "root", "", "lab_6");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $action = $_POST['action'];
    $item_id = $_POST['item_id'];

    if ($action == 'like') {
        $sql = "UPDATE response SET likes = likes + 1 WHERE id = '$item_id'";
    } elseif ($action == 'dislike') {
        $sql = "UPDATE response SET dislikes = dislikes + 1 WHERE id = '$item_id'";
    }

    mysqli_query($conn, $sql);
}

$item_id = 1;
$result = mysqli_query($conn, "SELECT likes, dislikes FROM response WHERE id = '$item_id'");
$row = mysqli_fetch_assoc($result);
$likes = $row['likes'];
$dislikes = $row['dislikes'];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Like & Dislike System</title>
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
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
            text-align: center;
            width: 350px;
        }
        h2 {
            color: #333;
        }
        .btn {
            border: none;
            padding: 10px 15px;
            font-size: 16px;
            margin: 10px;
            cursor: pointer;
            border-radius: 5px;
            transition: 0.3s;
        }
        .like-btn {
            background-color: #28a745;
            color: white;
        }
        .like-btn:hover {
            background-color: #218838;
        }
        .dislike-btn {
            background-color: #dc3545;
            color: white;
        }
        .dislike-btn:hover {
            background-color: #c82333;
        }
        .count {
            font-size: 18px;
            font-weight: bold;
            margin-top: 10px;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>Like & Dislike System</h2>
        <form method="POST">
            <input type="hidden" name="item_id" value="1">
            <button type="submit" name="action" value="like" class="btn like-btn">👍 Like</button>
            <button type="submit" name="action" value="dislike" class="btn dislike-btn">👎 Dislike</button>
        </form>
        <div class="count">
            Likes: <span style="color: green;"><?php echo $likes; ?></span> |
            Dislikes: <span style="color: red;"><?php echo $dislikes; ?></span>
        </div>
    </div>

</body>
</html>
