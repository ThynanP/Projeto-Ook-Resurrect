<?
  $myFile = fopen("dados.txt", "r") or die("o arquivo nao pode ser aberto");

  echo fread ($myFile, filesize("dados.txt"));

  fclose($myFile);

?>
