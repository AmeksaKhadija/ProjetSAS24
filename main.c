#include <stdio.h>
#include <stdlib.h>

int main()
{
    menu1();
    return 0;
}
//enum pour les departement
typedef enum
{
    SCIENCE,
    ARTS,
    ENGINEERING,
    LAW,
    MEDICINE
} DepartementType;

//struct pour la date de naissance
struct dateNaissance
{
    int jour;
    int mois;
    int annee;
};

//struct d'etudiant
struct etudiant
{
    int id;
    char nom[100];
    char prenom[100];
    struct dateNaissance dateNaissance;
    DepartementType departement;
    int noteGenerale;
};

struct etudiant etudiant1[200];
int compteur = 0;
int nouvel_id;
int id_existe = 0;
int IDmodifier;
int IDdel;
int IDinfo;
char nomRechercher[100];
char departementRechercher[100];
struct etudiant temporaire;

//function pour afficher les departement existe
void getDepartementName(DepartementType departement)
{
    switch(departement)
    {
    case SCIENCE:
        printf("Science");
        break;
    case ARTS:
        printf("Arts");
        break;
    case ENGINEERING:
        printf("Engineering");
        break;
    case LAW:
        printf("Law");
        break;
    case MEDICINE:
        printf("Medicine");
        break;
    default:
        printf("Unknown");
        break;
    }
}

// function pour ajouter un etudiant
void Ajouter_etudiant()
{
    printf("===============================AJOUTER UN ETUDIANT===============================\n");
    do
    {
        printf("\nEntrer un identifiant unique :");
        scanf("%d", &nouvel_id);
        id_existe = 0;
        for (int i = 0; i < compteur; i++)
        {
            if (etudiant1[i].id == nouvel_id)
            {
                id_existe = 1;
                printf("Erreur : Cet identifiant existe deje. Veuillez entrer un identifiant unique.\n");
                break;
            }
        }
    }
    while (id_existe == 1);

    etudiant1[compteur].id = nouvel_id;

    printf("Entrer le nom de l'etudiant: ");
    getchar(); // To consume the newline character left by scanf
    gets(etudiant1[compteur].nom);

    printf("Entrer le prenom de l'etudiant: ");
    gets(etudiant1[compteur].prenom);

    printf("Entrer la date de naissance de l'etudiant :\n");
    printf("Jour: ");
    scanf("%d", &etudiant1[compteur].dateNaissance.jour);
    printf("Mois: ");
    scanf("%d", &etudiant1[compteur].dateNaissance.mois);
    printf("Annee: ");
    scanf("%d", &etudiant1[compteur].dateNaissance.annee);

    // Choose department
    int choixDepartement;
    printf("Entrer la departement de l'etudiant (0:Science, 1:Arts, 2:Engineering, 3:Law, 4:Medicine): ");
    scanf("%d", &choixDepartement);

    // Validate department choice
    if (choixDepartement >= 0 && choixDepartement <= 4)
    {
        etudiant1[compteur].departement = (DepartementType)choixDepartement;
    }
    else
    {
        printf("Erreur : Departement non valide.\n");
        return;
    }

    printf("Entrer la note generale de l'etudiant: ");
    scanf("%d", &etudiant1[compteur].noteGenerale);

    compteur++;
}
//function pour choisir la modification ou la supprission d'un etudiant.
void Modifier_supprimer_etudiant()
{
    menu2();
};

