#include<iostream>
#include<string.h>
#include<cstdlib>
#include<stdio.h>

using namespace std;
struct atmintukas       //aprasome kintamuosius
{
    string gamintojas;
    int talpa;
    int kaina;
    atmintukas *next;
};

int main()
{
    char taip='t';
    int nr=0;
    struct atmintukas *r1=NULL, *r2=NULL;
    
   do        //nauju irsau ivedimas
    {
        if(r1==NULL)
        {
                r1=new atmintukas; //malloc funkcija skiria prasoma atminties dydi
                r2=r1;
        }
        else
        {
            r2->next=new atmintukas;  //dinamines atminties priskyrimas rosyklei r2
            r2=r2->next;
        }
        cout<<"Iveskite atmintuko gamintoja: ";
        cin>>r2->gamintojas;
        cout<<"Iveskte atmintuko talba (GB): ";
        cin>>r2->talpa;
        cout<<"Iveskite atmintuko kaina (Lt): ";
        cin>>r2->kaina;
        
        cout<<"Ar norite ivesti dar viena atmintuka? (t/n)\n";
        cin>>taip;
        r2->next=NULL;
    }
     while((taip=='t')||(taip=='T'));
        cout<<"--------------------------------------------------------------\n \n";    //saraso spausdinimas
        cout<<"Atmintuku sarasas \n\n";     
        r2=r1;
    while(r2!=NULL)
    {
        cout<<(nr+1)<<'.'<<r2->gamintojas<<" "<<r2->talpa<<"GB "<<r2->kaina<<"Lt.\n";
        nr++;
        r2=r2->next;
    }
    
    cout<<"--------------------------------------------------------------\n \n";
    r2=r1;      //spausdinam atmintukus kurie mazesni 4GB ir sumazintom kainom
    nr=0;
    cout<<"Atmintukai, kuriu dydis mazesnis uz 4Gb sumazintos kainos 30% \n\n";
    while(r2!=NULL)
    {
        if(r2->talpa<4)     //tikrinam ar mazesni uz 4GB
        {
            r2->kaina=r2->kaina-r2->kaina*0.3;      //sumazinam kaina
            cout<<(nr+1)<<'.'<<r2->gamintojas<<" "<<r2->talpa<<"Gb "<<r2->kaina<<"Lt.\n";
            nr++;
        }
        r2=r2->next;
    }

    system("PAUSE");               
    return EXIT_SUCCESS;
}
