#include<iostream>

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
    team* queue=new team[1000];//what's the different between
                               //1. team queue[1000]
                               //2. team* queue=new team[1000]
                               //heap? stack? what's the different
                               //https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array
    team* teamQueue=new team[];//undone
    //input
    while(1){
        int teamNum;
        cin>>teamNum;
        if(teamNum==0)
        {
			break;
        }
        for(int i=0;i<teamNum;i++)
        {
            cin>>queue[i].elementNum;
            for(int j=0;j<queue[i].elementNum;j++)
            {
                cin>>queue[i].element[j];
            }
        }

    }


}
