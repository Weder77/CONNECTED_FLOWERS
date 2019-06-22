#------------------------------------------------------------
#        Script UF_DEV YNOV 
#------------------------------------------------------------


#------------------------------------------------------------
# Table: CATEGORIE
#------------------------------------------------------------

CREATE TABLE CATEGORIE(
        ID_CATEGORIE          Int  Auto_increment  NOT NULL ,
        NOM_CATEGORIE         Varchar (30) NOT NULL ,
        DESCRIPTION_CATEGORIE Text NOT NULL
        ,CONSTRAINT CATEGORIE_PK PRIMARY KEY (ID_CATEGORIE)
);


#------------------------------------------------------------
# Table: PLANTE
#------------------------------------------------------------

CREATE TABLE PLANTE(
        ID_PLANTE              Int  Auto_increment  NOT NULL ,
        NOM_PLANTE             Varchar (30) NOT NULL ,
        DESCRIPTION_PLANTE     Text NOT NULL ,
        LUMINOSITE_MIN_PLANTE  Int NOT NULL ,
        LUMINOSITE_MAX_PLANTE  Int NOT NULL ,
        HUMIDITE_MIN_PLANTE    Int NOT NULL ,
        HUMIDITE_MAX_PLANTE    Int NOT NULL ,
        TEMPERATURE_MIN_PLANTE Int NOT NULL ,
        TEMPERATURE_MAX_PLANTE Int NOT NULL ,
        TEXTURE_SOL            Varchar (100) NOT NULL ,
        FLORAISON_DEBUT        Date NOT NULL ,
        FLORAISON_FIN          Date NOT NULL ,
        ID_CATEGORIE           Int NOT NULL
        ,CONSTRAINT PLANTE_PK PRIMARY KEY (ID_PLANTE)

        ,CONSTRAINT PLANTE_CATEGORIE_FK FOREIGN KEY (ID_CATEGORIE) REFERENCES CATEGORIE(ID_CATEGORIE)
);


#------------------------------------------------------------
# Table: UTILISATEUR
#------------------------------------------------------------

CREATE TABLE UTILISATEUR(
        ID_UTIL         Int  Auto_increment  NOT NULL ,
        PRENOM          Varchar (20) NOT NULL ,
        NOM             Varchar (20) NOT NULL ,
        EMAIL           Varchar (50) NOT NULL ,
        DATE_NAISSANCE  Date NOT NULL ,
        MOT_DE_PASSE    Varchar (255) NOT NULL ,
        DATE_PLANTATION Date NOT NULL ,
        NIVEAU          Int NOT NULL,
        ID_PLANTE       Int
        ,CONSTRAINT UTILISATEUR_PK PRIMARY KEY (ID_UTIL)

        ,CONSTRAINT UTILISATEUR_PLANTE_FK FOREIGN KEY (ID_PLANTE) REFERENCES PLANTE(ID_PLANTE)
);


#------------------------------------------------------------
# Table: ETAT PLANTE
#------------------------------------------------------------

CREATE TABLE ETAT_PLANTE(
        ID_ETAT_PLANTE Int  Auto_increment  NOT NULL ,
        HUMIDITE       Int NOT NULL ,
        LUMINOSITE     Int NOT NULL ,
        TEMPERATURE    Int NOT NULL,
        HUMIDITE_SOL   Int NOT NULL
        ,CONSTRAINT ETAT_PLANTE_PK PRIMARY KEY (ID_ETAT_PLANTE)
);


#------------------------------------------------------------
# Table: s'occuper
#------------------------------------------------------------

CREATE TABLE s_occuper(
        ID_UTIL        Int Auto_increment NOT NULL ,
        ID_ETAT_PLANTE Int NOT NULL ,
        DATE_ETAT      Date NOT NULL
        ,CONSTRAINT s_occuper_PK PRIMARY KEY (ID_UTIL,ID_ETAT_PLANTE)

        ,CONSTRAINT s_occuper_UTILISATEUR_FK FOREIGN KEY (ID_UTIL) REFERENCES UTILISATEUR(ID_UTIL)
        ,CONSTRAINT s_occuper_ETAT_PLANTE0_FK FOREIGN KEY (ID_ETAT_PLANTE) REFERENCES ETAT_PLANTE(ID_ETAT_PLANTE)
);

#------------------------------------------------------------
# Table: PROBLEME
#------------------------------------------------------------

CREATE TABLE PROBLEME(
        ID_PROBLEME Int Auto_increment NOT NULL,
        EMAIL_CONTACT Varchar (50) NOT NULL,
        PROBLEME Text NOT NULL,
        CONSTRAINT PROBLEME PRIMARY KEY (ID_PROBLEME)
);

#------------------------------------------------------------
# INSERT INFO PLANTES
#------------------------------------------------------------

INSERT INTO CATEGORIE VALUES(NULL, "Arbre Fruitier", "Arbre produisant des fruits");
INSERT INTO CATEGORIE VALUES(NULL, "Fleure", "Fleure");
INSERT INTO CATEGORIE VALUES(NULL, "Epice", "Epices");

