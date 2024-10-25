
#include "BrowserHistory.hpp"

BrowserHistory::BrowserHistory()
{
    // No changes needed
}

BrowserHistory::~BrowserHistory()
{
    // No changes needed
}

/*
 * Purpose: Has to detect if a defect is present in the linkedlist pointed by head
 * @param none
 * @return integer length of defect if one exists. If defect not present return -1
 */
int BrowserHistory::findDefectLength(){

    // TODO START =============================================
    WebPage *slow = head;
    WebPage *fast = head;
    int res=1;
    while (slow && fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            struct WebPage *temp = slow;
            while (temp->next!=slow) {
                res++;
                temp=temp->next;
            }
            return res;
        }
    }
    return -1;
    // TODO END ==================================================
}

/*
 * Purpose: Has to remove all the WebPage nodes from [start, end] inclusive.
 * Has to print appropriate messages on cout like below if the linkedlist is empty
 * or if the values of start/ end are improper
 * follow the same order for couts in the writeup - check empty list first, then check wrong start/end values
 * @param integers start and end (1 based indexing not 0 based)
 * @return none
 */
void BrowserHistory::removeWebPages(int start, int end){

    // TODO START ===================================================
    if (head==NULL) {
        cout << "Browsing history is Empty" << endl;
        return;
    }
    int count;
    WebPage* curr=head;
    while (curr!=NULL) {
        count++;
        curr=curr->next;
    }
    if (start>end || start<1) {
        cout << "Invalid start or end values" << endl;
        return;
    }
    WebPage* temp=head;
    WebPage* prev;
    for (int i=1; i<start; i++) {
        prev=temp;
        temp=temp->next;
    }
    if (start==1) {
        for (int i=0; i<end-start+1; i++) {
            WebPage* temphead=head;
            head=temphead->next;
        }
        return;
    }
    for (int i=0; i<end-start+1; i++) {
        WebPage* temp2=prev->next;
        prev->next=temp2->next;
    }
    free(temp);
    return;
    // TODO END ===================================================
}


/*
 * Purpose: Interweave the webpages alternatively into a new linkedlist 
 * starting with the first webpage in the list one
 * Assign the head of the new interweaved list to the head of this BrowserHistory
 * DO NOT create new nodes and copy the data, just use the same nodes from one and two and change pointers
 * If one of them runs out of length append the remaining of the other one at end
 * @param two linkedlist heads one and two
 * @return none
 */
void BrowserHistory::mergeTwoHistories(WebPage *headOne, WebPage * headTwo){

    // TODO START =============================================
    WebPage* oneCurr=headOne;
    WebPage* twoCurr=headTwo;
    WebPage* oneNext;
    WebPage* twoNext;
    while (oneCurr!=NULL && twoCurr!=NULL) {
        //next pointers
        oneNext=oneCurr->next;
        twoNext=twoCurr->next;
        //making twoCurr the next value of OneCurr
        twoCurr->next=oneNext;
        oneCurr->next=twoCurr;
        //update pointers for next loop
        oneCurr=oneNext;
        twoCurr=twoNext;
    }
    headTwo=twoCurr;
    head=headOne;

    // TODO END ==================================================
}
