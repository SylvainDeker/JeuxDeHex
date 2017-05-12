package JeuOie;

/**
 * Case spéciale prison
 */
public class CasePrison extends Case {

    private Oie oieCoince;

    /**
     * Constructeur de la case prison
     */
    public CasePrison() {
        super(51);
    }

    /**
     * Action spéciale a l'arrivée sur la case
     * @param oie oie en jeu
     * @return la même case
     */
    @Override
    protected Case arrivee(Oie oie) {
        if (oieCoince != null){
            oieCoince.ajouterMessage("L'oie "+oieCoince.getCouleur()+" est libre ! ");
        }

        this.oieCoince = oie;
        oie.ajouterMessage(" tombe sur la case prison et reste bloqué ou libère une oie! ");

        return this;

    }

    /**
     * Action spéciale a effecteur au départ de la case : case suivante ou même case si aucune oie n'est arrivée
     * @param oie oie en jeu
     * @return la même case ou la case suivante
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

                oie.ajouterMessage("L'oie "+oieCoince.getCouleur()+" reste en prison ");
                return oie.getPlateau().donnerCase(51);
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
