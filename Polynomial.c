#include "Polynomial.h"
#include <stdio.h>
#include <stdlib.h>
Node *CreatePolyn(){
    //返回一个链表
    Node *head,*q;
    
    head=(Node *)malloc(sizeof(Node));
    //分配空间
    head->next=NULL;
    //头结点
    q=head;
    //
    int n;
    printf("Enter:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       Node *p;
       p=(Node *)malloc(sizeof(Node));
       scanf("%d%d",&p->coe,&p->pow);
      
       p->next=q->next;
       q->next=p;
       q=q->next; 

        }
    return head;
    }

Node *AddPolyn(Node *ha,Node *hb){
    Node *pa,*pb,*p;
    pa=ha->next;
    pb=hb->next;
    p=ha;
    while(pa&&pb){
        if(pa->pow==pb->pow){
            pa->coe+=pb->coe;

            p->next=pa;

            p=p->next;

            pa=pa->next;

            pb=pb->next;
    }
        else if(pa->pow<pb->pow) {
            p->next=pa;

            p=p->next;

            pa=pa->next;
        }
        else {
            p->next =pb;

            p=p->next;

            pb=pb->next;
        }
        }
    if(pa){
        p->next = pa;
        }
        else {
        p->next=pb;
        }
     return ha; 

     }

void PrintPolyn(Node *head){
    Node *p;

    p=(Node *)malloc(sizeof(Node));

    p=head->next;

    while(p!=NULL){
        printf("%d %d ",p->coe,p->pow);
        p=p->next;
}
}
int main(){
    Node *ha,*hb,*hc;
    
    ha=CreatePolyn();
    hb=CreatePolyn();
    hc=AddPolyn(ha,hb);
    PrintPolyn(hc);
    return 0;
}

// void CreatePolyn(Polynomial p,int n){
//     p=(struct Node *)malloc(sizeof(struct Node));
//     p->next=NULL;
//     Polynomial pre=(struct Node *)malloc(sizeof(struct Node));
//     for(int i=1;i<=n;i++){
//         Polynomial s=(struct Node *)malloc(sizeof(struct Node)),q=(struct Node *)malloc(sizeof(struct Node));
//         scanf("%d%d",&s->coe,&s->pow);
//         pre=p;//保存q的前驱
//         q=p->next;//q指向首元结点
//         while(q&&q->pow<s->pow){
//            pre=q;
//            q=q->next; 
//         }
//         s->next=q;
//         pre->next=s;
//     }
//     Polynomial pc;
//     pc=p->next;
//     while(pc){
//         printf("%d %d ",pc->coe,pc->pow);
//         pc=pc->next;
//     }
//     printf("\n");
//     printf("You cteate sucessfully!\n");
// }
// // void AddPolyn(Polynomial pa,Polynomial pb){
// //     CreatePolyn(pa,2);
// //     printf("\n");
// //     printf("OK\n");
// //     CreatePolyn(pb,2);
// //     printf("\n");
// //     printf("OK\n");

// //      Polynomial p1=(struct Node *)malloc(sizeof(struct Node)),p2=(struct Node *)malloc(sizeof(struct Node)),p3=(struct Node *)malloc(sizeof(struct Node));
// //      p1=pa->next,p2=pb->next;//首元结点
// //      Polynomial r=(struct Node *)malloc(sizeof(struct Node));
// //      p3=pa;
// //      int sum=0;
// //      while(p1&&p2){
// //          printf("OK\n");
// //         if(p1->pow==p2->pow){
// //         sum=p1->coe+p2->coe;
// //         if(sum!=0){
// //             p1->coe=sum;
// //             p3->next=p1;
// //             p3=p1;
// //             p1=p1->next;
// //             r=p2;
// //             p2=p2->next;
// //             free(r);
// //         }
// //         else {
// //             r=p1;
// //             p1=p1->next;
// //             free(r);
// //             r=p2;
// //             p2=p2->next;
// //             free(r);
// //         }
// //         }
// //         else if(p1->pow<p2->pow){
// //              p3->next=p1;
// //              p3=p1;
// //              p1=p1->next;
// //         }
// //         else {
// //             p3->next=p2;
// //             p3=p2;
// //             p2=p2->next;
// //         }
// //      }
// //      p3->next=p1?p1:p2;
// //      free(pb);
// //     // Polynomial pc;
// //     // pc=pa->next;
// //     // while(pc){
// //     //     printf("%lf %d ",pc->coe,pc->pow);
// //     //     pc=pc->next;
// //     // }
// // }
// void AddPolyn(Polynomial Pa, Polynomial Pb)   
// {   
//     Polynomial ha = Pa, hb = Pb, qa = ha->next, qb = hb->next;   
//     int a, b;   
//     while(qa && qb)   
//     {   
//         a = qa->pow, b = qb->pow;   
//         if(a < b)   
//         {   
//           ha = qa;
//           qa = qa->next;   
//         }   
          
