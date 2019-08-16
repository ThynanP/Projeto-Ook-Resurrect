<?php
//string json contendo os dados de um funcionário
$json_str = $_GET['dados']; //'{"nome":"Fernando", "idade":32, "sexo": "M"}';

$obj = json_decode($json_str);
$aux = $obj->nome;
$idade = $obj->idade;

  $myFile = fopen ("$aux.js", "w") or die("O arquivo nao pode ser aberto");
	fwrite($myFile, $json_str);


//imprime o conteúdo do objeto
echo "nome: $obj->nome<br>";
echo "idade: $obj->idade<br>";
echo "sexo: $obj->sexo<br>";
echo "$aux.js";
?>
