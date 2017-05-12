package banque;

import java.util.Arrays;

/**
 * Permet de créer une carte bancaire
 */
public class Carte {
    private int[] codeCarte;
    private Banque banque;
    private Client client;
    private int numCompte;
    private Date dateValidite;
    private int compteurCodeValide;

    /**
     * Constructeur de la carte;
     * @param codeCarte le code de la carte
     * @param banque la banque liée à la carte
     * @param client le client propriétaire de la carte
     * @param numCompte le numéro du compte lié à la carte
     * @param dateValidite la fin de date de validité de la carte
     */
    public Carte(int[] codeCarte, Banque banque, Client client, int numCompte, Date dateValidite) {
        this.codeCarte = new int[4];
        this.codeCarte = codeCarte;
        this.banque = banque;
        this.client = client;
        this.numCompte = numCompte;
        this.dateValidite = dateValidite;
        this.compteurCodeValide = 3;
    }

    /**
     * Vérifie que le code est bien valide selon le tableau en paramètre
     * @param code verifie si le code tapé est juste
     * @return true si le code est valide, false sinon
     */
    boolean codeValide(int[] code){
        if(Arrays.equals(code,this.codeCarte)){
            return true;
        }else{
            compteurCodeValide++;
            return false;
        }
    }

    /**
     * Permet de payer le montant à la banque b au client numClient sur son compte numCompte
     * @param b la banque du compte récepteur
     * @param numClient le numéro du client qui réçoit le virement
     * @param numCompte le numéro du compte qui reçoit le virement
     * @param montant le montant du virement
     */
    void payer(Banque b, int numClient, int numCompte, float montant){
        this.getClient().getCompte(this.numCompte).retrait(montant);
        b.getClient(numClient).getCompte(numCompte).depot(montant);
    }

    /**
     * Retourne la banque liée à la carte
     * @return la banque liée à la carte
     */
    public Banque getBanque() {
        return banque;
    }

    /**
     * Retourne la date de validité de la carte
     * @return la date de fin de validité de la carte
     */
    public Date getDateValidite() {
        return dateValidite;
    }

    /**
     * Retourne le client lié à la carte
     * @return un client
     */
    public Client getClient() {
        return this.client;
    }
}