//         else if(a == b)   
//         {   
//             int sum = qa->coe + qb->coe;   
//             if(sum != 0)   
//             {   
//                 qa->coe = sum;  
//                 ha = qa;   
//             }   
              
//             else   
//             {   
//                 ha->next = qa->next;   
//                 free(qa);   
//             }   
                  
//                 hb->next = qb->next;   
//                 free(qb);   
//                 qb = hb->next;  
//                 qa = ha->next;   
//        }   
          
//         else if(a > b)   
//         {   
//             hb->next = qb->next;    
//             ha->next = qb;    
//             qb->next = qa;    
//             qb = hb->next;    
//             ha = ha->next;   
//         }   
//   }   
//     if(qb != NULL)   
//     {   
//         while(qb != NULL)   
//         {   
//             Polynomial pnew = (Polynomial)malloc(sizeof(struct Node));   
//             pnew->coe = qb->coe;   
//             pnew->pow = qb->pow;   
//             pnew->next = NULL;   
//             ha->next = pnew;   
//             ha = ha->next;   
//             qb = qb->next;   
//         }      
//     }   
//     Polynomial pc;
//     pc=Pa->next;
//     while(pc){
//         printf("%d %d ",pc->coe,pc->pow);
//         pc=pc->next;
//     }
// } 
// void show(Polynomial p){
//     Polynomial pc;
//     pc=p->next;
//     while(pc){
//         printf("%d %d ",pc->coe,pc->pow);
//         pc=pc->next;
//     }
// }
// int main(){
//     PNode Pa[100],Pb[100];
//     Polynomial pa=Pa,pb=Pb;
    
//     CreatePolyn(pa,3);

//     CreatePolyn(pb,2);

//     AddPolyn(pa,pb);

//     // show(Pa);

// //     Polynomial ha = Pa, hb = Pb, qa = ha->next, qb = hb->next;   
// //     int a, b;   
// //     while(qa && qb)   
// //     {   
// //         a = qa->pow, b = qb->pow;   
// //         if(a < b)   
// //         {   
// //           ha = qa;
// //           qa = qa->next;   
// //         }   
          
// //         else if(a == b)   
// //         {   
// //             int sum = qa->coe + qb->coe;   
// //             if(sum != 0)   
// //             {   
// //                 qa->coe = sum;  
// //                 ha = qa;   
// //             }   
              
// //             else   
// //             {   
// //                 ha->next = qa->next;   
// //                 free(qa);   
// //             }   
                  
// //                 hb->next = qb->next;   
// //                 free(qb);   
// //                 qb = hb->next;  
// //                 qa = ha->next;   
// //        }   
          
// //         else if(a > b)   
// //         {   
// //             hb->next = qb->next;    
// //             ha->next = qb;    
// //             qb->next = qa;    
// //             qb = hb->next;    
// //             ha = ha->next;   
// //         }   
// //   }   
// //     if(qb != NULL)   
// //     {   
// //         while(qb != NULL)   
// //         {   
// //             Polynomial pnew = (Polynomial)malloc(sizeof(struct Node));   
// //             pnew->coe = qb->coe;   
// //             pnew->pow = qb->pow;   
// //             pnew->next = NULL;   
// //             ha->next = pnew;   
// //             ha = ha->next;   
// //             qb = qb->next;   
// //         }      
// //     }   
// //     Polynomial pc;
// //     pc=Pa->next;
// //     while(pc){
// //         printf("%d %d ",pc->coe,pc->pow);
// //         pc=pc->next;
// //     }
//     return 0;

// }