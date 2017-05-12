package JeuOie;

import JeuOie.Case;

/**
 * Case spéciale puits
 */
public class CasePuits extends Case {

    private Oie oieCoince;

    /**
     * Constructeur de la case puits
     */
    public CasePuits() {
        super(30);
    }

    /**
     * Ajout d'un message suite à l'arrivée sur la case et initialisation de l'oie coincé
     * @param oie oie en jeu
     * @return la case puits
     */
    @Override
    protected Case arrivee(Oie oie) {
        if (oieCoince != null){
            oieCoince.ajouterMessage("L'oie "+oieCoince.getCouleur()+" est libre ! ");
        }

        this.oieCoince = oie;
        oie.ajouterMessage(" arrive sur la case puits et elle y reste ! ");

        return this;

    }

    /**
     * Action au départ de la case: même case si il reste des tours sinon la case suivante
     * @param oie oie en jeu
     * @return case suivante ou la même case s'il reste des tours
     */
    @Override
    public Case depart(Oie oie){
        if(this.oieCoince != null){
            if(!oie.equals(this.oieCoince)){

                String couleur = oie.getCouleur();
                this.oieCoince = null;
                String nomCase = getNom();
                oie.ajouterMessage("L'oie "+couleur+" est sur la case "+nomCase);
                int valeurDes = oie.lanceDe();

                Case caseArrivee = this.caseSuivante(oie, valeurDes+this.numCase-1);
                return caseArrivee;




            }else{

                oie.ajouterMessage("L'oie "+oieCoince.getCouleur()+" est toujours sur la case puits !  ");
                return oie.getPlateau().donnerCase(30);
            }
        }else{
            String couleur = oie.getCouleur();
            String nomCase = getNom();
            oie.ajouterMessage("L'oie "+couleur+" est sur la case "+nomCase);
            int valeurDes = oie.lanceDe();

            Case caseArrivee = this.caseSuivante(oie, valeurDes+this.numCase-1);
            return caseArrivee;
        }




    }




}
