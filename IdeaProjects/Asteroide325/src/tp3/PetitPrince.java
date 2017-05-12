package tp3;

import tp3.console.ConsoleJavaBoy;

/**
 * Created by salimcherifi on 20/03/17.
 */
public class PetitPrince implements Sujet, Joueur {

    private ConsoleJavaBoy console;
    private String nom;
    private int argent;

    public PetitPrince(String nom, int argent) {
        this.nom = nom;
        this.argent = argent;
        this.console = new ConsoleJavaBoy(this);
    }


    @Override
    public String getNom() {
        return this.nom;
    }

    @Override
    public int getArgent() {
        return this.argent;
    }

    @Override
    public void run() {
        this.console.parler("Attaque ou défense Matuidi Charo ");
        this.console.seDirigerVers(0);
    }
}
