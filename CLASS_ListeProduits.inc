<?php
// La classe ListeProduits implante le controleur de la
// liste des produits. Elle gère la construction du modèle
// et son affichage
class ListeProduits
{
  // le champ model contient le modèles de données de la
  // liste des produits c'est-à-dire un tableau d'objet
  // de la classe Produit
  private $model = array();
  // Le champ vues contiet un tableau de différentes vue
  // possibles de la liste des produits.
  // Chaque vue est un objet de type Vues.
  private $vues;

  public function __construct(){
    // On initialise une première vue de type liste
    $this->vues[] = new VueListe($this);
    // On initialise une seconde vue de type tableau
    $this->vues[] = new VueTable($this);
    // On initialise un Objet de connexion à la base
    // de données.
    $db=new DBHandle();
    // On récupère les modèle construit à partir de
    // la requête idoine.
    $this->model = $db->recupereDonneesProduits();
  }

  // Cette méthode permet l'affichage de la liste de
  // produits avec une vue particulière.
  public function affiche($mode){
    $this->vues[$mode]->affiche($this->model);
  }
  // Methode permettant le dialogue entre le controler
  //et la vue.
  public function getModel(){
    return $this->model;
  }
}
?>
