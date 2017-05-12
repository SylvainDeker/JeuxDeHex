/**
 * Permet de créer un Ronin
 */
public class Ronin extends Humain {

    private int honneur;
    /**
     * Constructeur d'un ronin
     *  @param argent  l'argent que possède le ronin
     * @param boisson la boisson que boit le ronin
     * @param nom     le nom du ronin
     */
    public Ronin(int argent, String boisson, String nom) {
        super(argent, boisson, nom);
        this.honneur = 1;
    }

    /**
     * Donner un montant au commerçant c
     * @param c le commerçant bénéficiaire du don
     * @param montant le montant du don
     */
    public void donner(Commerçant c, int montant){
        parler("Tiens "+c.getNom()+" voici "+montant+" sous\n");
        this.argent -= montant;
        c.argent += montant;
        c.parler("Je te remercie généreux donateur\n");
    }

    /**
     * Provoquer un Yakuza
     * @param y le yakuza provoquer
     */
    public void provoquer(Yakuza y){
        if(2*this.honneur > y.getReputation()){
            this.ajouterArgent(y.getArgent());
            y.perdre();
            this.honneur++;
            this.parler("JAI GAGNÉÉÉÉÉÉ!!!\n");
        }else{
            this.honneur--;
            y.gagner();
        }
    }



}
