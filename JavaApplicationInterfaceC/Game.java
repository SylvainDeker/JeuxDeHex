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
        fOut.flush();
        fOut.close();
    }

    public char[] receiveFromC() throws IOException {
        char read[] = new char[50];
        FileReader fIn = new FileReader("../c_vers_java");
        fIn.read(read);

        fIn.close();

        return read;
    }

    public void save() throws IOException{
      System.out.print("What is the name of the savefile ? Name : ");
      String savefile = inputKeyboard();
      System.out.print("A quick description of the game : ");
      String desc = inputKeyboard();

      sendToC("s( "+savefile+" , "+desc+" )\n");
      System.out.println("Press [Enter] please...");
      //Wait for enter key
      System.in.read();
      quit();
    }


    public void quit() throws IOException{

      sendToC("q\n");
    }


    public void letsPlayHvsH() throws IOException {
        String continueOrSave;
        String x;
        String y;
        boolean validMove;
        while (true){
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
                        System.out.println("Square already used, choose another one please !");
                    }
                }

                System.out.print("[ENTER] to continue, [u] to undo, [s] to save or [q] to quit : ");
                continueOrSave = inputKeyboard();
                switch (continueOrSave){
                    case "":
                        break;
                    case "q":
                        System.out.println("Goodbye !");
                        quit();
                        return;
                    case "s":
                        save();
                        return;
                    case "u":
                        System.out.println("Your last play will be canceled! [y] to confirm, [n] to cancel");
                        String choice = inputKeyboard();
                        if (choice.equals("y")) {
                          System.out.println("FAIT");
                          sendToC("u\n");
                        }else{
                          System.out.println("Canceling...");

                        }
                    default : break;
                }

                if (existsWinner() != 0) {
                  System.out.println("Bravo au joueur "+this.joueurs[i-1].getName()+" !");

                  quit();
                  return;
                }
            }
        }

    }




    public void restore() throws IOException{
        String savefile;
        char[] returnValue = new char[50];
        returnValue[0] = '0';

        while(returnValue[0] == '0'){
          System.out.print("What is the name of the savefile ? Name : ");
          savefile = inputKeyboard();
          sendToC("r( "+savefile+" )\n");

          returnValue = receiveFromC();
          if (returnValue[0] == '0') {
            System.out.println("File does not exist, specify another : ");
          }
        }

        System.out.println("Press [Enter] please...");
        //Wait for enter key
        System.in.read();
        sendToC("g\n");
        //AJOUTER SI FICHIER EXISTE PAS
        char[] board = receiveFromC();
        this.plateau = new Plateau(Character.getNumericValue(board[0]));
        System.out.print("What is the name of the first player ? Name : ");
        this.joueurs[0] = new Joueur(inputKeyboard());
        System.out.print("What is the name of the second player ? Name : ");
        this.joueurs[1] = new Joueur(inputKeyboard());




    }

    public void newGameHvsH() throws IOException{
        String size;
        System.out.print("What is the name of the first player ? Name : ");
        this.joueurs[0] = new Joueur(inputKeyboard());
        System.out.print("What is the name of the second player ? Name : ");
        this.joueurs[1] = new Joueur(inputKeyboard());
        System.out.print("What is the size of the board ? Size : ");
        size = inputKeyboard();

        sendToC("n("+size+")\n");

        System.out.println("Press [Enter] please...");
        //Wait for enter key
        System.in.read();
        this.plateau = new Plateau(Integer.parseInt(size));
    }







    public void NewGameHvsIA() throws IOException{
      String playerTurn;
      String size;
      System.out.print("Do you want to play first or second ? (1 or 2) Answer : ");
      playerTurn = inputKeyboard();
      System.out.print("What is the name of the player ? Name : ");
      this.joueurs[0] = new Joueur(inputKeyboard());
      this.joueurs[1] = new Joueur("IA");
      System.out.print("What is the size of the board ? Size : ");
      size = inputKeyboard();

      sendToC("n("+size+")\n");

      System.out.println("Press [Enter] please...");
      //Wait for enter key
      System.in.read();
      this.plateau = new Plateau(Integer.parseInt(size));


      letsPlayHvsAI(playerTurn);


    }



    public void letsPlayHvsAI(String a) throws IOException{
      String continueOrSave;
      String x;
      String y;
      boolean validMove;

      sendToC("i(1)\n");
      while (true){
          for (int i = 1; i < 3;i++){
              if (a.equals("1")) {
                i = i+1;
              }
              if (i == 1) { //tour IA
                validMove = false;
                System.out.println("=================== JOUEUR "+this.joueurs[1].getName()+" ===================");

                sendToC("g\n");
                this.plateau.printBoard(receiveFromC());



                sendToC("v\n");



                System.out.println("Press [Enter] please...");
                //Wait for enter key
                System.in.read();


              }else{

                validMove = false;
                System.out.println("=================== JOUEUR "+this.joueurs[0].getName()+" ===================");

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
                        sendToC("k\n");
                        validMove = true;
                    }else{
                        System.out.println("Square already used, choose another one please !");
                    }
                }

                System.out.print("[ENTER] to continue, [u] to undo, [s] to save or [q] to quit : ");
                continueOrSave = inputKeyboard();
                switch (continueOrSave){
                    case "":
                        break;
                    case "q":
                        System.out.println("Goodbye !");
                        quit();
                        return;
                    case "s":
                        save();
                        return;
                    case "u":
                        System.out.println("Your last play will be canceled! [y] to confirm, [n] to cancel");
                        String choice = inputKeyboard();
                        if (choice.equals("y")) {
                          System.out.println("FAIT");
                          sendToC("u\n");
                        }else{
                          System.out.println("Canceling...");

                        }
                    default : break;
                }
              }


              if (existsWinner() != 0) {
                System.out.println("Bravo au joueur "+this.joueurs[i-1].getName()+" !");

                quit();
                return;
              }
          }
      }
    }














    public void menuGame() throws IOException, InterruptedException {
        String choice;
        boolean validChoice = false;
        boolean validChoiceLvl2 = false;
        System.out.println("1 - New Game");
        System.out.println("2 - Load game");
        System.out.print("What do you want to do ? Choice : ");
        choice = inputKeyboard();
        while(validChoice == false){
            switch (choice){

                case "1":
                    validChoice = true;
                    System.out.println("1 - Human vs Human");
                    System.out.println("2 - Human vs Machine");
                    System.out.print("What do you want to do ? Choice : ");
                    choice = inputKeyboard();
                    while(validChoiceLvl2 == false){
                      switch(choice){
                        case "1":
                            validChoiceLvl2 = true;
                            newGameHvsH();
                            letsPlayHvsH();
                            break;
                        case "2":
                            validChoiceLvl2 = true;
                            NewGameHvsIA();
                            break;
                        default: break;
                      }
                    }


                    break;
                case "2" :
                  validChoice = true;
                    restore();
                    letsPlayHvsH();
                    break;
                default :
                    System.out.println("Please choose a valid option");
                    break;
            }
        }

    }

}
