#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;
int cantidad_caracteres (char *palabra); //ejercicio 1.
int cantidad_palabras (char * palabra); //ejercicio 2.
int ocurrencia(char *palabra1, char *palabra2); //ejercicio3.
char *quitar_ocu (char *palabra1, char *palabra2);//ejercicio4.
char * quitar_palabra(char *palabras, int cantidad_letras);//ejercicio5.
int tquitarpalabra(char *palabras, int cantidad_letras);//ejercicio5
char ** cortecadena(char *palabras, char caracter);//ejercicio6
int cantcortecadena(char *palabra1, char caracter);//ejercicio6

int main()
{
    int opcion;
       string opc;
       char cadena1[100];
       char cadena2[20];
       int cantidad=0;
       char caracter;
       int o=0;
       do
       {
       cout<<"Opciones:"<<endl;
       cout<<" 1-EJERCICIO 1"<<"  ||  ";
       cout<<"2-EJERCICIO 2"<<"  ||  ";
       cout<<"3-EJERCICIO 3"<<"  ||  ";
       cout<<"4-EJERCICIO 4"<<"  ||  ";
       cout<<"5-EJERCICIO 5"<<"  ||  ";
       cout<<"6-EJERCICIO 6"<<endl;
       cout<<"Ingrese una opcion: ";
       cin>>opcion;
       cin.get();

       switch (opcion)
       {
       case 1:{
           cout<<"Dado un cstring retorna la cantidad de caracteres."<<endl<<"Ingrese cadena: ";
           cin.getline(cadena1,100);
           cout<<"La cantidad de caracteres es: "<<cantidad_caracteres(cadena1)<<endl;
           break;
       }
       case 2:{
           cout<<"Dado un cstring retorna la cantidad de palabras"<<endl<<"Ingrese cadena : ";
           cin.getline(cadena1,100);
           cout<<"la cantidad de palabras es: "<<cantidad_palabras(cadena1)<<endl;
           break;
       }
       case 3:{
           cout<<"Dado dos cstring, cuente las ocurrencias del segundo en el primero"<<endl;
           cout<<"Ingrese cadena 1: ";
           cin.getline(cadena1,100);
           cout<<"Ingrese cadena 2: ";
           cin.getline(cadena2,20);
           o=ocurrencia(cadena1,cadena2);
           cout<<"la cantidad de ocurrencias del segundo en el primero es: "<<o<<endl;
           break;
       }
       case 4:{
           cout<<"Dado dos cstring, remueve todas las ocurrencias del segundo en el primero"<<endl;
           cout<<"Ingrese cadena 1: ";
           cin.getline(cadena1,100);
           cout<<"Ingrese cadena 2: ";
           cin.getline(cadena2,20);
           char *a=new char[cantidad_caracteres(quitar_ocu(cadena1,cadena2))];
           a=quitar_ocu(cadena1,cadena2);
           cout<<"La primer cadena con las ocurrencias removidas es: ";
           for(int i=0;i<(cantidad_caracteres(quitar_ocu(cadena1,cadena2)));i++){
               cout<<a[i];
           }
           cout<<endl;
           break;
       }
       case 5:{
           cout<<"Dado un cstring, remueve todas las palabras que tengan menos que un numero de caracteres pasado por parámetro"<<endl;
           cout<<"Ingrese cadena:";
           cin.getline(cadena1,100);
           cout<<"Ingrese cantidad la cantidad de letras que tiene que tener la palabra a elimina: ";
           cin>>cantidad;
           cin.get();
           int tamano_quitar;
           tamano_quitar=tquitarpalabra(cadena1,cantidad);
           if(tamano_quitar>=1)
           {
               char * vec6=new char[tamano_quitar];
               vec6=quitar_palabra(cadena1,cantidad);
               cout<<"La cadena obtenida de quitar las palabras con cantidad de letras inferior a "<<cantidad<< " es: ";
               for(int i=0;i<tamano_quitar;i++)
               {
                   cout<<vec6[i];
               }
           }
           else
           {
               cout<<"SE ELIMINARON TODAS LAS PALABRAS PORQUE LA CADENA NO TIENE NINGUNA PALABRA CON MAS DE "<<cantidad<<" LETRAS";
           }
           cout<<endl<<endl;
           break;
       }
       case 6:{
           cout<<"Dado un cstring y un char, retorne un vector de cstring los cuales son producto de corte del cstring por el char enviado por parametros"<<endl;
           cout<<"Ingrese cadena: ";
           cin.getline(cadena1,100);
           cout<<"Ingrese caracter: ";
           cin.get(caracter);
           cout<<"EJ6-El vector de palabras resultado de eliminar el caracter '"<<caracter<<"' es"<<endl<<endl;
           int ca=cantcortecadena(cadena1, caracter);
           char ** vecpalaux = new char *[ca];
           vecpalaux=cortecadena(cadena1,caracter);
           int j=0;
               for (int i=0;i<ca;i++) {
                       while (vecpalaux[i][j]!='\0') {
                           cout<<vecpalaux[i][j];
                           j++;
                       }
                           j=0;
                           if(i<ca-1)
                           {
                           cout<<",";
                           }
                   }
           cout<<endl<<endl;
           break;
       }

       }//finswitch
       cout<<"DESEA EJECUTAR OTRO EJERCICIO? Y/N:";
       cin>>opc;
       }while (opc=="Y"||opc=="y");//findowhile



}



