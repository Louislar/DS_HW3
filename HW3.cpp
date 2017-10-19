#include<iostream>
#include<istream>
#include<string>

using namespace std;

class team
{
    public:
        team()
        {
            elementNum=0;
        }
        int element[1000];
        int elementNum;//How many element are in each team
};

main()
{
    //input file
    /*ifstream ifs;
    string str;
    cout<<"Input file name: ";
    cin>>str;
    ifs.open(str, ios::in);*/
    team* teams=new team[1000];//what's the different between
                               //1. team queue[1000]
                               //2. team* queue=new team[1000]
                               //heap? stack? what's the different
                               //https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array
    int queue[100];//undone
    //input
    while(1){
        //Input teams
        int teamNum;
        cin>>teamNum;
        if(teamNum==0)
        {
			break;
        }
        for(int i=0;i<teamNum;i++)
        {
            cin>>teams[i].elementNum;
            for(int j=0;j<teams[i].elementNum;j++)
            {
                cin>>teams[i].element[j];
            }
        }

        //Enqueue or Dequeue
        string str1;
        while(cin>>str1)
        {
            if(str1.compare(0, 1, "S")==0)
                break;

            //Enqueue
            if(str1.compare(0, 1, "E")==0)
            {
                int enqueueNum;
                cin>>enqueueNum;

            }

        }

    }


}
