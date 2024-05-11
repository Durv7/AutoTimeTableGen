#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Subject{
    public:
        int credits;
        string name;
};

class Division{
    string tt[6][5];
    Subject s[11];
    string days[6]= {"          ","Tues","Wed","Thurs","Fri","Sat"};
    string slots[6]={"9:30-10:30","10:30-11:30","11:45-12:45","12:45-1:45","2:45-3:45","3:45-4:45"};
    public:
        void subjectEntries()
        {
            for(int i=0;i<11;i++)
            {
                cout<<"Enter Subject Name:";
                cin>>s[i].name;
                cout<<"Enter Credits Of "<<s[i].name<<" :";
                cin>>s[i].credits;
            }
        }
        void initilizeTT()
        {
            for(int i=0;i<6;i++)
            {
                for(int j=0;j<5;j++)
                {
                    tt[i][j]="-1";
                }
            }
        }

        void displaySubjectList()
        {
            for(int i=0;i<11;i++)
            {
                cout<<i<<" "<<s[i].name<<":"<<s[i].credits<<endl;
            }
        }
        void display()
        {
            for(int i=0;i<6;i++)
            {
                cout<<days[i]<<"\t";
            }
            cout<<endl;
            for(int i=0;i<6;i++)
            {
                int k=0;
                cout<<slots[k]<<"\t";
                for(int j=0;j<5;j++)
                {
                    cout<<tt[i][j]<<"\t";
                }
                cout<<endl;
            }
        }

        void fixedSlots()
        {
            cout<<endl<<endl;
            cout<<"Enter your fixed slots>>>"<<endl;
            int slot1=4,slot2=5;
            bool more;
            displaySubjectList();
            bool y=true;
            int subIndex;
            int flag=0;  
            while(y)
            { 
                srand(time(0));
                int day=rand()%4;
                cout<<"Enter Subject Number From Above List:";
                // cin.ignore();
                cin>>subIndex;
                while(flag==0)
                {   

                    if(tt[slot1][day]=="-1" && tt[slot2][day]=="-1")
                    {
                        tt[slot1][day]=s[subIndex].name;
                        tt[slot2][day]=s[subIndex].name;
                        flag=1;
                    }
                    else{
                        srand(time(0));
                        int day=rand()%4;
                        flag=0;
                    }

                }
                cout<<"Do You Want To Add More Slots???(1 for Yes)";
                cin>>more;
                if(more)
                {
                    srand(time(0));
                    int day=rand()%4;
                    flag=0;
                }
                else{
                    y=false;
                }
            }

            // cout<<day<<endl;


        }

};

int main()
{
    Division B;
    B.initilizeTT();
    B.display();
    B.subjectEntries();
    //B.displaySubjectList();
    B.fixedSlots();
    B.display();
}