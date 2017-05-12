package JeuOie;

/**
 * Case spéciale jardin case d'arrivée
 */
public class CaseJardin extends Case {
    /**
     * Constructeur de la case jardin finale
     */
    public CaseJardin() {
        super(62);
    }

    /**
     * Action a effectuer à l'arrivée au jardin, la fin du jeu
     * @param oie oie en jeu
     * @return null car arrivée a la fin du plateau
     */
    @Override
    protected Case arrivee(Oie oie){
        String nomCase = getNom();
        oie.ajouterMessage(" arrive au jardin et gagne ! ");
        return null;
    }
}
