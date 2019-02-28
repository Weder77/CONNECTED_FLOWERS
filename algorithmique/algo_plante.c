/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*       <algo_plante.c>                          __     __                   */
/*                                                \ \   / /                   */
/*   By: Dany JEAN-CHARLES (Weder77)               \ \_/ /                    */
/*                                                  \   /                     */
/*   Created: 22/02/19 by Weder77                    | |                      */
/*   Updated: 26/02/19 by Weder77                    |_|Nov Informatique      */
/*                                                                            */
/* ************************************************************************** */     

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// On récupère les données de la plante depuis la bdd
int humidité_max;
int humidité_min;

int luminosité_max;
int luminosité_min;

int température_atmosphériqeu_max;
int température_atmosphérique_min;

// On récupère les données actuelle de la plante
int humidité_plante;

int luminosité_plantee;

int température_atmosphérique_plante;
// On insère ces données dans la bdd pour que l'historique puisse être accessible pour l'utilisateur

// On compare les données de la bdd avec les données actuelle




int main()
{
  char nom[100]; // nom utilisateur
  char prenom[100]; // prenom utilisateur
  char email[100]; // mail utilisateur
  char mdp[100]; // mdp utilisateur
  char mdp_verif[100]; // verif du mdp quand on crée un compte
  char mdp_test[100]; // verif du mdp quand on se connecte
  char mdp_change[100]; // verif poru changer le mdp
  int age; // age de l'utilisateur
  int choix_menu; // choix du menu principal
  int choix_menu_connexion; // choix du menu de connexion
  int plante_terre = 0; // on regarde si l'objet est connecté
  int niveau_expertise_plante; // 1 = debutant 2 = intermédiaire 3 = expert
  char probleme[500]; // en cas de pb, message de l'utilisateur qui est envoyé
  int choix_notifs; // param les notifs
  int choix_notifs_heures=6; // param les notifs horaires, defaut = 6 heures
  int notifs_desactivee=0; // message a afficher en fonction des params notifs
  int fail_mdp; // si l'utilisateur fail son mdp a la page de connexion
  int fail_mdp_change; // quand l'utilisateur veut changer son mdp
  int choix_menu_compte; // choix au compte modification du compte
  int choix_menu_compte_2; // choix au compte
  int choix_plante; // choix au menu des plantes
  int choix_plante_2; // choix des plantes a planter
  int valider_plantage; // valider dans le menu des plantes 


  accueil:
  printf("\e[0;33m=== CONNEXION ===\e[0m\n\n");
  printf("1. Se connecter\n");
  printf("2. S'inscrire\n");
  printf("\nVotre choix ? ");
  scanf("%d", &choix_menu_connexion);

  switch (choix_menu_connexion) // switch qui gère le menu de connexion
  {
    case 1:
        connexion:
        printf("\e[0;33m=== CONNEXION ===\e[0m\n\n");

        printf("Entrez votre email :\n"); 
        scanf("%s",&email);
        mdp_check:
        printf("Entrez votre mot de passe : (non caché)\n"); 
        scanf("%s",&mdp_test);
        if (strcmp (mdp,mdp_test) == 0)
        {
          printf("\n\n\n");
          goto menu;
        }
        else
        {
          printf("\n\e[0;31mMot de passe / email incorrect. \e[0m\n\n");
          fail:
          printf("1. Ressayer\n2. Quitter\n");
          scanf("%d",&fail_mdp);
          if (fail_mdp>2 || fail_mdp<1)
           {
              printf("Nombre incorrect.\n\n");
              goto fail;
            }
          else if (fail_mdp==1)
            {
              goto connexion;
            }
          else if (fail_mdp==2)
            {
              return 0;
            }
        }

        goto menu;

       break;
    case 2:
        inscription:
        printf("\e[0;33m=== INSCRIPTION ===\e[0m\n\n");
        printf("Entrez votre nom :\n"); 
        scanf("%s",&nom);
        printf("Entrez votre prenom :\n"); 
        scanf("%s",&prenom);
        printf("Entrez votre email :\n"); 
        scanf("%s",&email);
        printf("Entrez votre mot de passe : (non caché)\n"); 
        scanf("%s",&mdp);
        printf("Confirmez votre mot de passe : (non caché)\n"); 
        scanf("%s",&mdp_verif);
        printf("Entrez votre âge :\n"); 
        scanf("%d",&age);
        niveau_expertise_plante:
        printf("Votre niveau d'epxertise avec les plantes ?\n1/ Débutant\n2/ Intermédiaire\n3/ Expert\n\n"); 
        scanf("%d",&niveau_expertise_plante);
        if (niveau_expertise_plante>3 || niveau_expertise_plante<1)
        {
          printf("Le nombre choisi est incorrect\n");
          goto niveau_expertise_plante;
        }
        if (strcmp (mdp,mdp_verif) == 0)
        {

        }
        else
        {
          printf("\n\n\e[0;31mLes 2 mots de passe ne correspondent pas.\e[0m \n\n\n");
          goto inscription;
        }
        printf("\e[0;32m=== Votre compte a été crée avec succès, merci de vous connecter pour accèder à l'application ===\e[0m\n\n");
        goto connexion;

    default:
       printf("Vous n'avez pas rentre un nombre correct. Retour au menu de connexion.");
       goto accueil;
       break;
  }



  menu:
  printf("\e[0;33m=== MENU ===\e[0m\n\n");
  printf("1. Gérer mon compte\n");
  printf("2. Plante actuelle\n"); // fini
  printf("3. Historique des plantes\n"); // fini
  printf("4. Voir toutes les plantes\n");
  printf("5. Notifications\n"); // fini 
  printf("6. Contact\n"); // fini
  printf("7. Se deconnecter\n"); // fini
  printf("\nVotre choix ? ");
  scanf("%d", &choix_menu);
  
  printf("\n");
  
  switch (choix_menu) // Menu principal
  {
    case 1:
      compte:
      printf("\e[0;33m=== MON COMPTE ===\e[0m\n\n");
      printf("Bonjour %s !\n",prenom);
      printf("Voici tes informations :\nNom : %s.\nPrénom : %s.\nAge : %d.\nEmail : %s.\n\n", nom, prenom, age, email);
      printf("1. Modifier mes informations\n");
      printf("2. Modifier mon mot de passe\n");
      printf("3. Retour\n");    
      printf("4. Se deconnecter\n");
      printf("\nVotre choix ? ");
      scanf("%d", &choix_menu_compte);
      switch (choix_menu_compte)
       {
         case 1:
            modifier_compte:
            printf("\e[0;33m=== MODIFIER MON COMPTE ===\e[0m\n\n");
            printf("Quelles informations souhaites-tu modifier ?\n");
            printf("Voici tes informations :\n1. Nom : %s.\n2. Prénom : %s.\n3. Age : %d.\n4. Email : %s.\n\n", nom, prenom, age, email);
            printf("5. Retour\n");    
            printf("\nVotre choix ? ");
            scanf("%d", &choix_menu_compte_2);
            switch (choix_menu_compte_2)
            {
              case 1:
                printf("Ton nom actuel est : %s, par quoi veux-tu le remplacer ?\n", nom);
                scanf("%s",&nom);
                goto modifier_compte;
                break;
              case 2:
                printf("Ton prenom actuel est : %s, par quoi veux-tu le remplacer ?\n", prenom);
                scanf("%s",&prenom);
                goto modifier_compte;
                break;
              case 3:
                printf("Ton age est : %d, par quoi veux-tu le remplacer ?\n", age);
                scanf("%s",&age);
                goto modifier_compte;
                break;
              case 4:
                printf("Ton email actuel est : %s, par quoi veux-tu le remplacer ?\n", email);
                scanf("%s",&email);
                goto modifier_compte;
                break;
              case 5:
                goto compte;
                break;
              default:
                printf("Vous n'avez pas rentre un nombre correct.\n");
                goto modifier_compte;
                break;
            }    
              break;
         case 2:
            change_pass:
            printf("Pour modifier ton mot de passe vous devez d'abord confimer ton ancien mot de passe.\n");
            scanf("%s",&mdp_change);
            if (strcmp (mdp,mdp_change) == 0)
           {
              mdp_change:
              printf("Entrez votre nouveau mot de passe :\n");
              scanf("%s",&mdp);
              printf("Confirmez votre nouveau mot de passe :\n");
              scanf("%s",&mdp_verif);
              if (strcmp (mdp,mdp_verif) == 0)
             {

             }
              else
             {
               printf("\n\n\e[0;31mLes 2 mots de passe ne correspondent pas.\e[0m \n\n\n");
               goto mdp_change;
             }
            goto modifier_compte;
           }
           else
           {
             printf("\n\e[0;31mMot de passe incorrect. \e[0m\n\n");
             fail_mdp_change:
             printf("1. Ressayer\n2. Retour\n");
             scanf("%d",&fail_mdp_change);
             if (fail_mdp_change>2 || fail_mdp_change<1)
              {
                 printf("Nombre incorrect.\n\n");
                 goto fail_mdp_change;
               }
             else if (fail_mdp_change==1)
               {
                 goto change_pass;
               }
             else if (fail_mdp_change==2)
               {
                 goto compte;
               }
            }           
            goto compte;
            break;
         case 3:
            goto menu;
            break;
         case 4:
            printf("Au revoir !\n");
            return 0;
            break;
         default:
            printf("Vous n'avez pas rentre un nombre correct. Retour au menu.\n");
            goto compte;
            break;
       }
       break;
    case 2:
      ma_plante:
      if (plante_terre == 1)
      {
        printf("Vous avez une plante connectée : (affichage du nom de la plante)\n");
        printf("Caractéristiques actuelles :\n(affichage des caractéristiques + des besoins)\n");
      }
      else 
      {
        printf("Vous n'avez aucune plante mise a terre.\n");
        goto menu;
      }
      break;
    case 3:
       printf("Voici l'historique de vos plantes :\n");
       printf("(récupère depuis la bdd les plantes connectées -> affichage des noms des plantes\n");
       goto menu;
       break;
    case 4:
       plante_choix: 
       printf("Voici toutes les plantes que vous pouvez planter :\n");
       affichage_plantes();
       printf("Souhaitez-vous planter une nouvelle plante ?\n1. Oui\n2. Non\n");
       scanf("%d",&choix_plante);
       if (choix_plante>2 || choix_plante<1)
       {
        printf("Nombre choisi incorrect.\n");
        goto plante_choix;
       }
       else if (choix_plante==2)
       {
        goto menu;
       }
       else if (choix_plante==1)
       {
        plantage:
        system("clear");
        affichage_plantes();
        printf("Quelle plante voulez-vous planter ?\n");
        scanf("%d",&choix_plante_2);


        /*           DEBUT DES CHOIX DE PLANTES             */

        switch (choix_plante_2)
         {
         case 1:
           system("clear"); 
           abricotier:
           printf("Vous allez planter : L'Abricotier.\nDescription : Arbre d’origine d’Asie d’une hauteur de 5 à 7m, L’arbre fait pousser des fruits appeler abricot. Lors de la floraison l’arbre est recouvert de fleurs blanche.\n");
           printf("Texture du sol : Limon, sol sablonneux.\nTempérature atmosphérique : Méditerranéen, craint le froid.\nLuminosité : Héliophile, a besoin de beaucoup de soleil pour se développer.\nHumidité du sol : Humide à sec.\nPériode de floraison : Février-Mars.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto abricotier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 2:
           system("clear"); 
           cerisier:
           printf("Vous allez planter : Le Cerisier.\nDescription : Arbre d’origine d’Asie d’une hauteur de 8 à 18m, l’arbre qui fait pousser des cerises. Lors de la floraison d’une certaine espèce de cerisier l’arbre est recouvert de fleurs rose mais celle-ci sont blanche.\n");
           printf("Texture du sol : Ordinaire, non argileux, sol légèrement calcaire accepté.\nTempérature atmosphérique : Montagnard avec peu de vent.\nLuminosité : A besoin de soleil régulièrement pour se développer.\nHumidité du sol : Humide.\nPériode de floraison : Mars-Avril.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto cerisier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 3:
           system("clear"); 
           pecher:
           printf("Vous allez planter : Le Pêcher.\nDescription : Arbre d’origine de Chine d’une hauteur de 2 à 5m, l’arbre qui fait pousser des pêches. Lors de la floraison est recouvert de fleurs rose.\n");
           printf("Texture du sol : Ordinaire, non argileux, sol légèrement calcaire accepté.\nTempérature atmosphérique : Montagnard.\nLuminosité : A besoin de soleil régulièrement pour se développer.\nHumidité du sol : Humide.\nPériode de floraison : Printemps.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto pecher;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 4:
           system("clear"); 
           pommier:
           printf("Vous allez planter : Le Pommier.\nDescription : Arbre d’origine d’Asie du Sud-Ouest d’une hauteur de15m, l’arbre qui fait pousser des pommes. Lors de la floraison est recouvert de fleurs blanche rosé.\n");
           printf("Texture du sol : Limon, cad un sol sablonneux.\nTempérature atmosphérique : Montagnard.\nLuminosité : Doit être exposer à mi-ombre.\nHumidité du sol : mésoxérophiles, c'est à dire, peut pousser dans un sol sec comme dans un sol un peu humide.\nPériode de floraison : Printemps.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto pommier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 5:
           system("clear"); 
           poirier:
           printf("Vous allez planter : Le Poirier.\nDescription : Arbre d’origine d’Asie d’une hauteur de15m, l’arbre qui fait pousser des poires. Lors de la floraison est recouvert de fleurs blanche rosé.\n");
           printf("Texture du sol : Limon, cad un sol sablonneux.\nTempérature atmosphérique : Montagnard.\nLuminosité : A besoin de soleil régulièrement pour se développer.\nHumidité du sol : mésoxérophiles, c'est à dire, peut pousser dans un sol sec comme dans un sol un peu humide.\nPériode de floraison : Printemps.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto poirier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 6:
           system("clear"); 
           chataignier:
           printf("Vous allez planter : Le Châtaignier.\nDescription : Arbre d’origine d’Asie d’une hauteur de 20m, l’arbre qui fait pousser des châtaignes. Lors de la floraison est recouvert de fleurs crémé.\n");
           printf("Texture du sol : Sable fin.\nTempérature atmosphérique : Montagnard.\nLuminosité : A besoin de beaucoup de lumière.\nHumidité du sol : Frais.\nPériode de floraison : Mai - Juin.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto chataignier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 7:
           system("clear"); 
           citronnier:
           printf("Vous allez planter : Le Citronnier.\nDescription : Arbre d’origine du Sud et d’Asie d’une hauteur de 6m, l’arbre qui fait pousser des citrons. Lors de la floraison est recouvert de fleurs blanches.\n");
           printf("Texture du sol : Drainé à léger.\nTempérature atmosphérique : Méditerranéen .\nLuminosité : A besoin de beaucoup de lumière à l’abris du vent.\nHumidité du sol : Pas trop sec a frais.\nPériode de floraison : Juillet-Aout.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto citronnier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 8:
           system("clear"); 
           mandarinier:
           printf("Vous allez planter : Le Mandarinier.\nDescription : Arbre d’origine d’Asie d’une hauteur de 6m, l’arbre qui fait pousser des mandarines. Lors de la floraison est recouvert de fleurs blanches.\n");
           printf("Texture du sol : Drainé à léger.\nTempérature atmosphérique : Méditerranéen .\nLuminosité : A besoin de beaucoup de lumière à l’abris du vent.\nHumidité du sol : Pas trop sec a frais.\nPériode de floraison : Mars-Avril.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto mandarinier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 9:
           system("clear"); 
           oranger:
           printf("Vous allez planter : L'Oranger.\nDescription : Arbre d’origine d’Asie d’une hauteur de 6m, l’arbre qui fait pousser des mandarines. Lors de la floraison est recouvert de fleurs blanches.\n");
           printf("Texture du sol : Drainé à léger.\nTempérature atmosphérique : Méditerranéen .\nLuminosité : A besoin de beaucoup de lumière à l’abris du vent.\nHumidité du sol : Pas trop sec a frais.\nPériode de floraison : Juin - Juillet.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto oranger;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 10:
           system("clear"); 
           olivier:
           printf("Vous allez planter : L'Olivier .\nDescription : Arbre d’origine de Syrie d’une hauteur de 20m, l’arbre qui fait pousser des mandarines. Lors de la floraison est recouvert de fleurs blanches.\n");
           printf("Texture du sol : Sec, tolère les sols rocailleux et pauvres.\nTempérature atmosphérique : Méditerranéen craint le froid.\nLuminosité : A besoin de beaucoup de lumière à l’abris du vent.\nHumidité du sol : Faible, les racines craignent l’humidité.\nPériode de floraison : Mai.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto olivier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 11:
           system("clear"); 
           jonquille:
           printf("Vous allez planter : Jonquille.\nDescription : Fleur d’origine d’Europe du Sud et d’Afrique du Nord d’une hauteur de 30cm. La fleur est de couleur jaune.\n");
           printf("Texture du sol : Argileux et caillouteux.\nTempérature atmosphérique : Méditerranéen.\nLuminosité : Ensoleiller à mi-ombre.\nHumidité du sol : Humide.\nPériode de floraison : Avril.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto jonquille;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 12:
           system("clear"); 
           chrysanthème:
           printf("Vous allez planter : Chrysanthème.\nDescription : Fleur d’origine de Chine, Japon, Russie, d’une hauteur de 150cm. La fleur possède de multiple coloris.\n");
           printf("Texture du sol : Riche en humus.\nTempérature atmosphérique : entre 5°C à 15°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Septembre.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto chrysanthème;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 13:
           system("clear"); 
           lys:
           printf("Vous allez planter : Lys.\nDescription : Fleur d’origine du Balkans et méditerranée orientale, d’une hauteur de 90 à 150cm. La fleur possède de multiple coloris.\n");
           printf("Texture du sol : Riche et calcaire.\nTempérature atmosphérique : Méditerranéen.\nLuminosité : Ensoleiller à mi-ombre.\nHumidité du sol : Frais.\nPériode de floraison : Juin.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto lys;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 14:
           system("clear"); 
           orchidéepapillon:
           printf("Vous allez planter : Orchidée papillon.\nDescription : Fleur d’origine d’Asie et d’Océanie, d’une hauteur de 60cm. La fleur possède de multiple coloris.\n");
           printf("Texture du sol : Riche.\nTempérature atmosphérique : entre 18°C à 25°C.\nLuminosité : Vive.\nHumidité du sol : Frais.\nPériode de floraison : Toute l'année.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto orchidéepapillon;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 15:
           system("clear"); 
           rose:
           printf("Vous allez planter : Rose.\nDescription :Fleur d’origine d’Asie, d’une hauteur de 3m. La fleur possède de multiple coloris.\n");
           printf("Texture du sol : Riche et argileux.\nTempérature atmosphérique : entre 18°C à 25°C.\nLuminosité : Ensoleiller et à l’abris du vent.\nHumidité du sol : Frais.\nPériode de floraison : Printemps.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto rose;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 16:
           system("clear"); 
           tulipe:
           printf("Vous allez planter : Tulipe.\nDescription : Fleur d’origine d’Asie centrale, d’une hauteur de 10 à 70cm. La fleur possède de multiple coloris.\n");
           printf("Texture du sol : Léger, sableux, riche.\nTempérature atmosphérique : entre 10°C à 18°C.\nLuminosité : Ensoleiller et à l’abris du vent.\nHumidité du sol : Frais.\nPériode de floraison : Février à Mai.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n"); 
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto tulipe;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 17:
           system("clear"); 
           tournesol:
           printf("Vous allez planter :Description : Tournesol.\nFleur d’origine d’Amérique du Nord, d’une hauteur de 0.80 à 2.5M. La fleur est de couleur jaune, orange ou rouge.\n");
           printf("Texture du sol : Profond, riche.\nTempérature atmosphérique : entre 18°C à 25°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais à sec.\nPériode de floraison : Juillet àSeptembre.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto  tournesol;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 18:
           system("clear"); 
           oeillet:
           printf("Vous allez planter : Œillet.\nDescription : Fleur d’origine d’Asie, d’une hauteur de 20 à 80cm. La fleur est de couleur rouge, rose, blanc ou mauve.\n");
           printf("Texture du sol : Ordinaire.\nTempérature atmosphérique : entre 10°C à 18°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Humidide.\nPériode de floraison : Juin.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto oeillet;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 19:
           system("clear"); 
           gingembre:
           printf("Vous allez planter : Gingembre.\nDescription :Plante d’origine d’Inde, d’une hauteur de 1,80m. La fleur est de couleur jaune ou blanche.\n");
           printf("Texture du sol :  Humus.\nTempérature atmosphérique : entre 10°C à 18°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison :  Eté.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto gingembre;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 20:
           system("clear"); 
           Estragon:
           printf("Vous allez planter : Estragon.\nDescription : Plante d’origine du centre de l’Europe et du Sud de la Russie, d’une hauteur jusqu’à 1.2m.\n");
           printf("Texture du sol : Riche en Humus.\nTempérature atmosphérique : entre 10°C à 18°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Août.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto Estragon;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 21:
           system("clear"); 
           coriandre:
           printf("Vous allez planter : Coriandre.\nDescription : Plante d’origine d’Asie d’occidentale, d’une hauteur de 30 à 60cm.\n");
           printf("Texture du sol : Humus.\nTempérature atmosphérique : entre 10°C à 18°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Juin, Juillet, Août.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto coriandre;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 22:
           system("clear"); 
           basilic:
           printf("Vous allez planter : Basilic.\nDescription : Plante d’origine d’Inde, d’une hauteur de 40cm. La fleur est de couleur blanche.\n");
           printf("Texture du sol : Riche en humus.\nTempérature atmosphérique : entre 10°C à 18°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Juin, Juillet, Août.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto basilic;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 23:
           system("clear"); 
           origan:
           printf("Vous allez planter : Origan.\nDescription : Plante d’origine du bassin méditerranéen, d’une hauteur de 30 à 80cm. La fleur est de couleur rose pâle ou blanc.\n");
           printf("Texture du sol : Léger, ordinaire.\nTempérature atmosphérique : Entre 10°C à 18°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Juillet à Octobre.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto origan;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 24:
           system("clear"); 
           thym:
           printf("Vous allez planter : Thym.\nPlante d’origine du bassin méditerranéen, d’une hauteur de 20 à 40cm. La fleur est de couleur blanc-rosé, rose ou rouge.\n");
           printf("Texture du sol : Léger, ordinaire.\nTempérature atmosphérique : entre 18°C à 25°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais, légerement sec .\nPériode de floraison : Juin, Juillet, Août.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto thym;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 25:
           system("clear"); 
           persil:
           printf("Vous allez planter : Persil.\nPlante d’origine d’Asie occidental, d’une hauteur de 30cm. La fleur est de couleur blanche.\n");
           printf("Texture du sol : Léger, riche et humus.\nTempérature atmosphérique : entre 18°C à 25°C.\nLuminosité : Mi-ombre.\nHumidité du sol : Frais.\nPériode de floraison : Juin, Juillet, Août.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto persil;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 26:
           system("clear"); 
           romarin:
           printf("Vous allez planter : Romarin.\nPlante d’origine du bassin méditerranéen, d’une hauteur jusqu’à 1,5m. La fleur est de couleur bleu.\n");
           printf("Texture du sol : : Ordinaire.\nTempérature atmosphérique : Entre 18°C à 25°C.\nLuminosité : Ensoleiller et à l’abris du vent.\nHumidité du sol : Sec.\nPériode de floraison : Février, Mars et Avril.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto romarin;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 27:
           system("clear"); 
           ciboulette:
           printf("Vous allez planter : Ciboulette.\nPlante d’origine d’Europe Occidentale, d’une hauteur de 20 à 30cm. La fleur est la couleur rose.\n");
           printf("Texture du sol : Ordinaire.\nTempérature atmosphérique : Entre 18°C à 25°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Mai.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto ciboulette;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 28:
           system("clear"); 
           menthe_verte:
           printf("Vous allez planter : Menthe verte.\nPlante d’origine d’Europe, d’une hauteur de 60cm. La fleur possède différente coloris tel que le blanc, rose et violet.\n");
           printf("Texture du sol : Riche en humus.\nTempérature atmosphérique : Entre 18°C à 25°C.\nLuminosité : Ensoleiller,mi-ombre.\nHumidité du sol : Frais.\nPériode de floraison : Juin, Juillet, Août.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto menthe_verte;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 29:
           system("clear"); 
           aneth:
           printf("Vous allez planter : Aneth.\nPlante d’origine du Moyen Orient, d’une hauteur de 60cm à 1.50m. La fleur est de couleur jaune verdâtre.\n");
           printf("Texture du sol : Meuble.\nTempérature atmosphérique : Entre 18°C à 25°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais voir sec.\nPériode de floraison : Juin à Septembre.\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto aneth;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         case 30:
           system("cleari"); 
           pamplemoussier:
           printf("Vous allez planter : Pamplemoussier.\n Arbre d’origine d’Asie de l’est, d’une hauteur de 6 à 9 m. La fleur est de couleur blanche.\n");
           printf("Texture du sol : Riche.\nTempérature atmosphérique : Entre 18°C à 25°C.\nLuminosité : Ensoleiller.\nHumidité du sol : Frais.\nPériode de floraison : Juin, Juillet, Août..\n");
           printf("\n\n1. Suivre les étapes\n2. Retour\n");
           scanf("%d",&valider_plantage);
           if (valider_plantage>2 || valider_plantage<1)
           {
            printf("Nombre incorrect\n");
            goto pamplemoussier;
           }
           else if (valider_plantage==2)
           {
            goto plante_choix;
           }
           else if (valider_plantage==1)
           {
            printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
            goto plante_choix;
           }
         default:
           printf("Nombre choisis incorrect.\n");
           goto plantage;

         } // fin du switch choix_plante_2
       }
       break; // fin case 4



        /*           FIN DES CHOIX DE PLANTES             */






    case 5:
       notifications:
       printf("\e[0;33m=== NOTIFICATIONS ===\e[0m\n\n");
       if (notifs_desactivee==0)
       {
        printf("Paramètre des notifications actuels : toutes les %d heures.\n\n",choix_notifs_heures);        
       }
       else if (notifs_desactivee==1)
       {
        printf("Paramètre des notifications actuels : desactivées.\n\n",choix_notifs_heures);        
       }
       printf("1. Désactiver les notifications.\n");
       printf("2. Notification toutes les X heures.\n");
       printf("3. Retour.\n");
       scanf("%d",&choix_notifs);
       if (choix_notifs<1 || choix_notifs>3)
       {
        printf("Nombre incorrect.\n\n");
        goto notifications;
       }
       else if (choix_notifs==3)
       {
        goto menu;
       }
       else if (choix_notifs==1)
       {
        printf("Les notifications sont maintenant désactivées.\n\n");
        notifs_desactivee=1;
        goto notifications;
       }
       else if (choix_notifs==2)
       {
        notifications_heure:
        printf("Entrez l'heure voulue ( 1h minimun / 48h maximum ):\n");
        scanf("%d",&choix_notifs_heures);
        if (choix_notifs_heures>48 || choix_notifs_heures<1)
        {
          printf("Nombre incorrect.\n\n");
          goto notifications_heure;
        }
       else
        {
          printf("Vous avez défini les notifications sur : toutes les %d heures.\n",choix_notifs_heures);
          notifs_desactivee=0;
          goto notifications;
        }
       }
       break;
    case 6:
       contact:      
       printf("\e[0;33m=== CONTACT ===\e[0m\n\n");
       printf("Un problème ? Une erreur ? Une question ? Remplis ce formulaire pour nous contacter :\n");
       scanf("%s",&probleme);
       printf("Ton message a été envoyé !\n\n");
       goto menu;
       break;
    case 7:
       printf("À bientôt ! \n\n\n\n");
       break;
    default:
       printf("Vous n'avez pas rentre un nombre correct. Retour au menu.");
       break;
  }
  
  printf("\n\n");
  
  return 0;
}




int affichage_plantes()
{
  printf("1. Abricotier\n");
  printf("2. Cerisier\n");
  printf("3. Pêcher\n");
  printf("4. Pommier\n");
  printf("5. Poirier\n");
  printf("6. Châtaignier\n");
  printf("7. Citronnier\n");
  printf("8. Mandarinier\n");
  printf("9. Oranger\n");
  printf("10. Olivier\n");
  printf("11. Jonquille\n");
  printf("12. Chrysanthème\n");
  printf("13. Lys\n");
  printf("14. Orchidée \n");
  printf("15. Rose\n");
  printf("16. Tulipe\n");
  printf("17. Tournesol\n");
  printf("18. Œillet\n");
  printf("19. Gingembre \n");
  printf("20. Estragon \n");
  printf("21. Coriandre \n");
  printf("22. Basilic \n");
  printf("23. Origan \n");
  printf("24. Thym \n");
  printf("25. Persil \n");
  printf("26. Romarin \n");
  printf("27. Ciboulette \n");
  printf("28. Menthe Verte \n");
  printf("29. Aneth \n");
  printf("30. Pamplemoussier \n\n");
}








