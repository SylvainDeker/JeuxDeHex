package CollectionArrayList;

/**
 * Created by salimcherifi on 03/03/17.
 */
public class File implements Ifile {

    class Cellule{
        int val;
        Cellule next;
        public Cellule(int val){
            this.val = val;
            this.next = null;
        }
    }

    protected Cellule first;
    protected Cellule last;
    protected int size;
    @Override
    public void inserer(int i) {
        if(this.first == null){
            this.first = this.last = new Cellule(i);
        }else{

            this.last.next = new Cellule(i);
            this.last = this.last.next;
        }
    }

    @Override
    public void supprimer() {
        if(this.size == 1){
            this.first = null;
            this.last = null;
        }else{
            this.first = this.first.next;
        }
        this.size--;
    }

    @Override
    public boolean estVide() {
        return(this.size == 0);
    }

    @Override
    public int premier() {
        return this.first.val;
    }

    @Override
    public int longueur() {
        return this.size;
    }
}
