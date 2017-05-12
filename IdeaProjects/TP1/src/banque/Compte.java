package banque;

/**
 * Permet de créer un compte
 */
public class Compte {

    private float solde = 0;
    private int numCompte;
    /**
     * Constructeur du compte
     * @param solde le solde du compte
     * @param numCompte le numéro du compte
     */
    public Compte(float solde, int numCompte) {
        this.solde = solde;
        this.numCompte = numCompte;
    }

    /**
     * Permet de déposer un montant sur le compte : depot(montant)
     * @param valeur la valeur du montant du dépot
     */
    void depot(float valeur){
        this.solde+=valeur;
    }

    /**
     *
     * @param valeur Le montant du retrait
     */
    void retrait(float valeur)
    {
        assert(this.solde >= valeur);
        this.solde-=valeur;
    }

    /**
     *
     * @return le solde
     */
    float getSolde(){
        return this.solde;
    }

    /**
     * Retourne le numero du compte
     * @return le numéro du compte
     */
    public int getNumCompte() {
        return numCompte;
    }


    /**
     * Permet de virer un montant du compte au compte destinataire
     * @param valeur valeur a virer
     * @param destinataire le destinataire du virement
     */
    void virer(float valeur, Compte destinataire){
        this.solde-=valeur;
        destinataire.solde += valeur;
    }

    /**
     * Permet d'afficher les informations du compte
     * @return les informations du compte mises en forme
     */
    @Override
    public String toString() {
        return "Compte{" +
                "solde=" + solde +
                ", numCompte=" + numCompte +
                '}';
    }
}
