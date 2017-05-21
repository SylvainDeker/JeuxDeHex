import javax.sound.midi.Soundbank;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by salimcherifi on 5/18/17.
 */
public class Plateau {
    private int size;

    public Plateau(int size ) {
        this.size = size;
    }

    public void printBoard(char[] s){
        char ch;
        int cpt = 0;
        for (int i = 2;i<(this.getSize()*this.getSize())+2;i++){

            if((i-2)%this.getSize() == 0 && i != 2) {
                System.out.print("\\\n\n");
                cpt++;
                for (int h = 0; h < cpt; h++) {
                    System.out.print("    ");
                }
            }

            ch = s[i];

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
        System.out.println("\\\n");

        }



    public String getBoard() throws IOException {

        char read[] = new char[50];
        FileWriter fOut = new FileWriter("../java_vers_c");
        fOut.write("g\n");
        fOut.close();
        FileReader fIn = new FileReader("../c_vers_java");
        fIn.read(read);
        fIn.close();
        String message = new String(read);
        return message;
    }

    public int getSize() {
        return size;
    }
}
