#include <iostream>

using namespace std;
struct student{
    string name;
    student *next;
};

student* start=NULL;
student* recieved= new student;
student *temp_1,*temp_2;
bool insertBeg(student *data){
    if(start==NULL){
        start=data;
        start->next=NULL;
        return true;
    }
    else{
        temp_1=start;
        start=data;
        start->next=temp_1;
        return true;
    }
}

bool insertEnd(student *data) {
    student* temp = start;
    if (start == NULL) {
        start = data;
        return true;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = data;
        data->next = NULL;  // Set the next pointer to NULL for the last node
        return true;
    }
}


bool insertMid(int pos, student *data) {
    temp_1 = start;
     if (pos <= 0) {
        return false;
    }
    if (start == NULL && pos==1) {
            start=data;
        return true;
    }
    else {
    for (int i = 1; i < pos - 1; i++) {
        if (temp_1->next == NULL) {
            return false; // Handle the case where pos is out of bounds
            }
            temp_1 = temp_1->next;
        }
        data->next = temp_1->next;
        temp_1->next = data;
        return true;
    }
}
void display(){
    student* temp_=start;
     while (temp_ != NULL) {
        cout << "\n\t\t\tNAME: " << temp_->name;
        temp_ = temp_->next;
    }
    cout << "\n\n\t\t\t\tEND OF LIST\n";
}
bool displayN(int pos){
    temp_1=start;
     for (int i = 1; i < pos && temp_1 != NULL; i++) {
        temp_1 = temp_1->next;
    }
    if (temp_1 == NULL) {
        cout << "\n\n\t\t\t\tNO NODE @ THIS POSITION";
        return false;
    }
    cout << "\n\n\t\t\tDATA  @ THIS "<<pos<<" POSITION\n\n";
    cout << "\n\t\t\tNAME: " << temp_1->name;
    return true;
}

void deleteFirst(){
    temp_1=start;
    if(start!=NULL){
        start=start->next;
        delete temp_1;
        cout<<"\n\n\t\t\t\tFIRST NODE IS DELETED";
    }
    else{
       cout<<"\n\n\t\t\t\tLIST IS EMPTY";
    }

}
void deleteEnd(){
    temp_1=start;
    temp_2=NULL;
 if (start != NULL) {
   while (temp_1->next != NULL) {
            temp_2 = temp_1;
            temp_1 = temp_1->next;
        }

        if (temp_2 != NULL) {
            temp_2->next = NULL;
            delete temp_1;
        }
        else {
            // Only one element in the list
            delete temp_1;
            start = NULL;
        }
    }
    else {
        cout << "\n\n\t\t\t\tLIST IS EMPTY";
    }

}

void deleteMid(int pos){
    temp_1=start;
    temp_2=NULL;
    if (pos <= 0 || start == NULL) {
        cout << "\n\n\t\t\t\tINVALID POSITION";
        return;
    }
    if (pos == 1) {
        temp_1= start;
        start = start->next;
        delete temp_1;
        return;
    }
     for (int i = 1; i < pos && temp_1 != NULL; i++) {
        temp_2 = temp_1;
        temp_1 = temp_1->next;
    }
    if (temp_1 == NULL) {
        cout << "\n\n\t\t\t\tNO NODE @ THIS POSITION";
        return;
    }
    if (temp_1->next== NULL) {
        temp_2->next = NULL;
        delete temp_1;
        return;
    }
    temp_2->next = temp_1->next;
    delete temp_1;
}
// Delete all nodes in the list
void deleteAllNodes() {
    temp_1 = start;
    while (temp_1 != NULL) {
        start = temp_1->next; // Move the start to the next node
        delete temp_1;        // Delete the current node
        temp_1 = start;       // Move to the next node
    }
    cout << "\n\n\t\t\t\tALL NODES DELETED\n";
}

int menu(){
    int userInput;
    cout<<"\n\t\t\t   MENU\n";
    cout<<"\n\t\t\t1.Insert at the beginning\n";
    cout<<"\n\t\t\t2.Insert at the end\n";
    cout<<"\n\t\t\t3.Insert at the middle\n";
    cout<<"\n\t\t\t4.Delete the first node\n";
    cout<<"\n\t\t\t5.Delete the end node\n";
    cout<<"\n\t\t\t6.Delete the middle node\n";
    cout<<"\n\t\t\t7.Display first to last\n";
    cout<<"\n\t\t\t8.Display from last to first\n";
    cout<<"\n\t\t\t9.Display from Specific position\n";
    cout<<"\n\t\t\t choose[1/2/3/4/5/6/7/8]: ";
    cin>>userInput;
    return userInput;
}
int main()
{
char hold='v';
int pos;
menu:
    switch(menu()){
    case 1:
        cout<<"\n\t\t\tEnter the data below\n\n";
        cout<<"\n\t\t\tName: ";
        cin>>recieved->name;
        if(insertBeg(recieved))
            cout<<"\n\t\t\t Successful added"<<endl;
        break;
    case 2:
        cout<<"\n\t\t\tEnter the data below\n\n";
        cout<<"\n\t\t\tName: ";
        cin>>recieved->name;
        if(insertEnd(recieved))
            cout<<"\n\t\t\t Successful added"<<endl;
        break;
    case 3:
         cout<<"\n\t\t\tEnter the data below\n\n";
        cout<<"\n\t\t\tName: ";
        cout<<"\n\t\t\tEnter the position to add: ";
        cin>>pos;
        cin>>recieved->name;
        if(insertMid(pos ,recieved))
            cout<<"\n\t\t\t Successful added"<<endl;
        break;
    case 4:deleteFirst();
        break;
    case 5:deleteEnd();
        break;
    case 6:
        cout<<"\n\t\t\tEnter the position to delete: ";
        cin>>pos;
        deleteMid(pos);
        break;
    case 7:display();
        break;
    case 8://will be implemented letter
        break;
    case 9://will be implemented letter
        cout<<"\n\t\t\tEnter the position to add: ";
        cin>>pos;
        displayN(pos);
        break;

    }
cout<<"Enter 'y to continue: ";
cin>>hold;
if(hold=='y'||hold=='Y'){
   goto menu;
}
else{
deleteAllNodes();
}

    return 0;

}
