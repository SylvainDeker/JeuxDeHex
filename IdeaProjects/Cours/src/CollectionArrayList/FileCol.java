package CollectionArrayList;

import java.io.File;
import java.util.ArrayList;

/**
 * Created by salimcherifi on 03/03/17.
 */
public class FileCol implements Ifile {

    protected ArrayList<Integer> data;

    public FileCol(){
        data = new ArrayList<Integer>();
    }
    @Override
    public void inserer(int i) {
        data.add(i);
    }

    @Override
    public void supprimer() {
        assert(data.size() != 0);
        data.remove(0);
    }

    @Override
    public boolean estVide() {
        return(data.isEmpty());
    }

    @Override
    public int premier() {
        return data.get(0);
    }

    @Override
    public int longueur() {
        return data.size();
    }
}
