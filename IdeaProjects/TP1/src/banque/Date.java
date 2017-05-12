package banque;

/**
 * Permet de créer une date et de l'utiliser dans les classes
 */
public class Date {
   private int jour, mois, an;
   private int heure = 0;
   private int minute = 0;
   private int seconde = 0;

    /**
     * Constructeur de la date
     * @param jour les jours
     * @param mois les mois
     * @param an les années
     */
    public Date(int jour, int mois, int an) {
        this.jour = jour;
        this.mois = mois;
        this.an = an;
    }

    /**
     * Retourne les jours
     * @return les jours
     */
    public int getJour() {
        return jour;
    }

    /**
     *Retourne les mois
     * @return les mois
     */
    public int getMois() {
        return mois;
    }

    /**
     *Retourne les années
     * @return les années
     */
    public int getAn() {
        return an;
    }

    /**
     *Retourne les heures
     * @return les heures
     */
    public int getHeure() {
        return heure;
    }

    /**
     * Retourne les minutes
     * @return les minutes
     */
    public int getMinute() {
        return minute;
    }

    /**
     * Retourne les secondes
     * @return les secondes
     */
    public int getSeconde() {
        return seconde;
    }


    /**
     * Affiche la date au format : h:m:s j/m/a
     * @return le format h:m:s j/m/a
     */
    @Override
    public String toString() {
        return "["+heure+":"+minute+":"+seconde+" "+jour+"/"+mois+"/"+an+"]";
    }
}
