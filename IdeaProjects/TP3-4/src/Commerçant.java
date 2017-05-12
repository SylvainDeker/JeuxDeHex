/**
 * Créer un commerçant
 */
public class Commerçant extends Humain {

    /**
     * Constructeur d'un Commerçant
     *
     * @param argent  l'argent que possède l'humain
     * @param nom     le nom de l'humain
     */
    public Commerçant(int argent, String nom) {
        super(argent, "thé", nom);

    }

    /**
     * Le commerçant perd tous son argent
     */
    public void seFaireExtorquer(){
        super.perdreArgent();
        super.parler("Je viens de me faire extorquer ! Le monde est injuste !!!!!\n");
    }

    /**
     * Le commerçant reçoit de l'argent de la part
     * @param a le montant reçu
     */
    public void recevoir(int a){
        super.ajouterArgent(a);
        parler("Merci infiniment Monsieur le Ronin MERCI BEAUCOUP !!!!!!!\n");
    }


}
