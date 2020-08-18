#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <conio.h>
using namespace std;

#define Conc_SIZE 50

   /*  conclusion list */
char conclt[Conc_SIZE][30];
//string conclusions[Conc_SIZE];
/*  variable list */
char varlt[50][30];
/*  clause vairable list */
char clvarlt[300][30];
char variable[30];
char TOXIC_SUBSTANCE[6];

char CHEMICALS[6];
char POISON[6];
char SNAKE_BITE[6];
char FOOD_POISON[6];

char SEV_HEADACHE[6];
char BUR_PAIN_IN_STOMACH[6];
char STOMACH_CRAMPS[6];
char SALIVATION[6];
char VOMITING[6];
char MUSCLE_TWITCHING[6];
char BLOOD_VOMITING[6];
char DIFFICULT_IN_BREATHING[6];
char FLUID_BUILDING_IN_LUNGS[6];
char SEISURE[6];
char SUDDEN_UNCONSCIOUS[6];
char DIZZINESS[6];
char DESTRUCTION_OF_RBC[6];
char INTESTINAL_BLEEDING[6];
char SEVERE_ABDOMINAL_PAIN[6];
char SEVERE_FLANK_PAIN[6];
char FISH[6];
char SEVERE_FLU[6];
char FAINT[6];
char LANDSCAPPING[6];
char MUSHROOM[6];
char SKIN_DISCOLORATION[6];
char ECESSIVE_SALIVATION[6];

char NEW_FOOD[6];
char INHALE_HARMFUL_GAS[6];
char INSTANT_ITCHY_RASH[6];
char SEIZURE[6];

char buff[128];


/* instantiated list */
int instlt[41];
/* statement stack */
int statsk[41];
int /* clause stack */ clausk[41], f, i, j, s, k, /*stack pointer */ sp;
int sn;
//*float /* grade */ gr, /*experience */
bool stack_not_empty = false;
bool conclusion_push = false;
void determine_member_concl_list(void);
string backward_chaining();
void instantiate(void);
void push_on_stack();

       string conclusions[50]={" ","CARBAMATES","ORGANO-CHLORINES","NOT POISON",
                             "ZINC PHOSPHIDE","NITROGEN OXIDE",
                              "INHALED HARMFUL GAS","NOT POISON","NOT POISON","INHALED CYANIDE","NOT POISON","INHALED RICIN",
                              "NOT POISON","INHALED NERVE GAS","NOT POISON","ARSENIC","FOOD POISON","MERCURY","NOT POISON",
                              "NOT POISON","AMATOXIN","NOT POISON","VENOM FROM SNAKE BITE","VENOM FROM SNAKE BITE",
                              "NOT POISON","VENOM FROM SCORPION BITE","NOT POISON","NOT POISON"};


