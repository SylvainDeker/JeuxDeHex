/**
 * Permet de créer un Yakuza
 */
public class Yakuza extends Humain {

    private String clan;
    private int reputation;

    /**
     * Constructeur d'un humain
     *
     * @param argent  l'argent que possède l'humain
     * @param boisson la boisson que boit l'humain
     * @param nom     le nom de l'humain
     * @param clan Le clan
     */
    public Yakuza(int argent, String boisson, String nom, String clan) {
        super(argent, boisson, nom);
        this.clan = clan;
        this.reputation = 0;
    }

    /**
     * Obtenir le clan du Yakuza
     * @return un clan
     */
    public String getClan() {
        return clan;
    }

    /**
     * Obtenir la réputation du Yakuza
     * @return la réputation
     */
    public int getReputation() {
        return reputation;
    }

    /**
     * Voler l'argent du commerçant et incrémente la réputation
     * @param c le commerçant extorqué
     */
    void extorquer(Commerçant c){
        this.ajouterArgent(c.getArgent());
        c.perdreArgent();
        c.seFaireExtorquer();
        this.reputation++;
        this.parler("Je viens d'extorquer ce minable "+c.getNom()+".\n");
    }

    /**
     * Gagner un duel et donc en réputation
     */
    void gagner(){
        this.reputation++;
        this.parler("Je viens de gagner un duel YEEEEESSSS!!\n");
    }

    /**
     * Perdre un duel et donc en réputation
     * @return la réputation
     */
    int perdre(){
        this.parler("Je viens de perdre un duel et "+this.argent+" sous."+" Je suis minable.\n");
        this.perdreArgent();
        this.reputation--;

        return getReputation();
    }

    /**
     * Dire bonjour tout en précisant le clan
     */
    public void direBonjour(){
        super.direBonjour();
        parler(" et j'appartiens au clan "+this.getClan()+"\n");
    }

}



