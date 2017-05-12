/**
 * Permet de créer un humain
 */
public class Humain {
    protected int argent;
    protected String boisson;
    private String nom;

    /**
     * Constructeur d'un humain
     * @param argent l'argent que possède l'humain
     * @param boisson la boisson que boit l'humain
     * @param nom le nom de l'humain
     */
    public Humain(int argent, String boisson, String nom) {
        this.argent = argent;
        this.boisson = boisson;
        this.nom = nom;
    }

    /**
     * Ajouter de l'argent à l'humain
     * @param montant le montant à ajouter
     */
    public void ajouterArgent(float montant){
        this.argent+=montant;
    }

    /**
     * Soustraire de l'argent à l'humain
     */
    public void perdreArgent(){
        this.argent=0;
    }

    /**
     * Permet de boire
     */
    public void boire(){
        parler("Ahhhh, un bon verre de "+this.boisson+" ! GLOUPS !\n");
    }

    /**
     * Permet de à l'humain de parler
     * @param texte Ce que doit dire l'humain
     */
    public void parler(String texte){
        System.out.print(this.nom+" - "+texte);
    }

    /**
     * Permet à l'humain de dire bonjour
     */
    public void direBonjour(){

        parler("Bonjour ! Je m'appelle "+this.nom+", j'aime boire du "+this.boisson+" et j'ai "+this.getArgent()+" sous\n");
    }

    /**
     * Retourne l'argent que possède l'humain
     * @return l'argent que possède l'humain
     */
    public int getArgent() {
        return argent;
    }

    /**
     * Retourne la boisson que boit l'humain
     * @return la boisson que boit l'humain
     */
    public String getBoisson() {
        return boisson;
    }

    /**
     * Retourne le nom de l'humain
     * @return le nom de l'humain
     */
    public String getNom() {
        return nom;
    }
}
