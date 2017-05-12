package JeuOie;

/**
 * Cases spéciales case fastes
 */
public class CasesFastes extends Case {
    /**
     * Constructeur de la case fastes
     * @param numCase numéro de la case faste
     */
    public CasesFastes(int numCase) {
        super(numCase);
    }

    /**
     * Action a effectué à l'arrivée sur la case fastes : rejouer
     * @param oie oie en jeu
     * @return la case suivante après avoir rejouer
     */
    protected Case arrivee(Oie oie){
        String nomCase = getNom();
        oie.ajouterMessage(" tombe sur une case fast et rejoue ! ");
        int valeurDes = oie.lanceDe();
        return this.caseSuivante(oie,valeurDes+this.numCase-1);

    }
}
