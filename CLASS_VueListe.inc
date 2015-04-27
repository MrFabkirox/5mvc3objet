<?php
// Sous classe de Vues. Implantant une représentation de la liste des produits
// sous forme de liste.
class VueListe extends Vues
{
  // référence sur le controler gerant la vue et permettant d'accéder au modèle.
  private $controler;

  // À la construction on donne le controler gérant la vue.
  public function __construct($controler){
    $this->controler = $controler;
  }

  // Affichage sous forme d'une liste en itérant sur les éléments du tableau
  // constituant le modèle.
  public function affiche(){
    echo '<ul>';
    foreach($this->controler->getModel() as $prod){
     echo "<li> ".$prod->getDesignation()." (".$prod->getPrix()." &euro;)";
    }
    echo "</ul>";
  }
}

?>

