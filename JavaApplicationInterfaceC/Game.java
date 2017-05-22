import java.io.*;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

/**
 * Create a game
 */
public class Game {

    //The board of the game
    Plateau plateau;
    //THe players of the game Max 2
    Joueur joueurs[] = new Joueur[2];

    /**
     * Read the keyboard inputKeyboard
     * @return the keyboard input
     * @throws IOException
     */
    public String inputKeyboard() throws IOException {

        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        return input;
    }

    /**
     * Checks if a square is free
     * @param  String      x             the x axis coordinate
     * @param  String      y             the y axis coordinate
     * @return             true if free and false if already occupied
     * @throws IOException [description]
     */
    public boolean squareFree(String x, String y) throws IOException {
        sendToC("e("+x+","+y+")\n");
        char message[] = receiveFromC();
        return (message[0] == '0');
    }

    /**
     * Send the code to place a pawn on (x,y)
     * @param  String      j             Which player is playing
     * @param  String      x             the x coordinate
     * @param  String      y             the y coordinate
     * @throws IOException
     */
    public void placePawn(String j,String x, String y) throws IOException {
        sendToC("p("+j+","+x+","+y+")\n");
    }


    /**
     * CHecks if a winner eixsts by sending a code to the c program
     * @return 0 if no winner 1 if winner is player 1 or 2 if player 2. -1 if error
     * @throws IOException
     */
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

    /**
     * Send to the c program the message
     * @param  String      message       The message you want to send to the c program
     * @throws IOException
     */
    public void sendToC(String message) throws IOException {
        FileWriter fOut = new FileWriter("../java_vers_c");
        fOut.write(message);
        fOut.flush();
        fOut.close();
    }


    /**
     * Receive from the c program any kind of information
     * @return the information read
     * @throws IOException
     */
    public char[] receiveFromC() throws IOException {
        char read[] = new char[50];
        FileReader fIn = new FileReader("../c_vers_java");
        fIn.read(read);

        fIn.close();

        return read;
    }

    /**
     * Saves the current play by sending the s code to the c program
     * @throws IOException
     */

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


    /**
     * Quit the current play without saving
     * @throws IOException
     */
    public void quit() throws IOException{

        sendToC("q\n");
    }


    /**
     * Start a game Human vs Human
     * @throws IOException [description]
     */
    public void letsPlayHvsH() throws IOException {
        String continueOrSave;
        String x;
        String y;
        boolean validMove;
        //Loop until winner is found
        while (true){
          //Loop between the two players
            for (int i = 1; i < 3;i++){
                validMove = false;
                System.out.println("=================== JOUEUR "+this.joueurs[i-1].getName()+" ===================");
                //Print the board
                sendToC("g\n");

                this.plateau.printBoard(receiveFromC());

                //The Player chooses where he wants to play
                while (validMove == false){
                    //ajouter gestion des pions deja placé
                    System.out.println("Coordinates of the pawn to place (x,y) : ");
                    System.out.print("x : ");
                    x = inputKeyboard();
                    System.out.print("y : ");
                    y = inputKeyboard();
                    //if square is free place pawn and break from loop else loop until valid choice
                    if (squareFree(x,y)){
                        placePawn(Integer.toString(i),x,y);
                        validMove = true;
                    }else{
                        System.out.println("Square already used, choose another one please !");
                    }
                }
                //Choice to continue undo quit or save
                System.out.print("[ENTER] to continue, [u] to undo, [s] to save or [q] to quit : ");
                continueOrSave = inputKeyboard();
                switch (continueOrSave){
                    case "": //Continue
                        break;
                    case "q": //Quit game
                        System.out.println("Goodbye !");
                        quit();
                        return;
                    case "s": //Save game
                        save();
                        return;
                    case "u": //Undo last play
                        System.out.println("Your last play will be canceled! [y] to confirm, [n] to cancel");
                        String choice = inputKeyboard(); //Confirm
                        if (choice.equals("y")) {
                            System.out.println("FAIT");
                            sendToC("u\n");
                        }else{
                            System.out.println("Canceling...");

                        }
                    default : break;
                }
                //If a winner exists display winner quit game and break from loop;
                if (existsWinner() != 0) {
                    System.out.println("Bravo au joueur "+this.joueurs[i-1].getName()+" !");

                    quit();
                    return;
                }
            }
        }

    }



