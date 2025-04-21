<?php include 'db_connect.php'; ?>

<?php
if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];
    $sql = "INSERT INTO students (name, email, phone) VALUES ('$name', '$email', '$phone')";
    if ($conn->query($sql) === TRUE) {
        $msg = "Record added successfully.";
    } else {
        $msg = "Error: " . $conn->error;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Add Student</title>
    <style>
        body { font-family: Arial; background: #f4f4f4; padding: 20px; }
        .form-box { background: #fff; padding: 20px; max-width: 400px; margin: auto; border-radius: 8px; box-shadow: 0 0 10px #ccc; }
        input { width: 100%; padding: 10px; margin: 10px 0; border-radius: 4px; border: 1px solid #ccc; }
        button { background: #007BFF; color: white; padding: 10px; border: none; border-radius: 4px; cursor: pointer; }
        button:hover { background: #0056b3; }
        .msg { margin-top: 10px; color: green; }
    </style>
</head>
<body>
    <div class="form-box">
        <h2>Add Student</h2>
        <form method="POST">
            <input type="text" name="name" placeholder="Enter name" required>
            <input type="email" name="email" placeholder="Enter email" required>
            <input type="text" name="phone" placeholder="Enter phone number" required>
            <button type="submit" name="submit">Add</button>
        </form>
        <?php if (isset($msg)) echo "<div class='msg'>$msg</div>"; ?>
    </div>
</body>
</html>
