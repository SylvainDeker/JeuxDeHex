package JeuOie;

/**
 * Case spéciale labyrinthe
 */
public class CaseLabyrinthe extends Case {
    /**
     * Constructeur de la case labyrinthe
     */
    public CaseLabyrinthe() {
        super(41);
    }

    /**
     * Action speciale a l'arrivée sur une case labyrinth : on redirige sur la case 30
     * @param oie oie en jeu
     * @return la case n°30
     */
    @Override
    protected Case arrivee(Oie oie){
        String nomCase = getNom();
        oie.ajouterMessage(" tombe sur le labyrinthe et va sur la case 30 ");
        return oie.getPlateau().donnerCase(29);
    }
}