//int main()
string diagnosis()
{
     string poison;
    /***** initialization section ******/
        /* stack space is 40 we initially place stack space at 40+1 */
        sp=41;
        for (i=1; i<41; i++)
        {
                strcpy(conclt[i],"");
                strcpy(varlt[i],"");
                instlt[i]=0;
                statsk[i]=0;
                clausk[i]=0;
        }
         for (i=1; i<301; i++)
            strcpy(clvarlt[i],"");
        /* enter conclusions which are the variables in the then part, 1 at
        a time.  enter the conclusions in exact order starting at the 1st
        if-then.  after last conclusion hit return key for rest of
        conclusions */

        /*** comment 305 *****/
        strcpy(conclt[1], "POISON");
        strcpy(conclt[2], "POISON");
        strcpy(conclt[3], "POISON");
        strcpy(conclt[4], "POISON");
        strcpy(conclt[5], "POISON");
        strcpy(conclt[6], "INHALE_HARMFUL_GAS");
        strcpy(conclt[7], "POISON");
        strcpy(conclt[8], "POISON");
        strcpy(conclt[9], "POISON");
        strcpy(conclt[10], "POISON");
        strcpy(conclt[11], "POISON");
        strcpy(conclt[12], "POISON");
        strcpy(conclt[13], "POISON");
        strcpy(conclt[14], "POISON");
        strcpy(conclt[15], "POISON");
        strcpy(conclt[16], "FOOD_POISON");
        strcpy(conclt[17], "POISON");
        strcpy(conclt[18], "POISON");
        strcpy(conclt[19], "POISON");
        strcpy(conclt[20], "POISON");
        strcpy(conclt[21], "POISON");
        strcpy(conclt[22], "POISON");
        strcpy(conclt[23], "POISON");
        strcpy(conclt[24], "POISON");
        strcpy(conclt[25], "POISON");
        strcpy(conclt[26], "POISON");
        strcpy(conclt[27], "POISON");
        strcpy(conclt[28], "POISON");
        strcpy(conclt[29], "POISON");
        strcpy(conclt[30], "POISON");
        strcpy(conclt[31], "POISON");
        strcpy(conclt[32], "SNAKE_BITE");
        strcpy(conclt[33], "POISON");
        strcpy(conclt[34], "POISON");
        strcpy(conclt[35], "POISON");
        strcpy(conclt[36], "POISON");
        strcpy(conclt[37], "POISON");



        /* enter variables which are in the if part, 1 at a time in the exact
        order that they occur, up to 3 variables per if statement.  do not
        duplicate any variable names.  any name is used only once.  if no
        more variables left just hit return key. */

        /**** comment 367 *****/
        strcpy(varlt[1], "TOXIC_SUBSTANCE");
        //strcpy(varlt[1], "SEV_HEADACHE");
        strcpy(varlt[2], "SEV_HEADACHE");
        strcpy(varlt[3], "BUR_PAIN_IN _STOMACH");
        strcpy(varlt[4], "STOMACH_CRAMPS");
        strcpy(varlt[5], "SALIVATION");
        strcpy(varlt[6], "VOMITING");
        strcpy(varlt[7], "MUSCLE_TWITCHING");
        strcpy(varlt[8], "BLOOD_VOMITING");
        strcpy(varlt[9], "DIFFICULT_IN_BREATHING");
        strcpy(varlt[10], "SEIZURE");
        strcpy(varlt[11], "FLUID_BUILDING_IN_LUNGS");
        strcpy(varlt[12], "SUDDEN_UNCONSCIOUS");
        strcpy(varlt[13], "SEVERE_ABDOMINAL_PAIN");
        strcpy(varlt[14], "DIZZINESS");
        strcpy(varlt[15], "DESTRUCTION_OF_RBC");
        //strcpy(varlt[16], "INTESTINAL_BLEEDING");
        //strcpy(varlt[17], "INSTANT_ITCHY_RASH");
        //strcpy(varlt[18], "NEW_FOOD");
        strcpy(varlt[16], "NEW_FOOD");
        strcpy(varlt[17], "FISH");
        strcpy(varlt[18], "SEVERE_FLANK_PAIN");
        strcpy(varlt[19], "MUSHROOM");
        strcpy(varlt[20], "SEVERE_FLU");
        strcpy(varlt[21], "LANDSCAPING");
        strcpy(varlt[22], "SKIN_DISCOLORATION");
        strcpy(varlt[23], "EXCESSIVE_SALIVATION");
        strcpy(varlt[24], "FAINT");
        //strcpy(varlt[25], "INHALE_HARMFUL_GAS");
        //strcpy(varlt[26], "TOXIC_SUBSTANCE");




        /***** comment 407 through 409 ***/
        /*************RULE 1**************/
        strcpy(clvarlt[1], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[2], "SEV_HEADACHE");

        /*************RULE 2**************/
        strcpy(clvarlt[9], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[10], "SEV_HEADACHE");
        strcpy(clvarlt[11], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[12], "STOMACH_CRAMPS");

        /*************RULE 3**************/
        strcpy(clvarlt[17], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[18], "SEV_HEADACHE");
        strcpy(clvarlt[19], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[20], "STOMACH_CRAMPS");

        /*************RULE 4**************/
        strcpy(clvarlt[25], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[26], "SEV_HEADACHE");
        strcpy(clvarlt[27], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[28], "SALIVATION");

        /*strcpy(clvarlt[19], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[20], "SEV_HEADACHE");
        strcpy(clvarlt[21], "BUR_PAIN_IN _STOMACH");*/

        /*************RULE 5**************/
        strcpy(clvarlt[33], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[34], "SEV_HEADACHE");
        strcpy(clvarlt[35], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[36], "SALIVATION");
        strcpy(clvarlt[37], "VOMITING");
        strcpy(clvarlt[38], "MUSCLE_TWITCHING");
        strcpy(clvarlt[39], "BLOOD_VOMITING");


        //strcpy(clvarlt[31], "TOXIC_SUBSTANCE");
       // strcpy(clvarlt[32], "SEV_HEADACHE");

        /*************RULE 6**************/
        strcpy(clvarlt[41], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[42], "SEV_HEADACHE");
        strcpy(clvarlt[43], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[44], "SALIVATION");
        strcpy(clvarlt[45], "VOMITING");
        strcpy(clvarlt[46], "MUSCLE_TWITCHING");
        strcpy(clvarlt[47], "DIFFICULT_IN_BREATHING");




        /*************RULE 7**************/
        strcpy(clvarlt[49], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[50], "SEV_HEADACHE");
        strcpy(clvarlt[51], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[52], "SALIVATION");
        strcpy(clvarlt[53], "VOMITING");
        strcpy(clvarlt[54], "MUSCLE_TWITCHING");
        strcpy(clvarlt[55], "BLOOD_VOMITING");


        /*************RULE 8**************/
        strcpy(clvarlt[57], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[58], "SEV_HEADACHE");
        strcpy(clvarlt[59], "BUR_PAIN_IN _STOMACH");
        strcpy(clvarlt[60], "SALIVATION");
        strcpy(clvarlt[61], "VOMITING");
        strcpy(clvarlt[62], "MUSCLE_TWITCHING");
        strcpy(clvarlt[63], "DIFFICULT_IN_BREATHING");

        /*************RULE 9**************/

        strcpy(clvarlt[65], "INHALE_HARMFUL_GAS");
        strcpy(clvarlt[66], "SEIZURE");
        //strcpy(clvarlt[67], "FLUID_BUILDING_IN_LUNGS");
        //strcpy(clvarlt[68], "SUDDEN_UNCONSCIOUS");

        /***************RULW 10*****************/
        strcpy(clvarlt[73], "INHALE_HARMFUL_GAS");
        strcpy(clvarlt[74], "SEIZURE");
        //strcpy(clvarlt[75], "FLUID_BUILDING_IN_LUNGS");
        //strcpy(clvarlt[76], "SUDDEN_UNCONSCIOUS");

         /***************RULW 11*****************/
        //strcpy(clvarlt[81], "INHALE_HARMFUL_GAS");
        strcpy(clvarlt[81], "SEIZURE");
        strcpy(clvarlt[82], "FLUID_BUILDING_IN_LUNGS");

         /***************RULW 12*****************/
        //strcpy(clvarlt[89], "INHALE_HARMFUL_GAS");
        strcpy(clvarlt[89], "SEIZURE");
        strcpy(clvarlt[90], "FLUID_BUILDING_IN_LUNGS");

         /***************RULW 13*****************/
        //strcpy(clvarlt[97], "INHALE_HARMFUL_GAS");
        strcpy(clvarlt[97], "SEIZURE");
        strcpy(clvarlt[98], "SUDDEN_UNCONSCIOUS");

         /***************RULW 14*****************/
        strcpy(clvarlt[105], "SEIZURE");
        strcpy(clvarlt[106], "SUDDEN_UNCONSCIOUS");
        strcpy(clvarlt[107], "SEVERE_ABDOMINAL_PAIN");
        strcpy(clvarlt[108], "DIZZINESS");
         /***************RULW 15*****************/
        strcpy(clvarlt[113], "SEIZURE");
        strcpy(clvarlt[114], "SUDDEN_UNCONSCIOUS");
        strcpy(clvarlt[115], "SEVERE_ABDOMINAL_PAIN");
        strcpy(clvarlt[116], "DIZZINESS");
        strcpy(clvarlt[117], "DESTRUCTION_OF_RBC");
         /***************RULW 16*****************/
        strcpy(clvarlt[121], "SEIZURE");
        strcpy(clvarlt[122], "SUDDEN_UNCONSCIOUS");
        strcpy(clvarlt[123], "SEVERE_ABDOMINAL_PAIN");
        strcpy(clvarlt[124], "DIZZINESS");
        strcpy(clvarlt[125], "DESTRUCTION_OF_RBC");

       /* strcpy(clvarlt[137], "VOMITING");
        strcpy(clvarlt[138], "SEVERE_ABDOMINAL_PAIN");
        strcpy(clvarlt[139], "INTESTINAL_BLEEDING");

        strcpy(clvarlt[145], "VOMITING");
        strcpy(clvarlt[146], "SEVERE_ABDOMINAL_PAIN");
        strcpy(clvarlt[147], "INTESTINAL_BLEEDING");

        strcpy(clvarlt[153], "TOXIC_SUBSTANCE");
        strcpy(clvarlt[154], "INSTANT_ITCHY_RASH");

        strcpy(clvarlt[161], "INSTANT_ITCHY_RASH");*/
         /***************RULW 17*****************/
        strcpy(clvarlt[129], "NEW_FOOD");
        strcpy(clvarlt[130], "FISH");
        strcpy(clvarlt[131], "SEVERE_FLANK_PAIN");
        //strcpy(clvarlt[132], "SEVERE_FLANK_PAIN");
         /***************RULW 18*****************/
        strcpy(clvarlt[137], "NEW_FOOD");
        strcpy(clvarlt[138], "FISH");
        strcpy(clvarlt[139], "SEVERE_FLANK_PAIN");
       // strcpy(clvarlt[140], "SEVERE_FLANK_PAIN");
         /***************RULW 19*****************/
        strcpy(clvarlt[145], "NEW_FOOD");
        strcpy(clvarlt[146], "FISH");
        //strcpy(clvarlt[147], "FISH");
         /***************RULW 20*****************/
        strcpy(clvarlt[153], "NEW_FOOD");
        strcpy(clvarlt[154], "MUSHROOM");
        strcpy(clvarlt[155], "SEVERE_FLU");
       // strcpy(clvarlt[156], "SEVERE_FLU");
         /***************RULW 21*****************/
        strcpy(clvarlt[161], "NEW_FOOD");
        strcpy(clvarlt[162], "MUSHROOM");
        strcpy(clvarlt[163], "SEVERE_FLU");
      //  strcpy(clvarlt[164], "SEVERE_FLU");
         /***************RULW 22*****************/
        strcpy(clvarlt[169], "NEW_FOOD");
        strcpy(clvarlt[170], "MUSHROOM");
        strcpy(clvarlt[171], "LANDSCAPING");
        strcpy(clvarlt[172], "SKIN_DISCOLORATION");
        strcpy(clvarlt[173], "EXCESSIVE_SALIVATION");
        //strcpy(clvarlt[174], "EXCESSIVE_SALIVATION");
         /***************RULW 23*****************/
        strcpy(clvarlt[177], "FAINT");
         /***************RULW 24*****************/
        strcpy(clvarlt[185], "FAINT");
         /***************RULW 25*****************/
        strcpy(clvarlt[193], "NEW_FOOD");
        strcpy(clvarlt[194], "MUSHROOM");
        strcpy(clvarlt[195], "LANDSCAPING");
        strcpy(clvarlt[196], "SKIN_DISCOLORATION");
       // strcpy(clvarlt[197], "SKIN_DISCOLORATION");
         /***************RULW 26*****************/
        strcpy(clvarlt[201], "NEW_FOOD");
        strcpy(clvarlt[202], "MUSHROOM");
        strcpy(clvarlt[203], "LANDSCAPING");
        strcpy(clvarlt[204], "SKIN_DISCOLORATION");
        //strcpy(clvarlt[205], "SKIN_DISCOLORATION");
         /***************RULW 27*****************/
        strcpy(clvarlt[209], "NEW_FOOD");
        strcpy(clvarlt[210], "MUSHROOM");
        strcpy(clvarlt[211], "LANDSCAPING");
        //strcpy(clvarlt[212], "LANDSCAPING");



        /****** inference section *****/
        cout << "PLEASE ENTER YOUR CONCLUSION :" << endl;
        cin >> variable;
        /* get conclusion statement number (sn) from the conclusion list
           (conclt) */
        /* first statement starts search */
        cout<<"variable" << " "<< variable << endl;
       // cout<<"before backward chaining";

        poison=backward_chaining();


   // cout<<endl<<poison;
    return poison;
}

 void instantiate()
        {
        /* routine to instantiate a variable (variable) if it isn't already.  the
        instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
        variable list (varlt) contains the variable (variable). */
       int i=1;
        /* find variable in the list */

       // cout<< "(strcmp(varble, varlt[i]) is "<<(strcmp(varble, varlt[i]));
        while((strcmpi(variable, varlt[i]) != 0) && (i<28)) i=i+1;

        if((strcmpi(variable, varlt[i]) == 0) && (instlt[i] != 1))
                /*found variable and not already instantiated */
        {
               // cout<<"==========i value is \n"<<i;
                instlt[i]=1; /*mark instantiated */
                /* the designer of the
               knowledge base places the input statements to
               instantiate the variables below in the case statement */
        switch (i)
                {
                        /***** input statement *****/
                        /* input statements for sample position knowledge
                           base */
                           /***** comment 1700 ******/
                case 1: cout << "Does Patient had any TOXIC SUBSTANCE intentionally? Enter Yes or No. : ";
                        cin >> TOXIC_SUBSTANCE;
                       break;
                case 2: cout <<"Does Patient suffering from SEVERE HEADACHE? Enter Yes or No. : ";
                        cin >> SEV_HEADACHE;
                       break;
                 case 3: cout <<"Does Patient suffering from BURNING PAIN IN STOMACH? Enter Yes or No. :  ";
                        cin >> BUR_PAIN_IN_STOMACH;
                       break;
                case 4: cout <<"Does Patient suffering from STOMACH CRAMPS? Enter Yes or No. :  ";
                        cin >> STOMACH_CRAMPS;
                       break;
                case 5: cout <<"Does Patient experienced SALIVATION? Enter Yes or No. : ";
                        cin >> SALIVATION;
                        break;
                case 6: cout <<"Does Patient experienced VOMITING? Enter Yes or No. :  ";
                        cin >> VOMITING;
                        break;
                case 7: cout <<"Does Patient has MUSCLE TWITCHING? Enter Yes or No. :  ";
                        cin >> MUSCLE_TWITCHING;
                       break;
                case 8: cout <<"Does Patient has experienced BLOOD in VOMITING? Enter Yes or No. :  ";
                        cin >> BLOOD_VOMITING;
                        break;
                case 9: cout <<"Does Patient has any DIFFICULTY in BREATHING? Enter Yes or No. :  ";
                        cin >> DIFFICULT_IN_BREATHING;
                        break;
                case 10: cout <<"Does Patient has experienced SEISURE? Enter Yes or No. :  ";
                        cin >> SEIZURE;
                       break;
                case 11: cout <<"Does Patient has FLUID BUILDING in LUNGS? Enter Yes or No. :  ";
                        cin >> FLUID_BUILDING_IN_LUNGS;
                        break;
                case 12: cout <<"Does Patient has experienced SUDDEN UNCONSCIOUS? Enter Yes or No. :  ";
                        cin >> SUDDEN_UNCONSCIOUS;
                        break;
                case 13: cout <<"Does Patient has SEVERE ABDOMINAL PAIN? Enter Yes or No. :  ";
                        cin >> SEVERE_ABDOMINAL_PAIN;
                        break;
                case 14: cout <<"Does Patient has experienced DIZZINESS? Enter Yes or No. :  ";
                        cin >> DIZZINESS;
                        break;
                case 15: cout <<"Does Patient has experienced DESTRUCTION of RBC? Enter Yes or No. :  ";
                        cin >> DESTRUCTION_OF_RBC;
                        break;
               // case 16: cout <<"Does Patient has experienced INTESTINAL_BLEEDING? Enter Yes or No. :  ";
                //        cin >> INTESTINAL_BLEEDING;
                //        break;
                case 16: cout <<"Does Patient has eaten any NEW FOOD? Enter Yes or No. :  ";
                        cin >> NEW_FOOD;
                        break;
                case 17: cout <<"Does Patient has eaten FISH? Enter Yes or No. :  ";
                        cin >> FISH;
                        break;
                case 18: cout <<"Does Patient has SEVERE FLANK PAIN? Enter Yes or No. :  ";
                        cin >> SEVERE_FLANK_PAIN;
                        break;
                case 19: cout <<"Does Patient has eaten MUSHROOM? Enter Yes or No. :  ";
                        cin >> MUSHROOM;
                        break;
                case 20: cout <<"Does Patient has SEVERE FLU? Enter Yes or No. :  ";
                        cin >> SEVERE_FLU;
                        break;
                case 21: cout << "Does Patient do LANDSCAPPING? Enter Yes or No. :  ";
                        cin >> LANDSCAPPING;
                        break;
                case 22: cout <<"Does Patient has any SKIN DISCOLORATION? Enter Yes or No. :  ";
                        cin >> SKIN_DISCOLORATION;
                        break;
                case 23: cout <<"Does Patient has any ECESSIVE SALIVATION? Enter Yes or No. :  ";
                        cin >> ECESSIVE_SALIVATION;
                        break;
                case 24: cout <<"Does Patient has experienced FAINT? Enter Yes or No. :  ";
                        cin >> FAINT;
                        break;
                        /***** comment 1715 ****/
                }
        /* end of inputs statements for sample position knowledge
                   base */
        }
        }

        void push_on_stack()
        {
          // cout<<"inside push_on_stack";
            sp=sp-1;
            statsk[sp]=sn;
            clausk[sp]=1;
        }