// function pour modifier les info d'un etudiant
void Modifier_etudiant()
{
    printf("\n=====================================MODIFICATION D'UN ETUDIANT=====================================");
    int found=0;
    printf("\n entrer ID de l'eleve que tu veux modifier :");
    scanf("%d",&IDmodifier);
    int choix;
    int choixDepartement;
    for(int i=0; i<compteur; i++)
    {
        if(etudiant1[i].id == IDmodifier)
        {
            found = 1;
            printf("\n modifier l'etudiant de ID : %d\n",IDmodifier);
            printf("1.modifier le nom \n");
            printf("2.modifier le prenom \n");
            printf("3.modifier la date de naissance \n");
            printf("4.modifier la departement \n");
            printf("5.modifier la note generale \n");
            printf("entrer votre choix :");
            scanf("%d",&choix);
            switch(choix)
            {
            case 1:
                printf("entrer un nouveau nom :");
                getchar();
                gets(etudiant1[i].nom);
                printf("le nom est modifier.\n");
                break;
            case 2:
                printf("entrer un nouveau prenom \n");
                getchar();
                gets(etudiant1[i].prenom);
                printf("le prenom est modifier.\n");
                break;
            case 3:
                printf("entrer un nouveau date de naissance :\n");
                printf("jour :");
                scanf("%d",&etudiant1[i].dateNaissance.jour);
                printf("mois :");
                scanf("%d",&etudiant1[i].dateNaissance.mois);
                printf("annee :");
                scanf("%d",&etudiant1[i].dateNaissance.annee);
                break;
            case 4:

                printf("Entrer une nouvelle departement (0:Science, 1:Arts, 2:Engineering, 3:Law, 4:Medicine): ");
                scanf("%d", &choixDepartement);

                if (choixDepartement >= 0 && choixDepartement <= 4)
                {
                    etudiant1[i].departement = (DepartementType)choixDepartement;
                }
                else
                {
                    printf("Erreur : Departement non valide.\n");
                    return;
                }
                break;
            case 5:
                printf("Entrer une nouvelle note generale: ");
                scanf("%d", &etudiant1[i].noteGenerale);
                break;
            default:
                printf("choix n'existe pas .\n");
                break;
            }
        }
    }
    if (!found)
    {
        printf("Erreur : L'etudiant avec ID %d n'existe pas.\n", IDmodifier);
    }
};

//function pour supprimer un etudiant
void Supprimer_etudiant()
{
    printf("\n=====================================SUPRIMER UN ETUDIANT=====================================");
    int found=0;
    printf("\n entrer ID de l'etudiant qui tu veux suprimee :\n");
    scanf("%d",&IDdel);
    for(int i=0; i<compteur; i++)
    {
        if (etudiant1[i].id==IDdel)
        {
            found = 1;
            for (int N=i; N<compteur-1; N++)
            {
                etudiant1[N]=etudiant1[N+1];
            }
            compteur--;
            printf(" l'etudiant de ID=%d est supprime \n",IDdel);
            break;
        }
    }
    if(!found)
    {
        printf("l'etudiant avec ID=%d n'existe pas.\n",IDdel);
    }
};

//function pour afficher les info d'un etudiant
void Afficher_info()
{
    printf("\n=====================================AFFICHER LES INFORMATION D'UN ELEVE=====================================");
    int found=0;
    printf("\n entrer ID de l'etudiant qui tu veux afficher leur informations :\n");
    scanf("%d",&IDinfo);
    for(int i=0; i<compteur; i++)
    {
        if (etudiant1[i].id == IDinfo)
        {
            found = 1;
            printf("Les informations de l'etudiant avec ID : %d sont :\n", IDinfo);
            printf("Nom : %s\n", etudiant1[i].nom);
            printf("Prenom : %s\n", etudiant1[i].prenom);
            printf("Date de naissance : %d/%d/%d\n", etudiant1[i].dateNaissance.jour, etudiant1[i].dateNaissance.mois, etudiant1[i].dateNaissance.annee);

            printf("Departement : ");
            getDepartementName(etudiant1[i].departement);
            printf("\n");

            printf("Note generale : %d\n", etudiant1[i].noteGenerale);
        }
    }
    if(!found)
    {
        printf("l'etudiant avec ID=%d n'existe pas.\n",IDinfo);
    }
};

