/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*       <algo_plante.c>                          __     __                   */
/*                                                \ \   / /                   */
/*   By: Dany JEAN-CHARLES (Weder77)               \ \_/ /                    */
/*                                                  \   /                     */
/*   Created: 22/02/19 by Weder77                    | |                      */
/*   Updated: 26/02/19 by Weder77                    |_|Nov Informatique      */
/*   Updated: 10/06/19 by MENT3                                               */
/*                                                                            */
/* ************************************************************************** */     


/*
SOMMAIRE DU PROGRAMME ('contrôle + F' ou 'commande + F' pour rechercher un élément directement) :
  - 1.0.VARIABLES
  - 1.1.1.ACCUEIL
  - 1.1.CONNEXION
  - 1.2.INSCRIPTION
  - 2.0.MENU 
  - 2.1.COMPTE
  - 2.2.MODIFIER COMPTE
  - 3.0.MA PLANTE
  - 3.1.HISTORIQUE PLANTE 
  - 3.2.INFOS PLANTE
  - 4.0.NOTIFICATIONS
  - 5.0.CONTACT
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mysql.h>

// On recupere les donnees de la plante depuis la bdd
int humidite_max;
int humidite_min;

int luminosite_max;
int luminosite_min;

int temperature_atmospheriqeu_max;
int temperature_atmospherique_min;

// On recupere les donnees actuelle de la plante
int humidite_plante;

int luminosite_plantee;

int temperature_atmospherique_plante;
// On insere ces donnees dans la bdd pour que l'historique puisse être accessible pour l'utilisateur

// On compare les donnees de la bdd avec les donnees actuelle


int main()
{
  /* 1.0.VARIABLES */
  // MYSQL set
  MYSQL conn;

  char *server = "192.168.0.110";
  char *user = "clement";
  char *password = "toor!12"; /* set me first */
  char *database = "ConnectF";

  mysql_init(&conn);


  // Variable set
  char nom[100]; // nom utilisateur
  char prenom[100]; // prenom utilisateur

  /* Variables de configuration pour la date de naissance*/
  int jour;
  int mois;
  int annee;
  int date[10]; // Date qui va être insert dans la db
  char date_naissance[10];

  char email[100]; // mail utilisateur
  char mdp[100]; // mdp utilisateur
  char mdp_verif[100]; // verif du mdp quand on cree un compte
  char mdp_test[100]; // verif du mdp quand on se connecte
  char mdp_change[100]; // verif poru changer le mdp
  char buf[1024] = {}; //buffer -> requetes
  char plante[3]; //ID plante depuis la base
  char probleme[500]; // en cas de pb, message de l'utilisateur qui est envoye
  char id_util[3]; //user id
  int id_plante; //ID_PLANTE
  int choix_menu; // choix du menu principal
  int choix_menu_connexion; // choix du menu de connexion
  int niveau_expertise_plante; // 1 = debutant 2 = intermediaire 3 = expert
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
  int ajouter_plante;
  int connected = 0;
  system("clear");

  accueil:
  /* 1.1.1.ACCUEIL */
  printf("\e[0;33m=== CONNEXION ===\e[0m\n\n");
  printf("1. Se connecter\n");
  printf("2. S'inscrire\n");
  printf("\nVotre choix ? ");
  scanf("%d", &choix_menu_connexion);

    switch (choix_menu_connexion) // switch qui gere le menu de connexion
    {
      case 1:
      connexion:
      /* 1.1.CONNEXION */
      printf("\e[0;33m=== CONNEXION ===\e[0m\n\n");

      printf("Entrez votre email :\n"); 
      scanf("%s",&email);
      mdp_check:
      printf("Entrez votre mot de passe :\n"); 
      system("stty -echo");
      scanf("%s",&mdp_test);
      system("stty echo");

      if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0))
      {
            /* Init */

        MYSQL_RES *res = NULL;
        MYSQL_ROW row;

            if (mysql_query(&conn, "SELECT * FROM UTILISATEUR")) //Check si la requete est possible
            {
              fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
              exit(1);
            }
            res = mysql_use_result(&conn);

            /* Test connexion */
            while ((row = mysql_fetch_row(res)) != NULL){
              if ((strcmp(row[3],email)==0) && (strcmp(row[5],mdp_test)==0)){
                strcpy(nom, row[2]);
                strcpy(prenom, row[1]); 
                strcpy(email, row[3]); 
                strcpy(id_util, row[0]);
                strcpy(date, row[4]);
                if (row[8] > 0)
                {
                  strcpy(plante, row[8]);
                } else {
                  strcpy(plante, "0");
                }
                connected=1;

                printf("\n\033[32;1m=== Connexion réussie ===\033[0m\n\n\n");

                /* Fermeture */
                mysql_free_result(res);
                mysql_close(&conn);
                system("sleep 1");
                goto menu;
              }
            }
            if (connected == 0)
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
                mysql_free_result(res);
                mysql_close(&conn);
                goto connexion;
              }
              else if (fail_mdp==2)
              {
                return 0;
              }
            }
          }
          else
          {
            printf("Une erreur s'est produite lors de la connexion a la BDD!");
            return 0;
          }
          break;
          case 2:
          inscription:
          /* 1.2.INSCRIPTION */
          printf("\e[0;33m=== INSCRIPTION ===\e[0m\n\n");
          printf("Entrez votre prenom :\n"); 
          scanf("%s",&prenom);

          printf("Entrez votre nom :\n"); 
          scanf("%s",&nom);

          printf("Entrez votre date de naissance : (Format : AAAA-MM-JJ sans les tirets)\n");
          scanf("%s", &date);
 
          printf("Entrez votre email :\n"); 
          scanf("%s",&email);

          printf("Entrez votre mot de passe :\n");
          system("stty -echo");
          scanf("%s",&mdp);
          system("stty echo");

          printf("Confirmez votre mot de passe :\n");
          system("stty -echo");
          scanf("%s",&mdp_verif);
          system("stty echo");

          // printf("Entrez votre âge :\n"); 
          // scanf("%d",&age);
          niveau_expertise_plante:
          printf("Votre niveau d'epxertise avec les plantes ?\n1/ Debutant\n2/ Intermediaire\n3/ Expert\n\n"); 
          scanf("%d",&niveau_expertise_plante);

          if (niveau_expertise_plante>3 || niveau_expertise_plante<1)
          {
            printf("Le nombre choisi est incorrect\n");
            goto niveau_expertise_plante;
          }
          if (strcmp (mdp,mdp_verif) != 0)
          {
           printf("\n\n\e[0;31mLes 2 mots de passe ne correspondent pas.\e[0m \n\n\n");
           goto inscription;
          }


         

         if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0))
         {
              /* Init */

          MYSQL_RES *res = NULL;
          MYSQL_ROW row;


          char buf[1024] = {}; 
              sprintf(buf, "INSERT INTO UTILISATEUR VALUES(NULL, '%s', '%s', '%s', '%s', '%s', '2019-01-01', %d, NULL)", prenom, nom, email, date, mdp, niveau_expertise_plante); //Concatène avec les variables et return dans le buffer


              if (mysql_query(&conn,buf)) //Check si la requete est possible
              {
                fprintf(stderr, "£££ - %s\n", mysql_error(&conn));
                exit(1);
              }

              printf("\e[0;32m=== Votre compte a ete cree avec succes, merci de vous connecter pour acceder à l'application ===\e[0m\n\n");

              /* Fermeture */
              mysql_free_result(res);
              mysql_close(&conn);

              goto connexion;
            }
            else
            {
              printf("Une erreur s'est produite lors de la connexion a la BDD!");
            }

            break;
            default:
            printf("Vous n'avez pas rentre un nombre correct. Retour au menu de connexion.");
            goto accueil;
            break;
          }



          menu:
          /* 2.0.MENU */
          system("clear");
          printf("\e[0;33m=== MENU ===\e[0m\n\n");
          printf("1. Gerer mon compte\n");
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
      /* 2.1.COMPTE */
      printf("\e[0;33m=== MON COMPTE ===\e[0m\n\n");
      printf("Bonjour %s !\n",prenom);
      printf("Voici tes informations :\nNom : %s\nprenom : %s\nDate de naissance : %s\nEmail : %s\n\n", nom, prenom, date, email);
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
        /* 2.2.MODIFIER COMPTE */
        if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){

                  /* Init */
          MYSQL_RES *res = NULL;
          MYSQL_ROW row;

          char buf[1024] = {}; 
                  sprintf(buf, "SELECT * FROM UTILISATEUR WHERE ID_UTIL=%s", id_util); //Concatène avec les variables et return dans le buffer

                  if (mysql_query(&conn,buf)) //Check si la requete est possible
                  {
                    fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                    exit(1);
                  }
                  res = mysql_use_result(&conn);
                  row = mysql_fetch_row(res);

                  printf("\e[0;33m=== MODIFIER MON COMPTE ===\e[0m\n\n");
                  printf("Quelles informations souhaites-tu modifier ?\n");
                  printf("Voici tes informations :\n1. Nom : %s.\n2. prenom : %s.\n3. Date de naissance : %.s\n4. Email : %s.\n\n", row[2], row[1], date, row[3]);
                  printf("5. Retour\n");    
                  printf("\nVotre choix ? ");
                  scanf("%d", &choix_menu_compte_2);
                  switch (choix_menu_compte_2)
                  {
                    case 1:
                    printf("Ton nom actuel est : %s, par quoi veux-tu le remplacer ?\n", row[2]);
                    scanf("%s",&nom);
                    mysql_free_result(res);
                    mysql_close(&conn);
                    if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){

                        /* Init */
                      MYSQL_RES *res = NULL;
                      MYSQL_ROW row;

                      char buf[1024] = {}; 
                        sprintf(buf, "UPDATE UTILISATEUR SET NOM='%s' WHERE ID_UTIL=%s", nom, id_util); //Concatène avec les variables et return dans le buffer
                        if (mysql_query(&conn,buf)) //Check si la requete est possible
                        {
                          fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                          exit(1);
                        }
                      }
                      else {
                        printf("Une erreur s'est produite lors de la connexion a la BDD!");
                        return 0;
                      }
                      mysql_free_result(res);
                      mysql_close(&conn);
                      goto modifier_compte;
                      break;
                      case 2:
                      printf("Ton prenom actuel est : %s, par quoi veux-tu le remplacer ?\n", row[1]);
                      scanf("%s",&prenom);
                      mysql_free_result(res);
                      mysql_close(&conn);
                      if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){

                        /* Init */
                        MYSQL_RES *res = NULL;
                        MYSQL_ROW row;

                        char buf[1024] = {}; 
                        sprintf(buf, "UPDATE UTILISATEUR SET prenom='%s' WHERE ID_UTIL=%s", prenom, id_util); //Concatène avec les variables et return dans le buffer
                        if (mysql_query(&conn,buf)) //Check si la requete est possible
                        {
                          fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                          exit(1);
                        }
                        mysql_free_result(res);
                        mysql_close(&conn);
                      }
                      else {
                        printf("Une erreur s'est produite lors de la connexion a la BDD!");
                        return 0;
                      }
                      goto modifier_compte;
                      break;
                      case 3:
                      printf("Ta date de naissance est : %d, par quoi veux-tu le remplacer ? (Format : AAAA-MM-JJ sans les tirets)\n", date);
                      scanf("%s",&date);
                      goto modifier_compte;
                      break;
                      case 4:
                      printf("Ton email actuel est : %s, par quoi veux-tu le remplacer ?\n", row[3]);
                      scanf("%s",&email);
                      mysql_free_result(res);
                      mysql_close(&conn);
                      if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){

                        /* Init */
                        MYSQL_RES *res = NULL;
                        MYSQL_ROW row;

                        char buf[1024] = {}; 
                        sprintf(buf, "UPDATE UTILISATEUR SET EMAIL='%s' WHERE ID_UTIL=%s", email, id_util); //Concatène avec les variables et return dans le buffer
                        if (mysql_query(&conn,buf)) //Check si la requete est possible
                        {
                          fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                          exit(1);
                        }
                      }
                      else {
                        printf("Une erreur s'est produite lors de la connexion a la BDD!");
                        return 0;
                      }
                      mysql_free_result(res);
                      mysql_close(&conn);
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

                  /* Fermeture */
                    mysql_free_result(res);
                    mysql_close(&conn);
                  } 
                  else {
                    printf("Une erreur s'est produite lors de la connexion a la BDD!");
                    return 0;
                  }
                  case 2:
                  change_pass:
                  if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){
                        /* Init */
                    MYSQL_RES *res = NULL;
                    MYSQL_ROW row;

                    char buf[1024] = {}; 
                sprintf(buf, "SELECT MOT_DE_PASSE FROM UTILISATEUR WHERE ID_UTIL=%s", id_util); //Concatène avec les variables et return dans le buffer
                if (mysql_query(&conn,buf)) //Check si la requete est possible
                {
                  fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                  exit(1);
                }
                res = mysql_use_result(&conn);
                row = mysql_fetch_row(res);

                printf("Pour modifier ton mot de passe vous devez d'abord confimer ton ancien mot de passe.\n");
                system("stty -echo");
                scanf("%s",&mdp_change);
                system("stty echo");
                if (strcmp (row[0],mdp_change) == 0)
                {
                  mdp_change:
                  printf("Entrez votre nouveau mot de passe :\n");
                  system("stty -echo");
                  scanf("%s",&mdp);
                  system("stty echo");
                  printf("Confirmez votre nouveau mot de passe :\n");
                  system("stty -echo");
                  scanf("%s",&mdp_verif);
                  system("stty echo");
                  if (strcmp (mdp,mdp_verif) != 0)
                  {
                    printf("\n\n\e[0;31mLes 2 mots de passe ne correspondent pas.\e[0m \n\n\n");
                    goto mdp_change;
                  }
                  else {
                        /* Fermeture */
                    mysql_free_result(res);
                    mysql_close(&conn);
                    if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){
                        /* Init */
                      MYSQL_RES *res = NULL;
                      MYSQL_ROW row;

                      char buf[1024] = {}; 
                        sprintf(buf, "UPDATE UTILISATEUR SET MOT_DE_PASSE='%s' WHERE ID_UTIL=%s", mdp, id_util); //Concatène avec les variables et return dans le buffer
                        if (mysql_query(&conn,buf)) //Check si la requete est possible
                        {
                          fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                          exit(1);
                        }
                        mysql_free_result(res);
                        mysql_close(&conn);
                        goto modifier_compte;
                      }
                      else {
                        printf("Une erreur s'est produite lors de la connexion a la BDD!");
                        return 0;
                      }
                    }
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
                      mysql_free_result(res);
                      mysql_close(&conn);
                      goto compte;
                    }
                  } 
                  mysql_free_result(res);
                  mysql_close(&conn);          
                  goto compte;
                }
                else {
                  printf("Une erreur s'est produite lors de la connexion a la BDD!");
                  return 0;
                }
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
              /* 3.0.MA PLANTE */
              if (strcmp(plante, "0") == 0){
                printf("Vous n'avez selectionné aucune plante.\n");
                printf("1. Selectionner une plante\n");
                printf("2. Retour\n");
                scanf("%d",&ajouter_plante);
                if (ajouter_plante>2 && ajouter_plante<1){
                  goto ma_plante;
                } 
                else if (ajouter_plante==1){
                  goto plante_choix;
                } 
                else if (ajouter_plante==2){
                  goto menu;
                }
              } 
              else {
                if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){

                /* Init */
                  MYSQL_RES *res = NULL;
                  MYSQL_ROW row;

                  char buf[1024] = {}; 
                  sprintf(buf, "SELECT * FROM PLANTE WHERE ID_PLANTE=%s", plante); //Concatène avec les variables et return dans le buffer

                  if (mysql_query(&conn,buf)) //Check si la requete est possible
                  {
                    fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                    exit(1);
                  }
                  res = mysql_use_result(&conn);
                  row = mysql_fetch_row(res);

                  printf("Vous avez une plante connectee : %s\n", row[1]);

                  mysql_free_result(res);

                  if (mysql_query(&conn,"SELECT * FROM ETAT_PLANTE WHERE ID_ETAT_PLANTE=(SELECT MAX(ID_ETAT_PLANTE) FROM ETAT_PLANTE)")) //Check si la requete est possible
                  {
                    fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                    exit(1);
                  }
                  res = mysql_use_result(&conn);
                  row = mysql_fetch_row(res);

                  printf("Caracteristiques actuelles :\nHumidité : %s%\nLuminosité: %s lumen\nTempérature: %s°C\nHumidité du sol: %s\n\n", row[1], row[2], row[3], row[4]);
                  printf("1. Changer de plante\n");
                  printf("2. Retour\n");
                  scanf("%d",&choix_menu);
                  if (choix_menu<1 && choix_menu>2){
                    goto ma_plante;
                  }
                  else if (choix_menu==1){
                    /* Fermeture */
                    mysql_free_result(res);
                    mysql_close(&conn);
                    goto plante_choix;
                  }
                  else if (choix_menu==2){
                    /* Fermeture */
                    mysql_free_result(res);
                    mysql_close(&conn);
                    goto menu;
                  }

                } 
                else {
                  printf("Une erreur s'est produite lors de la connexion a la BDD!");
                }
              }


            break;
            case 3:
            printf("\033[1;33mBientôt disponible\033[0m\n");
            system("sleep 3");
            goto menu;
            break;
            case 4:
            plante_choix: 
            /* 3.1.HISTORIQUE PLANTE */
            printf("Voici toutes les plantes que vous pouvez planter :\n");
            affichage_plantes();
            printf("Souhaitez-vous planter une nouvelle plante ?\n1. Oui\n2. Non (retour)\n");
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
                strcpy(plante,"1");
                id_plante=1;
                goto info_plante;
                case 2:
                strcpy(plante,"2");
                id_plante=2;
                goto info_plante;
                case 3:
                strcpy(plante,"3");
                id_plante=3;
                goto info_plante;
                case 4:
                strcpy(plante,"4");
                id_plante=4;
                goto info_plante;
                case 5:
                strcpy(plante,"5");
                id_plante=5;
                goto info_plante;
                case 6:
                strcpy(plante,"6");
                id_plante=6;
                goto info_plante;
                case 7:
                strcpy(plante,"7");
                id_plante=7;
                goto info_plante;
                case 8:
                strcpy(plante,"8");
                id_plante=8;
                goto info_plante;
                case 9:
                strcpy(plante,"9");
                id_plante=9;
                goto info_plante;
                case 10:
                strcpy(plante,"10");
                id_plante=10;
                goto info_plante;
                case 11:
                strcpy(plante,"11");
                id_plante=11;
                goto info_plante;
                case 12:
                strcpy(plante,"12");
                id_plante=12;
                goto info_plante;
                case 13:
                strcpy(plante,"13");
                id_plante=13;
                goto info_plante;
                case 14:
                strcpy(plante,"14");
                id_plante=14;
                goto info_plante;
                case 15:
                strcpy(plante,"15");
                id_plante=15;
                goto info_plante;
                case 16:
                strcpy(plante,"16");
                id_plante=16;
                goto info_plante;
                case 17:
                strcpy(plante,"17");
                id_plante=17;
                goto info_plante;
                case 18:
                strcpy(plante,"18");
                id_plante=18;
                goto info_plante;
                case 19:
                strcpy(plante,"19");
                id_plante=19;
                goto info_plante;
                case 20:
                strcpy(plante,"20");
                id_plante=20;
                goto info_plante;
                case 21:
                strcpy(plante,"21");
                id_plante=21;
                goto info_plante;
                case 22:
                strcpy(plante,"22");
                id_plante=22;
                goto info_plante;
                case 23:
                strcpy(plante,"23");
                id_plante=23;
                goto info_plante;
                case 24:
                strcpy(plante,"25");
                id_plante=24;
                goto info_plante;
                case 25:
                strcpy(plante,"26");
                id_plante=25;
                goto info_plante;
                case 26:
                strcpy(plante,"27");
                id_plante=26;
                goto info_plante;
                case 27:
                strcpy(plante,"28");
                id_plante=27;
                goto info_plante;
                case 28:
                strcpy(plante,"29");
                id_plante=28;
                goto info_plante;
                case 29:
                strcpy(plante,"29");
                id_plante=29;
                goto info_plante;
                case 30:
                strcpy(plante,"30");
                id_plante=30;
                goto info_plante;
                default:
                printf("Nombre choisis incorrect.\n");
                goto plantage;
              } // fin du switch choix_plante_2
              info_plante:
              /* 3.2.INFOS PLANTE */
              if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0)){

                    /* Init */
                MYSQL_RES *res = NULL;
                MYSQL_ROW row;

                char buf[1024] = {}; 
                    sprintf(buf, "SELECT * FROM PLANTE WHERE ID_PLANTE=%s", plante); //Concatène avec les variables et return dans le buffer

                    if (mysql_query(&conn,buf)) //Check si la requete est possible
                    {
                      fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                      exit(1);
                    }
                    res = mysql_use_result(&conn);
                    row = mysql_fetch_row(res);

                    printf("Nom de la plante : %s\n", row[1]);
                    printf("Description : %s\n", row[2]);
                    printf("Texture de sol recommandé : %s\n", row[9]);
                    printf("Température atmospherique : Entre %s et %s\n", row[8], row[7]);
                    printf("Luminosité : Entre %s et %s\n", row[4], row[3]);
                    printf("Humididé :  Entre %s et %s\n", row[6], row[4]);
                    printf("Période de floraison : %s - %s\n", row[10], row[11]);
                    printf("\n");

                    printf("\n\n1. Suivre les etapes\n2. Retour\n");
                    scanf("%d",&valider_plantage);
                    if (valider_plantage>2 || valider_plantage<1)
                    {
                      printf("Nombre incorrect\n");
                        /* Fermeture */
                      mysql_free_result(res);
                      mysql_close(&conn);
                      goto plantage;
                    }
                    else if (valider_plantage==2)
                    {
                          /* Fermeture */
                      mysql_free_result(res);
                      mysql_close(&conn);
                      goto plante_choix;
                    }
                    else if (valider_plantage==1)
                    {
                      printf("Bonne chance ! Toutes les informations de la plante sont ici :).\n\n\n");
                      /* Fermeture */
                      mysql_free_result(res);
                      mysql_close(&conn);
                      goto update;
                    }
                  } 
                  else {
                    printf("Une erreur s'est produite lors de la connexion a la BDD!");
                  }
                }
                update:
                if(mysql_real_connect(&conn, server, user, password, database,0,NULL,0))
                {
                /* Init */

                  MYSQL_RES *res = NULL;
                  MYSQL_ROW row;

                  char buf[1024] = {}; 
                sprintf(buf, "UPDATE UTILISATEUR SET ID_PLANTE=%d WHERE ID_UTIL=%s", id_plante, id_util); //Concatène avec les variables et return dans le buffer

                if (mysql_query(&conn,buf)) //Check si la requete est possible
                {
                  fprintf(stderr, "*£$£* - %s\n", mysql_error(&conn));
                  exit(1);
                }

                /* Fermeture */
                mysql_free_result(res);
                mysql_close(&conn);

              }
              else
              {
                printf("Une erreur s'est produite lors de la connexion a la BDD!");
              }
              goto menu;
        break; // fin case 4

    /*           FIN DES CHOIX DE PLANTES             */
        case 5:
        notifications:
        /* 4.0.NOTIFICATIONS */
        printf("\e[0;33m=== NOTIFICATIONS ===\e[0m\n\n");
        if (notifs_desactivee==0)
        {
          printf("Parametre des notifications actuels : toutes les %d heures.\n\n",choix_notifs_heures);        
        }
        else if (notifs_desactivee==1)
        {
          printf("Parametre des notifications actuels : desactivees.\n\n",choix_notifs_heures);        
        }
        printf("1. Desactiver les notifications.\n");
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
          printf("Les notifications sont maintenant desactivees.\n\n");
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
            printf("Vous avez defini les notifications sur : toutes les %d heures.\n",choix_notifs_heures);
            notifs_desactivee=0;
            goto notifications;
          }
        }
        break;
        case 6:
        contact:   
        /* 5.0.CONTACT */   
        printf("\e[0;33m=== CONTACT ===\e[0m\n\n");
        printf("Un probleme ? Une erreur ? Une question ? Remplis ce formulaire pour nous contacter :\n");
        scanf("%s",&probleme);
        printf("Ton message a ete envoye !\n\n");
        goto menu;
        break;
        case 7:
        printf("À bientôt ! \n\n\n\n");
        connected=0;
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
      system("clear");
      printf("\e[0;33m=== Liste des plantes ===\e[0m\n\n");
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
      printf("12. Chrysantheme\n");
      printf("13. Lys\n");
      printf("14. Orchidee \n");
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
      printf("30. Pamplemoussier \n\n\n\n");
    }


