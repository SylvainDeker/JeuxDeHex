import javax.sound.midi.Soundbank;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Create a board
 */
public class Plateau {
    /**
     * Size of the board
     */
    private int size;

    /**
     * Constructor of the board
     * @param  int size          size of the board
     * @return     the board
     */
    public Plateau(int size ) {
        this.size = size;
    }

    /**
     * Print the board you are playing on
     * @param char[] s the code of the board sent from the c code
     */
    public void printBoard(char[] s){
        char ch;
        int cpt = 0;

        for (int i = 2;i<(this.getSize()*this.getSize())+2;i++){
            /**
             * If we reached the end of one line print a \ , jump line and display a space
             */
            if((i-2)%this.getSize() == 0 && i != 2) {
                System.out.print("\\\n\n");
                cpt++;
                for (int h = 0; h < cpt; h++) {
                    System.out.print("    ");
                }
            }
            /**
             * The character read
             */
            ch = s[i];

            /**
             * if character corresponds to an empty square print a dot
             * if the character corresponds to a square of player 1 print a 1
             * if the character correspond to a square of player 2 print a 2
             */
            switch (ch){
                case '0':
                    System.out.print("\\  .  ");
                    break;
                case '1':
                    System.out.print("\\  1  ");
                    break;
                case '2':
                    System.out.print("\\  2  ");
                    break;
                default:
                    break;

            }

        }
        /**
         * At the end of the board print a \n and end
         */
        System.out.println("\\\n");

        }


        /**
         * Get the code of the board from the c program
         * @return the code of the board Ex : 2-0000 or 4-0000000000000000
         * @throws IOException
         */
    public String getBoard() throws IOException {

        char read[] = new char[50];
        FileWriter fOut = new FileWriter("../java_vers_c");
        //send the code to print the board
        fOut.write("g\n");
        fOut.close();
        FileReader fIn = new FileReader("../c_vers_java");
        //Read the code
        fIn.read(read);
        fIn.close();
        //Make a string out the char array
        String message = new String(read);
        return message;
    }
    /**
     * Return the size  of the board
     * @return the size of the board
     */
    public int getSize() {
        return size;
    }
}
