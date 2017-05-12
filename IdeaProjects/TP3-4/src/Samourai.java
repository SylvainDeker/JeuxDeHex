/**
 * Permet de créer un Samourai
 */
public class Samourai extends Ronin {
    private String seigneur;
    /**
     * Constructeur d'un Samurai
     *  @param argent  l'argent que possède le samurai
     * @param boisson la boisson que boit le samurai
     * @param nom     le nom deu samourai
     * @param honneur l'honneur du samurai
     * @param seigneur le seigneur du Samourai
     */
    public Samourai(int argent, String boisson, String nom, int honneur, String seigneur) {
        super(argent, boisson, nom);
        this.seigneur = seigneur;
    }

    /**
     * Dire bonjour et spécifier le seigneur
     */
    public void direBonjour(){
        super.direBonjour();
        parler(" et je sers le seigneur "+this.seigneur+"\n");
    }

    /**
     * Permet au personnage de boire sa boisson favorite
     * @param boisson
     */
    public void boire(String boisson){
        parler("Ahhhh, un bon verre de "+boisson+" ! GLOUPS !\n");
    }


    public void setBoisson(String boisson){
        this.boisson = boisson;
    }

}
