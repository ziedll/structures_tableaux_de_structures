#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// structures
typedef struct date date;
typedef struct voyage voyage;
typedef struct client client;
struct date
{
    int jour;
    int mois;
    int annee;
};
struct voyage
{
    char destination[20];
    date date_de_voyage;
};
struct client
{
    int id;
    char nom[20];
    char    prenom[20];
    int nombre_de_voyages;
    voyage voy[100];
};





int main()
{
    //declarations
    int choix,i,n,j,m,k,min;
    client client[200];
    voyage aux;
     int max=0;
     int indice_fidele=-1;
     int indice_client=-1;
     int identifiant;
     int freq[200];
     int compteur;


    //Menu
    do
    {
        do
        {
            printf("----------MENU-------------\n");
            printf("1-Remplir le tableau de clients\n");
            printf("2- Afficher les clients\n");
            printf("3-Trier les voyages des clients selon l�ordre d�croissant de la date. \n");
            printf("4- Afficher le voyageur le plus fid�le.\n");
            printf("5- Afficher la destination la plus demand�e pour un voyageur\n");
            printf("0-Quitter\n");
            scanf("%d", &choix);
        }
        while(choix<0||choix>4);

        switch (choix)
        {
        case 1:
            printf("Choisissez le nombre de clients");
            scanf("%d",&n);
            for(i=0; i<n; i++)
            {
                printf("Entrez l'identifiant\n");
                scanf("%d",&client[i].id);
                printf("Entrez son nom\n");
                fflush(stdin);
                gets(client[i].nom);
                printf("Entrez son prenom\n");
                scanf("%s", client[i].prenom);
                printf("Entrez le nombre de voyages\n");
                scanf("%d",&client[i].nombre_de_voyages);
                for (j=0;j<client[i].nombre_de_voyages;j++)
                {
                    printf("choisissez la destination\n");
                    fflush(stdin);
                    gets(client[i].voy[j].destination);
                    printf("Donnez le jour le mois et l'ann�e\n");
                    scanf("%d %d %d",&client[i].voy[j].date_de_voyage.jour,&client[i].voy[j].date_de_voyage.mois,&client[i].voy[j].date_de_voyage.annee);                }
            }



            break;


        case 2:
            for (i=0;i<n;i++)
            {
                printf("%d %s %s %d\n",&client[i].id,client[i].nom,client[i].prenom,&client[i].nombre_de_voyages);
                for(j=0;j<client[i].nombre_de_voyages;j++)
                {
                    printf("%s %d %d %d\n",client[i].voy[j].destination,&client[i].voy[j].date_de_voyage.jour,&client[i].voy[j].date_de_voyage.mois,&client[i].voy[j].date_de_voyage.annee);
                }
            }




            break;


        case 3:
               for (i=0;i<n;i++){
                for(j=0;j<client[i].nombre_de_voyages-1;j++){
                    min=j;
                    for(k=j+1;k<client[i].nombre_de_voyages;k++){
                        if (client[i].voy[k].date_de_voyage.annee<client[i].voy[min].date_de_voyage.annee)
                        {
                            min=k;
                        }{
                            if (client[i].voy[k].date_de_voyage.mois<client[i].voy[min].date_de_voyage.mois)
                            {
                                min=k;
                            }
                            {
                                if (client[i].voy[k].date_de_voyage.jour<client[i].voy[min].date_de_voyage.jour)
                                {
                                    min=k;
                                }
                            }
                        }
                        aux=client[i].voy[j];
                        client[i].voy[j]=client[i].voy[min];
                        client[i].voy[min]=aux;
                    }

                    
                }

               }



            break;

        case 4:
            for (i=0;i<n;i++)
            {
                if ("%d",&client[i].nombre_de_voyages>max)
                {
                   max=client[i].nombre_de_voyages;
                   indice_fidele=i;
                }

            }
            if (indice_fidele != -1) {
                printf("le client le plus fidele est %s %s",client[i].nom,client[i].prenom);
            }
            break;
        case 5:
        printf("Entrez l'identifiant du client");
        scanf("%d",&identifiant);
        for (i=0;i<n;i++)
        {
            if (client[i].id==identifiant)
            {
                indice_client=i;
            }

            
        }
        if (indice_client==-1)
        {
            printf("Client n'existe pas");
            break;
        }

        break;
    }
}
    while(choix!=0);
    return 0;
}