INSERT INTO PLANTE VALUES(NULL, "Abricotier", "Arbre d origine d Asie d une hauteur de 5 a 7m, L arbre fait pousser des fruits appeler abricot. Lors de la floraison l arbre est recouvert de fleurs blanche", 0, 800, 10, 70, -10, 40, "Limon, cad un sol sablonneux avec -10% d argile", "2019-02-01", "2019-03-31", 1);

INSERT INTO PLANTE VALUES(NULL, "Cerisier", "Arbre d origine d Asie d une hauteur de 8 a 18m, l arbre qui fait pousser des cerises. Lors de la floraison d une certaine espece de cerisier l arbre est recouvert de fleurs rose mais celle-ci sont blanche", 0, 800, 10, 70, -10, 40, "Ordinaire, non argileux, sol legerement calcaire accepte", "2019-03-31", "2019-04-30", 1);

INSERT INTO PLANTE VALUES(NULL, "Pecher", "Arbre d origine d Asie du Sud-Ouest d une hauteur de 15m, l arbre qui fait pousser des pommes. Lors de la floraison est recouvert de fleurs blanche rose", 0, 800, 10, 70, -10, 40, "Ordinaire, non argileux, sol legerement calcaire accepte", "2019-03-20", "2019-06-21", 1);

INSERT INTO PLANTE VALUES(NULL, "Pommier", "Arbre d origine de Chine d une hauteur de 2 a 5m, l arbre qui fait pousser des peches. Lors de la floraison est recouvert de fleurs rose", 0, 800, 10, 70, -10, 40, "Ordinaire, non argileux, sol legerement calcaire accepte", "2019-03-20", "2019-06-21", 1);

INSERT INTO PLANTE VALUES(NULL, "Poirier", "Arbre d origine d Asie d une hauteur de15m, l arbre qui fait pousser des poires. Lors de la floraison est recouvert de fleurs blanche rose", 0, 800, 10, 70, -10, 40, "Limon, cad un sol sablonneux avec -10% d argile", "2019-03-20", "2019-06-21", 1);

INSERT INTO PLANTE VALUES(NULL, "Châtaignier", "Arbre d origine d Asie d une hauteur de 20m, l arbre qui fait pousser des châtaignes. Lors de la floraison est recouvert de fleurs creme", 0, 800, 10, 70, -10, 40, "Limon, cad un sol sablonneux avec -10% d argile", "2019-03-20", "2019-06-21", 1);

INSERT INTO PLANTE VALUES(NULL, "Citronnier", "Arbre d origine du Sud et d Asie d une hauteur de 6m, l arbre qui fait pousser des citrons. Lors de la floraison est recouvert de fleurs blanches", 0, 800, 10, 70, -10, 40, "Draine a leger", "2019-07-01", "2019-08-31", 1);

INSERT INTO PLANTE VALUES(NULL, "Mandarinier", "Arbre d origine d Asie d une hauteur de 6m, l arbre qui fait pousser des mandarines. Lors de la floraison est recouvert de fleurs blanches", 0, 800, 10, 70, -10, 40, "Draine a leger", "2019-03-01", "2019-04-30", 1);

INSERT INTO PLANTE VALUES(NULL, "Oranger", "Arbre d origine d Asie d une hauteur de 6m, l arbre qui fait pousser des mandarines. Lors de la floraison est recouvert de fleurs blanchess", 0, 800, 10, 70, -10, 40, "Draine a leger", "2019-06-01", "2019-07-31", 1);

INSERT INTO PLANTE VALUES(NULL, "Olivier", "Arbre d origine de Syrie d une hauteur de 20m, l arbre qui fait pousser des mandarines. Lors de la floraison est recouvert de fleurs blanches", 0, 800, 10, 70, -10, 40, "Sec, tolere les sols rocailleux et pauvres", "2019-06-01", "2019-07-31", 1);

INSERT INTO PLANTE VALUES(NULL, "Jonquille", "AFleur d origine d Europe du Sud et d Afrique du Nord d une hauteur de 30cm. La fleur est de couleur jaune", 0, 800, 10, 70, -10, 40, "Argileux et caillouteux", "2019-06-01", "2019-07-31", 2);

INSERT INTO PLANTE VALUES(NULL, "Chrysantheme", "Fleur d origine de Chine, Japon, Russie, d une hauteur de 150cm. La fleur possede de multiple coloris", 0, 800, 10, 70, -5, 10, "Argileux et caillouteux", "2019-09-01", "2019-09-30", 2);

INSERT INTO PLANTE VALUES(NULL, "Lys", "Fleur d origine du Balkans et mediterranee orientale, d une hauteur de 90 a 150cm. La fleur possede de multiple coloris", 0, 800, 10, 70, -10, 40, "Riche et calcaire", "2019-06-1", "2019-06-30", 2);

INSERT INTO PLANTE VALUES(NULL, "Orchidee papillon", "Fleur d origine d Asie et d Oceanie, d une hauteur de 60cm. La fleur possede de multiple coloris", 0, 800, 10, 70, 18, 25, "Riche", "2019-06-01", "2019-06-30", 2);

