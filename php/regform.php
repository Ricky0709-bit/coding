<?php
session_start();
include "config.php"; 

$nameErr = $mobileErr = $emailErr = "";
$name = $mobile = $email = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = trim($_POST["name"]);
    $mobile = trim($_POST["mobile"]);
    $email = trim($_POST["email"]);

    if (empty($name)) {
        $nameErr = "Name is required.";
    } elseif (!preg_match("/^[a-zA-Z ]+$/", $name)) {
        $nameErr = "Only letters and spaces are allowed.";
    }

    if (empty($mobile)) {
        $mobileErr = "Mobile number is required.";
    } elseif (!preg_match("/^[0-9]{10}$/", $mobile)) {
        $mobileErr = "Invalid mobile number format. Must be 10 digits.";
    }

    if (empty($email)) {
        $emailErr = "Email is required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $emailErr = "Invalid email format.";
    }

    if (empty($nameErr) && empty($mobileErr) && empty($emailErr)) {
        $stmt = $conn->prepare("INSERT INTO users (name, mobile, email) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $name, $mobile, $email);

        if ($stmt->execute()) {
            $stmt->close();
            $conn->close();
            header("Location: welcome.php");
            exit();
        } else {
            echo "<script>alert('Error: Unable to save data. Please try again.');</script>";
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Authentication System</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
</head>
<body class="bg-light">

<div class="container mt-5">
    <div class="row justify-content-center">
        <div class="col-md-6">
            <div class="card shadow p-4">
                <h2 class="text-center mb-4">User Authentication</h2>
                <form method="post" action="">
                    <div class="mb-3">
                        <label class="form-label">Name</label>
                        <input type="text" name="name" class="form-control" value="<?php echo htmlspecialchars($name); ?>">
                        <small class="text-danger"><?php echo $nameErr; ?></small>
                    </div>

                    <div class="mb-3">
                        <label class="form-label">Mobile</label>
                        <input type="text" name="mobile" class="form-control" value="<?php echo htmlspecialchars($mobile); ?>">
                        <small class="text-danger"><?php echo $mobileErr; ?></small>
                    </div>

                    <div class="mb-3">
                        <label class="form-label">Email</label>
                        <input type="text" name="email" class="form-control" value="<?php echo htmlspecialchars($email); ?>">
                        <small class="text-danger"><?php echo $emailErr; ?></small>
                    </div>

                    <div class="text-center">
                        <button type="submit" class="btn btn-primary">Submit</button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>

</body>
</html>
