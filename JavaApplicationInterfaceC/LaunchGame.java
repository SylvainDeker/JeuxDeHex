import java.io.IOException;

/**
 * Main class : launch the game from the main menu
 */
public class LaunchGame {
    public static void main(String args[]) throws IOException, InterruptedException {
        Game game = new Game();
        game.menuGame();
    }
}