void determine_member_concl_list() {
        /* routine to determine if a variable (variable) is a member of the
           conclusion list (conclt).  if yes return sn != 0.
           if not a member sn=0;
        */
                /* initially set to not a member */
              // cout<<"inside determine member conclusion list";
               sn = 0;
                /* member of conclusion list to be searched is f */
                i = f;
                while((strcmpi(variable, conclt[i]) != 0) && (i<38))
                        /* test for membership */
                        i=i+1;
                if (strcmpi(variable, conclt[i]) == 0)
                    sn = i;  /* a member */
               // else
                   // cout<<"not a conclusion"<<conclt;
                //cout<<"i value" <<" " << i << endl;
        }

string backward_chaining(){

        do
        {
        conclusion_push = false;
        f=1;

        if(stack_not_empty == false)
          determine_member_concl_list();

          //cout<<"sn" << sn << endl;

          if (sn != 0)
          {
                  /* if sn = 0 then no conclusion of that name */
                  /* push statement number (sn) and clause number=1 on goal
                     stack which is composed of the statement stack
                     (statsk) and clause stack (clausk) */
                  do
                  {
                        if ( stack_not_empty == false )
                          push_on_stack();

                         // cout<<"inside backward chaining one";
                            int var_clvarlt_size=1;
                          do
                          {
                               //  cout<<"inside backward chaining two";
                           /* calculate clause location in clause-variable list */

                            i= (statsk[sp] -1) * 8 + clausk[sp];
                           // cout<<"i value statsk[sp] -1) *8 + clausk[sp]" << i << endl;

                            stack_not_empty = false;
                            /* clause variable */
                          //  cout<<"\nclvarlt[i]++++++++++++++++++++\n"<<clvarlt[i];
                            strcpy(variable, clvarlt[i]);
                            //cout<<"var_clvarlt_size\n"<<var_clvarlt_size<<"\n";
                                if( strcmp(variable, "") != 0)
                                {
                                    /*is this clause variable a conclusion? */
                                    f = 1;

                                    determine_member_concl_list();

                                    if(sn != 0 ){
                                    /* it is a conclusion push it */
                                    conclusion_push = true;
                                  //  cout<<"\nset conclusion_push\n";
                                    break;
                                    }
                                    //else/* check instantiation of this clause */
                                    instantiate();
                                   // cout<<"\nclausk\n"<<clausk[sp];
                                clausk[sp] = clausk[sp] + 1;
                                var_clvarlt_size++;
                                }
                          } while(strcmp(variable, "") != 0 ); /*do-while*/
                         //while(sn!=0);
                          /*no more clauses check if part of statement */

                          if( conclusion_push == true)
                          {
                          // cout<<"\n*******\n";
                              break;
                          }
                            /*No more clauses check if part of statement */
                         // cout<<"sp and statsk[sp]"<<sp<<statsk[sp];
                          sn = statsk[sp];
                           //  cout<<"&&&&&&&&&&&&&&&&&&& sn"<<sn;
                          s = 0;
                          /**** if then statements ****/
                          /* sample if parts of if then statements from
                             the position knowledge base */
switch (sn)
                          {
                                  /********* comment 1680 ******/

                           case 1: if(strcmp(TOXIC_SUBSTANCE, "YES") == 0 &&
                                    (strcmp(SEV_HEADACHE, "YES") == 0))
                                    s = 1;
                                    break;
                            case 2: if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "YES") == 0) &&
                                    (strcmp(STOMACH_CRAMPS, "YES") == 0))
                                    s = 1;
                                    break;
                            case 3: if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "YES") == 0) &&
                                    (strcmp(STOMACH_CRAMPS, "NO") == 0))
                                    s = 1;
                                    break;
                            case 4:  if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "NO") == 0) &&
                                    (strcmp(SALIVATION, "YES") == 0))
                                    s = 1;
                                    break;
                            case 5: if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "NO") == 0) &&
                                    (strcmp(SALIVATION, "NO") == 0) &&
                                    (strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(MUSCLE_TWITCHING, "YES") == 0) &&
                                    (strcmp(BLOOD_VOMITING, "YES") == 0))
                                    s = 1;
                                    break;
                            case 6: if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "NO") == 0) &&
                                    (strcmp(SALIVATION, "NO") == 0) &&
                                    (strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(MUSCLE_TWITCHING, "NO") == 0) &&
                                    (strcmp(DIFFICULT_IN_BREATHING, "YES") == 0))
                                    s = 1;
                                    break;
                            case 7: if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "NO") == 0) &&
                                    (strcmp(SALIVATION, "NO") == 0) &&
                                    (strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(MUSCLE_TWITCHING, "YES") == 0) &&
                                    (strcmp(BLOOD_VOMITING, "NO") == 0))
                                    s = 1;
                                    break;
                            case 8: if((strcmp(TOXIC_SUBSTANCE , "YES") == 0) &&
                                    (strcmp(SEV_HEADACHE, "NO") == 0) &&
                                    (strcmp(BUR_PAIN_IN_STOMACH, "NO") == 0) &&
                                    (strcmp(SALIVATION, "NO") == 0) &&
                                    (strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(MUSCLE_TWITCHING, "NO") == 0) &&
                                    (strcmp(DIFFICULT_IN_BREATHING, "NO") == 0))
                                    s = 1;
                                    break;
                            case 9: if((strcmp(SEIZURE, "YES") == 0) &&
                                    (strcmp(FLUID_BUILDING_IN_LUNGS, "YES") == 0))
                                    s = 1;
                                    break;
                            case 10: if((strcmp(SEIZURE, "YES") == 0) &&
                                    (strcmp(FLUID_BUILDING_IN_LUNGS, "NO") == 0))
                                    s = 1;
                                    break;
                            /*case 9: if((INHALE_HARMFUL_GAS , "YES") == 0 &&
                                    (strcmp(SEIZURE, "YES") == 0))
                                    s = 1;
                                    break;
                            case 10: if((INHALE_HARMFUL_GAS , "YES") == 0 &&
                                    (strcmp(SEIZURE, "NO") == 0))
                                    s = 1;
                                    break;*/
                                    //(strcmp(FLUID_BUILDING_IN_LUNGS, "YES") == 0))
                            /*case 10: if((strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(MUSCLE_TWITCHING, "YES") == 0) &&
                                    (strcmp(BLOOD_VOMITING, "YES") == 0))
                                    s = 1;
                                    break;*/
                            case 11: if((strcmp(SEIZURE, "YES") == 0) &&
                                    (strcmp(FLUID_BUILDING_IN_LUNGS, "YES") == 0))
                                    s = 1;
                                    break;
                            case 12: if((strcmp(SEIZURE, "YES") == 0) &&
                                    (strcmp(FLUID_BUILDING_IN_LUNGS, "NO") == 0))
                                    s = 1;
                                    break;
                            case 13: if((strcmp(SEIZURE, "NO") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "YES") == 0))
                                    s = 1;
                                    break;
                           /* case 14: if((strcmp(SEIZURE, "NO") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "NO") == 0))
                                    s = 1;
                                    break;*/
                          /* case 15: if((strcmp(SEIZURE, "YES") == 0))
                                    s = 1;
                                    break;*/
                          /* case 15: if((strcmp(SEIZURE, "NO") == 0))
                                    s = 1;
                                    break;
                           case 16: if((strcmp(SEIZURE, "YES") == 0) &&
                                    (strcmp(FLUID_BUILDING_IN_LUNGS, "YES") == 0))
                                    s = 1;
                                    break;
                           case 17: if((strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(FLUID_BUILDING_IN_LUNGS, "NO") == 0))
                                    s = 1;
                                    break;
                           case 18: if((strcmp(SEIZURE, "YES") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "YES") == 0))
                                    s = 1;
                                    break;
                           case 19: if((strcmp(VOMITING, "YES") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "NO") == 0))
                                    s = 1;
                                    break;*/
                           case 14: if((strcmp(SEIZURE, "NO") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "NO") == 0) &&
                                    (strcmp(SEVERE_ABDOMINAL_PAIN, "YES") == 0) &&
                                    (strcmp(DIZZINESS, "NO") == 0))
                                    s = 1;
                                    break;
                           case 15: if((strcmp(SEIZURE, "NO") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "NO") == 0) &&
                                    (strcmp(SEVERE_ABDOMINAL_PAIN, "YES") == 0) &&
                                    (strcmp(DIZZINESS, "YES") == 0) &&
                                    (strcmp(DESTRUCTION_OF_RBC, "YES") == 0))
                                    s = 1;
                                    break;
                           case 16:  if((strcmp(SEIZURE, "NO") == 0) &&
                                    (strcmp(SUDDEN_UNCONSCIOUS, "NO") == 0) &&
                                    (strcmp(SEVERE_ABDOMINAL_PAIN, "YES") == 0) &&
                                    (strcmp(DIZZINESS, "YES") == 0) &&
                                    (strcmp(DESTRUCTION_OF_RBC, "NO") == 0))
                                    s = 1;
                                    break;
                          /* case 17: if((strcmp(VOMITING, "NO") == 0) &&
                                    (strcmp(SEVERE_ABDOMINAL_PAIN, "NO") == 0) &&
                                    (strcmp(INTESTINAL_BLEEDING , "YES") == 0))
                                    s = 1;
                                    break;
                           case 18: if((strcmp(VOMITING, "NO") == 0) &&
                                    (strcmp(SEVERE_ABDOMINAL_PAIN, "NO") == 0) &&
                                    (strcmp(INTESTINAL_BLEEDING, "NO") == 0))
                                    s = 1;
                                    break;
                           case 19: if(strcmp(TOXIC_SUBSTANCE, "NO") == 0)
                                    s = 1;
                                    break;
                            case 20: if(strcmp(TOXIC_SUBSTANCE, "NO") == 0)
                                    s = 1;
                                    break;*/
                           case 17: if((strcmp(NEW_FOOD, "YES") == 0) &&
                                    (strcmp(FISH, "YES") == 0) &&
                                    (strcmp(SEVERE_FLANK_PAIN , "YES") == 0))
                                    s = 1;
                                    break;
                           case 18: if((strcmp(NEW_FOOD, "YES") == 0) &&
                                    (strcmp(FISH, "YES") == 0) &&
                                    (strcmp(SEVERE_FLANK_PAIN , "NO") == 0))
                                    s = 1;
                                    break;
                           case 19: if((strcmp(NEW_FOOD, "YES") == 0) &&
                                    (strcmp(FISH, "NO") == 0))
                                    s = 1;
                                    break;
                           case 20: if((strcmp(NEW_FOOD, "NO") == 0) &&
                                    (strcmp(MUSHROOM, "YES") == 0) &&
                                    (strcmp(SEVERE_FLU, "YES") == 0))
                                    s = 1;
                                    break;
                           case 21: if((strcmp(NEW_FOOD, "NO") == 0) &&
                                    (strcmp(MUSHROOM, "YES") == 0) &&
                                    (strcmp(SEVERE_FLU, "NO") == 0))
                                    s = 1;
                                    break;
                           case 22: if((strcmp(NEW_FOOD, "NO") == 0) &&
                                    (strcmp(MUSHROOM, "NO") == 0) &&
                                    (strcmp(LANDSCAPPING, "YES") == 0) &&
                                    (strcmp(SKIN_DISCOLORATION, "YES") == 0) &&
                                    (strcmp(ECESSIVE_SALIVATION, "YES") == 0))
                                    s = 1;
                                    break;
                           case 23: if((strcmp(FAINT, "YES") == 0))
                                    s = 1;
                                    break;
                           case 24: if((strcmp(FAINT, "NO") == 0))
                                    s = 1;
                                    break;
                           case 25: if((strcmp(NEW_FOOD, "NO") == 0) &&
                                    (strcmp(MUSHROOM, "NO") == 0) &&
                                    (strcmp(LANDSCAPPING, "YES") == 0) &&
                                    (strcmp(SKIN_DISCOLORATION, "YES") == 0) &&
                                    (strcmp(ECESSIVE_SALIVATION, "NO") == 0))
                                    s = 1;
                                    break;
                           case 26: if((strcmp(NEW_FOOD, "NO") == 0) &&
                                    (strcmp(MUSHROOM, "NO") == 0) &&
                                    (strcmp(LANDSCAPPING, "YES") == 0) &&
                                    (strcmp(SKIN_DISCOLORATION, "NO") == 0))
                                    s = 1;
                                    break;
                          case 27: if((strcmp(NEW_FOOD, "NO") == 0) &&
                                    (strcmp(MUSHROOM, "NO") == 0) &&
                                    (strcmp(LANDSCAPPING, "NO") == 0))
                                    s = 1;
                                    break;

                          }
                          /* see if the then part should be invoked */
                          if( s != 1)
                            {

                                  /* get conclusion */
                                  i = statsk[sp];
                                  strcpy(variable, conclt[i]);
                                  /* search for conclusion starting at the
                                     next statement number */
                                  f = statsk[sp] + 1;
                                  determine_member_concl_list();
                                  sp = sp+1;
                          }
                          /* pop old conclusion and put on new one */
                  } while((s != 1) && (sn !=0));  /* outer do-while loop */
                   // cout<<"conclusion_push" << conclusion_push << endl;
                  if(conclusion_push != true)
                  {

                  if(sn != 0)
                    {
                          //cout<<"!!!!!!!!!!!!!!!!!";/* if part true invoke then part */
                          /* then part of if-then statements from the
                             position knowledge base */
                          switch (sn)
                           {

                        case 1: strcpy(POISON, "YES");
                              cout << endl << "Patient have consumed Carbamates Chemical Poison. \n" << endl;
                              break;
                                /* then part of statement 2 */
                        case 2: strcpy(POISON, "YES");
                              cout<< endl << "Patient have Organo Chlorine Chemical Poison  \n" << endl;
                              break;
                              /* then part of statement 3 */
                        case 3: strcpy(POISON, "NO");
                              cout<< endl << "Patient have not consumed any Poison. \n" << endl;
                              break;
                              /* then part of statement 4 */
                       /* case 4: strcpy(POISON, "YES");
                              cout<< endl << "Patient have consumed Zinc Phosphide Chemical Poison. \n" << endl;
                              break;*/
                        case 4: strcpy(POISON, "YES");
                              cout<< endl << "Patient have consumed Zinc phosphide chemical Poison. \n" << endl;
                              break;
                              /* then part of statement 5 */
                        case 5: strcpy(POISON, "YES");
                              cout << endl << "Patient is exposed to Nitrogen Oxide Chemical Poison \n" << endl;
                              break;
                              /* then part of statement 6 */
                        case 6: strcpy(INHALE_HARMFUL_GAS, "YES");
                              cout << endl << "Patient might have Inhaled Harmful Gas.\n" << endl;
                              break;
                              /* then part of statement 7 */
                        case 7: strcpy(POISON, "NO");
                              cout<< endl << " Patient have not consumed any Poison.\n" << endl;
                              break;
                              /* then part of statement 8 */
                        case 8: strcpy(POISON, "NO");
                              cout << endl << "Patient have not consumed any Poison.\n" << endl;
                              break;
                              /* then part of statement 9 */
                        case 9: strcpy(POISON, "YES");
                              cout << endl << "Patient have Inhaled Cyanide Poison. \n" << endl;
                              break;
                              /* then part of statement 10 */
                        case 10: strcpy(POISON, "NO");
                              cout<< endl << "Patient have not consumed any Poison \n" << endl;
                              break;
                              /* then part of statement 11 */
                        case 11: strcpy(POISON, "YES");
                              cout << endl << "Patient have Inhaled Ricin Poison. \n" << endl;
                              break;
                              /* then part of statement 12 */
                        case 12: strcpy(POISON, "NO");
                              cout << endl << "Patient have not consumed any Poison \n" << endl;
                              break;
                              /* then part of statement 13 */
                        case 13: strcpy(POISON, "YES");
                              cout << endl << "Patient have Inhaled Nerve Gas Poison. \n" << endl;
                              break;
                              /* then part of statement 14 */
                        case 14: strcpy(POISON, "NO");
                              cout << endl << "Patient have not consumed any Poison \n" << endl;
                              break;
                              /* then part of statement 15 */
                        case 15: strcpy(POISON, "YES");
                              cout << endl << "Patient have  consumed Arsenic Poison. \n" << endl;
                              break;
                              /* then part of statement 16 */
                        case 16: strcpy(FOOD_POISON, "YES");
                              cout << endl << "Patient might be suffering from Food Poison. \n" << endl;
                              break;
                        case 17: strcpy(POISON, "YES");
                              cout << endl << "Patient have eaten Fish and that led to Mercury Poison. \n" << endl;
                              break;
                              /* then part of statement 25 */
                        case 18: strcpy(POISON, "NO");
                              cout << endl << "poisoning is not due to fish, No Poison. \n" << endl;
                              break;
                        case 19: strcpy(POISON, "NO");
                              cout << endl << "Patient have not eaten any food so, No Poison. \n" << endl;
                              break;
                        case 20: strcpy(POISON, "YES");
                              cout << endl << "Patient have eaten Poisonous Mushroom and that led to Amotoxin Poison. \n" << endl;
                              break;
                              /* then part of statement 25 */
                        case 21: strcpy(POISON, "NO");
                              cout << endl << "Patient have eaten Non-Poisonous Mushroom so, No Poison. \n" << endl;
                              break;
                        case 22: strcpy(SNAKE_BITE, "YES");
                              cout << endl << "Patient do landscaping work," << endl;
                              cout << endl << "excessive salivation and skin discoloration might be because of Sanke Bite. \n" << endl;
                              break;
                        case 23: strcpy(POISON, "YES");
                              cout << endl << "Patient was bitten by a Poisonous Snake. \n" << endl;
                              break;
                        case 24: strcpy(POISON, "NO");
                              cout << endl << "Patient was bitten by a Non-Poisonous Snake. \n" << endl;
                              break;
                              /* then part of statement 25 */
                        case 25: strcpy(POISON, "YES");
                              cout << endl << "Patient do landscaping work, \n" << endl;
                              cout << endl << "skin discoloration might be because of Scorpion Bite. \n" << endl;
                              break;
                        case 26: strcpy(POISON, "NO");
                              cout << endl << "Patient is just having a noraml Itchy Rash due to poison, so No Poison. \n" << endl;
                              break;
                        case 27: strcpy(POISON, "NO");
                              cout << endl << "Patient did some landscaping work and the Itchy Rash is noraml so, No Poison. \n" << endl;
                              break;

                        }

                          /* pop the stack */
                         // cout<<"\nsn\n"<<sn<<"\n";
                          sp=sp+1;
                          //cout<<"\n000sp value"<<sp<<"\n";

                          if(sp >= 41)
                            {
                                  /* finished */
                                 // cout<<"*** SUCCESS\n";
                                  stack_not_empty=false;
                                  conclusion_push=false;
                          }
                          else
                            {
                                  /* stack is not empty */
                                  /* get next clause then continue */
                                  clausk[sp] = clausk[sp]+1;
                                  //goto b545;
                                  stack_not_empty=true;
                                  conclusion_push=true;
                          }
                  }
        }
    }
}while(conclusion_push == true);
return conclusions[sn];
}

void disp_concl_list1()
{
 cout << "*** DIAGNOSIS CONCLUSION LIST ***" << endl;
        for (i=1; i<38; i++)
            cout <<i<<" " <<conclt[i] << endl;

        cout << "HIT RETURN TO CONTINUE" << endl;
        getchar();
        cout << endl;
}

void disp_clvar_list1()
{
  cout << "*** DIAGNOSIS CLAUSE-VARIABLE LIST ***" << endl;
  for(i=1; i<38; i++)
        {
                cout << "** CLAUSE"<< " "<< i<< endl;
                for(j=1; j<7; j++)
                {
                    k = 6 * (i-1) + j;
                  cout << "VARIABLE "<< j<<  " " << clvarlt[k]<< endl;
                }
                if (i==6)
                {
                    cout << "HIT RETURN KEY TO CONTINUE" <<endl;
                    getchar();
                    cout<<endl;
                }
        }
}

void disp_var_list1()
{
    cout << "DIAGNOSIS VARIABLE LIST" << endl;
     for(i=1; i<28; i++)
        {cout << i << " " << varlt[i] << endl;}
        printf("HIT RETURN KEY TO CONTINUE");
        getchar();
        cout << endl;
}








#endif // DIAGNOSIS_H
