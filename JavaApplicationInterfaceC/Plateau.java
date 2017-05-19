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

    public void printBoard(String s){
        char ch;
        for (int i = 2;i<this.getSize()+2;i++){

            for (int h = 0;h < i; h++)
                System.out.print("  ");
            for (int j = 0;j<this.getSize();j++){
                ch = s.charAt(i+j);
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
