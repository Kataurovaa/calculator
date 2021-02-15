




<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<style>
		* {
    		margin: 0;
   			padding: 0;
   		  }
        @font-face {
         font-family: Monospaced; 
         src: url(fonts/20219.ttf);  
        }
        h1 {
         font-family: Monospaced, 'Codename Coder Free 4F',bold;
        }
		p {
         font-family: Monospaced, 'Codename Coder Free 4F',bold;
        }
       </style>
	<title>
		Calculator
	</title>
	<link rel="stylesheet" href="css/style.css">
</head>
<body>
	<div class="fill-black" id="fill-black"></div>
	<div class="header">
		<h1 class="header-child">
			C A L C U L A T O R
		</h1>
		<?php if ($_COOKIE['user'] != ''):?> 
		<div class="header-chld">
			<div class="header-child1">
			<p class="txt-user">Привет, <?=$_COOKIE['user']?>!</p>
				<p class="txt-user">
					<button type="button" onmousedown="viewProp()"><img src="img/user.svg" width="50" height="50"></button>
				</p>
			</div>
		</div>
		<?php else: ?>
		<div class="header-chld">
			<div class="header-child1"><img src="img/login.svg" width="54" height="54" ></div>
			<button class="header-child2" type="button"  onmousedown="viewReg()"><p>вход/регистрация</p></button>
		</div>
		<?php endif; ?>
		
	</div>
	<div class="parent">
		<div class="child">
			<h1 class="word1">ЗАГРУЗИТЕ ФАЙЛ</h1>
			<button class="b1"  type="button"  onmousedown="viewFile()"><h1 class="word2">ЗАГРУЗИТЬ</h1></button>
		</div>
		<div class="child">
			<div class = "child2">
				<p>Наш калькулятор работает с:</p>
			</div>
			<div class = "child2">
				<p>
					>PI - число π<br>
					>e - число эйлера<br>
					>j - мнимая единица<br>
					<span title="Косинус">>cos()<br></span>
					<span title="Синус">>sin()<br></span>
					<span title="Тангенс">>tg()<br></span>
					<span title="Логарифм">>log()<br></span>
					<span title="Натуральный логарифм">>ln()<br></span>
				</p>
			</div>
			<div class = "child2">
				<p>
					<span title="Корень из числа">>sqrt()<br></span>
					<span title="Возвести в степень">>pow()<br></span>
					<span title="Модуль числа">>abs()<br></span>
					<span title="Экспонента">>exp()<br></span>
					<span title="ХЗ">>real()<br></span>
					<span title="ХЗ">>imag()<br></span>
					<span title="ХЗ">>mag()<br></span>
					<span title="ХЗ">>phase()</span>
				</p>
			</div>
		</div>
	</div>
	<div class="decision">
		<div  class="exer">
			<h1 class="e-word" align="center">ПРИМЕР</h1>
			<div class="field">
				<h1 class="e"><?php
						if (isset($_POST['submit']) and $_FILES)
						{
							// Получаем расширение файла
							$file_ext =  strtolower(strrchr($_FILES['file']['name'],'.'));
							// Генерируем случайное число
							$file_name = 1;
							// Формируем путь на сервере
							$uploadedFile  = "uploades/".$file_name.$file_ext;
							move_uploaded_file($_FILES['file']['tmp_name'],$uploadedFile);
							$fd = fopen("uploades/1.txt", 'r') or die("не удалось открыть файл");
							$str = fgets($fd);
							$str = fgets($fd);
							fclose("uploades/1.txt");
							echo $str;
						}
					?>		
				</h1>
			</div>
		</div>
		<div>
			<h1 class="e-word" align="center">РЕШЕНИЕ</h1>
			<div class="d-field">
				<?php
					system("C:/Server/data/htdocs/calculator/calc/release/calc.exe") or die("Err");
				?>
			</div>
		</div>
	</div>
	<div class="registration" id="registration">
		<button class="exit-reg" type="button" onmousedown="closeFill()"><img src="img/cancel.svg" alt="exit" width="20" height="20"></button>
		<div class="reg-child" >
			<p align="center" class="window-word">Зарегестрироваться</p>	
		</div>
		<form action="php/register.php" method="post" class="reg-child" id = "data">
			<p align="center" class="txt-log" id="txt-log">логин</p>
			<input type="text" name="login" placeholder="Придумайте логин" class="enter" required>
			<p align="center" class="txt-pass" id="txt-pass">пароль</p>
			<input type="password" name="password" placeholder="Придумайте пароль" class="enter" required>
			<button type="submit" class="button-enter" form="data"><p>Вход</p></button>
		</form>
		<button type="button" class="button-to-auth" onmousedown="viewAuth()"><p>Уже есть аккаунт?</p></button>
	</div>

	<div  class="authorization" id="authorization">
		<button class="exit-auth" type="button" onmousedown="closeFill()"><img src="img/cancel.svg" alt="exit" width="20" height="20"></button>
		<div class="auth-child" >
			<p align="center" class="window-word-a">Войти</p>	
		</div>
		<form action="php/auth.php" method="post" class="auth-child" id="data1">
			<p align="center" class="txt-log-a">логин</p>
			<input type="text" name="login" placeholder="Введите логин" class="enter-a" required>
			<p align="center" class="txt-pass-a" id="txt-pass">пароль</p>
			<input type="password" name="password" placeholder="Введите пароль" class="enter-a" required>
			<button type="submit" class="button-enter" form="data1"><p>Вход</p></button>
		</form>
		<button type="button" class="button-to-reg" onmousedown="viewReg()"><p>Нет аккаунта?</p></button>
	</div>

	<div class="property" id="property">
		<a href="php/exit.php"><p>Выйти</p></a>
	</div>







	<div class="upload" id="upload">
		<form method="post" action="" enctype="multipart/form-data">
			<button class="file-exit" type="button" onmousedown="closeFill()"><img src="img/cancel.svg" alt="exit" width="20" height="20"></button>
			<p>
				<input class="uptext" type="file" name="file" size="50">
			</p>
			<p>
				<input class="up" type="submit" name="submit" value="Загрузить">
			</p>
		</form>
	</div>
	


	<div class="foot">
		<h1 class="creators">
			2021   CREATORS:KORNILOV KATAUROVA SHABALIN DAMINOV
		</h1>
	</div>
	<script src ="jss/main.js"></script>
</body>
</html>

