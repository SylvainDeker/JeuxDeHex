public class Oie {
	private String couleur;
	private Des des;
	protected Journal journal= new Journal();
	protected Plateau plateau;
	protected Case casePlateau=new Case(0);
	
	public Oie(String couleur, Plateau plateau, Des des){
		this.couleur=couleur;
		this.plateau=plateau;
		this.des=des;
	}
	
	public Plateau getPlateau(){
		return this.plateau;
	}
	
	public String getCouleur(){
		return this.couleur;
	}
	
	public boolean action(){
		Case casePlateau=this.casePlateau.depart(this);
		this.journal.afficherMessage();
		this.casePlateau=casePlateau;
		return (casePlateau.getNom().equals("Numero 63"));
		
	}
	
	public int lancerDe(){
		int valeurD= this.des.lancer();
		ajouterMessage("Elle fait"+valeurD);
		return valeurD;
	}
	
	public void ajouterMessage(String message){
		this.journal.ajouterMessage(message);	
	}
}
