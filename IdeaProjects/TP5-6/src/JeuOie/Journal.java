package JeuOie;

/**
 * Créer un journal
 */
public class Journal {
    private String message = "";

    /**
     * Ajouter un message au journal
     * @param message message à ajouter
     */
    public void ajouterMessage(String message){
        this.message = this.message + message;
    }

    /**
     * Afficher les messages du journal
     */
    public void afficherMessage(){
        System.out.println(this.message);
        message = "";
    }
}
