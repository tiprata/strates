#include <stdio.h> //Cette ligne signifie au programme d'importer la librairie de fonction déjà présente sur notre ordinateur 'stdio.h', qui contiendra la fonction nous permettant d'écrire sur le terminal 

//Ci dessous la fonction "melange" : une fonction permet de séparer notre code en plusieurs petits "composants" pour s'y retrouver dans de très gros codes, d'identifier plus facilement leur rôle, par exemple quand nous travaillons sur le code d'un autre.

//Presque tout ce qui se passe dans une fonction, disparait une fois que son rôle est achevé(comme les variables qu'on a pu y créer), or, nous pouvon "retourner" une variable de notre choix : ici, nous renvoyons à la fonction Main la variable tailleGateau.

// La premiere ligne ci-dessous représente le "prototype" de la fonction 'melange' : en premier le type de la variable qu'elle va renvoyer au programme qui l'appelle (pouvant être un nombre, un caractère, une chaine de caractères, et bien d'autres), ensuite le nom sous lequel elle va être appelée dans la fonction 'main' : (melange), puis , entre parenthèses , les variables originaires de la fonction "main" que nous importons dans celle-ci afin de les réutiliser


int	melange(int farine, int sucre, int lait) 
{
  int tailleGateau; // Cette fonction a pour simple but d'additionner les variables farine, sucre et lait, 
  // on peut imaginer , en plus développée qu'elle pourrait servir à connaître le poids exact d'un gateau,
  // en gramme , en convertissant les centilitres de lait en grammes.

  tailleGateau = farine + sucre + lait;

  return (tailleGateau); // "return" est le mot-clés nous signifiant la fin de la fonction lorsque celle-ci doit renvoyer une variable à la fonction qui l'a appelée, variable que nous précisons ensuite entre parenthèse
}



// Cette fonction est prototypée en "void" : elle ne renvoie rien. Son rôle est uniquement de simuler un temps de cuisson, d'afficher à chaque changement de seconde le temps restant dans notre terminal, et d'évaluer le temps de cuisson : si celui-ci est suffisant ou trop élevé.

void	cuisson(int tailleGateau, int tempsDeCuisson)
{
  int tempsActuel;
  // Cette variable nous servira de "compteur" afin de savoir combien de fois répéter une action dans la boucle while ci-dessous
  tempsActuel = 0;
  // Le mot-clé "while" nous sert à répéter l'action contenue entre ses { } tant que la condition placée entre parenthèse après le mot while n'est pas validée.
  while (tempsActuel < tempsDeCuisson)
    {
      //Nous avons donc la variable tempsDeCuisson initialement mise à 180 dans la fonction 'main'.
      // Tant que la variable tempsActuel est strictement inférieure à tempsDeCuisson, l'action 'printf' se répètera.

      printf("La cuisson est terminee dans %d secondes\n", tempsDeCuisson - tempsActuel); // Cette fonction appelée depuis la librairie de fonctions 'stdio.h', inclue tout en haut de notre fichier, nous permet d'afficher du texte dans le terminal lorsque nous exécuterons le programme. Nous afficherons donc la phrase 'La cuison est terminée dans %d secondes\n', où %d correspond à la soustraction de la variable tempsActuel à la variable tempsDeCuisson, afin d'obtenir le temps de cuisson restant, et le '\n' correspondant à un retour à la ligne, pour plus de clarté 

      tempsActuel = tempsActuel + 1; // Ici nous "incrémentons" la variable : pour éviter une boucle sans fin, nous augmentons de 1 le nombre contenu dans la variable tempsActuel à chaque tour de la boucle, jusqu'à ce que ce nombre soit égal à celui contenu dans la variable tempsDeCuisson
    }
  if (tempsDeCuisson > 200)   //Ici nous utilisons le mot clé "if" (trois utilisations possibles, toutes présentées ci-dessous). Le code contenu entre les { } sera effectué uniquement si la condition entre la parenthèse est validée.
    {
      printf("Ton gateau est trop cuit ! Il pese %d grammes\n", tailleGateau);
    }
  else if (tempsDeCuisson < 100) // "else if "nous permet d'ajouter une condition qui sera vérifiée seulement si la ou les précédentes sont invalidées ET que la condition entre parenthèse est validée, le code entre les { } est alors exécuté.
    {
      printf("Ton gateau est pas assez cuit ! Il pese %d grammes \n", tailleGateau);
    }
  else  //"else" peut être utilisé après un 'if' ou après un 'else if' : il nous permet d'effectuer le code entre { } seulement si toutes les conditions précédentes (tout 'if' ou 'else if' au-dessus du 'else') sont invalidées. 
    {
      printf("Ton gateau est parfaitement cuit ! Il pese %d grammes \n", tailleGateau);
    }
}




//Ceci est la fonction principale, la seule dont le nom ne peut être changé. A l'exécution du programme, elle sera la première à être "lue" et le code contenu dedans sera exécuté. Depuis celle-ci, nous appelons , selon nos besoins, et autant de fois que nous voulons les autres fonctions ci-dessus, dont le code contenu à l'intérieur sera également exécuté. 
int	main(void)
{
  int farine; //Ici nous "déclarons" des variables de type 'int'(integer -> entiers) qui contiendront des nombres entiers que nous assignerons plus bas.
  int sucre;
  int lait;
  int tempsDeCuisson;
  int tailleGateau;

  tempsDeCuisson = 180;// Ici, nous assignons la valeur de 180 à la valeur tempsDeCuisson : une variable 'déclarée' mais non-'assignée' est inutilisable.
  lait = 30;
  sucre = 50;
  farine = 200;
  tailleGateau = melange(farine, sucre, lait); // Ici , nous assignons à la variable tailleGateau le retour (résultat renvoyé) de la fonction 'melange', et nous "passons en paramètre" les variables 'farine', 'sucre' et 'lait' , signifiant que nous pourrons les utiliser dans la fonction 'melange'.
  cuisson(tailleGateau, tempsDeCuisson); // Ici, nous appelons simplement la fonction "cuisson", et passons en paramètre la variable 'tailleGateau' et 'tempsDeCuisson' afin d'afficher l'etat de la cuisson, et déterminer si notre gateau sera trop cuit selon le paramètre tempsDeCuisson
  return (0); // Nous retournons 0 : la fonction main a remplis son rôle, nous signalons sa fin et donc l'arrêt total du programme.
}


// Exercice : Ajouter la température de cuisson en nouvelle variable et y faire dépendre le message indiquant que le gateau est trop cuit : si la température de cuisson dépasse les 250 ET que le temps de cuisson est supérieur à 50, signaler à l'utilisateur que son gateau sera carbonisé, et qu'il s'expose à des risques cardio-vasculaires. 
