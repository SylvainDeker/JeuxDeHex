package banque;

import java.util.Arrays;

/**
 * Permet de créer une banque
 */
public class Banque {
    private int nbreClients;
    private Client[] tabClients;

    /**
     * Constructeur de la banque
     * @param nbreClients Le nombre de clients
     */
    public Banque(int nbreClients) {
        this.nbreClients = nbreClients;
        this.tabClients = new Client[100];
    }

    /**
     * Permet d'ajouter un client à la banque
     * @param client ajouter un client à la banque
     */
    void ajouterClient(Client client){
        this.nbreClients++;
        tabClients[this.nbreClients-1] = client;
    }

    /**
     * Renvoi le client à l'indice numClient
     * @param numClient Le numéro du client
     * @return le client à l'indice numClient
     */
    Client getClient(int numClient){
        return this.tabClients[numClient];
    }

    /**
     * Affiche le bilan de la banque pour tous les clients
     */
    void afficherBilan(){
        for (int i=0;i<this.nbreClients;i++){
            System.out.println("Client : "+this.tabClients[i].getNom());
            this.tabClients[i].afficherBilan();
        }
    }


}
