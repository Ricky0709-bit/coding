<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Comment System</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
        }
        .container {
            background: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
            width: 400px;
            text-align: center;
        }
        h2 {
            color: #333;
        }
        textarea {
            width: 100%;
            height: 80px;
            padding: 10px;
            border: 1px solid #ddd;
            border-radius: 5px;
            resize: none;
        }
        button {
            background: #007bff;
            color: white;
            border: none;
            padding: 10px;
            width: 100%;
            border-radius: 5px;
            cursor: pointer;
            margin-top: 10px;
            font-size: 16px;
        }
        button:hover {
            background: #0056b3;
        }
        .comments {
            margin-top: 20px;
            text-align: left;
        }
        .comment-box {
            background: #f9f9f9;
            padding: 10px;
            margin: 5px 0;
            border-left: 4px solid #007bff;
            border-radius: 5px;
        }
    </style>
</head>
<body>

<div class="container">
    <h2>Leave a Comment</h2>

    <?php
    $conn = mysqli_connect("localhost", "root", "", "lab_6");

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $comment = trim($_POST['comment']); 
        if (!empty($comment)) { 
            $sql = "INSERT INTO comments (comment) VALUES (?)";
            $stmt = mysqli_prepare($conn, $sql);
            mysqli_stmt_bind_param($stmt, "s", $comment);
            mysqli_stmt_execute($stmt);
            mysqli_stmt_close($stmt);
        }
    }
    ?>

    <form method="POST">
        <textarea name="comment" placeholder="Write your comment..." required></textarea>
        <button type="submit">Post Comment</button>
    </form>

    <div class="comments">
        <h3>Recent Comments:</h3>
        <?php
        $result = mysqli_query($conn, "SELECT comment FROM comments ORDER BY id DESC");
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<div class='comment-box'>" . htmlspecialchars($row['comment']) . "</div>";
        }
        ?>
    </div>
</div>

</body>
</html>
