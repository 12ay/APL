#include <iostream>
#include <cstdio>
using namespace std;

struct playerNode{
    string playerName;
    int jerseyNumber;
    playerNode *next;
};
class playerList
{
    private:
    playerNode *head, *tail;
    public:
    playerList()
    {
      head = NULL;
      tail = NULL;
    }
    void createNode(string, int);
    void display();
    void deleteFirst();
    void deleteLast();
    void deleteMiddle();
    void displayReverse();
};

//this function creates a node
void playerList::createNode(string name, int number )
{
  playerNode *temp=new playerNode;
  temp->playerName=name;
  temp->jerseyNumber=number;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    tail=temp;
    temp=NULL;
  }
  else
  {
    tail->next=temp;
    tail=temp;
  }
}
void playerList::display()
{
    playerNode *temp=new playerNode;
    temp=head;
    while(temp!=NULL)
        {
            cout<<temp->playerName<<" "<<temp->jerseyNumber<<"\n";
            temp=temp->next;
        }
}
void playerList::deleteFirst()
{
    playerNode *temp = new playerNode;
    temp=head;          //old head
    head=head->next;    //new head
    delete temp;        //remove old head
}
void playerList::deleteLast()
{

    playerNode *current = new playerNode;
    playerNode *previous = new playerNode;
    current=head;

    while(current->next!=NULL)
    {
      previous=current;
      current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
}
void playerList::deleteMiddle()
{
    //this part finds the index of the middle node
    playerNode *temp=new playerNode;
    temp=head;
    int nodeCount = 0,midCount;
    while(temp!=NULL)
        {
            temp=temp->next;
            nodeCount++;
        }
    midCount = nodeCount/2;

    //this part deletes the node the middle node
    playerNode *current=new playerNode;
    playerNode *previous=new playerNode;
    current=head;
    for(int i=1;i<midCount;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;

}
void playerList::displayReverse()
{
    //this part reverses the order of the list
    if(head == NULL){return;}
    playerNode *prev = NULL;
    playerNode *current = NULL;
    playerNode *next = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    //this part displays the reversed order
    while(head!=NULL)
    {
        cout<<head->playerName<<" "<<head->jerseyNumber<<"\n";
        head=head->next;
    }
}

int main(){
	playerList players;
	players.createNode("Rose",1);
	players.createNode("Wade",3);
	players.createNode("Deng",9);
	players.createNode("Love",11);
	players.createNode("Noah",13);
	players.createNode("Butler",21);
	players.createNode("Gibson",22);
	players.createNode("Jordan",23);
	players.createNode("Pippen",33);
	players.createNode("Rodman",91);
	cout << "The original list:\n";
	players.display();

	cout << "\nThe list after deleting the first, middle, and last nodes:\n";
	players.deleteFirst();
	players.deleteLast();
	players.deleteMiddle();
	players.display();

	cout << "\nThe previous list in reverse order:\n";
	players.displayReverse();
    return 0;
}
