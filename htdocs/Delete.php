<?php
	$dados = $_GET['dados'];

unlink("$dados.js") or die("Nenhum arquivo encontrado");
?>
