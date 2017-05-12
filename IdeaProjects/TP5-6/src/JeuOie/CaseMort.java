package JeuOie;

/**
 * Case spéciale de mort
 */
public class CaseMort extends Case {
    /**
     * Constructeur de la case mort
     */
    public CaseMort() {
        super(57);
    }

    /**
     * Action a effectuer a l'arrivée sur la case mort : retour a la case 1
     * @param oie oie en jeu
     * @return la case 0
     */
    @Override
    protected Case arrivee(Oie oie){
        String nomCase = getNom();
        oie.ajouterMessage(" tombe sur la case mort et reviens à la case numéro 1 ");
        return oie.getPlateau().donnerCase(0);
    }
}
