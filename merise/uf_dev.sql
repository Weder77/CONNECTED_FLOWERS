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
)


#------------------------------------------------------------
# Table: PLANTE
#------------------------------------------------------------

CREATE TABLE PLANTE(
        ID_PLANTE              Int  Auto_increment  NOT NULL ,
        NOM_PLANTE             Varchar (30) NOT NULL ,
        DESCRIPTION_PLANTE     Text NOT NULL ,
        LUMINOSITE_MAX_PLANTE  Int NOT NULL ,
        LUMINOSITE_MIN_PLANTE  Int NOT NULL ,
        HUMIDITE_MAX_PLANTE    Int NOT NULL ,
        HUMIDITE_MIN_PLANTE    Int NOT NULL ,
        TEMPERATURE_MAX_PLANTE Int NOT NULL ,
        TEMPERATURE_MIN_PLANTE Int NOT NULL ,
        TEXTURE_SOL            Varchar (30) NOT NULL ,
        FLORAISON_DEBUT        Date NOT NULL ,
        FLORAISON_FIN          Date NOT NULL ,
        ID_CATEGORIE           Int NOT NULL
	,CONSTRAINT PLANTE_PK PRIMARY KEY (ID_PLANTE)

	,CONSTRAINT PLANTE_CATEGORIE_FK FOREIGN KEY (ID_CATEGORIE) REFERENCES CATEGORIE(ID_CATEGORIE)
)


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
        ID_PLANTE       Int
	,CONSTRAINT UTILISATEUR_PK PRIMARY KEY (ID_UTIL)

	,CONSTRAINT UTILISATEUR_PLANTE_FK FOREIGN KEY (ID_PLANTE) REFERENCES PLANTE(ID_PLANTE)
)


#------------------------------------------------------------
# Table: ETAT PLANTE
#------------------------------------------------------------

CREATE TABLE ETAT_PLANTE(
        ID_ETAT_PLANTE Int  Auto_increment  NOT NULL ,
        HUMIDITE       Int NOT NULL ,
        LUMINOSITE     Int NOT NULL ,
        TEMPERATURE    Int NOT NULL
	,CONSTRAINT ETAT_PLANTE_PK PRIMARY KEY (ID_ETAT_PLANTE)
)


#------------------------------------------------------------
# Table: s'occuper
#------------------------------------------------------------

CREATE TABLE s_occuper(
        ID_UTIL        Int NOT NULL ,
        ID_ETAT_PLANTE Int NOT NULL ,
        DATE_ETAT      Date NOT NULL
	,CONSTRAINT s_occuper_PK PRIMARY KEY (ID_UTIL,ID_ETAT_PLANTE)

	,CONSTRAINT s_occuper_UTILISATEUR_FK FOREIGN KEY (ID_UTIL) REFERENCES UTILISATEUR(ID_UTIL)
	,CONSTRAINT s_occuper_ETAT_PLANTE0_FK FOREIGN KEY (ID_ETAT_PLANTE) REFERENCES ETAT_PLANTE(ID_ETAT_PLANTE)
)

