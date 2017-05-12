public class Case {
	protected int numCase;
	
	//constructeur
	public Case(int numCase){
		this.numCase=numCase+1;
		
	}
	
	public String getNom (){
		return "Numero " +this.numCase;
	}
	
	public Case depart(Oie oie){

		oie.ajouterMessage("L'oie "+oie.getCouleur()+" est sur la case "+getNom());
		int deplacement=oie.lancerDe();
		Case caseArrive=this.caseSuivante(oie, this.numCase-1+deplacement);
		return caseArrive;
	}
	
	private Case arrivee(Oie oie){
		String nomC=getNom();
		oie.ajouterMessage(" elle va sur la case "+nomC);
		return this;
	}
	
	private Case caseSuivante(Oie oie, int numCaseDestination){
	    Case caseDestination = oie.getPlateau().donnerCase(numCaseDestination);
	    Case caseArrivee = caseDestination.arrivee(oie);
	    return caseArrivee;
	 
	    }
	
	
}