//function pour calculer la moyenne generale
void Calculer_moyenne_generale()
{
    printf("\n===================================== CALCULER LA MOYENNE GENERALE =====================================n");

    int totalNoteScience = 0, totalNoteArts = 0, totalNoteEngineering = 0, totalNoteLaw = 0, totalNoteMedicine = 0;
    int countScience = 0, countArts = 0, countEngineering = 0, countLaw = 0, countMedicine = 0;
    int totalNoteUniversity = 0;

    for (int i = 0; i < compteur; i++)
    {
        totalNoteUniversity += etudiant1[i].noteGenerale;

        switch (etudiant1[i].departement)
        {
        case SCIENCE:
            totalNoteScience += etudiant1[i].noteGenerale;
            countScience++;
            break;
        case ARTS:
            totalNoteArts += etudiant1[i].noteGenerale;
            countArts++;
            break;
        case ENGINEERING:
            totalNoteEngineering += etudiant1[i].noteGenerale;
            countEngineering++;
            break;
        case LAW:
            totalNoteLaw += etudiant1[i].noteGenerale;
            countLaw++;
            break;
        case MEDICINE:
            totalNoteMedicine += etudiant1[i].noteGenerale;
            countMedicine++;
            break;
        }
    }

    if (countScience > 0)
        printf("Moyenne generale du departement Science: %.2f\n", (float)totalNoteScience / countScience);
    else
        printf("Pas d'etudiants dans le departement Science.\n");

    if (countArts > 0)
        printf("Moyenne generale du departement Arts: %.2f\n", (float)totalNoteArts / countArts);
    else
        printf("Pas d'etudiants dans le departement Arts.\n");

    if (countEngineering > 0)
        printf("Moyenne generale du departement Engineering: %.2f\n", (float)totalNoteEngineering / countEngineering);
    else
        printf("Pas d'etudiants dans le departement Engineering.\n");

    if (countLaw > 0)
        printf("Moyenne generale du departement Law: %.2f\n", (float)totalNoteLaw / countLaw);
    else
        printf("Pas d'etudiants dans le departement Law.\n");

    if (countMedicine > 0)
        printf("Moyenne generale du departement Medicine: %.2f\n", (float)totalNoteMedicine / countMedicine);
    else
        printf("Pas d'etudiants dans le departement Medicine.\n");

    if (compteur > 0)
        printf("Moyenne generale de l'universite: %.2f\n", (float)totalNoteUniversity / compteur);
    else
        printf("Pas d'etudiants dans l'universite.\n");
}

