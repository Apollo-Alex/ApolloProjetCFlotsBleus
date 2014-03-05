typedef struct
	{
    char rue[50];            /* rue et numero */
    char cp[10];             /* code postal */
    char loc[30];            /* localite */
    char pays[20];           /* pays */
	} adresse;

typedef struct
	{
	unsigned int aa;         /* annee */
	unsigned int mm;         /* mois */
	unsigned int jj;         /* jour */
	} date;

typedef struct
	{
	unsigned int hh;         /* heure */
	unsigned int mm;         /* minute */
	} heure;

/* structures des tables elementaires */

typedef struct
	{
	char ca_lib[25];         /* libelle de la categorie */
	float ca_ch_pu[10];      /* prix unitaires des differentes charges
                                pour cette categorie */
	char ca_etat;            /* flag existant ' '-->ok  '*'--> supprime */
	} categorie;

typedef struct
	{
	char ch_lib[40];         /* libelle de la charge */
	char ch_freq;            /* frequence de facturation
	                            1 --> par jour de presence
	                            7 --> par semaine de presence
	                            M --> par mois de presence
	                            S --> 1 seule x par sejour */
	char ch_etat;            /* flag existant ' '-->ok  '*'--> supprime */
	} charge;

typedef struct
	{
	char cl_nom[30];         /* nom du client */
	char cl_prenom[30];      /* prenom du client */
	adresse cl_adresse;      /* adresse du client */
	char cl_tel[20];         /* no de telephone principal */
	char cl_tel2[20];        /* no de telephone portable */
	char cl_email[50];       /* adresse Email */
	unsigned long int cl_sj; /* no du dernier sejour du client 0==neant */
	unsigned long int cl_svt;/* no de l'enregistrement du client suivant
                                par ordre alphabetique */
	unsigned long int cl_pr; /* no de l'enregistrement du client précédent
                                par ordre alphabetique */
	} client;

typedef struct
	{
	char em_nom[30];         /* nom de cet emplacement */
	unsigned int em_ca_no;   /* no de categorie de cet emplacement */
	unsigned long int em_cl_no;
                             /* no du client occupant l'emplacement 0=libre */
	char em_etat;            /* flag existant ' '-->ok
                                              '*'-->(temporairement)supprime*/
	} emplacement;

typedef struct
	{
	unsigned int pa_nb_e;    /* no du dernier emplacement */
	unsigned int pa_nb_c;    /* no de la derniere categorie d'emplacements*/
	unsigned int pa_nb_ch;   /* no de la dernière charge */
	unsigned int pa_nb_s;    /* no du dernier service */
	unsigned long int pa_no_cli;
                             /* no du dernier client */
	unsigned long int pa_no_fact;
	                         /* no de la derniere facture */
	unsigned long int pa_no_sj;
                             /* no du dernier sejour */
	unsigned long int pa_no_su;
	                         /* no du dernier supplement */
	unsigned long int pa_pa_d;
	                         /* no enreg. premier client/ordre alphabetique */
	unsigned long int pa_pa_f;
	                         /* no enreg. dernier client/ordre alphabetique */
	date pa_date_jr;         /* date de travail */
	char pa_pasu[10];        /* mot de passe utilisateur */
	char pa_pass[10];        /* mot de passe superviseur */
	char pa_nom[30];         /* nom du camping */
	adresse pa_adresse;      /* adresse du camping */
	char pa_tel[20];         /* no de telephone 1    du camping */
	char pa_tel2[20];        /* no de telephone 2    du camping */
	char pa_email[50];       /* adresse Email        du camping */
	char pa_www[50];         /* adresse site web     du camping */
	char pa_rem[80];         /* texte libre imprime en bas des documents */
	} parametre;


typedef struct
	{
	char sr_lib[50];         /* libelle du service propose */
	char sr_unit[25];        /* unite de location du service propose */
	float sr_pu;             /* prix par unite de location */
	unsigned int sr_pv;      /* prix variable (0=non 1=oui) */
	char sr_etat;            /* flag existant ' '-->ok  '*'--> supprime */
	} service;

typedef struct
	{
	unsigned long int sj_cl_no;
                             /* no du client */
	unsigned int sj_em_no;   /* no de l'emplacement */
	date sj_d_in;            /* date de debut du sejour */
	date sj_d_out;           /* date de fin du sejour */
	unsigned int sj_nb_ch[10];
	                         /* nombre d'unites utilisees pour chacune
                                des charges */
	float sj_pu_ch[10];      /* prix unitaire applicable pour chacune
                                des charges */
	unsigned long int sj_su_deb;
	                         /* no enregistrement du 1er service consomme
	                            0=neant */
	unsigned long int sj_su_fin;
	                         /* no enregistrement du dernier service consomme
                                0=neant */
	float sj_acompte;        /* acompte verse pour le sejour */
	float sj_caution;        /* caution versee pour les locations */
	unsigned long int sj_fact;
	                         /* no de la facture du sejour (0=encours) */
	} sejour;

typedef struct
	{
	date su_dloc;            /* date de la location */
	heure su_hloc;           /* heure de la location */
	unsigned long int su_sj_no;
	                         /* no du sejour ayant loue */
	unsigned int su_sr_no;   /* no du service loue */
	int su_qte;              /* quantite */
	float su_pu;             /* tarif applicable au moment de la location */
	long int su_no_fact;     /* no de facture (0 si pas encore facture) */
	char su_flag;            /* flag existant ' '-->ok  '*'--> supprime */
	} supplement;
