package JeuOie;

/**
 * Case spéciale pont
 */
public class CasePont extends Case {
    /**
     * Constructeur de la case spéciale pont
     */
    public CasePont() {
        super(5);
    }

    /**
     * Action spéciale à l'arrivée sur la case pont : passage à la case 12
     * @param oie oie en jeu
     * @return la case d'indice 12
     */
    @Override
    protected Case arrivee(Oie oie){
        String nomCase = getNom();
        oie.ajouterMessage(" tombe sur la case pont et elle va sur la case numero 12 ");
        return oie.getPlateau().donnerCase(11);
    }
}
