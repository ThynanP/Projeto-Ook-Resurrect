<?php
	$dados = $_GET['dados'];
	echo $dados;

	if (strpos($dados, '{') !== false) {
		$myFile = fopen ("Json.js", "w") or die("O arquivo nao pode ser aberto");
	}
	else{
		$myFile = fopen ("dados.txt", "w") or die("O arquivo nao pode ser aberto");
	}

	fwrite($myFile, $dados);
	fclose($myFile);


?>
