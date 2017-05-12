package banque;

/**
 * Permet de créer un client
 */
public class Client {
    private String nom;
    private Date dateNaissance;
    private int nbreCompte;
    private Compte[] tabCompte;
    private int numClient;

    /**
     * Constructeur du client
     * @param nom le nom du client
     * @param dateNaissance la date de naissance du client
     * @param compte le premier compte du client
     * @param numClient le numéro du client
     */
    public Client(String nom, Date dateNaissance, Compte compte, int numClient) {
        this.nom = nom;
        this.dateNaissance = dateNaissance;
        this.numClient = numClient;
        this.nbreCompte = 1;
        this.tabCompte = new Compte[100];
        tabCompte[this.nbreCompte-1] = compte;
    }

    /**
     * Retourne le nom du client
     * @return le nom du client
     */
    public String getNom() {
        return nom;
    }

    /**
     * Retourne la date de naissance
     * @return la date
     */
    public Date getDate() {
        return dateNaissance;
    }

    /**
     * Retourne le compte identifié par le numero
     * @param numero le numero du compte
     * @return le compte correspondant au numero
     */
    public Compte getCompte(int numero) {
        return tabCompte[numero];
    }

    /**
     * Retourne le numéro du client
     * @return le numéro de client dans la banque
     */
    public int getNumClient() {
        return numClient;
    }

    /**
     * Affiche le bilan du compte
     */
    void afficherBilan(){
        for (int i=0;i<this.nbreCompte;i++){
            System.out.println("Le solde du compte "+i+" :"+getCompte(i).getSolde());
        }
    }

    /**
     * Retourne le solde total de tous les comptes du client
     * @return le solde du compte
     */
    float soldeTotal(){
        int solde = 0;
        for (int i=0;i<this.nbreCompte;i++){
            solde += this.tabCompte[i].getSolde();
        }
        return solde;
    }

    /**
     * Permet d'ajouter un compte au client
     * @param compte le compte à ajouter
     * @return le numero du compte crée
     */
    int ajouterCompte(Compte compte){
        assert(this.nbreCompte < 100);
        this.nbreCompte++;
        this.tabCompte[this.nbreCompte-1] = compte;
        return this.nbreCompte+1;
    }



}
