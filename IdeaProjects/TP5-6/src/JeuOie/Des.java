package JeuOie;

import java.util.Random;

/**
 * Permet de créer les deux dés
 */
public class Des {
    /**
     * Lancer les dés
     * @return le nombre affichés par les deux dés
     */
    public int lancer(){
        Random rand = new Random();
        return rand.nextInt(6) + 1;

    }
}
