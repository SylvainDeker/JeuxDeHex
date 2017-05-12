public class Plateau {
	private final int nbCases=63;
	private Case tab[]=new Case[nbCases];
	
//constructeur
	public Plateau(){
		for(int i=0;i<this.nbCases;i++){
			tab[i]=new Case(i);
		}
		
	}

	public Case donnerCase(int numCase){
		if(numCase>62){
			return tab[62-(numCase%62)];
		}
		return tab[numCase];
	}
	
	public Case caseDebutPartie(){
		return tab[0];
	}
}
