package JeuOie;

/**
 * Case spéciale hotel
 */
public class CaseHotel extends Case {


    int nbreTour = 2;

    /**
     * Constructeur de la case spéciale hotel
     */
    public CaseHotel() {
        super(18);
    }

    /**
     * Action spéciale de la case hotel : message spéciale pour la case hotel
     * @param oie oie en jeu
     * @return une copie de la case hotel
     */
    @Override
    protected Case arrivee(Oie oie) {


        oie.ajouterMessage(" elle va sur la case hotel");
        CaseHotel c = new CaseHotel();
        return c;

    }

    /**
     * Vérifie si l'oie a bien passé 2 tours si ce n'est pas le cas affichage d'un message spéciale sinon passage
     * a la case suivante
     * @param oie oie en jeu
     * @return la case suivante ou la même case si il reste des tours
     */
    @Override
    public Case depart(Oie oie){

        if(this.nbreTour == 0){

            String couleur = oie.getCouleur();
            String nomCase = getNom();
            oie.ajouterMessage("L'oie "+couleur+" est sur la case hotel");
            int valeurDes = oie.lanceDe();

            Case caseArrivee = this.caseSuivante(oie, valeurDes+this.numCase-1);
            return caseArrivee;




        }else{

            oie.ajouterMessage("L'oie "+oie.getCouleur()+" est à l'hotel pour encore "+this.nbreTour+" tours ");
            this.nbreTour-=1;
            return this;
        }

    }


}
