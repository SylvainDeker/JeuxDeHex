package tp3.jeu;

import java.util.Random;

/**
 * Created by salimcherifi on 20/03/17.
 */
public class JeuDe extends JeuSimple {

    public JeuDe(String nom) {
        super(nom);
    }

    @Override
    public String jouerUnTour() {
        Random rand = new Random();
        return String.valueOf(rand.nextInt(6)+1);
    }

    @Override
    public int arbitrer(String c1, String c2) {
        int i1 = Integer.valueOf(c1);
        int i2 = Integer.valueOf(c2);
        return i1 > i2 ? -1 : i1 < i2 ? 1 : 0;

    }
}
