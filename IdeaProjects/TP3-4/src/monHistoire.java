/**
 * Mon histoire
 */
public class monHistoire {
    public static void main(String args[]){
        Humain h = new Humain(10,"Porto", "Prof");

        h.direBonjour ();
        h.boire ();

        Commerçant c = new Commerçant(35, "Marchand");

        c.direBonjour ();

        Yakuza y = new Yakuza(42,"biere","Yaku le noir","WarSong");

        y.extorquer(c);

        Ronin r = new Ronin(61,"sake", "Roro");

        r.donner(c,10);
        r.provoquer(y);
        r.direBonjour();

        GrandMere GM = new GrandMere(500,"Huguette Norris");

        GM.direBonjour();
        GM.faireConnaissanceAvec(y);
        GM.faireConnaissanceAvec(r);
        GM.ragoter();

    }
}
