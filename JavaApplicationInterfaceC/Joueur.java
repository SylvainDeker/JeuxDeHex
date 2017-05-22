/**
   * Create a player
 */
public class Joueur {
    /**
     * Name of the player
     */
    private String name;
    /**
     * Constructor of the player
     * @param  String name          Name of the player you want to Created
     * @return        The player
     */
    public Joueur(String name) {
        this.name = name;
    }

    /**
     * get the name of the player
     * @return the name of the player
     */
    public String getName() {
        return name;
    }
}
