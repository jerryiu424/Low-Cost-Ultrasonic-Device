<?php
$host = 'localhost';
$db   = 'group10';
$user = 'user';
$pass = 'pass';
$charset = 'utf8mb4';

$dsn = "mysql:host=$host;dbname=$db;charset=$charset";
$options = [
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_EMULATE_PREPARES   => false,
];
try {
     $pdo = new PDO($dsn, $user, $pass, $options);
} catch (\PDOException $e) {
     throw new \PDOException($e->getMessage(), (int)$e->getCode());
}

//$schedule_id = htmlspecialchars($_GET['sensor']);
$items = [];

$stmt = $pdo->prepare("SELECT * FROM sesnor WHERE sensorID = 1");
//$stmt->execute([$schedule_id]);

echo $stmt;

?>
<!DOCTYPE html>
<html lang="en">

</html>
