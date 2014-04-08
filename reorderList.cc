// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.
// idea: find the median of the list. reverse the latter half of the list, and insert back to the former half every other node 
//PENDING
 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };


ListNode *reverse(ListNode *head)
{
    ListNode *previous = NULL;

    while (head != NULL) {
        // Keep next node since we trash
        // the next pointer.
        ListNode *next = head->next;

        // Switch the next pointer
        // to point backwards.
        head->next = previous;

        // Move both pointers forward.
        previous = head;
        head = next;
    }

    return previous;
}


 void reorderList(ListNode* head)
 {
 	if(!head) return;
 	if(!head->next) return;

 	ListNode* p1=head;  //slow cursor
 	ListNode* p2=head; //fast cursor

 	// find the middle of list 
 	while(p2->next && p2->next->next)
 	{
 		p1 = p1->next;
 		p2 = p2->next->next;
 	}

 	p1->next = reverse(p1->next);

 	//reorder



 }

 int main(int argc, char const *argv[])
 {
 	 
 }