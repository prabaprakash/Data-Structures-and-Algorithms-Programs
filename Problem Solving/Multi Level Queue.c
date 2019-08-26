#include<stdio.h>
#include<conio.h>




float avg_wt,avg_tt;
int i = 0,ttl_wt=0,ttl_tt=0,qt;

struct process
{
 int prn;
 char type;
 int bt;
 int wt;
 int tt;
 struct process *nxt;
}*stfor,*stbck,*np,*endfor,*endbck,*temp;

void ins_node(struct process *np)
{
 if(np->type == 'f')
 {
  if(stfor == NULL)
    stfor = endfor = np;
  else
  {
   endfor->nxt = np;
   endfor = np;
  }
 }
 else
 {
  if(stbck == NULL)
    stbck = endbck = np;
  else
  {
   endbck->nxt = np;
   endbck = np;
  }
 }
}

void del_node(struct process *np,int choice)
{
 if(np->type == 'f')
 {
  if(stfor == endfor)
   stfor = NULL;
  else
   stfor = stfor->nxt;
  if(choice == 1)
   delete np;
  }
  else
  {
   if(stbck == endbck)
    stbck = NULL;
   else
    stbck = stbck->nxt;
   delete np;
  }
}

void ins_dat()
{
  char ch;
  int j=0;
  stfor = endfor = stbck = endbck = NULL;
  do
  {
  np = new process;
  np->prn = ++j;
  printf("\n Enter the Burst time of Process #%d : ",np->prn);
  scanf("%d",&np->bt);
  printf("\n Enter the type of Process #%d (f-foreground or b-background): ",np->prn);
  np->type = getche();
  if(np->type == 'f')
   np->nxt = stfor;
  else
   np->nxt = NULL;
  np->wt = np->tt = 0;
  ins_node(np);
  printf("\n\n Continue ?? : ");
  ch = getche();
  }while(ch == 'y' || stfor == NULL);
}

void Round_Robin()
{
 getch();
 printf("\n\n Foreground RR Process Scheduling (Quantum Size = %d)\n\n",qt);
 printf("\n\n Process   Burst Time   Waiting Time   Turnaround Time \n");
 printf(" ------------------------------------------------------- \n");
 temp = stfor;
 do
 {
   printf(" %d \t\t %d \t\t",stfor->prn,stfor->bt);
   stfor->wt += (temp->tt - stfor->tt);
   if(qt >= stfor->bt)
   {
    stfor->tt = temp->tt + stfor->bt;
    stfor->bt = 0;
    printf(" %d \t\t %d\n\n",stfor->wt,stfor->tt);
    ttl_wt += stfor->wt;
    ttl_tt += stfor->tt;
    temp = np = stfor;
    del_node(np,1);
    ++i;
   }
   else
   {
    stfor->bt -= qt;
    stfor->tt = temp->tt + qt;
    printf(" %d \t\t %d\n\n",stfor->wt,stfor->tt);
    np = temp = stfor;
    del_node(np,2);
    ins_node(temp);
   }
 }while(stfor != NULL);
}

void FCFS()
{
 getch();
 printf("\n\n Background FCFS Process Scheduling \n\n");
 printf("\n\n Process   Burst Time   Waiting Time   Turnaround Time \n");
 printf(" ------------------------------------------------------- \n");
 do
 {
   printf(" %d \t\t %d \t\t",stbck->prn,stbck->bt);
   stbck->wt = temp->tt;
   stbck->tt = temp->tt + stbck->bt;
   printf(" %d \t\t %d\n\n",stbck->wt,stbck->tt);
   ttl_wt += stbck->wt;
   ttl_tt += stbck->tt;
   temp = np = stbck;
   del_node(np,1);
   ++i;
 }while(stbck != NULL);

}
void main()
{
 clrscr();
 printf("\n Enter the Quantum time for Foreground Process : ");
 scanf("%d",&qt);
 ins_dat();
 if(stfor != NULL)
  Round_Robin();
 if(stfor == NULL && stbck != NULL)
  FCFS();
 avg_wt = (float) ttl_wt/i;
 avg_tt = (float) ttl_tt/i;
 printf("\n\n Average Waiting Time  : %f",avg_wt);
 printf("\n Average Turnaround Time : %f",avg_tt);
 getch();
}