<?php include 'db_connect.php'; ?>
<?php $result = $conn->query("SELECT * FROM students"); ?>
<!DOCTYPE html>
<html>
<head>
    <title>Student Records</title>
    <style>
        body { font-family: Arial; padding: 20px; background: #eef2f3; }
        table { width: 80%; margin: auto; border-collapse: collapse; }
        th, td { padding: 10px; border: 1px solid #ccc; text-align: center; }
        th { background: #007BFF; color: white; }
        tr:nth-child(even) { background: #f2f2f2; }
    </style>
</head>
<body>
    <h2 style="text-align:center;">All Student Records</h2>
    <table>
        <tr><th>ID</th><th>Name</th><th>Email</th><th>Phone</th></tr>
        <?php while($row = $result->fetch_assoc()): ?>
            <tr>
                <td><?= $row['id'] ?></td>
                <td><?= $row['name'] ?></td>
                <td><?= $row['email'] ?></td>
                <td><?= $row['phone'] ?></td>
            </tr>
        <?php endwhile; ?>
    </table>
</body>
</html>
