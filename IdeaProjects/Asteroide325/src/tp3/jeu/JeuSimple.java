package tp3.jeu;

/**
 * Created by salimcherifi on 20/03/17.
 */
public abstract class JeuSimple {
    private String nom;

    public JeuSimple(String nom) {
        this.nom = nom;
    }

    public String getNom(){
        return this.nom;
    }
    public abstract String jouerUnTour();
    public abstract int arbitrer(String c1, String c2);

}

