package banque;

import java.util.Scanner;

/**
 * Application de test de la banque
 */
public class mainBanque {

    static int lireClavier(){
        int chaine;
        Scanner clavier = new Scanner(System.in);
        chaine = clavier.nextInt();
        return chaine;
    }


    public static void main(String[] args){

        Date dateJean = new Date(20, 9, 1996);
        Date datePizzaYolo = new Date(18, 7, 1991);
        Date dateCarte = new Date(01, 01, 2020);

        int[] code = {1,2,3,4};
        int[] codeEntre = new int[4];
        Banque banque = new Banque(0);

        Compte compteJean = new Compte(100, 0);
        Client jean = new Client("Jean Eude", dateJean, compteJean, 0);


        Compte comptePizzaYolo = new Compte(5000, 0);
        Client pizzaYolo = new Client("Pizza Yolo", datePizzaYolo, comptePizzaYolo, 1);

        banque.ajouterClient(jean);
        banque.ajouterClient(pizzaYolo);

        Carte carte = new Carte(code,banque,jean, jean.getNumClient(),dateCarte);
        Terminal terminal = new Terminal(banque,pizzaYolo.getNumClient(), comptePizzaYolo.getNumCompte());
        int montant = 30;


        for (int i=0;i<4;i++){
            codeEntre[i]=lireClavier();
        }



        if(!(terminal.genererAutorisation(carte, montant, codeEntre))){
            System.out.println("Non autorisé");
            return;
        }
        carte.payer(banque,pizzaYolo.getNumClient(),0,montant);

    }
}
