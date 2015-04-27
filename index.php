<?php
// On construit un class loader pour ne plus s'occuper du chargement des fichiers
class MyClassLoader
{
  public static function loadClass($class){
    //echo 'loading '.$class;
    require "CLASS_$class.inc";
  }
}
// Enregistrement de l'autoloader
spl_autoload_register('MyClassLoader::loadClass');

//construction du controler de la liste des Poduits
$listControler = new ListeProduits();
?>

<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>
MyDicount.com
</title>
<meta http-equiv="content-type" content="text/html; charset=utf-8">
</head>
<body>
</body>
</html>

<?php
// Génération de l'affichage de la liste de produits
$listControler->affiche(0);
?>
