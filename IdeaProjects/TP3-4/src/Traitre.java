/**
 * Permet de créer un Samourai
 */
public class Traitre extends Samourai {
    private float nvTraitre;
    /**
     * Constructeur du traitre
     * @param argent
     * @param boisson
     * @param nom
     * @param honneur
     * @param seigneur
     */
    public Traitre(int argent, String boisson, String nom, int honneur, String seigneur) {
        super(argent, boisson, nom, honneur, seigneur);
        this.nvTraitre = 0;
    }

    /**
     * Permet d'extorquer un commerçant et d'incrémenter le niveau de traitrise
     * @param c Le comerçant extorqué
     */
    public void extorquer(Commerçant c){
        if(this.nvTraitre == 3){
            this.parler("J'ai eu ma dose pour aujourd'hui je te laisse ton argent.\n");
            c.parler("Merci infiniment MERCI BEAUCOUP !\n");
        }else{
            this.parler("Donne moi tous ton argent "+c.getNom());
            c.seFaireExtorquer();
            this.nvTraitre++;
        }
    }

    /**
     * Dire bonjour et préciser le niveau de traitrise
     */
    @Override
    public void direBonjour() {
        super.direBonjour();
        parler(" et j'ai un rang de "+this.nvTraitre+" de traitrise\n");
    }

    /**
     * Donner montantDon a un humain h
     * @param h l'humain bénéficiaire
     * @param montantDon le montant du don
     */
    public void faireLeGentil(Humain h, float montantDon){
        parler("C'est ton jour de chance je fais ami-ami et te donne "+montantDon+" cher "+h.getNom());

        if(this.nvTraitre > 0) this.nvTraitre = this.nvTraitre-(this.nvTraitre/10);
    }
}
