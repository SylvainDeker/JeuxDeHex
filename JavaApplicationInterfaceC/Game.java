import java.io.*;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

/**
 * Created by salimcherifi on 5/17/17.
 */
public class Game {

    Plateau plateau;
    Joueur joueurs[] = new Joueur[2];
    public String inputKeyboard() throws IOException {

        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        return input;
    }

    public boolean squareFree(String x, String y) throws IOException {
        sendToC("e("+x+","+y+")\n");
        char message[] = receiveFromC();
        return (message[0] == '0');
    }

    public void placePawn(String j,String x, String y) throws IOException {
        sendToC("p("+j+","+x+","+y+")\n");
    }



    public int existsWinner() throws IOException {

        sendToC("w\n");

        char mess[] = receiveFromC();

        if (mess[0] == '0'){
            return 0;
        }else if (mess[0] == '1'){
            return 1;
        }else if(mess[0] == '2'){
            return 2;
        }
        return -1;
    }


    public void sendToC(String message) throws IOException {
        FileWriter fOut = new FileWriter("../java_vers_c");
        fOut.write(message);
        //fOut.flush();
        fOut.close();
    }

    public char[] receiveFromC() throws IOException {
        char read[] = new char[50];
        FileReader fIn = new FileReader("../c_vers_java");
        fIn.read(read);

        fIn.close();

        return read;
    }






    public void letsPlay() throws IOException {
        String continueOrSave;
        String x;
        String y;
        boolean validMove;

        while (existsWinner() == 0){
            for (int i = 1; i < 3;i++){
                validMove = false;
                System.out.println("=================== JOUEUR "+this.joueurs[i-1].getName()+" ===================");
                sendToC("g\n");

                this.plateau.printBoard(receiveFromC());
                while (validMove == false){
                    //ajouter gestion des pions deja placé
                    System.out.println("Coordinates of the pawn to place (x,y) : ");
                    System.out.print("x : ");
                    x = inputKeyboard();
                    System.out.print("y : ");
                    y = inputKeyboard();

                    if (squareFree(x,y)){
                        placePawn(Integer.toString(i),x,y);
                        validMove = true;
                    }else{
                        System.out.println("Square already used, choose another please !");
                    }
                }

                System.out.print("[ENTER] to continue, s to save or q to quit : ");
                continueOrSave = inputKeyboard();
                switch (continueOrSave){
                    case "":
                        break;
                    case "q":
                        System.out.println("Goodbye !");
                        sendToC("q\n");
                        return;
                    case "s":
                        //gérer la sauvegarde;
                        break;
                    default : break;
                }
            }
        }


    }
    public void menuGame() throws IOException, InterruptedException {
        String choice;
        String size;
        String savefile;
        String s;

        System.out.println("1 - New Game");
        System.out.println("2 - Load game");
        System.out.print("What do you want to do ? Choice : ");
        choice = inputKeyboard();
        switch (choice){

            case "1":
                System.out.print("What is the name of the first player ? Name : ");
                this.joueurs[0] = new Joueur(inputKeyboard());
                System.out.print("What is the name of the second player ? Name : ");
                this.joueurs[1] = new Joueur(inputKeyboard());
                System.out.println("What is the size of the board ? Size :  ");
                size = inputKeyboard();

                sendToC("n("+size+")\n");

                System.out.println("Press [Enter] please...");
                //Wait for enter key
                System.in.read();
                this.plateau = new Plateau(Integer.parseInt(size));

                letsPlay();
                break;
            case "2" :
                /*System.out.print("What is the name of the savefile ? Name : ");
                savefile = inputKeyboard();
                f.write("");*/
                break;
            default :
                System.out.println("Please choose a valid option");
                break;
        }
    }

}
