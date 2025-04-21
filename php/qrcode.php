<?php
require_once __DIR__ . '/phpqrcode/qrlib.php';

$qrCode = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $url = trim($_POST['url']);

    if (!empty($url)) {
        $file = 'qrcode.png';
        QRcode::png($url, $file, QR_ECLEVEL_L, 10, 2);
        $qrCode = "<img src='$file' alt='QR Code'>";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>QR Code Generator</title>
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
        input {
            width: 90%;
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
            font-size: 16px;
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
        .qr-code {
            margin-top: 15px;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>QR Code Generator</h2>
        <form method="POST">
            <input type="text" name="url" placeholder="Enter URL (e.g., https://example.com)" required>
            <button type="submit" name="generate_qr">Generate QR Code</button>
        </form>
        <div class="qr-code">
            <?php echo $qrCode; ?>
        </div>
    </div>

</body>
</html>
