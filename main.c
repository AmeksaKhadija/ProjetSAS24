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

// function pour ajouter un étudiant
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
                printf("Erreur : Cet identifiant existe d�j�. Veuillez entrer un identifiant unique.\n");
                break;
            }
        }
    }
    while (id_existe == 1);

    etudiant1[compteur].id = nouvel_id;

    printf("Entrer le nom de l'�tudiant: ");
    getchar(); // To consume the newline character left by scanf
    gets(etudiant1[compteur].nom);

    printf("Entrer le prenom de l'�tudiant: ");
    gets(etudiant1[compteur].prenom);

    printf("Entrer la date de naissance de l'�tudiant :\n");
    printf("Jour: ");
    scanf("%d", &etudiant1[compteur].dateNaissance.jour);
    printf("Mois: ");
    scanf("%d", &etudiant1[compteur].dateNaissance.mois);
    printf("Annee: ");
    scanf("%d", &etudiant1[compteur].dateNaissance.annee);

    // Choose department
    int choixDepartement;
    printf("Entrer la departement de l'�tudiant (0:Science, 1:Arts, 2:Engineering, 3:Law, 4:Medicine): ");
    scanf("%d", &choixDepartement);

    // Validate department choice
    if (choixDepartement >= 0 && choixDepartement <= 4)
    {
        etudiant1[compteur].departement = (DepartementType)choixDepartement;
    }
    else
    {
        printf("Erreur : D�partement non valide.\n");
        return;
    }

    printf("Entrer la note generale de l'�tudiant: ");
    scanf("%d", &etudiant1[compteur].noteGenerale);

    compteur++;
}
//function pour choisir la modification ou la supprission d'un �tudiant.
void Modifier_supprimer_etudiant()
{
    menu2();
};

// function pour modifier les info d'un étudiant
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
            printf("5.modifier la note g�n�rale \n");
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
                    printf("Erreur : D�partement non valide.\n");
                    return;
                }
                break;
            case 5:
                printf("Entrer une nouvelle note g�n�rale: ");
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
        printf("Erreur : L'étudiant avec ID %d n'existe pas.\n", IDmodifier);
    }
};

//function pour supprimer un étudiant
void Supprimer_etudiant()
{
    printf("\n=====================================SUPRIMER UN ETUDIANT=====================================");
    int found=0;
    printf("\n entrer ID de l'�tudiant qui tu veux suprimee :\n");
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
            printf(" l'�tudiant de ID=%d est supprime \n",IDdel);
            break;
        }
    }
    if(!found)
    {
        printf("l'�tudiant avec ID=%d n'existe pas.\n",IDdel);
    }
};

