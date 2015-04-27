<?php
// Objet gérant la connxion à la base de donnée
class DBHandle {
  // Objet PDO de Connexion
  private $db_handle;
  // Objet gérant la requête préparé sur la liste des produits
  private $req;

  // Constructeur avec des valeurs par défaut
  function __construct($serveur="localhost", $db="MVCMarket", $login="root", $password="root") {
    // Ouverture de la connexion à PDO.
    $this->db_handle = new PDO("mysql:host=$serveur;dbname=$db", $login, $password);
    // Préparation de la requête (il n'y a pas besoin de bindings).
    $this->req = $this->db_handle->prepare('SELECT * FROM produits');
  } 

  // Méthode exécutant la requête préparée sur la liste des produits.
  // Cette méthode construit un tableau d'objet de classe produit.
  function recupereDonneesProduits(){
    $this->req->execute();
    $res = array();
    while( $prod = $this->req->fetchObject('Produit')){
      $res[]= $prod;
    }
    return $res;
  }
}

?>
