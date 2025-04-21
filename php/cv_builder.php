<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = trim($_POST['name']);
    $email = trim($_POST['email']);
    $experience = trim($_POST['experience']);

    $cv_content = "====================\n";
    $cv_content .= "       CV\n";
    $cv_content .= "====================\n";
    $cv_content .= "Name: $name\n";
    $cv_content .= "Email: $email\n";
    $cv_content .= "--------------------\n";
    $cv_content .= "Experience:\n$experience\n";
    $cv_content .= "====================\n";

    $file_name = "cv_" . preg_replace("/[^a-zA-Z0-9]/", "", $name) . ".txt";
    file_put_contents($file_name, $cv_content);

    $download_link = "<p class='download-link'>CV generated successfully! <a href='$file_name' download>Download CV</a></p>";
} else {
    $download_link = "";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CV Generator</title>
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
        input, textarea {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
            font-size: 16px;
        }
        textarea {
            height: 100px;
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
            font-size: 16px;
        }
        button:hover {
            background-color: #0056b3;
        }
        .download-link {
            margin-top: 15px;
            color: #28a745;
            font-weight: bold;
        }
        .download-link a {
            text-decoration: none;
            color: #28a745;
        }
        .download-link a:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>Generate Your CV</h2>
        <form method="POST">
            <input type="text" name="name" placeholder="Your Name" required>
            <input type="email" name="email" placeholder="Your Email" required>
            <textarea name="experience" placeholder="Your Experience" required></textarea>
            <button type="submit">Generate CV</button>
        </form>
        <?php echo $download_link; ?>
    </div>

</body>
</html>