//function pour afficher les info d'un etudiant
void Afficher_info()
{
    printf("\n=====================================AFFICHER LES INFORMATION D'UN ELEVE=====================================");
    int found=0;
    printf("\n entrer ID de l'�tudiant qui tu veux afficher leur informations :\n");
    scanf("%d",&IDinfo);
    for(int i=0; i<compteur; i++)
    {
        if (etudiant1[i].id == IDinfo)
        {
            found = 1;
            printf("Les informations de l'�tudiant avec ID : %d sont :\n", IDinfo);
            printf("Nom : %s\n", etudiant1[i].nom);
            printf("Prenom : %s\n", etudiant1[i].prenom);
            printf("Date de naissance : %d/%d/%d\n", etudiant1[i].dateNaissance.jour, etudiant1[i].dateNaissance.mois, etudiant1[i].dateNaissance.annee);

            printf("D�partement : ");
            getDepartementName(etudiant1[i].departement);
            printf("\n");

            printf("Note g�n�rale : %d\n", etudiant1[i].noteGenerale);
        }
    }
    if(!found)
    {
        printf("l'�tudiant avec ID=%d n'existe pas.\n",IDinfo);
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
        printf("Moyenne générale du département Science: %.2f\n", (float)totalNoteScience / countScience);
    else
        printf("Pas d'étudiants dans le département Science.\n");

    if (countArts > 0)
        printf("Moyenne générale du département Arts: %.2f\n", (float)totalNoteArts / countArts);
    else
        printf("Pas d'étudiants dans le département Arts.\n");

    if (countEngineering > 0)
        printf("Moyenne générale du département Engineering: %.2f\n", (float)totalNoteEngineering / countEngineering);
    else
        printf("Pas d'étudiants dans le département Engineering.\n");

    if (countLaw > 0)
        printf("Moyenne générale du département Law: %.2f\n", (float)totalNoteLaw / countLaw);
    else
        printf("Pas d'étudiants dans le département Law.\n");

    if (countMedicine > 0)
        printf("Moyenne générale du département Medicine: %.2f\n", (float)totalNoteMedicine / countMedicine);
    else
        printf("Pas d'étudiants dans le département Medicine.\n");

    if (compteur > 0)
        printf("Moyenne générale de l'université: %.2f\n", (float)totalNoteUniversity / compteur);
    else
        printf("Pas d'étudiants dans l'université.\n");
}

//function pour afficher les statistique
void Afficher_statistiques()
{
    int choix;

    printf("\n===================================== STATISTIQUES =====================================\n");
    printf("Choisissez une option :\n");
    printf("1. Afficher le nombre total d'étudiants inscrits\n");
    printf("2. Afficher le nombre d'étudiants dans chaque département\n");
    printf("3. Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil\n");
    printf("4. Afficher les 3 étudiants ayant les meilleures notes\n");
    printf("5. Afficher le nombre d'étudiants ayant réussi dans chaque département (note >= 10)\n");
    printf("6. Quitter\n");

    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("\n Nombre total d'étudiants inscrits est : %d\n", compteur);
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

        printf("\nNombre d'étudiants dans le département Science : %d\n", countScience);
        printf("Nombre d'étudiants dans le département Arts : %d\n", countArts);
        printf("Nombre d'étudiants dans le département Engineering : %d\n", countEngineering);
        printf("Nombre d'étudiants dans le département Law : %d\n", countLaw);
        printf("Nombre d'étudiants dans le département Medicine : %d\n", countMedicine);
        break;
    }

    case 3:
    {
        float seuil;
        printf("\n Entrez un seuil pour afficher les étudiants avec une moyenne supérieure : ");
        scanf("%f", &seuil);

        printf("\n Étudiants ayant une moyenne supérieure à %.2f sont :\n", seuil);
        for (int i = 0; i < compteur; i++)
        {
            if (etudiant1[i].noteGenerale > seuil)
            {
                printf("ID: %d, Nom: %s, Prenom: %s, Note générale: %d\n",etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
            }
        }
        break;
    }

    case 4:
        printf("\n Les 3 étudiants avec les meilleures notes sont :\n");

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
            printf("ID: %d, Nom: %s, Prenom: %s, Note générale: %d\n",etudiant1[i].id, etudiant1[i].nom, etudiant1[i].prenom, etudiant1[i].noteGenerale);
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

        printf("\nNombre d'étudiants ayant réussi (note >= 10) dans le département Science : %d\n", countSuccessScience);
        printf("Nombre d'étudiants ayant réussi (note >= 10) dans le département Arts : %d\n", countSuccessArts);
        printf("Nombre d'étudiants ayant réussi (note >= 10) dans le département Engineering : %d\n", countSuccessEngineering);
        printf("Nombre d'étudiants ayant réussi (note >= 10) dans le département Law : %d\n", countSuccessLaw);
        printf("Nombre d'étudiants ayant réussi (note >= 10) dans le département Medicine : %d\n", countSuccessMedicine);
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

//function pour rechercher des étudiants
void Rechercher()
{
    printf("\n===================================== RECHERCHER PAR UN ETUDIANT =====================================n");
    int choix;
    int found = 0;
    printf("entrer votre choix :\n");
    printf("1:Rechercher un étudiant par son nom .\n",nomRechercher);
    printf("2:Afficher la liste des étudiants inscrits dans un département spécifique .\n",departementRechercher);
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        printf("Entrer le nom de l'étudiant qui tu veux rechercher :");
        scanf("%s",&nomRechercher);
        for(int i=0; i<compteur; i++)
        {
            if (strcmp(etudiant1[i].nom, nomRechercher) == 0)
            {
                found = 1;
                printf("Les informations de l'�tudiant avec le nom : %s sont :\n", nomRechercher);
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

    }

};

//menu principale
int menu1()
{
    int selection;

    do
    {
        printf("\n===================================== GESTION DES ETUDIANTS =====================================n");
        printf("\n Choisissez une option :\n");
        printf("1. Ajouter un �tudiant\n");
        printf("2. Modifier ou supprimer un �tudiant\n");
        printf("3. Afficher les d�tails d'un �tudiant\n");
        printf("4. Calculer la moyenne g�n�rale\n");
        printf("5. Statistiques\n");
        printf("6. Rechercher un �tudiant\n");
        printf("7. Trier un �tudiant\n");
        printf("8. Quitter\n");
        scanf("%d", &selection);

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
        printf("1. Modifier les informations d'un �tudiant\n");
        printf("2. Supprimer les informations d'un �tudiant\n");
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