    /**
     * Restore a previously saved game
     * @throws IOException
     */
    public void restore() throws IOException{
        String savefile;
        char[] returnValue = new char[50];
        returnValue[0] = '0';

        while(returnValue[0] == '0'){
            System.out.print("What is the name of the savefile ? Name : ");
            savefile = inputKeyboard();
            sendToC("r( "+savefile+" )\n");

            returnValue = receiveFromC();
            //r returns 1 if file exists and 0 if file does not exist
            if (returnValue[0] == '0') {
                System.out.println("File does not exist, specify another : ");
            }
        }

        System.out.println("Press [Enter] please...");
        //Wait for enter key
        System.in.read();
        sendToC("g\n");

        char[] board = receiveFromC();
        this.plateau = new Plateau(Character.getNumericValue(board[0]));
        System.out.print("What is the name of the first player ? Name : ");
        this.joueurs[0] = new Joueur(inputKeyboard());
        System.out.print("What is the name of the second player ? Name : ");
        this.joueurs[1] = new Joueur(inputKeyboard());




    }

    /**
     * Display the menu for a new game Human vs Human
     * @throws IOException
     */
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






    /**
     * Display a menu for a new game HUman vs AI
     * @throws IOException [description]
     */

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


    /**
     * Game Human vs AI
     * @param  String      a             The order of the game : 1 if player plays first 2 otherwise
     * @throws IOException
     */
    public void letsPlayHvsAI(String a) throws IOException{
        String continueOrSave;
        String x = "";
        String y = "";
        boolean validMove;
        int i = 0;
        int cptI = 0;

        //If player plays first we begin with him otherwise we begin with the AI
        if (a.equals("1")) {
            i = 1;
        }else{
            i=2;
            //Initialize the solver
            sendToC("i(1)\n");

        }

        while (true){

            if (i == 2) {

                System.out.println("=================== "+this.joueurs[1].getName()+" ===================");

                sendToC("g\n");
                this.plateau.printBoard(receiveFromC());
                //If player plays first initialize the solver here
                if(a.equals("1") && cptI == 0){
                    sendToC("i(2)\n");
                    cptI++;
                }

                System.out.println("Press [Enter] please...");
                //Wait for enter key
                System.in.read();

                //If player plays second increment the counter so we launch the k command a the right time
                if (a.equals("2")) {
                    cptI++;
                }
                if (cptI >= 2 ) {
                    sendToC("k("+x+","+y+")\n");
                }

                System.out.println("Press [Enter] please...");
                //Wait for enter key
                System.in.read();

                //AI plays
                sendToC("v\n");
                cptI++;





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
                            System.out.println("DONE");
                            sendToC("u\n");
                        }else{
                            System.out.println("Canceling...");
                        }
                        break;
                    default : break;
                }
            }

            //Detects if a winner exists
            if (existsWinner() != 0) {
                System.out.println("Bravo au joueur "+this.joueurs[i-1].getName()+" !");

                quit();
                return;
            }
            //i loop between 1 and 2 so each player can play
            i = (i%2)+1;

        }
    }













    /**
     * Display the menu of the game
     * @throws IOException
     * @throws InterruptedException
     */
    public void menuGame() throws IOException, InterruptedException {
        String choice;
        //Boolean if the first choice is not right
        boolean validChoice = false;
        //Boolean for the second menu displayed for a new game so it loops if the choice is not right
        boolean validChoiceLvl2 = false;


        while(validChoice == false){
          System.out.println("1 - New Game");
          System.out.println("2 - Load game");
          System.out.print("What do you want to do ? Choice : ");
          choice = inputKeyboard();
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
                                System.out.println("ouloulou");
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
