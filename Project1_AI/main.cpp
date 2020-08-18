
#include "Diagnosis.h"
#include "Treatment.h"


int main()
{
    int choice;
    string p;

    do {
    cout<<"*********************************************************************************"<<endl;
    cout<<endl;
    cout<<"                    HOSPITAL EMERGENCY ROOM - EXPERT SYSTEM                      "<<endl;
    cout<<"                       ALPHA VERSION - INFERENCE ENGINE                          "<<endl;
    cout<<endl;

    cout<<"*********************************************************************************"<<endl;

    cout<<endl;
    cout<<"                                  MAIN MENU  "<<endl;
    cout<<endl<<"*********************************************************************************";
	cout<<endl<<"1.Diagnosis of Poison based on symptoms.(Using Backward Chaining)";
	cout<<endl<<"2.Treatment for the poison detected.(Forward chaining)";
	cout<<endl<<endl<<"3.Display the variable list for Diagnosis.";
	cout<<endl<<"4.Display the clause-variable list for Diagnosis.";
	cout<<endl<<"5.Display the conclusion list for Diagnosis.";
	cout<<endl<<"6.Display the variable list for Treatment.";
	cout<<endl<<"7.Display the clause-variable list for Treatment.";
	cout<<endl<<"8.Display the conclusion list for Treatment.";
	cout<<endl<<"9.EXIT.";
	cout<<endl<<"Choose an option from the menu above:";

	cin>>choice;

	switch(choice)
	{
	case 1: p=diagnosis();
		    break;
	case 2: treatment(p);
		    break;
	case 3: disp_var_list1();
		    break;
	case 4: disp_clvar_list1();
		    break;
	case 5: disp_concl_list1();
			break;
	case 6: disp_var_list2();
		    break;
	case 7: disp_clvar_list2();
			break;
	case 8: disp_concl_list2();
			break;
	case 9: exit(0);
            break;
    default: cout<<" Please select a valid choice!"<<endl;
             break;

	  }
  getch();

	}while(choice!=9);


 return 0;

}
