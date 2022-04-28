https://practice.geeksforgeeks.org/problems/move-all-zeros-to-the-front-of-the-linked-list/1#

void moveZeroes(struct Node **head)
{
    Node *curr=*head, *prev=NULL, *new_head=*head;
    while(curr!=NULL){
        if(curr->data==0 && curr!=*head){
            
            Node* temp=curr->next;
            
            curr->next=new_head;
            new_head=curr;
            prev->next=temp;
            
           curr=temp;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    *head=new_head;
}