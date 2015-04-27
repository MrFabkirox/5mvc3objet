<?php
// La classe Produit renferme les champs correspondant à la base de donnée.
class Produit
{
  private $id;
  private $Designation;
  private $prix;

  public function getID(){
    return $this->id;
  }
  public function getDesignation(){
    return $this->Designation;
  }
  public function getPrix(){
    return $this->prix;
  }
}
?>
