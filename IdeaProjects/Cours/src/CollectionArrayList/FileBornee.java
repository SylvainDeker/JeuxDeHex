package CollectionArrayList;

/**
 * Created by salimcherifi on 03/03/17.
 */
public class FileBornee implements IfileBornee {
    protected int[] data;
    protected int first;
    protected int last;
    protected int size;

    public FileBornee(int taille){
        this.data =  new int[taille];
    }


    @Override
    public void inserer(int i) {
        this.data[last] = i;
        this.last++;
        this.size++;
    }

    @Override
    public void supprimer() {
        this.first++;
        this.size--;
    }

    @Override
    public boolean estVide() {
        return(this.last==this.first && this.size == 0);
    }

    @Override
    public int premier() {
        return this.data[this.first];
    }

    @Override
    public int longueur() {
        return this.size;
    }

    @Override
    public boolean estPleine() {

        return(this.first == this.last && this.size>0);
    }

}
