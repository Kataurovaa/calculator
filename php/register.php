<?php
    $login = filter_var(trim($_POST['login']), FILTER_SANITIZE_STRING);
    $password = filter_var(trim($_POST['password']), FILTER_SANITIZE_STRING);

    /*if(mb_strlen($login) < 1 || mb_strlen($login) > 90) {
        echo "Недопустимая длина логина";
        exit();
    } else if(mb_strlen($password) < 1 || mb_strlen($password) > 15) {
        echo "Недопустимая длина пароля (от 8 до 15 символов)";
        exit();
    } */

    $password = md5($password."cfguw2");
    $mysql = new mysqli('localhost', 'root', '', 'register');
    $mysql->query("INSERT INTO `users` (`login`, `password`) VALUES('$login', '$password')");

    $mysql->close();

    header('Location: /calculator');
    exit();

?>