//function pour afficher les statistique
void Afficher_statistiques()
{
    int choix;

    printf("\n===================================== STATISTIQUES =====================================\n");
    printf("Choisissez une option :\n");
    printf("1. Afficher le nombre total d'etudiants inscrits\n");
    printf("2. Afficher le nombre d'etudiants dans chaque departement\n");
    printf("3. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
    printf("4. Afficher les 3 etudiants ayant les meilleures notes\n");
    printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement (note >= 10)\n");
    printf("6. Quitter\n");

    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("\n Nombre total d'etudiants inscrits est : %d\n", compteur);
        break;

    case 2:
    {
        int countScience = 0, countArts = 0, countEngineering = 0, countLaw = 0, countMedicine = 0;

        for (int i = 0; i < compteur; i++)
        {
            switch (etudiant1[i].departement)
            {
            case SCIENCE:
                countScience++;
                break;
            case ARTS:
                countArts++;
                break;
            case ENGINEERING:
                countEngineering++;
                break;
            case LAW:
                countLaw++;
                break;
            case MEDICINE:
                countMedicine++;
                break;
            }
        }

        printf("\nNombre d'etudiants dans le departement Science : %d\n", countScience);
        printf("Nombre d'etudiants dans le departement Arts : %d\n", countArts);
        printf("Nombre d'etudiants dans le departement Engineering : %d\n", countEngineering);
        printf("Nombre d'etudiants dans le departement Law : %d\n", countLaw);
        printf("Nombre d'etudiants dans le departement Medicine : %d\n", countMedicine);
        break;
    }

    case 3:
    {
        float seuil;
        printf("\n Entrez un seuil pour afficher les etudiants avec une moyenne superieure : ");
        scanf("%f", &seuil);

        printf("\n etudiants ayant une moyenne superieure a %.2f sont :\n", seuil);
        for (int i = 0; i < compteur; i++)
        {
            if (etudiant1[i].noteGenerale > seuil)
            {
                printf("ID: %d, Nom: %s, Prenom: %s, Note generale: %d\n",etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
            }
        }
        break;
    }

    case 4:
        printf("\n Les 3 etudiants avec les meilleures notes sont :\n");

        for (int i = 0; i < compteur - 1; i++)
        {
            for (int j = i + 1; j < compteur; j++)
            {
                if (etudiant1[i].noteGenerale < etudiant1[j].noteGenerale)
                {
                    struct etudiant temp = etudiant1[i];
                    etudiant1[i] = etudiant1[j];
                    etudiant1[j] = temp;
                }
            }
        }

        for (int i = 0; i < 3 && i < compteur; i++)
        {
            printf("ID: %d, Nom: %s, Prenom: %s, Note generale: %d\n",etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
        }
        break;

    case 5:
    {
        int countSuccessScience = 0, countSuccessArts = 0, countSuccessEngineering = 0, countSuccessLaw = 0, countSuccessMedicine = 0;

        for (int i = 0; i < compteur; i++)
        {
            if (etudiant1[i].noteGenerale >= 10)
            {
                switch (etudiant1[i].departement)
                {
                case SCIENCE:
                    countSuccessScience++;
                    break;
                case ARTS:
                    countSuccessArts++;
                    break;
                case ENGINEERING:
                    countSuccessEngineering++;
                    break;
                case LAW:
                    countSuccessLaw++;
                    break;
                case MEDICINE:
                    countSuccessMedicine++;
                    break;
                }
            }
        }

        printf("\nNombre d'etudiants ayant reussi (note >= 10) dans le departement Science : %d\n", countSuccessScience);
        printf("Nombre d'etudiants ayant reussi (note >= 10) dans le departement Arts : %d\n", countSuccessArts);
        printf("Nombre d'etudiants ayant reussi (note >= 10) dans le departement Engineering : %d\n", countSuccessEngineering);
        printf("Nombre d'etudiants ayant reussi (note >= 10) dans le departement Law : %d\n", countSuccessLaw);
        printf("Nombre d'etudiants ayant reussi (note >= 10) dans le departement Medicine : %d\n", countSuccessMedicine);
        break;
    }

    case 6:
        printf("Quitter les statistiques.\n");
        break;

    default:
        printf("Option invalide. Veuillez choisir un nombre entre 1 et 6.\n");
        break;
    }
}

//function pour rechercher des etudiants
void Rechercher()
{
    printf("\n===================================== RECHERCHER PAR UN ETUDIANT =====================================\n");
    int choix;
    int found = 0;
    int choixDepartement;
    printf("entrer votre choix :\n");
    printf("1:Rechercher un etudiant par son nom .\n",nomRechercher);
    printf("2:Afficher la liste des etudiants inscrits dans un departement specifique .\n",departementRechercher);
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        printf("Entrer le nom de l'etudiant qui tu veux rechercher :");
        scanf("%s",&nomRechercher);
        for(int i=0; i<compteur; i++)
        {
            if (strcmp(etudiant1[i].nom, nomRechercher) == 0)
            {
                found = 1;
                printf("Les informations de l'etudiant avec le nom %s sont :\n", nomRechercher);
                printf("Nom : %s\n", etudiant1[i].nom);
                printf("Prenom : %s\n", etudiant1[i].prenom);
                printf("Date de naissance : %d/%d/%d\n", etudiant1[i].dateNaissance.jour, etudiant1[i].dateNaissance.mois, etudiant1[i].dateNaissance.annee);
                printf("Departement : ");
                getDepartementName(etudiant1[i].departement);
                printf("\n");
                printf("Note generale : %d\n", etudiant1[i].noteGenerale);
            }
        }
        if(!found)
        {
            printf("l'etudiant avec le nom  : %s n'existe pas.\n",nomRechercher);
        }
        break;
    case 2:
        printf("Entrez le numero du departement (0:Science, 1:Arts, 2:Engineering, 3:Law, 4:Medicine) : ");
        scanf("%d", &choixDepartement);

        if (choixDepartement < 0 || choixDepartement > 4)
        {
            printf("Erreur : Departement non valide.\n");
            return;
        }

        printf("Liste des etudiants dans le departement : ");
        getDepartementName((DepartementType)choixDepartement);
        printf("\n");
        for (int i = 0; i < compteur; i++)
        {
            if (etudiant1[i].departement == choixDepartement)
            {
                found = 1;
                printf("ID: %d, Nom: %s, Prenom: %s, Note generale: %d\n", etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
            }
        }

        if (!found)
        {
            printf("Aucun etudiant dans ce departement.\n");
        }
        break;
    default:
        printf("Choix invalide.\n");
        break;
    }

};

//function pour que utilisateur choisi la façon avec laquelle doit fair le triage
void Triage()
{
    printf("\n===================================== TRIER UN ETUDIANT =====================================\n");
    int choix,ordre;
    printf("Entrer votre choix :\n");
    printf("1.Tri alphabetique des etudiants en fonction de leur nom (de A a Z ou de Z a A)\n");
    printf("2.Tri des etudiants par moyenne generale, du plus eleve au plus faible ou inversement\n");
    printf("3.Tri des etudiants selon leur statut de reussite (ceux ayant une moyenne superieure ou egale a 10/20)\n");
    scanf("%d",&choix);

    switch(choix)
    {
    case 1:
        printf("Entrer l'ordre de tri : 1 pour A a Z, 2 pour Z a A : ");
        scanf("%d", &ordre);
        for (int i = 0; i < compteur - 1; i++)
        {
            for (int j = i + 1; j < compteur; j++)
            {
                if ((ordre == 1 && strcasecmp(etudiant1[i].nom, etudiant1[j].nom) > 0) || (ordre == 2 && strcasecmp(etudiant1[i].nom, etudiant1[j].nom) < 0))
                {
                    temporaire = etudiant1[i];
                    etudiant1[i] = etudiant1[j];
                    etudiant1[j] = temporaire;
                }
            }
        }
        printf("\nListe des etudiants tries par nom :\n");
        for (int i = 0; i < compteur; i++)
        {
            printf("ID: %d, Nom: %s, Prenom: %s, Note generale: %d\n", etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
        }
        break;
    case 2:
        printf("Entrer l'ordre de tri : 1 pour du plus eleve au plus faible, 2 pour l'inverse : ");
        scanf("%d", &ordre);
        for (int i = 0; i < compteur - 1; i++)
        {
            for (int j = i + 1; j < compteur; j++)
            {
                if ((ordre == 1 && etudiant1[i].noteGenerale < etudiant1[j].noteGenerale) || (ordre == 2 && etudiant1[i].noteGenerale > etudiant1[j].noteGenerale))
                {
                    temporaire = etudiant1[i];
                    etudiant1[i] = etudiant1[j];
                    etudiant1[j] = temporaire;
                }
            }
        }
        printf("\nListe des etudiants tries par note generale :\n");
        for (int i = 0; i < compteur; i++)
        {
            printf("ID: %d, Nom: %s, Prenom: %s, Note generale: %d\n", etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
        }
        break;
    case 3:
        printf("\nListe des etudiants ayant une moyenne superieure ou egale a 10/20 :\n");
        for (int i = 0; i < compteur; i++)
        {
            if (etudiant1[i].noteGenerale >= 10)
            {
                printf("ID: %d, Nom: %s, Prenom: %s, Note generale: %d\n", etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
            }
        }
        break;

    default:
        printf("Choix invalide.\n");
        break;
    }
};


//menu principale
int menu1()
{
    int selection;
    char input[10];

    do
    {
        printf("\n===================================== GESTION DES ETUDIANTS =====================================n");
        printf("\n Choisissez une option :\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Modifier ou supprimer un etudiant\n");
        printf("3. Afficher les details d'un etudiant\n");
        printf("4. Calculer la moyenne generale\n");
        printf("5. Statistiques\n");
        printf("6. Rechercher un etudiant\n");
        printf("7. Trier un etudiant\n");
        printf("8. Quitter\n");
        scanf("%s", input);
        selection=atoi(input);

        switch (selection)
        {
        case 1:
            Ajouter_etudiant();
            break;
        case 2:
            Modifier_supprimer_etudiant();
            break;
        case 3:
            Afficher_info();
            break;
        case 4:
            Calculer_moyenne_generale();
            break;
        case 5:
            Afficher_statistiques();
            break;
        case 6:
            Rechercher();
            break;
        case 7:
            Triage();
            break;
        }
    }
    while (selection != 8);

    return 0;
}

int menu2()
{
    int selection;

    do
    {
        printf("\n choisissez une option :\n");
        printf("1. Modifier les informations d'un etudiant\n");
        printf("2. Supprimer les informations d'un etudiant\n");
        printf("3. Quitter\n");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            Modifier_etudiant();
            break;
        case 2:
            Supprimer_etudiant();
            break;
        }
    }
    while (selection != 3);
    return 0;
}
