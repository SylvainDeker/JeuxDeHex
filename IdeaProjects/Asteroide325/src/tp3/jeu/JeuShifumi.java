package tp3.jeu;

import java.util.Random;

/**
 * Created by salimcherifi on 20/03/17.
 */
public class JeuShifumi extends JeuSimple {

    private enum shifumi{FEUILLE, CISEAUX, PIERRE}
    public JeuShifumi(String nom) {
        super(nom);
    }

    @Override
    public String jouerUnTour() {
        Random rand = new Random();
        switch(rand.nextInt(3)){
            case 0 : return shifumi.FEUILLE.toString();
            case 1 : return shifumi.PIERRE.toString();
            case 2 : return shifumi.CISEAUX.toString();
            default : return null;
        }
    }

    @Override
    public int arbitrer(String c1, String c2) {
        if(c1.equals("FEUILLE") && c2.equals("FEUILLE")){
            return 0;
        }
        if(c1.equals("FEUILLE") && c2.equals("PIERRE")){
            return -1;
        }
        if(c1.equals("FEUILLE") && c2.equals("CISEAUX")){
            return 1;
        }


        if(c1.equals("PIERRE") && c2.equals("PIERRE")){
            return 0;
        }
        if(c1.equals("PIERRE") && c2.equals("FEUILLE")){
            return 1;
        }
        if(c1.equals("PIERRE") && c2.equals("CISEAUX")){
            return -1;
        }


        if(c1.equals("CISEAUX") && c2.equals("CISEAUX")){
            return 0;
        }
        if(c1.equals("CISEAUX") && c2.equals("PIERRE")){
            return 1;
        }
        if(c1.equals("CISEAUX") && c2.equals("FEUILLE")){
            return -1;
        }
        return -2;
    }
}
