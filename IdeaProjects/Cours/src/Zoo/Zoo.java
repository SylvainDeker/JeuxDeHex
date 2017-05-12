package Zoo;

import java.util.ArrayList;

/**
 * Created by salimcherifi on 03/03/17.
 */
public class Zoo {
    protected ArrayList<Fauve> fauve;
    public Zoo(){
        this.fauve = new ArrayList<Fauve>();
    }
    public void nourrir(){
        for (Fauve l : this.fauve) {
            l.manger();
        }
    }
    
    public void faireDormir(){
        for (Fauve l :
                this.fauve) {
            l.dormir();
        }
    }
}
