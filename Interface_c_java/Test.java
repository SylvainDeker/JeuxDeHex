import java.io.*;

class Test {
  public static void main(String[] args) throws Exception {
    PrintWriter pw = new PrintWriter(new BufferedOutputStream(new FileOutputStream("java_vers_c")));
    pw.println("hello");
    pw.close();
  }
}
