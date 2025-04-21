<?php
include 'db_connect.php';

if (!isset($_GET['id'])) {
    die("Error: ID not provided.");
}

$id = $_GET['id'];

if (isset($_POST['confirm'])) {
    $conn->query("DELETE FROM students WHERE id=$id");
    header("Location: read.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Delete Student</title>
    <style>
        body { font-family: Arial; background: #f8f9fa; padding: 40px; text-align: center; }
        .box { background: white; padding: 30px; max-width: 400px; margin: auto; border-radius: 10px; box-shadow: 0 0 10px #ccc; }
        button { padding: 10px 20px; margin: 10px; border: none; border-radius: 5px; cursor: pointer; }
        .yes { background: #dc3545; color: white; }
        .no { background: #6c757d; color: white; text-decoration: none; display: inline-block; padding: 10px 20px; }
    </style>
</head>
<body>
    <div class="box">
        <h2>Are you sure you want to delete student ID <?= $id ?>?</h2>
        <form method="POST">
            <button type="submit" name="confirm" class="yes">Yes, Delete</button>
            <a href="read.php" class="no">Cancel</a>
        </form>
    </div>
</body>
</html>
