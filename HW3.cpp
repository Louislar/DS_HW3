#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

using namespace std;

class team
{
    public:
        team()
        {
            elementNum=0;
            for(int i=0;i<1000;i++)
            {
            	element[i]=0;
			}
        }
        int element[1000];
        int elementNum;//How many element are in each team
};

main()
{
    //input file
    ifstream ifs;
    string str;
    cout<<"Input file name: ";
    cin>>str;
    char* cstr=new char [str.length()+1];
    strcpy(cstr, str.c_str());
    ifs.open(cstr, ios::in);
    
    int queue[100];
    for(int i=0;i<100;i++)
    {
    	queue[i]=0;
	}
    int queueLength=0;
    int k=0;
    
    //input
    while(1){
    	team* teams=new team[1000];//what's the different between
                               //1. team queue[1000]
                               //2. team* queue=new team[1000]
                               //heap? stack? what's the different
                               //https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array
    	
    	int output[100];
    	for(int i=0;i<100;i++)
    	{
    		output[i]=0;
		}
    	int outputLength=0;
        //Input teams
        int teamNum;
        ifs>>teamNum;
        if(teamNum==0)
        {
			break;
        }
        for(int i=0;i<teamNum;i++)
        {
            ifs>>teams[i].elementNum;
            for(int j=0;j<teams[i].elementNum;j++)
            {
                ifs>>teams[i].element[j];
            }
        }
			
        //Enqueue or Dequeue
        string str1;
        while(ifs>>str1)
        {
        	//cout<<"str1: "<<str1<<endl;
            if(str1.compare(0, 1, "S")==0)
                break;

            //Enqueue
            if(str1.compare(0, 1, "E")==0)
            {
            	//check
            	if(queueLength==100)
            	{
            		cout<<"Queue is full";
				}
            	
            	//start
                int enqueueNum;
                int enqueueNumTeamIndex;
                ifs>>enqueueNum;
                
                //find which team enqueueNum is in
                for(int i=0;i<teamNum;i++)
                {
                	int temp=0;
                	for(int j=0;j<teams[i].elementNum;j++)
                	{
                		if(teams[i].element[j]==enqueueNum)
                		{
                			enqueueNumTeamIndex=i;
                			temp=1;
                			break;
						}
					}
					if(temp) break;
				}
				
				// find if there are any number in queue
				// which is in the same team whith enqueueNum
				int sameTeamNumIndex=-1;
				for(int i=queueLength-1;i>=0;i--)
				{
					int temp=0;
					for(int j=0;j<teams[enqueueNumTeamIndex].elementNum;j++)
					{
						if(teams[enqueueNumTeamIndex].element[j]==queue[i])
						{
							sameTeamNumIndex=i;
							temp=1;
							/*cout<<"EnqueueNum: "<<enqueueNum<<endl;
							cout<<"Find sameNum: "<<queue[sameTeamNumIndex]<<endl;
							cout<<"Find sameTeamNumIndex: "<<sameTeamNumIndex<<endl;*/
						}
					}
					if(temp) break;
				}
				
				//execute
				if(sameTeamNumIndex!=-1)
				{
					if(sameTeamNumIndex+1==queueLength)
					{
						queue[sameTeamNumIndex+1]=enqueueNum;
					}
					else
					{
						//all the element after sameTeamNumIndex
						// need to be moved backward one index
						for(int i=queueLength;i>sameTeamNumIndex;i--)
						{
							queue[i]=queue[i-1];
						}
						//move enqueueNum in queue
						queue[sameTeamNumIndex+1]=enqueueNum; 
					}
					queueLength++;
				}
				else
				{
					queue[queueLength]=enqueueNum;
					queueLength++;
				}

            }
            
            //Dequeue
            if(str1.compare(0, 1, "D")==0)
            {
            	if(queueLength==0)
				{
					cout<<"No element in queue";
					break;
				}
				output[outputLength]=queue[0];
				for(int i=0;i<queueLength-1;i++)
				{
					queue[i]=queue[i+1];
				}
				queueLength--;
				outputLength++;
			}
			
			//test
			/*cout<<"queue statment: "<<endl;
			for(int i=0;i<queueLength;i++)
			{
				cout<<queue[i]<<" ";
			}
			cout<<endl;
			cout<<"Test ouput :"<<endl;
			for(int i=0;i<outputLength;i++)
        	{
        		cout<<output[i]<<" ";
			}
			cout<<endl<<endl;*/

        }//end enqueue or dequeue while
        
        //output
        cout<<"Scenario #"<<++k<<endl;
        for(int i=0;i<outputLength;i++)
        {
        	cout<<output[i]<<endl;
		}
		
		//initial
		for(int i=0;i<100;i++)
    	{
    		queue[i]=0;
		}
    	queueLength=0;
    }// end while
	


}
