package JeuOie;

/**
 * Main du jeu de l'oie
 */
public class JeuOieMain {
    public static void main(String argv[]){
        JeuOie jeuOie = new JeuOie(3);
        jeuOie.ajouterOie("verte");
        jeuOie.ajouterOie("jaune");
        jeuOie.ajouterOie("bleu");
        jeuOie.jouer();
    }
}
