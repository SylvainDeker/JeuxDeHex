import java.util.ArrayList;
import java.util.Random;

/**
 * Permet de créer une grand-mère
 */
public class GrandMere extends Humain {

    private ArrayList<Humain> memoire;

    /**
     * Constructeur d'une grand-mère
     *
     * @param argent  l'argent que possède la grand mere
     * @param nom     le nom de l'humain
     */
    public GrandMere(int argent, String nom) {
        super(argent, "tisane", nom);
        this.memoire = new ArrayList<>(30);
    }

    /**
     * Retourne un type d'humain au hasard
     * @return L'humain sorti au hasard
     */
    public String humainHasard(){
        Random rnd = new Random();
        int v = rnd.nextInt(6);
        switch (v){
            case 0:
                return ("Commerçant");

            case 1:
                return ("Yakuza");

            case 2:
                return ("Traitre");

            case 3:
                return ("GrandMere");

            case 4:
                return ("Ronin");

            case 5 :
                return("Samourai");
            default:
                return "";

        }
    }

    /**
     * Ajouter un humain au connaissance de la mémé
     * @param h L'humain à ajouter
     */
    public void faireConnaissanceAvec(Humain h){
        parler("Bonjour mon petit "+h.getNom()+", je suis enchanté de faire ta connaissance.\n");
        if(this.memoire.size() < 30){
            this.memoire.add(h);
        }else{
            this.memoire.remove(this.memoire.size()-1);
        }
    }

    /**
     * Préciser les types des humains quela mémé connait
     */
    void ragoter(){

        for (int i = 0; i < this.memoire.size() ;i++){
            if (this.memoire.get(i) instanceof Traitre){
                parler("Je sais que "+this.memoire.get(i).getNom()+" est un Traitre\n");
            }
            parler("Je crois que "+this.memoire.get(i).getNom()+" est un "+this.memoire.get(i).getClass().getSimpleName()+"\n");
        }
    }

}
