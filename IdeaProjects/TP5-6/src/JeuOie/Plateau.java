package JeuOie;

/**
 * Construire un plateau
 */
public class Plateau {

    private int NB_CASES = 63;
    private Case cases[];

    /**
     * Constructeur du plateau
     */
    public Plateau() {
        this.cases = new Case[this.NB_CASES];
        for (int i = 0;i < this.NB_CASES; i++){
            this.cases[i] = new Case(i);
        }
        initialisationCasesSpecifique();
    }

    /**
     * Initialiser les case spéciales
     */
    private void initialisationCasesSpecifique(){
        for (int i=0;i < this.NB_CASES;i=i+9){
            this.cases[i] = new CasesFastes(i);
        }
        this.cases[5] = new CasePont();
        this.cases[18] = new CaseHotel();
        this.cases[30] = new CasePuits();
        this.cases[41] = new CaseLabyrinthe();
        this.cases[51] = new CasePrison();
        this.cases[57] = new CaseMort();
        this.cases[62] = new CaseJardin();

    }

    /**
     * Retourner la case de début de partie
     * @return la case d'indice 1
     */
    public Case caseDebutPartie(){
        return this.cases[0];
    }

    /**
     * Retourner la case d'indice i avec un modulo si jamais on arrive a la fin du plateau
     * @param i l'indice de la case
     * @return la case d'indice i
     */
    public Case donnerCase(int i){
        if(i > 62){
            return this.cases[62-(i%62)];
        }
        return this.cases[i];
    }
}
