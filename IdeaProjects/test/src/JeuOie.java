public class JeuOie {
	private Oie[] oies;
	private int nbOie=0;
	private Plateau plateau = new Plateau();
	private Des des = new Des();
	
	public JeuOie (int nbOieMax){
		oies = new Oie[nbOieMax];
	}
	
	public void ajouterOie (String couleur){
		if(this.nbOie<oies.length){
				oies[nbOie]= new Oie(couleur, plateau, des);
				this.nbOie++;
		}
	}
	
	
	public void jouer(){
		
		boolean fin=(nbOie<2);
		int cpt=0;
		while(!fin){
			cpt=0;
			while(!fin && cpt!=(this.nbOie)){
				fin=this.oies[cpt].action();
				cpt++;
			}
		}
	}
}
