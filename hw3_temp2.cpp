#include<iostream>
#include<fstream>

using namespace std;

class chainNode
{
public:
    chainNode(){data=0;link=0;}
    chainNode(int e, chainNode* l)
    {
        data=e;
        link=l;
    }
    int data;
    chainNode* link;
};

class member
{
public:
    member()
    {
        for(int i=0;i<1000;i++) m[i]=0;
        mLength=0;
    }
    int m[1000];
    int mLength;
};

int main()
{
    //file input
    cout<<"Input filename: ";
    ifstream ifs;
    char filename[100];
    int filenameLength=0;
    for(int i=0;i<100;i++) filename[i]='\0';
    {
        char temp;
        while(cin.get(temp))
        {
            if(temp=='\n') break;
            else
            {
                filename[filenameLength]=temp;
                filenameLength++;
            }
        }
    }
    ifs.open(filename, ios::in);




    int howManyTeams;
    int scenarioCount=1;
    while(ifs>>howManyTeams)
    {
        member* teams=new member[1000];
        chainNode* queue=0;
        if(howManyTeams==0) break;
        for(int q=0;q<howManyTeams;q++)
        {
            int teamElemantNum;
            ifs>>teamElemantNum;
            for(int w=0;w<teamElemantNum;w++)
            {
                int element;
                ifs>>element;
                teams[q].m[teams[q].mLength]=element;
                teams[q].mLength++;

            }
        }
        for(int q=0;q<howManyTeams;q++)
        {
            for(int i=0;i<teams[q].mLength;i++)
                cout<<teams[q].m[i]<<" ";
            cout<<endl;
        }

        string str1;
        chainNode* out=0;
        while(ifs>>str1)
        {
            if(str1[0]=='S') break;

            //enqueue
            if(str1[0]=='E')
            {
                cout<<"ENQUEUE"<<endl;
                int enqueueNum;
                ifs>>enqueueNum;

                //find which team enqueueNumber is in
                int enqueueNumTeamIndex=-1;
                for(int w=0;w<howManyTeams;w++)
                {
                    for(int e=0;e<teams[w].mLength;e++)
                    {
                        if(teams[w].m[e]==enqueueNum)
                            enqueueNumTeamIndex=w;
                    }
                }

                cout<<"enqueueNumTeamIndex: "<<enqueueNumTeamIndex<<endl;

                //find if there is any same team number in queue
                chainNode* sameteamNum=0;
                if(enqueueNumTeamIndex>=0){
                    chainNode* cur=queue;
                    for(;cur;cur=cur->link)
                    {
                        for(int q=0;q<teams[enqueueNumTeamIndex].mLength;q++)
                        {
                            if(cur->data==teams[enqueueNumTeamIndex].m[q])
                                sameteamNum=cur;
                        }
                    }
                }

                if(sameteamNum==0) cout<<"No same team number"<<endl;
                //cout<<"sameteamNum: "<<sameteamNum->data<<endl;


                //execute
                {
                    chainNode* cur=queue;
                    if(!cur) queue=new chainNode(enqueueNum, 0);
                    else if(sameteamNum==0)
                    {
                        chainNode* cur=queue;
                        for(;cur->link;cur=cur->link);
                        cur->link=new chainNode(enqueueNum, 0);
                    }
                    else
                    {
                        chainNode* temp=sameteamNum->link;
                        sameteamNum->link=new chainNode(enqueueNum, temp);
                    }
                }
                chainNode* cur=queue;
                for(;cur;cur=cur->link) cout<<cur->data<<" ";
                cout<<endl;

            }//enqueue end


            //dequeue
            if(str1[0]=='D')
            {
                cout<<"DEQUEUE"<<endl;
                chainNode* curOut=queue;
                queue=queue->link;
                if(!out) out=new chainNode(curOut->data, 0);
                else
                {
                    chainNode* cur=out;
                    for(;cur->link;cur=cur->link);
                    cur->link=new chainNode(curOut->data, 0);

                }
                delete curOut;


            }//dequeue end
        }//str1 while end
        cout<<"Scenario #"<<scenarioCount<<endl;
        scenarioCount++;
        chainNode* cur=out;
        for(;cur;cur=cur->link) cout<<cur->data<<endl;


    }//howManyTeams while end


}
