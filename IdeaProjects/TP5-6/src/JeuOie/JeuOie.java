package JeuOie;

/**
 * Créer une partie du Jeu de l'oie
 */
public class JeuOie {
    private Oie[] oies;
    private int nbOie = 0;
    private Plateau plateau = new Plateau();
    private Des des = new Des();

    /**
     * Constructeur du jeu de l'oie
     * @param nbOieMax le nombre d'oie maximale
     */
    public JeuOie(int nbOieMax){
        oies = new Oie[nbOieMax];
    }

    /**
     * Ajouter une oie au jeu
     * @param couleur La couleur de l'oie qu'on veut attribuer
     */
    public void ajouterOie(String couleur){
        if(nbOie < oies.length){
            oies[nbOie] = new Oie(couleur, plateau, des);
            nbOie++;
        }
    }

    /**
     * Lancer la partie
     */
    public void jouer(){
        boolean finPartie = nbOie<2;

            while(!finPartie){
                int n = 0;
                while (!finPartie && n != (this.nbOie)){

                    finPartie = this.oies[n].action();
                    n++;
                }
            }
    }
}
