package Heritage;

/**
 * Created by salimcherifi on 10/02/17.
 */
public class Homme extends EtreVivant {
    public Homme(String nom) {
        super(100, nom);
    }

    public void parler(String texte){
        System.out.println(texte);
    }

}
