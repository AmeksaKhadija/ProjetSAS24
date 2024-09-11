#include <stdio.h>
#include <stdlib.h>

int main()
{
    menu1();
    return 0;
}

typedef enum
{
    SCIENCE,
    ARTS,
    ENGINEERING,
    LAW,
    MEDICINE
} DepartementType;

struct dateNaissance
{
    int jour;
    int mois;
    int annee;
};

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


