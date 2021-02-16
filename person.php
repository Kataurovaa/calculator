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
		<div class="header-child">
			<p class="txt-user">Привет, <?=$_COOKIE['user']?>!</p>
			<p class="txt-user"><button class="txt-user-b" type="button" onmousedown="viewProp()"><img src="img/user.svg" width="50" height="50"></button>
			</p>
		</div>
	</div>
</body>
</html>