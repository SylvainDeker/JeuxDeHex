package JeuOie;

/**
 * Case du jeu
 */
public class Case {
    protected int numCase;

    /**
     * Constructeur d'une case
     * @param numCase le numéro de la case
     */
    public Case(int numCase) {
        this.numCase = numCase+1;
    }

    /**
     * Retourner le nom de la case
     * @return le nom de la case sous la forme : numero [numero de case]
     */
    public String getNom(){
        return("numero "+this.numCase);
    }

    /**
     * Action à l'arrivée sur la case
     * @param oie oie en jeu
     * @return la case sur laquelle on est arrivée
     */
    protected Case arrivee(Oie oie){
        String nomCase = getNom();
        oie.ajouterMessage(" elle va sur la case "+ nomCase);
        return this;
    }

    /**
     * Action a faire au départ du tour
     * @param oie oie en jeu
     * @return la case suivante
     */
    public Case depart(Oie oie){
        String couleur = oie.getCouleur();
        String nomCase = getNom();
        oie.ajouterMessage("L'oie "+couleur+" est sur la case "+nomCase);
        int valeurDes = oie.lanceDe();

        Case caseArrivee = this.caseSuivante(oie, valeurDes+this.numCase-1);
        return caseArrivee;


    }

    /**
     * Calculer la case suivante en fonction de la valeur des des
     * @param oie oie en jeu
     * @param numCaseDestination indice de la case suivante
     * @return la case suivante
     */
    protected Case caseSuivante(Oie oie, int numCaseDestination){
        Case caseDestination = oie.getPlateau().donnerCase(numCaseDestination);
        Case caseArrivee = caseDestination.arrivee(oie);
        return caseArrivee;

    }
}
