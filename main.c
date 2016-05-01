#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file={NULL},* file0={NULL};

    char *buffer, nomfichier[50];
    char*p;
    char transaction[20]=" ";

    long file_size;

    int key=5;

etiq:
     fflush(stdin);///pour vider le tampon
     printf("\naction: ");
            fgets(transaction,10,stdin);

            p=strchr(transaction,'\n');

            if(p!=NULL)
            *p=0;


            if(strcmp(transaction,"decrypt")==0)
                key=(-1)*key;
            else if(strcmp(transaction,"encrypt")==0)
                key=(1)*key;
            else
                goto etiq;

etiq2:
            fflush(stdin);///pour vider le tampon
            printf("\nfilename: ");
            fgets(nomfichier,50,stdin);
            p=strchr(nomfichier,'\n');
            if(p!=NULL)
            *p=0;


            file=fopen(nomfichier,"rb");


            if(file!= NULL)
            {
            fseek(file,0,SEEK_END);
            file_size=ftell(file);



            rewind(file);

            buffer=malloc(file_size*(sizeof(char)));
            fread(buffer, sizeof(char), file_size, file);

                file0=fopen("tampon.txt","w+");
int i=0;
                for(i=0;i<=(int)file_size;i++)
                {
                    buffer[i]=buffer[i]+key;

                }


            fwrite(buffer, sizeof(char), file_size, file0);



                fclose(file);///ON ferme les fichiers pour pouvoir les renommer ou les efffacer.
                fclose(file0);

            remove(nomfichier);
            rename("tampon.txt",nomfichier);
            /*rename("tampon.dat","ent_cont.dat"); ///Le tampon devient contact.dat
            rename("e.dat","tampon.dat");/// contact.dat devient tampon.dat*/


               // printf("Hello world!\n");
                printf("Done\n");

                getchar();
                return 0;
}
                else
                    printf("fichier non trouvé!\n");

                return 0;

}




