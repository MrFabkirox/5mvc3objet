<?php
// Sous classe de Vues. Implantant une représentation de la liste des produits
// sous forme d'un tableau.
class VueTable extends Vues
{
  // référence sur le controler gerant la vue et permettant d'accéder au modèle.
  private $controler;

  // À la construction on donne le controler gérant la vue.
  public function __construct($controler){
    $this->controler = $controler;
  }

  // Affichage sous forme d'un tableau en itérant sur les éléments du tableau
  // constituant le modèle.
  public function affiche(){
   echo '<table>';
   echo '<tr><th>désignation</th><th>prix</th></tr>';
   foreach($this->controler->getModel() as $prod){
    echo "<tr>";
    echo "<td> ".$prod->getDesignation()."</td><td>".$prod->getPrix()." &euro;</td>";
    echo "</tr>";
   }
   echo "</table>";
  }
}

?>

