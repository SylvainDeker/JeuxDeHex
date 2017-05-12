package JeuOie;

/**
 * Permet de créer une oie
 */
public class Oie {
    private String couleur;
    private Plateau plateau;
    private Des des;
    private Journal journal = new Journal();
    private Case casePlateau = new Case(0);

    /**
     * Constructeur de l'oie
     * @param couleur Couleur de l'oie
     * @param plateau Plateau de l'oie
     * @param des Des lié à l'oie
     */
    public Oie(String couleur, Plateau plateau, Des des){
        this.couleur = couleur;
        this.plateau = plateau;
        this.des = des;
    }

    /**
     * Obtenir la couleur de l'oie
     * @return la couleur de l'oie
     */
    public String getCouleur() {
        return couleur;
    }

    /**
     * Retourner le plateau de l'oie
     * @return le plateau de l'oie
     */
    public Plateau getPlateau() {
        return plateau;
    }


    /**
     * Lancer le dés
     * @return la valeur suite au lance des dés
     */
    public int lanceDe(){
        int valeurDes = this.des.lancer();
        this.ajouterMessage(" elle fait "+valeurDes);
        return valeurDes;
    }

    /**
     * Ajouter un message au journal de l'oie
     * @param message le message à ajouter
     */
    public void ajouterMessage(String message){
        this.journal.ajouterMessage(message);
    }

    /**
     * Lancer le tour de l'oie
     * @return si l'oie a atteint la case 63
     */
    public boolean action(){
        Case casePlateau = this.casePlateau.depart(this);
        this.journal.afficherMessage();
        String nomCase = this.casePlateau.getNom();

        this.casePlateau = casePlateau;
        return (casePlateau == null);
    }
}

