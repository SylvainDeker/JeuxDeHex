Pour lancer le programme : make run

Pour Simuler le fonctionnement du programme c : make all; valgrind ./JeuxDeHex
 - Envoyer une commande avec : echo "commande_a_envoyer">java_vers_c
   (ex: création d'un grille de taille 3x3 : echo "n(3)">java_vers_c )
 - Lire un résultat avec : cat c_vers_java
    (Toute les commandes ne donnent pas forcement de resultats)



Pour Simuler le fonctionnement du programme java : make run -C JavaApplicationInterfaceC
 - Envoyer un résultat avec : echo "resultat_a_envoyer">c_vers_java
    (Toute les commandes ne donnent pas forcement de resultats)
 - Lire une commande avec : cat java_vers_c









Chose à verifier et faire manuellement pour les simulations de fonctionnement:
 - Evoyer le signal "q" pour quitter le programme c (à faire la fin du programme java).
 - Evoyer le signal "t" avant de refaire un "n(x)" pour terminé la partie avant d'en recommencer une autre
