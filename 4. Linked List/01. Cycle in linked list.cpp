//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/#

void removeLoop(Node* head)
    {
        bool loop=false;
        Node *fast=head,*slow=head;

        //detect cycle
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                loop=true;
               break;
            }
        }
        //if loop then
        if(loop)
        {
            //if loop is at head
        if(fast == head){

               while(fast->next!=slow)
                   fast = fast->next;
           }
        else{
            slow=head;
            while(fast->next!=slow->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        //remove loop
        fast->next=NULL;
        }
    }