char ** cortecadena(char *palabras, char caracter)
{
    int t1= cantidad_caracteres (palabras);
    int cantpal=1;
    int ini=0;
    int fin=t1;
    while (palabras[ini]==caracter) {
        ini++;
    }
    while (palabras[fin-1]==caracter) {
        fin--;
    }

    for (int i=ini;i<fin;i++) {
        if (palabras[i]==caracter&&palabras[i+1]!=palabras[i]) {
            cantpal++;
        }
    }

   int indpalabra=0;
   int indcaracter=0;
   char ** vecpalabras=new char *[cantpal];
   for(int i=ini;i<fin;i++)
    {
          if(palabras[i]!=caracter)
          {
           indcaracter++;
          }
          else if(indcaracter>0)
          {

           vecpalabras[indpalabra]= new char [indcaracter];
           indpalabra++;
           indcaracter=0;

          }

      }
   vecpalabras[indpalabra]= new char [indcaracter];
   indpalabra=0;
   indcaracter=0;

   for(int i=ini;i<fin;i++)
      {
          if(palabras[i]!=caracter)
          {
           vecpalabras[indpalabra][indcaracter]=palabras[i];
           indcaracter++;

          }
          else if(indcaracter>0)
          {
           vecpalabras[indpalabra][indcaracter]='\0';
           indpalabra++;
           indcaracter=0;
          }

      }
   vecpalabras[indpalabra][indcaracter]='\0';

return vecpalabras;

}

int cantcortecadena(char *palabra, char caracter) //
{
    int cant_palabras=0;
    int tamanio=cantidad_caracteres(palabra);
    int ini=0;
    while(palabra[ini]==caracter)
    {
        ini++;
    }
    int fin=tamanio-1;
    while (palabra[fin]==caracter) {
        fin--;
    }

    for(int i=ini; i<fin;i++)
    {
        if(palabra[i]==caracter&&palabra[i]!=palabra[i+1])
        {
           cant_palabras++;
        }
    }


    return cant_palabras+1;

}

int tquitarpalabra(char *palabras, int cantidad_letras)
{
    int ca=cantcortecadena(palabras, ' ');
    char ** vecpalaux = new char *[ca];
    vecpalaux=cortecadena(palabras, ' ');
    int taux=0;
    int contpalmaycantletras=0;
        for (int i=0;i<ca;i++)
        {
            if (cantidad_caracteres(vecpalaux[i])>cantidad_letras) {
                taux=taux+cantidad_caracteres(vecpalaux[i]);
                contpalmaycantletras++;
            }
        }

    taux=taux+(contpalmaycantletras-1);
    return taux;
}

char * quitar_palabra(char *palabras, int cantidad_letras)
{
    int taux=tquitarpalabra(palabras,cantidad_letras);
    int ca=cantcortecadena(palabras, ' ');
    char ** vecpalaux = new char *[ca];
    vecpalaux=cortecadena(palabras, ' ');
    if(taux>0){
    char * npalabras = new char [taux];
    int j=0;
    int posnpalabras=0;
    for (int i=0;i<ca;i++)
    {
        if (cantidad_caracteres(vecpalaux[i])>cantidad_letras) {

            while (vecpalaux[i][j]!='\0') {
                npalabras[posnpalabras]=vecpalaux[i][j];
                j++;
                posnpalabras++;
            }
            npalabras[posnpalabras]=' ';
            posnpalabras++;
            j=0;
        }
    }
    return npalabras;
    }
    else{
        char * npalabras = new char [1];
        npalabras[0]='\0';
        return npalabras;
    }
}

char *quitar_ocu (char *palabra1, char *palabra2)
{

    int ocu=ocurrencia (palabra1, palabra2);
    int t1= cantidad_caracteres (palabra1);
    int t2= cantidad_caracteres (palabra2);
    int subocu=0;
    if(ocu>=1)
    {
        char *aux=new char [(t1-(t2*ocu))];
        int a=0;

        for(int i=0;i<t1;i++)
        {
            if(palabra2[0]==palabra1[i])
            {
                subocu=1;



                for(int j=subocu;j<t2;j++)
                {
                    i++;
                    if(palabra2[j]==palabra1[i])
                    {
                        subocu++;


                    }
                    else
                    {
                        j=t2;
                    }
                }




                int z=0;


                if(subocu<t2)
                {
                    z=i;

                    for(int k=z;k<z+subocu;k++)
                    {
                        aux[a]=palabra1[k-subocu];
                        a++;
                    }
                    i--;


                }
            }
            else
            {

                aux[a]=palabra1[i];
                a++;
            }
        }
        return aux;
    }
    else
        {
            return palabra1;
        }
}



int ocurrencia	(char *palabra1, char *palabra2){

    int t1= cantidad_caracteres (palabra1);
    int t2= cantidad_caracteres (palabra2);
    int ocu=0;
    int subocu=0;

    if (t1>=t2){
        for(int i=0;i<t1;i++){
            if(palabra2[0]==palabra1[i]){
                subocu=1;
                for(int j=subocu;j<t2;j++){
                    i++;

                    if(palabra2[j]==palabra1[i]){
                        subocu++;
                    }
                    else {
                        j=t2;
                        i--;
                    }

                }
                    if(subocu==t2){

                    ocu++;

                }
            }
        }
    }

    return ocu;
}
int cantidad_caracteres (char *palabra)
{
    int contador=0;
    for(int i=0; palabra[i]!='\0'; i++)
    {
        contador++;
    }
   return contador;
}


int cantidad_palabras (char * palabra)
{
    int cant_palabras=0;
    int tamanio=cantidad_caracteres(palabra);
    int ini=0;
    while(palabra[ini]==' ')
    {
        ini++;
    }
    int fin=tamanio-1;
    while (palabra[fin]==' ') {
        fin--;

    }
    for(int i=ini; i<fin;i++)
    {
        if(palabra[i]==' '&&palabra[i]!=palabra[i+1])
        {
           cant_palabras++;
        }
    }


        return cant_palabras+1;

}
