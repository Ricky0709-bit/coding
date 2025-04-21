<?php
include 'db_connect.php';

if (!isset($_GET['id'])) {
    die("Error: ID not provided in the URL.");
}
$id = $_GET['id'];
$result = $conn->query("SELECT * FROM students WHERE id=$id");

if (!$result || $result->num_rows == 0) {
    die("Error: Student not found.");
}

$data = $result->fetch_assoc();

if (isset($_POST['update'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];

    $sql = "UPDATE students SET name='$name', email='$email', phone='$phone' WHERE id=$id";
    if ($conn->query($sql) === TRUE) {
        header("Location: read.php");
        exit;
    } else {
        $msg = "Error updating record: " . $conn->error;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Edit Student</title>
    <style>
        body { font-family: Arial; background: #f8f9fa; padding: 20px; }
        .form-box { background: #fff; padding: 20px; max-width: 400px; margin: auto; border-radius: 8px; box-shadow: 0 0 10px #ccc; }
        input { width: 100%; padding: 10px; margin: 10px 0; border-radius: 4px; border: 1px solid #ccc; }
        button { background: #28a745; color: white; padding: 10px; border: none; border-radius: 4px; cursor: pointer; }
        button:hover { background: #218838; }
        .msg { color: red; margin-top: 10px; }
    </style>
</head>
<body>
    <div class="form-box">
        <h2>Edit Student</h2>
        <form method="POST">
            <input type="text" name="name" value="<?= $data['name'] ?>" required>
            <input type="email" name="email" value="<?= $data['email'] ?>" required>
            <input type="text" name="phone" value="<?= $data['phone'] ?>" required>
            <button type="submit" name="update">Update</button>
        </form>
        <?php if (isset($msg)) echo "<div class='msg'>$msg</div>"; ?>
    </div>
</body>
</html>
