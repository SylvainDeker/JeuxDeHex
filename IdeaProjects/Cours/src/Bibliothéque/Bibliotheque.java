package Bibliothéque;

import java.util.Arrays;

/**
 * Created by salimcherifi on 03/02/17.
 */
public class Bibliotheque {
    protected int nbOuvrages;
    protected Ouvrage ouvrages[];
    public final static int ERREUR = -1; //Constante

    public Bibliotheque(int nbMax) {
        this.nbOuvrages = 0;
        this.ouvrages = new Ouvrage[nbMax];
    }

    public boolean ajouterOuvrage(String titre, String auteur, int nbMax){

        if(this.nbOuvrages >= ouvrages.length){
            return false;
        }
        for (int i=0;i<this.nbOuvrages;i++){

            if (titre.equals(this.ouvrages[i].getTitre()) && auteur.equals(this.ouvrages[i].getAuteur()) ){
                return false;
            }
        }
        Ouvrage n = new Ouvrage(titre, auteur, nbMax);
        this.ouvrages[this.nbOuvrages] = n;
        this.nbOuvrages++;
        return true;

    }

    public boolean supprimerOuvrage(String titre, String auteur){

        if(this.nbOuvrages == 0){
            return false;
        }
        boolean bool=false;
        int index = 0;
        for (int i=0;i<this.nbOuvrages;i++){

            if (titre.equals(this.ouvrages[i].getTitre()) && auteur.equals(this.ouvrages[i].getAuteur()) ){
                bool = true;
                index = i;
            }
        }

        if(!trouve){
            return false;
        }
        this.ouvrages[index] = null;
        for (int i = index; i < this.nbOuvrages; i++){
            this.ouvrages[i] = this.ouvrages[i+1];
        }
        this.nbOuvrages--;
        return true;
    }

    public void emprunterExemplaire(String titre, String auteur){
        assert(this.nbOuvrages != 0);
        for(int i=0;i<this.nbOuvrages;i++){
            if (titre.equals(this.ouvrages[i].getTitre()) && auteur.equals(this.ouvrages[i].getAuteur()) ){
                this.ouvrages[i].setEmpreunte();
            }
        }

    }

    public boolean retournerExemplaire(String titre){

    }

    public int nbExemplaires(String titre, String auteur){
        int c;
        assert(this.nbOuvrages != 0);
        for(int i=0;i<this.nbOuvrages;i++){
            if (titre.equals(this.ouvrages[i].getTitre()) && auteur.equals(this.ouvrages[i].getAuteur()) ){
                c++;
            }
        }
        return c;
    }

    @Override
    public String toString() {
        return "Bibliotheque{" +
                "nbOuvrages=" + nbOuvrages +
                ", ouvrages=" + Arrays.toString(ouvrages) +
                '}';
    }


    public boolean ajouterExemplaire(String auteur, String titre, String cote, int anneeP, String ???? ){

    }
}
