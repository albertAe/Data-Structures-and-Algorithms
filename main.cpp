/**
AUTHORS:
        Annor Yankyera Samuel(Say)   219IT01000163
        Collins Kweku Amewu          220EI01000506
        Albert Arhin Kow Bentum.     219CS01000169
**/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#define max 25



using namespace std;


                    struct file{
                         int all[10],maxx[10],need[10],flag;
                         };

                      void deadLock()
                           {

                             struct file f[10];
                             int fl;
                             int i,j,k,p,b,n,r,g,cnt=0,id,newr,numProcess;
                             int avail[10],seq[10];

                             cout<<"---------------\n";
                             cout<<" DEAD LOCK\n";
                             cout<<"---------------\n";

                             cout<<"\nEnter the number of processes--";
                             cin>>numProcess;

                             cout<<"\nEnter the number of resources--";
                             cin>>r;

                             for(i=0;i<numProcess;i++)
                             {
                                cout<<"\nEnter the details for the P"<<i<<" \n";
                                cout<<"\nEnter the allocation\t--\t";

                                for(j=0;j<r;j++)
                                cin>>f[i].all[j];

                                cout<<"\nEnter then Max\t\t--\t";

                                for(j=0;j<r;j++)
                                cin>>f[i].maxx[j];
                                f[i].flag=0;
                             }

                             cout<<"\nEnter Available Resources\t-\t";
                               for(i=0;i<r;i++)
                                  cin>>avail[i];

                               cout<<"Enter New Request Details--\n";
                               cout<<"Enter pid\t-\t";
                                 cin>>id;

                             cout<<"\nEnter Request for Resources\t-\t";
                               for(i=0;i<r;i++)
                               {
                                   cin>>newr;
                                   f[id].all[i]+=newr;
                                   avail[i]=avail[i]-newr;
                               }

                               for(i=0;i<numProcess;i++)
                               {
                                   for(j=0;j<r;j++)
                                   {
                                       f[i].need[j]=f[i].maxx[j]-f[i].all[j];
                                          if(f[i].need[j]<0)
                                            f[i].need[j]=0;
                                   }
                               }

                                   cnt=0;
                                   fl=0;
                                   while(cnt!=numProcess)
                                   {
                                       g=0;
                                       for(j=0;j<numProcess;j++)
                                       {
                                           if(f[j].flag==0)
                                           {
                                               b=0;
                                                for(p=0;p<r;p++)
                                                {
                                                    if(avail[p]>=f[j].need[p])
                                                        b=b+1;

                                                    else
                                                        b=b-1;

                                                }
                                                if(b==r)
                                                {
                                                    cout<<"\nP is visited "<<j;
                                                    seq[fl++]=j;
                                                    f[j].flag=1;

                                                  for(k=0;k<r;k++)
                                                       avail[k]=avail[k]+f[j].all[k];
                                                  cnt=cnt+1;
                                                  cout<<endl;

                                                  for(k=0;k<r;k++)
                                                     cout<<setw(3)<<avail[k];
                                                  cout<<endl;
                                                  g=1;
                                                }
                                           }
                                       }
                                       if(g==0)
                                       {
                                           cout<<"REQUEST NOT GRANTED - DEADLOCK OCCURED\n";
                                           cout<<"SYSTEM IS IN UNSAFE STATE\n";
                                           goto y;
                                       }

                                   }
                        cout<<"\nSYSTEM IS IN SAFE STATE";
                        cout<<"\nThe safe Sequence is--";
                                for(i=0;i<fl;i++)
                                 cout<<setw(2)<<seq[i];
                                 cout<<endl;

                                     y:cout<<"\nProcess\t\tAllocation\t\tMax\t\tNeed\n";
                                       for(i=0;i<numProcess;i++)
                                       {
                                           cout<<"P "<<i<<setw(16);

                                           for(j=0;j<r;j++)
                                                cout<<f[i].all[j];

                                           for(j=0;j<r;j++)
                                               cout<<setw(12)<<f[i].maxx[j];

                                           for(j=0;j<r;j++)
                                              cout<<f[i].need[j]<<setw(12);
                                              cout<<"\n";
                                       }

                                    }

    int main()
        {
      //Declaring Variables//
        int memAvailable,blockSize,nob,ef,numProcesses,memProcesses[10],tif=0;
        int i; int p=0, a=0;
        int ms,mp[10],temp=0,n=0;
        char ch='y'; int input;
        char C='y';
               int memSize,pageSize,numProcess,numPages,rempages,offset,physicalAdd;
          int j,x,y,k,h;
           int s[10],fno[10][20];
         int fragment[max],b[max],f[max],z[max],numBlocks,numFiles,lowest=10000,highest=0;
         static int bf[max],ff[max];

    int burstTime[20], wt[20],tat[20],burstTPro,waitingTime[10],tatz[10],t,ct[10];
    int avgTime,avgTurnaround,avgWaTime=0,avgTunArndTime=0,worstTime,tot=0,numTrucks=0,sum=0;

    int ps[20],bursTime[20],tate[20],prty[20],su[20],tohm[20],ts[20],d[20],atr[20];

             float wtavg,tatavg,avhm;


       /** On screen Display. This is What the user would see on the screen.
       It explains to the user what the program is about and what he should do**/
        cout<<"@ C 2021"<<"\nDone by:\n";
        cout<<"Annor Yankyera Samuel(Say)   219IT01000163"<<
           "\nCollins Kweku Amewu          220EI01000506"<<
            "\nAlbert Arhin.                219CS01000169\n";
        cout<<"\nThis a Program Displaying Memory Management Techniques in Operating Systems\n";
        cout<<"There are six Techniques available to use. Just choose any of them and proceed"<<endl;
        cout<<endl;
        cout<<"1. MFT MEMORY MANAGEMENT TECHNIQUE\n";
        cout<<"2. MVT MEMORY MANAGEMENT TECNIQUE\n";
        cout<<"3. MEMORY MANAGEMENT SCHEME WORST-FIT\n";
        cout<<"4. MEMORY MANAGEMENT SCHEME BEST-FIT\n";
        cout<<"5. MEMORY MANAGEMENT SCHEME FIRST-FIT\n";
        cout<<"6. PAGING TECHNIQUE\n";
        cout<<"7. FCFS CPU SCHEDULLING ALGORITHM\n";
        cout<<"8. SJF CPU SCHEDULING ALGORITHM\n";
        cout<<"9. ROUND ROBIN CPU SCHUDULING ALGORITHM\n";
        cout<<"10. PRIORITY CPU SCHEDULILNG\n";
        cout<<"11. MULTI-LEVEL QUEUE SCHEDULING\n";
        cout<<"12. DEAD LOCK\n";
        cout<<"13. FCFS DISK SCHEDULLING ALGORITHM\n";
        cout<<"14. SCAN DISK SCHEDULLING ALGORITHM\n";
        cout<<"15. C-SCAN FCFS DISK SCHEDULLING ALGORITHM\n";



        do{
            cout<<endl;
        /**The user would have to input a choice**/
        cout<<"\nChoose the memory technique of your choice  ";
        cin>>input;
         cout<<endl;

        // This is to correct wrong input by the user. It would make the user reenter the numbers//
     while(input<1 || input>15)
        {
            cout<<"Invalid number.Enter 1,2,3,4,5,6,7,8,9,10,11,12,13,14 or 15";
            cin>>input;
        }
                /**MVT Technique**/

        if(input==1)
           {
                 cout<<"------------------------------\n";
               cout <<"\n      MFT MEMORY MANAGEMENT TECHNIQUE\n";
                 cout<<"------------------------------\n";
               cout<<"All inputs should be positive integer values. Decimal values are not accepted";
                cout<<"Enter the total memory available---------:"; //Memory available input
                   cin>>memAvailable;

                cout<<"Enter the block Size ---------------------:";//Block size
                    cin>>blockSize;

                cout<<"Enter the number of processes-------------------:";//Number of processes
                     cin>>numProcesses;  //input//
               cout<<endl;// Ending line

           /**Computation or Calculation**/
           nob=memAvailable/blockSize;      // Number of blocks available in memory//
           ef=memAvailable-(nob*blockSize); // External Fragmentation//

           /**Performs the iteration**/
     for(i=0;i<numProcesses;i++)
       {
       cout<<"Enter the memory required for process "<< (i+1)<< " in bytes: ";
       cin>>memProcesses[i]; //Input//
       cout<<endl;
       }
          cout<<"Number of blocks available in memory is "<<nob<< ".\n"; //number of blocks in memory//
          cout<<endl;

          cout<<"\nPROCESS\t  MEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION\n";
          cout<<"----------------------------------------------------------------------------\n";
          for(i=0; i<numProcesses && p<nob; i++)
           {
            cout<<endl;
            cout<<setw(3)<< i+1 << "\t\t" <<setw(2)<<memProcesses[i]<<setw(6);
                   if(memProcesses[i]>blockSize)
                    {
                      cout << "\t\tNO\t\t   ---";
                    }
                   else{
                       cout<<setw(11)<<"\t\tYES\t\t"<<setw(6)<<blockSize-memProcesses[i];
                          tif=(tif+blockSize)-memProcesses[i];
                            p++;
                          cout<<endl;
                            cout<<endl;
                          }
             }

          if(i<=numProcesses)
               cout<<"Memory is full,The remaining processes cannot be accommodated"<<endl;
               cout<<"\nTotal Internal Fragmentation is "<<tif<<".";
               cout<<"\nTotal External Fragmentation is "<<ef<<endl;

          }

          //MFT Technique
    else if(input==2)
        {
             cout<<"        ------------------------------\n";
             cout<<"\n      MVT MEMORY MANAGEMENT TECNIQUE\n";
             cout<<"        ------------------------------\n";
              cout<<"All inputs should be positive integer values. Decimal values are not accepted";
             cout <<"Enter the total memory available in bytes---";
                 cin>> memAvailable;
            temp=memAvailable;

                  for(i=0;ch=='y';i++,n++)
                     {
                        cout<<"\nEnter memory required for process "<<i+1<< " in byte--";
                           cin>> memProcesses[i];
                     if(mp[i]<=temp)
                        {
                          cout<<"Memory is allocated for process "<<i+1;
                        temp=temp-memProcesses[i];
                        }
                  else
                     {
                      cout<<"\nMemory Full";
                         break;
                     }
                     cout<<"\nDo you want to continue(y/n)--";
                         cin>>ch;
                     }

            cout<<endl;
            cout<<"\nTotal memory Available is--- "<<ms;
            cout<<endl;
            cout<<endl;

    cout<<"PROCESS\t\tMEMORY ALLOCATED\n";
    cout<<"-----------------------------------\n";
            for(i=0;i<n;i++)
               cout<<setw(4)<<i+1<<setw(19)<<memProcesses[i]<<endl;
               cout<<endl;
               cout<<"Total Memory Allocated is "<<ms-temp<<endl;
               cout<<"Total External Fragmentation is "<<temp;
               cout<<endl;
        }

        else if(input==3)
        {

    cout<<"        ------------------------------\n";
    cout <<"       MEMORY MANAGEMENT SCHEME WORST-FIT"<<endl;
    cout<<"        ------------------------------\n";
    cout<<"All inputs should be positive integer values. Decimal values are not accepted";

    cout<< "Enter the number of blocks: ";
    cin>>numBlocks;

    cout<<"\nEnter the number of files: ";
    cin>>numFiles;

    cout<<"Enter the size of the blocks:";
    for(i=1;i<=numBlocks;i++)
    {
        cout<<"\nBlock "<<i<<": ";
        cin>>b[i];
    }
    cout<<"Enter the size of the files: \n";
    for(i=1;i<=numFiles;i++)
    {
        cout<<"File"<<i<<": ";
        cin>>f[i];
    }

    for(i=1;i<=numFiles;i++)
    {
        for(j=1;j<=numBlocks;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                {
                    ff[i]=j;
                    break;
                }
            }
        }
        fragment[i]=temp;
        bf[ff[i]]=1;
    }
    cout<<"\nFile number\tFile-Size\tBlock number\tBlock-Size\tFragment\n";
    for(i=1;i<=numFiles;i++){
        cout<<setw(4)<<i<<setw(16)<<f[i]<<setw(19)<<ff[i]<<setw(16)<<b[ff[i]]<<setw(16)<<fragment[i]<<endl;

    }
        }

        else if(input==4)
        {
             cout<<"        ------------------------------\n";
             cout <<"       MEMORY MANAGEMENT SCHEME BEST-FIT"<<endl;
             cout<<"        ------------------------------\n";
             cout<<"All inputs should be positive integer values. Decimal values are not accepted";

    cout<<"\nEnter the number of blocks: ";
    cin>>numBlocks;

    cout<<"Enter the number of files: ";
    cin>>numFiles;

    cout<<"\nEnter the size of the blocks:";
    for(i=1;i<=numBlocks;i++)
    {
        cout<<"\nBlock "<<i<<": ";
        cin>>b[i];
    }
    cout<<"\nEnter the size of the files: \n";
    for(i=1;i<=numFiles;i++)
    {
        cout<<"File"<<i<<": ";
        cin>>f[i];
    }

    for(i=1;i<=numFiles;i++)
    {
        for(j=1;j<=numBlocks;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                    if(lowest>temp)

                {
                    ff[i]=j;
                lowest=temp;
                }
            }
        }
        fragment[i]=lowest;
        bf[ff[i]]=1;
        lowest=10000;
    }
    cout<<"\nFile number\tFile-Size\tBlock number\tBlock-Size\tFragment\n";
    for(i=1;i<=numFiles;i++){
        cout<<setw(4)<<i<<setw(16)<<f[i]<<setw(19)<<ff[i]<<setw(16)<<b[ff[i]]<<setw(16)<<fragment[i]<<endl;

    }
        }


        else if(input==5)
        {
              cout<<"       ------------------------------\n";
              cout <<"      MEMORY MANAGEMENT SCHEME FIRST-FIT"<<endl;
              cout<<"       ------------------------------\n";
              cout<<"All inputs should be positive integer values. Decimal values are not accepted";

    cout<<"\nEnter the number of blocks: ";
    cin>>numBlocks;

    cout<<"Enter the number of files: ";
    cin>>numFiles;

    cout<<"\nEnter the size of the blocks:";
    for(i=1;i<=numBlocks;i++)
    {
        cout<<"\nBlock "<<i<<": ";
        cin>>b[i];
    }
    cout<<"\nEnter the size of the files: \n";
    for(i=1;i<=numFiles;i++)
    {
        cout<<"File"<<i<<": ";
        cin>>f[i];
    }

    for(i=1;i<=numFiles;i++)
    {
        for(j=1;j<=numBlocks;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                    if(highest<temp)

                {
                    ff[i]=j;
               highest=temp;
                }
            }
        }
        fragment[i]=highest;
        bf[ff[i]]=1;
       highest=0;
    }
    cout<<"\nFile number\tFile-Size\tBlock number\tBlock-Size\tFragment\n";
    for(i=1;i<=numFiles;i++){
        cout<<setw(4)<<i<<setw(16)<<f[i]<<setw(19)<<ff[i]<<setw(16)<<b[ff[i]]<<setw(16)<<fragment[i]<<endl;

    }
        }


        else if(input==6)
        {
              cout<<endl;
              cout<<"       ------------------------------\n";
              cout<<"       PAGING TECHNIQUE\n";
              cout<<"       ------------------------------\n";
           cout<<"All inputs should be positive integer values. Decimal values are not accepted";
    cout<<"Enter the memory size ---";
    cin>>memSize;

    cout<<"\nEnter the page size----";
    cin>>pageSize;

    numPages=memSize/pageSize;

    cout<<"\nThe number of pages available in memory are--"<<numPages;
    cout<<"\nEnter the number of processes---";
    cin>>numProcess;

         rempages=numPages;

    for(i=1;i<=numProcess;i++)
    {
        cout<<"\nEnter the number of pages required for process--"<<i<<": ";
        cin>>s[i];

        if(s[i]>rempages)
        {
            cout<<"\nMemory is Full";
            break;
        }
        cout<<endl;
        cout<<endl;
        rempages=rempages-s[i];
        cout<<"\nEnter page table for process--"<<i<<": ";
           for(j=0;j<s[i];j++)
               cin>>fno[i][j];
    }

    cout<<"\nEnter logical Address to find Physical Address";
    cout<<"\nEnter process number and page number and offset--";
    cin>>x>>y>>offset;

    if(x>numProcess|| y>=s[i] || offset>=pageSize)
        cout<<"\nInvalid process or page number or offset";
    else{

       physicalAdd=fno[x][y]*pageSize+offset;
        cout<<"\nThe physical Address is --"<<physicalAdd;
    }
    cout<<endl;
        }

        else if(input==7)
        {
             cout<<"FCFS CPU SCHEDULING"<<endl;
    cout<<"\nFCFS CPU SCHEDULING"<<endl;
    cout <<"\nEnter the number of processes ";
    cin>>numProcess;

    for(i=0;i<numProcess;i++)
    {
        cout<<"\nEnter Burst time for Processes--"<<i<<": ";
        cin>>burstTime[i];
    }

    wt[0]=avgTime=0;
    tat[0]=avgTurnaround=burstTime[0];

    for(i=1;i<numProcess;i++)
    {
        wt[i]=wt[i-1]+burstTime[i-1];
        tat[i]=tat[i-1]+burstTime[i];
        avgTime=avgTime+wt[i];
        avgTurnaround=avgTurnaround+tat[i];
    }
    cout<<"PROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
     for(i=0;i<numProcess;i++)

         cout<<setw(2)<<"P("<<i<<")"<<setw(16)<<burstTime[i]<<setw(17)<<wt[i]<<setw(18)<<tat[i]<<endl;
         cout<<"\nAverage Waiting Time," <<avgTime;
         cout<<"\nAverage Turnaround Time ," <<avgTurnaround;
    }

        else if(input==8)
         {


             cout<<"      SJF CPU SCHEDULING"<<endl;

             cout<<"Enter the number of processes--";
             cin>>numProcess;

             for(i=0;i<numProcess;i++)
             {
                 ps[i]=i;
                 cout<<"Enter Burst Time for process-"<<i<<": ";
                 cin>>bursTime[i];
             }

             for(i=0;i<numProcess;i++)
                for(k=0;k<numProcess;k++)
                       if(bursTime[i]>bursTime[k])
             {
                 temp=burstTime[i];
                 bursTime[i]=bursTime[k];
                 bursTime[k]=temp;

                 temp=ps[i];
                 ps[i]=ps[k];
                 ps[k]=temp;
             }
        wt[0]=wtavg=0;
        tatz[0]=tatavg=bursTime[0];
        for(i=1;i<numProcess;i++)
        {
            wt[i]=wt[i-1]+bursTime[i-1];
            tatz[i]=tatz[i-1]+bursTime[i];
            wtavg+=wt[i];
            tatavg+=tatz[i];
        }
        cout<<"\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
        for(i=0;i<numProcess;i++)
            cout<<setw(2)<<"P("<<ps[i]<<")"<<setw(16)<<burstTime[i]<<setw(17)<<wt[i]<<setw(18)<<tatz[i]<<"\n";
           cout<<"\nAverage waiting time-is:"<<wtavg;
          cout<<"\nAverage Turnaround Time is:"<<tatavg;
         }

            // Robin Scheduling
         else if(input==9)
         {
            int j,burstTPro[10],wa[10],tat_1[10],t,ct[10],a[max];
            float awt=0,att=0,temps=0;

         cout<<"      ------------------------------\n";
         cout<<"      ROUND ROBIN CPU SCHUDULING ALGORITHM"<<endl;
         cout<<"      ------------------------------\n";
             cout<<"Enter the number of processes: ";
             cin>>numProcess;
             for(i=0;i<numProcess;i++)
             {
                 cout<<"Enter the  Burst Time for process "<<i+1<<": ";
                 cin>>burstTPro[i];
                 ct[i]=burstTPro[i];
             }

             cout<<"\nEnter the size of time slice ";
             cin>>t;
             a[max]=burstTPro[0];

             for(i=1;i<numProcess;i++)
                if(a[max]<burstTPro[i])
                     a[max]=burstTPro[i];
                for(j=0;j<(a[max]/t)+ 1;j++)
                    for(i=0;i<numProcess;i++)

                          if(burstTPro[i]!=0)

                              if(burstTPro[i]<=t)
                              {
                              tat_1[i]=temp+burstTPro[i];
                              temp=temp+burstTPro[i];
                              burstTPro[i]=0;
                              }
                   else
                   {
                       burstTPro[i]=burstTPro[i]-t;
                       temp=temp+t;
                   }

                   for(i=0;i<numProcess;i++)
                   {
                       wa[i]=tat_1[i]-ct[i];
                       att+=tat_1[i];
                       awt+=wa[i];
                   }

                   cout<<"\nAverage Turnaround Time is "<<att;
                   cout<<"\nAverage Waiting Time is "<<awt;
                   cout<<"\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
                   for(i=0;i<numProcess;i++)
                   cout<<setw(2)<<i+1<<setw(16)<<ct[i]<<setw(17)<<wa[i]<<setw(18)<<tat_1[i]<<endl;
         }

         else if(input==10)
         {
             cout<<"PRIORITY CPU SCHEDULILNG\n";
             cout<<"Enter the number of processes--- ";
             cin>>numProcess;

             for(i=0;i<numProcess;i++)
             {
                 ps[i]=i;
             cout<<"Enter the burst Time & Priority of process--- "<< i<<" ";
             cin>> bursTime[i]>>prty[i];
             }
             for(i=0;i<numProcess;i++)
                  for(k=i+1;k<numProcess;k++)
                    if(prty[i]>prty[k])
                         {
                           temp=ps[i];
                           ps[i]=ps[k];
                           ps[k]=temp;

                           temp=bursTime[i];
                           bursTime[i]=temp;
                           bursTime[k]=temp;

                           temp=prty[i];
                           prty[i]=prty[k];
                           prty[k]=temp;

                         }

                         wtavg=wt[0]=0;
                         tatavg=tate[0]=bursTime[0];

                         for(i=1;i<numProcess;i++)
                         {
                             wt[i]=wt[i-1]+bursTime[i-1];
                             tate[i]=tate[i-1]+bursTime[i];

                             wtavg=wtavg+wt[i];
                             tatavg=tatavg+tate[i];
                         }

                         cout<<"PROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\t1TURNAROUND TIME\n";
                           for(i=0;i<numProcess;i++)

                             cout<<setw(2)<<ps[i]<<setw(17)<<prty[i]<<setw(18)<<bursTime[i]<<setw(18)<<wt[i]<<setw(19)<<tate[i]<<endl;

                           cout<<"Average Waiting Time is---"<<wtavg<<"\n";
                           cout<<"Average Turnaround Time is---"<<tatavg<<"\n";

                     }

                     else if(input==11)
                     {
                         cout<<"     ------------------------------\n";
                         cout<<"     MULTI-LEVEL QUEUE SCHEDULING\n";
                         cout<<"     ------------------------------\n";
                         cout<<"\nEnter the number of processes--- ";
                         cin>>numProcess;

                         for(i=0;i<numProcess;i++)
                         {
                             ps[i]=i;
                             cout<<"\nEnter the Burst Time of process-- "<<i<<" ";
                             cin>>bursTime[i];

                             cout<<"\nSystem/User Process(0/1)?-- ";
                             cin>>su[i];
                         }
                         for(i=0;i<numProcess;i++)
                            for(k=i+1;k<numProcess;k++)
                               if(su[i]>su[k])
                                   {
                                      temp=ps[i];
                                      ps[i]=ps[k];
                                      ps[k]=temp;

                                      temp=bursTime[i];
                                      bursTime[i]=bursTime[k];
                                      bursTime[k]=temp;

                                      temp=su[i];
                                      su[i]=su[k];
                                      su[k]=temp;
                                   }

                               wtavg=wt[0]=0;
                               tatavg=tate[0]=bursTime[0];

                               for(i=1;i<numProcess;i++)
                               {
                                   wt[i]=wt[i-1]+bursTime[i-1];
                                   tate[i]=tate[i-1]+bursTime[i];
                                   wtavg=wtavg+wt[i];
                                   tatavg=tatavg+tate[i];
                               }

                        cout<<"PROCESS\t\tSYSTEM/USER PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
                        for(i=0;i<numProcess;i++)
                                cout<<setw(3)<<ps[i]<<setw(18)<<su[i]<<setw(20)<<bursTime[i]<<setw(23)<<wt[i]<<setw(19)<<tate[i]<<endl;
                        cout<<"Average Waiting Time is "<<wtavg<<"\n";
                        cout<<"Average Turnaround Time is "<<tatavg<<"\n";
                     }

                     else if(input==12)
                     {

                         deadLock();
                     }

                     else if(13==input)
                     {
                         cout<<"      ------------------------------\n";
                         cout<<"      FCFS DISK SCHEDULLING ALGORITHM\n";
                         cout<<"      ------------------------------\n";
                         cout<<"Enter the number of trucks---";
                         cin>>numTrucks;
                         cout<<"\nEnter the track to be traversed--";
                              for(i=2;i<numTrucks+2;i++)
                                cin>>ts[i];
                          for(i=1;i<numTrucks;i++)
                          {
                              tohm[i]=ts[i+1]-ts[i];
                             if(tohm[i]<0)
                                tohm[i]=tohm[i]*(-1);
                          }
                          for(i=1;i<numTrucks+1;i++)
                            tot+=tohm[i];
                          avhm=(float)tot/numTrucks;

                           cout<<"Tracks traversed\tDifference between track\n";
                             for(i=1;i<numTrucks+1;i++)
                                cout<<setw(7)<<ts[i]<<setw(35)<<tohm[i]<<"\n";
                             cout<<"Average header movements: "<<avhm;

                     }

                     else if(input==14)
                     {
                          cout<<"       ------------------------------\n";
                          cout<<"       SCAN DISK SCHEDULLING ALGORITHM\n";
                           cout<<"      ------------------------------\n";
                          cout<<"Enter the number of tracks to be traversed";
                          cin>>numTrucks;

                          cout<<"\nEnter the position of head";
                          cin>>h;
                          ts[0]=0;ts[1]=h;

                          cout<<"\nEnter the tracks";
                              for(i=2;i<numTrucks+2;i++)
                                cin>>ts[i];
                               for(i=0;i<numTrucks+2;i++)
                               {
                                   for(j=0;j<(numTrucks+2)-i-1;j++)
                                   {
                                      if(ts[j]>ts[j+1])
                                        {
                                           temp=ts[j];
                                           ts[j]=ts[j+1];
                                           ts[j+1]=temp;
                                        }
                                   }

                               }
                               for(i=0;i<numTrucks+2;i++)
                                if(ts[i==h])
                                j=i;k=i;
                               p=0;

                               while(ts[j]!=0)
                               {
                                   atr[p]=ts[j];
                                   j--;
                                   p++;
                               }

                               atr[p]=ts[j];
                               for(p=k+1;p<numTrucks+2;p++,k++)
                                atr[p]=ts[k+1];
                               for(j=0;j<numTrucks+1;j++)
                               {
                                   if(atr[j]>atr[j+1])
                                     d[j]=atr[j]-atr[j+1];
                                   else
                                    d[j]=atr[j+1]-atr[j];
                                   sum+=d[j];
                               }
                               cout<<"\nAverage header movements: "<<(float)sum/numTrucks;
                     }

                     else if(input==15)
                     {
                          cout<<"       ---------------------------------------\n";
                          cout<<"       C-SCAN FCFS DISK SCHEDULLING ALGORITHM\n";
                          cout<<"       ----------------------------------------\n";
                          cout<<"\nEnter the number of tracks to be traversed";
                          cin>>numTrucks;

                          cout<<"\nEnter the position of the head";
                          cin>>h;
                          ts[0]=0;ts[1]=h;

                          cout<<"\nEnter total tracks";
                             for(i=3;i<=numTrucks+2;i++)
                                cin>>ts[i];
                             for(i=0;i<=numTrucks+2;i++)
                                 for(j=0;j<=(n+2)-i-1;j++)
                                      if(ts[j]>ts[j+1])
                             {
                                 temp=ts[j];
                                 ts[j]=ts[j+1];
                                 ts[j+1]=temp;
                             }
                    for(i=0;i<numTrucks+2;i++)
                        if(ts[i]==h)
                            j=i;
                          break;

                    p=0;
                     while(ts[j]!=tot-1)
                     {
                         atr[p]=ts[j];
                         j++;
                         p++;
                     }
                     atr[p]=ts[j];
                     p++;
                     i=0;

                     while(p!=(numTrucks+3)&& ts[i]!=ts[h])
                     {
                         atr[p]=ts[i];
                         i++;
                         p++;
                     }

                       for(j=0;j<numTrucks+2;j++)
                       {
                           if(atr[j]>atr[j+1])
                           d[j]=atr[j]-atr[j+1];

                           else
                            d[j]=atr[j+1]-atr[j];
                            sum+=d[j];
                       }

                       cout<<"\nTotal header movement "<<sum;
                       cout<<"\nAverage is "<<(float)sum;

                     }

        cout<<"\nIf you want to re-run the program Enter y or n to end: ";
        cin>>C;

        }

        while(C=='y');




return 0;

}



