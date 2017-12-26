#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

class chainNode
{
public:
    chainNode(){}
    chainNode(int e, chainNode* l=0)
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
    cout<<"Input file name: ";
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



    member* teams=new member[1000];

    int t=0;
    int scenarioCount=0;

    while(ifs>>t)
    {
        if(t==0) break;
        scenarioCount++;
        cout<<"Scenario #"<<scenarioCount<<endl;
        //The queue
        chainNode* queue=0;

        if(t!=0)
        {
            for(int q=0;q<t;q++)
            {
                int teamNum;
                ifs>>teamNum;

                for(int l=0;l<teamNum;l++)
                {
                    int temp;
                    ifs>>temp;
                    teams[q].m[teams[q].mLength]=temp;
                    teams[q].mLength++;
                }
            }
        }

        for(int q=0;q<t;q++)
        {
            cout<<"Team "<<q<<": "<<endl;
            for(int i=0;i<teams[q].mLength;i++)
                cout<<teams[q].m[i]<<endl;
            cout<<endl;
        }



        /**********enqueue & dequeue***************/
        string str1;
        while(ifs>>str1)
        {
            if(str1.compare(0, 1, "S")==0) break;
            else if(str1.compare(0, 1, "E")==0)
            {
                //cout<<"ENQUEUE ";
                int enqueueNumber;
                ifs>>enqueueNumber;
                //cout<<enqueueNumber;

                //find which team includes the number
                int enqueueNumberTeamIndex=0;
                for(int o=0;o<t;o++)
                {
                    for(int u=0;u<teams[o].mLength;u++)
                    {
                        if(teams[o].m[u]==enqueueNumber)
                            enqueueNumberTeamIndex=o;
                    }
                }

                /***********start here***********/

                //find is there any number in queue is same team as enqueue number
                int findSameTeam=0;
                chainNode* cur=queue;
                chainNode* sameTeamNum=0;
                for(;cur;cur=cur->link)
                {
                    for(int l=0;l<teams[enqueueNumberTeamIndex].mLength;l++)
                    {
                        if(cur->data==teams[enqueueNumberTeamIndex].m[l])
                        {
                            sameTeamNum=cur;
                            findSameTeam=1;
                        }
                    }
                }



                /*if(findSameTeam){
                cout<<" "<<sameTeamNum->data<<endl;
                }
                else {cout<<endl;}*/



                //whether find a same team number or not
                if(findSameTeam)
                {
                    chainNode* temp=sameTeamNum->link;
                    sameTeamNum->link=new chainNode(enqueueNumber, temp);
                }
                else
                {
                    if(queue==0) queue=new chainNode(enqueueNumber, 0);
                    else
                    {
                        for(cur=queue;cur->link;cur=cur->link) ;
                        cur->link=new chainNode(enqueueNumber, 0);
                    }
                }



            }
            else if(str1.compare(0, 1, "D")==0)
            {
                //cout<<"DEQUEUE"<<endl;
                chainNode* deleteNode=queue;
                queue=queue->link;
                cout<<deleteNode->data<<endl;
                delete deleteNode;



            }
        }

        /*************queue output*****************/
        /*chainNode* out=queue;
        for(;out;out=out->link)
            cout<<out->data<<" ";*/
    }// t while end

}
