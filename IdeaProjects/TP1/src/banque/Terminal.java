package banque;

/**
 * Permet de créer un terminal
 */
public class Terminal {
    private Banque banque;
    private int numClient;
    private int numCompte;

    /**
     * Constructeur du terminal
     * @param banque la banque
     * @param numClient le numéro du client
     * @param numCompte le numéro du compte
     */
    public Terminal(Banque banque, int numClient, int numCompte) {
        this.banque = banque;
        this.numClient = numClient;
        this.numCompte = numCompte;
    }

    /**
     * Génére l'autorisation de payement en fonction du code entré et du montant
     * @param CB La carte
     * @param montant le montant du payement
     * @param codeEntre le code entré pour le payement sur le terminal
     * @return True si l'autorisation est donnée
     */
    boolean genererAutorisation(Carte CB, float montant, int[] codeEntre){

        if(! CB.codeValide(codeEntre)){
            System.out.println("Code Invalide");
            return false;
        }
        if(montant > 1000 || CB.getDateValidite().getAn() < 2017){
            System.out.println("Carte invalide");
            return false;
        }else{
            System.out.println("OK");
            return true;
        }
    }

    void payer(float montant, Carte CB, int[] codeCarte){
        if(CB.codeValide(codeCarte)){
            CB.payer(this.banque,this.numClient,this.numCompte,montant);
        }else{
            System.out.println("Erreur : Code invalide");
        }

    }
}
