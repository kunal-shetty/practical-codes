<?php
include('db.php');

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $roll_number = $_POST['roll_number'];
    $email = $_POST['email'];
    $contact_number = $_POST['contact_number'];
    $course = $_POST['course'];
    $semester = $_POST['semester'];
    $subjects = $_POST['subjects'];
    $declaration = $_POST['declaration'];

    $sql = "INSERT INTO atkt_applications (name, roll_number, email, contact_number, course, semester, subjects, declaration)
            VALUES ('$name', '$roll_number', '$email', '$contact_number', '$course', '$semester', '$subjects', '$declaration')";

    if ($conn->query($sql) === TRUE) {
        $last_id = $conn->insert_id;
        echo "Application submitted successfully. Application ID: " . $last_id;
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $uploadDirectory = "uploads/";

    $fileNames = [];
    for ($i = 1; $i <= 4; $i++) {
        if (isset($_FILES["document$i"]) && $_FILES["document$i"]["error"] == 0) {
            $fileName = basename($_FILES["document$i"]["name"]);
            $targetFilePath = $uploadDirectory . $fileName;
            
            if (move_uploaded_file($_FILES["document$i"]["tmp_name"], $targetFilePath)) {
                $fileNames[] = $fileName;
                $fileSql = "INSERT INTO atkt_files (application_id, file_name) VALUES ('$last_id', '$fileName')";
                $conn->query($fileSql);
            }
        }
    }

    $conn->close();
}
?>
