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
    playerNode *head;
    public:
    playerList()
    {
      head = NULL;
    }
    void push(string,int);
    void display();
    void deleteFirst();
};

//This function adds new elements into a stack.
//Elements are order FILO.
void playerList::push(string name, int number)
{
    playerNode *newNode=new playerNode;
    newNode->playerName  = name;
    newNode->jerseyNumber  = number;
    newNode->next = head;
    head    = newNode;
}
//This function traverses through the stack and prints out the elements.
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
//This function prints the element at the top of the stack and deletes it.
void playerList::deleteFirst()
{
    playerNode *temp = new playerNode;
    temp=head;          //old head
    head=head->next;    //new head
    cout<<temp->playerName<<" "<<temp->jerseyNumber<<" deleted.\n";
    delete temp;        //remove old head
}

int main(){
	playerList players;
	players.push("Rose",1);
	players.push("Wade",3);
	players.push("Deng",9);
	players.push("Love",11);
	players.push("Noah",13);
	players.push("Butler",21);
	players.push("Gibson",22);
	players.push("Jordan",23);
	players.push("Pippen",33);
	players.push("Rodman",91);
	cout << "Stack after adding 10 elements:\n";
	players.display();

	cout << "********************\n";
    players.deleteFirst();
	players.deleteFirst();
	players.deleteFirst();
	cout << "********************";

	cout << "\nStack after deleting the top element three times:\n";
	players.display();

    return 0;
}
