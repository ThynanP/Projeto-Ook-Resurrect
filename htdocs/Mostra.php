<?
  //$myFile = fopen("dados.txt", "r") or die("o arquivo nao pode ser aberto");
  $json_str = $_GET['dados'];
  $myFile = fopen("$json_str.js", "r") or die("o arquivo nao pode ser aberto");

   $obj = json_decode(fread ($myFile, filesize("$json_str.js")));
   $aux = $obj->nome;
   $idade = $obj->idade;

   echo "nome: $obj->nome<br>";
   echo "idade: $obj->idade<br>";
   echo "sexo: $obj->sexo<br>";
   fclose($myFile);
?>
