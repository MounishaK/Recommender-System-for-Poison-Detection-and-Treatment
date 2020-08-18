#ifndef TREATMENT_H
#define TREATMENT_H


#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstdio>
#include <conio.h>
#include "Queue.h"
using namespace std;

#define Vlist_SIZE 16

struct POISON
{
   string Initialized;
   string value;
}P[Vlist_SIZE];

//int i;

char clause_variable_list[60][10];


string Vvalue[Vlist_SIZE] ={ " ","NOT POISON", "CARBAMATES","ORGANO-CHLORINES",
                             "ZINC PHOSPHIDE","NITROGEN OXIDE","INHALED CYANIDE",
                             "INHALED RICIN","INHALED NERVE GAS","ARSENIC",
                             "RICIN","HYDROGEN CYANIDE","MERCURY",
                             "AMATOXIN","VENOM FROM SNAKE BITE","VENOM FROM SCORPION BITE"};



void treatment(string STR)
{
    Queue cvq;
    int var_index=0;
    int rule_number=0;
    int clause_number=0;
    string TREATMENT;
    string variable;


    for(i=0;i<Vlist_SIZE;i++)
    {
       P[i].value= Vvalue[i];
       P[i].Initialized="NI";
    }

    ///////////////////
       for (i=0;i < 60; i++)
       strcpy(clause_variable_list[i]," ");
    strcpy(clause_variable_list[0], "");
            for(i=1;i<58;i+=4)
    strcpy(clause_variable_list[i], "POISON");
    ///////
    //adding to queue
   cvq.enqueue(STR);

     for(i=0;i<Vlist_SIZE;i++)
     {
         if(P[i].value==STR)
            { var_index=i;
              clause_number=(i*4)-3;
              P[i].Initialized="I";
            }
     }
////////////////////////////////////////////


        while(!cvq.isEmpty())
       {
            variable = cvq.get_front();
            cvq.dequeue();
       }


            //find rule number
            rule_number = (int(clause_number / 4) + 1) * 10;

        switch (rule_number)
        {
        case 10:
           // if (strcmp(STR, "NO POISON") == 0)
            TREATMENT="NO TREATMENT NEEDED FOR POISON CONSULT THE DOCTOR";
            break;
        case 20:
            //if ((strcmp(STR, "CARBAMATES") == 0))
            TREATMENT="ATROPINE";
            break;
        case 30:
            //if ((strcmp(STR, "ORGANO CHLORINES") == 0))
            TREATMENT="ACTIVATED CHARCOAL + CHOLESTYRAMINE + OLESTRA";
            break;
        case 40:
            //if ((strcmp(STR, "ZINC PHOSPHIDE ") == 0))
            TREATMENT="CASTOR OIL";
            break;
        case 50:
            //if ((strcmp(STR, "NITROGEN OXIDE") == 0))
            TREATMENT="WATER OR MILK + IV";
            break;
        case 60:
            //if ((strcmp(STR, "CYANIDE") == 0))
            TREATMENT="CHARCOAL + OXYGEN ";
            break;
        case 70:
            //if ((strcmp(STR, "RICIN GAS") == 0))
            TREATMENT="REHYDRATION + IV";
            break;
        case 80:
            //if ((strcmp(STR, "NERVE GAS") == 0))
            TREATMENT="ATROPINE + ANTICHOLINERGIC";
            break;
        case 90:
           // if ((strcmp(STR, "ARSENIC") == 0))
            TREATMENT="OXYGEN + IV + CHARCOAL";
            break;
        case 100:
           // if ((strcmp(STR, "RICIN") == 0))
            TREATMENT="CHARCOAL";
            break;
        case 110:
           // if ((strcmp(STR, "HYDROGEN CYANIDE") == 0))
            TREATMENT="SODIUM THIOSULPHATE IV";
            break;
        case 120:
            //if (strcmp(STR, "MERCURY") == 0)
            TREATMENT="CHELATION";
            break;
        case 130:
           // if ((strcmp(STR, "AMATOXIN") == 0))
            TREATMENT="IV + ELECTROLYTE";
            break;
        case 140:
           // if ((strcmp(STR, "VENOM FROM SNAKE BITE") == 0))
            TREATMENT="TETANUS SHOT + PARACETAMOL";
            break;
        case 150:
            //if ((strcmp(STR, "VENOM FROM SCORPION BITE") == 0))
            TREATMENT="ICE + ASPIRIN + ELEVATION";
            break;
        default: cout<<"\nSorry treatment not listed - consult doctor.";
        }


         cout<<"\n Treatment for "<<variable<<" :"<<TREATMENT<<endl;



}

void disp_var_list2()
{
   cout<<"*** TREATMENT VARIABLE LIST ***\n";


        cout<<" VARIABLE  POISON";
        cout<<endl;

       cout<<"HIT RETURN TO CONTINUE\n";
       getch();
}
void disp_clvar_list2()
{
  cout<<"*** TREATMENT CLAUSE-VARIABLE LIST ***\n";

    for (i=0;i < 60; i++)
       strcpy(clause_variable_list[i]," ");
            for(i=0;i<58;i+=4)
    strcpy(clause_variable_list[i], "POISON");
    for (i = 0; i < 60; i++)
    {
        cout<<" CLAUSE "<<i<<" "<<clause_variable_list[i]<<endl;
     }

            cout<<"HIT RETURN TO CONTINUE\n\n";
            getch();
}
void disp_concl_list2()
{
cout << "*** TREATMENT CONCLUSION LIST ***" << endl;
        for (i=0; i<38; i++)
            cout <<i<<" " <<"TREATMENT" << endl;

        cout << "HIT RETURN TO CONTINUE" << endl;
        getchar();
        cout << endl;
}

#endif // TREATMENT_H