INSERT INTO PLANTE VALUES(NULL, "Rose", "Fleur d origine d Asie, d une hauteur de 3m. La fleur possede de multiple coloris", 0, 800, 10, 70, 18, 25, "Riche et argileux", "2019-03-20", "2019-06-21", 2);

INSERT INTO PLANTE VALUES(NULL, "Tulipe", "Fleur d origine d Asie centrale, d une hauteur de 10 a 70cm. La fleur possede de multiple coloris", 0, 800, 10, 70, 10, 18, "Leger, sableux, riche", "2019-02-01", "2019-05-31", 2);

INSERT INTO PLANTE VALUES(NULL, "Tournesol", "Fleur d origine d Amerique du Nord, d une hauteur de 0.80 a 2.5M. La fleur est de couleur jaune, orange ou rouge", 0, 800, 10, 70, 18, 25, "Profond, riche", "2019-07-01", "2019-10-31", 2);

INSERT INTO PLANTE VALUES(NULL, "Œillet", "Fleur d origine d Asie, d une hauteur de 20 a 80cm. La fleur est de couleur rouge, rose, blanc ou mauve", 0, 800, 10, 70, 10, 18, "Ordinaire", "2019-06-01", "2019-06-30", 2);

INSERT INTO PLANTE VALUES(NULL, "Gingembre", "Plante d origine d Inde, d une hauteur de 1,80m. La fleur est de couleur jaune ou blanche", 0, 800, 10, 70, 10, 18, "Humus", "2019-06-21", "2019-09-23", 3);

INSERT INTO PLANTE VALUES(NULL, "Estragon", "Plante d origine du centre de l Europe et du Sud de la Russie, d une hauteur jusqu a 1.2m", 0, 800, 10, 70, 10, 18, "Riche en humus", "2019-08-01", "2019-08-31", 3);

INSERT INTO PLANTE VALUES(NULL, "Coriandre", "Plante d origine d Asie d occidentale, d une hauteur de 30 a 60cm", 0, 800, 10, 70, 10, 18, "Humus", "2019-06-01", "2019-08-31", 3);

INSERT INTO PLANTE VALUES(NULL, "Basilic", "Plante d origine du bassin mediterraneen, d une hauteur de 30 a 80cm. La fleur est de couleur rose pâle ou blanc", 0, 800, 10, 70, 10, 18, "Riche et humus", "2019-06-21", "2019-09-23", 3);

INSERT INTO PLANTE VALUES(NULL, "Origan", "Plante d origine d Inde, d une hauteur de 40cm. La fleur est de couleur blanche", 0, 800, 10, 70, 10, 18, "leger, ordinaire", "2019-07-01", "2019-10-31", 3);

INSERT INTO PLANTE VALUES(NULL, "Thym", "Plante d origine du bassin mediterraneen, d une hauteur de 20 a 40cm. La fleur est de couleur blanc-rose, rose ou rouge", 0, 800, 10, 70, 18, 25, "leger, ordinaire", "2019-06-21", "2019-09-23", 3);

INSERT INTO PLANTE VALUES(NULL, "Persil", "Plante d origine d Asie occidental, d une hauteur de 30cm. La fleur est de couleur blanche", 0, 800, 10, 70, 18, 25, "leger, riche et humus", "2019-06-21", "2019-09-23", 3);

INSERT INTO PLANTE VALUES(NULL, "Romarin", "Plante d origine du bassin mediterraneen, d une hauteur jusqu a 1,5m. La fleur est de couleur bleu", 0, 800, 10, 70, 18, 25, "leger, riche et humus", "2019-02-01", "2019-04-30", 3);

INSERT INTO PLANTE VALUES(NULL, "Romarin", "Plante d origine du bassin mediterraneen, d une hauteur jusqu a 1,5m. La fleur est de couleur bleu", 0, 800, 10, 70, 18, 25, "Ordinaire", "2019-02-01", "2019-04-30", 3);

INSERT INTO PLANTE VALUES(NULL, "Ciboulette", "Plante d origine d Europe Occidentale, d une hauteur de 20 a 30cm. La fleur est la couleur rose", 0, 800, 10, 70, 18, 25, "Ordinaire", "2019-05-01", "2019-05-31", 3);

INSERT INTO PLANTE VALUES(NULL, "Menthe verte", "Plante d origine d Europe, d une hauteur de 60cm. La fleur possede differente coloris tel que le blanc, rose et violet", 0, 800, 10, 70, 18, 25, "Riche et humus", "2019-06-21", "2019-09-23", 3);

INSERT INTO PLANTE VALUES(NULL, "Aneth", "Plante d origine du Moyen Orient, d une hauteur de 60cm a 1.50m. La fleur est de couleur jaune verdâtre", 0, 800, 10, 70, 18, 25, "Meuble", "2019-06-01", "2019-09-30", 3);

INSERT INTO PLANTE VALUES(NULL, "Pamplemoussier", ": Arbre d origine d Asie de l est, d une hauteur de 6 a 9 m. La fleur est de couleur blanche", 0, 800, 10, 70, 18, 25, "Riche", "2019-06-21", "2019-09-23", 1);

















