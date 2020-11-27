#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    struct node *next;
} *head=NULL;

map<int, string> songs;

void conclusion();
void delay(unsigned int);
void insertatbeginning(int);
void insertatmiddle(int);
void insertatlast(int);
void del(int);
int display();
void insert(int);
void songlist();
int count();
void intro();
void body();

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal > clock());
}

void insertatbeginning(int n)
{
    struct node *newnode, *temp;
    newnode= new node();
    newnode->data=n;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
    cout <<"Song inserted at beginning\n";

}

void insertatmiddle(int n)
{
    int a, f=0;
    struct node *newnode = new node();
    newnode->data=n;
    cout <<"After which song would you like to insert:";
    cin>>a;
    struct node* temp=head;
    while(temp->data!=a)
    {
        if(temp->next==head)
        {
            cout<<"The song isn't available in the Queue!\n";
            f=1;
            return;
        }
        else
        {
            temp=temp->next;
        }

    }
    if(f==0)
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
    cout<<"The song has been added to the playlist!\n";
}

void insertatlast(int n)
{
    struct node *newnode, *temp;
    newnode = new node();
    newnode->data=n;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    cout<<"Song added to the end of queue\n";

}

void del(int x)
{
    struct node *temp;
    if(head==NULL)
    {
        cout<<"The Queue is empty\n";
        return;
    }
    else if(head->data==x)
    {
        struct node* temp=head;
        head=temp->next;
        free(temp);
    }
    else
    {
        int f=0;
        struct node* p=head;
        while(p->next->data!=x)
        {
            if(p->next->next==head)
            {
                cout << "\n The song is not present in the Queue\n";
                f=1;
                return;
            }
            else
            {
                p=p->next;
            }
        }
        if(f==0)
        {
            struct node* temp=p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    cout << "\n The song has been removed from the playlist!\n";
}


int display()
{
    struct node *temp;
    int arr1[20],i=0;
    temp=head;
    if(temp == NULL)
    {
        cout << "No songs playing currently. \n";
        conclusion();
    }
    else
    {
        cout << "\nQueue: \n";
        while(temp->next != head)
        {
            string s = songs.find(temp->data)->second;
            cout << temp->data << " " << s << "\n";
            arr1[i] = temp->data;
            temp = temp->next;
            i = i+1;
        }
        string s = songs.find(temp->data)->second;
        cout << temp->data << " " << s << "\n";
        arr1[i] = temp->data;
    }
    cout << "\n";
    return *arr1;
}

void insert(int n)
{
    int b;
    cout << "\nChoose an option: \n";
    cout << "\n0. To display the current playlist\n1. Add it at the beginning\n2. Add it at the end of the Queue\n3. Add it after a song\n4. Remove the song\n";
    cout << "\nEnter your choice: ";
    cin >> b;
    switch(b)
    {
        case 0:
            if(head== NULL)
            {
                cout<<"The playlist is empty!\n";
            }
            else display();
            break;
        case 1:
            insertatbeginning(n);
            break;
        case 2:
            insertatlast(n);
            break;
        case 3:
            insertatmiddle(n);
            break;
        case 4:
            del(n);
            break;
        default:
            cout << "Choose one of the given numbers please!\n";
            insert(n);
            break;
    }
}

void songlist()                                //to be used with file handling
{
    cout << "\n";
    FILE *fptr;
    fptr = fopen("dsaproject-songlist.txt", "r");
    int line = 0;
    int i = 1;
    char song[300];
    while(!feof(fptr))
    {
        songs.insert({i, fgets(song, 300, fptr)});
        i++;
    }
    fclose(fptr);
    for(auto i = songs.begin(); i != songs.end(); i++) {
        cout << i->first << ". " << i->second << "\n";
    }
}

void songlist2(){                                  //uses the maps data structure
    cout << "\n";
    songs.insert({1, "dna"});
    songs.insert({2, "trampoline"});
    songs.insert({3, "blinding lights"});
    songs.insert({4, "on"});
    songs.insert({5, "dynamite"});
    songs.insert({6, "fake love"});
    songs.insert({7, "pillowtalk"});
    songs.insert({8, "love me like you do"});
    songs.insert({9, "bad liar"});
    songs.insert({10, "thunder"});
    for(auto i = songs.begin(); i != songs.end(); i++) {
        cout << i->first << ". " << i->second << "\n";
    }
}


void intro()
{
    cout << "\t\t\t\t\t\tTHE MUSIC PLAYER IS ON \n\n";
    delay(1000);
    cout << "Create your personalized playlist below: \n";
    delay(1000);
    cout << "Enter the serial number associated with the song you want to choose!\n";
    delay(1000);
    cout << "Enter 0 if you are done with creating your Queue!\n";
    delay(1000);
    cout << "If you want to remove a song from the playlist, first enter the serial number of the song and then choose ů.";
    delay(1000);
}
void body()
{
    int a=99;
    while(a!=0)
    {
        cout<<"\nEnter the serial number or enter zero to play the songs: ";
        cin >> a;
        if(a == 0) {
            cout << " ";
        }
        else if(a > 10 || a<0) cout << "Please enter a valid serial number";
        else insert(a);
    }
}


void conclusion()
{
    int j=99,k=99;
    cout<<"Enter 0 if you wish to close the player!\n";
    delay(500);
    cout<<"Enter 1 if you wish to create a new playlist!\n";
    delay(500);
    cout<<"Enter 2 if you wish to replay the current playlist!\n";
    delay(500);
    cout<<"Enter: ";
    cin >> j;
    if(j==1)
    {
        head=NULL;
        intro();
        songlist();
        body();
        display();
        conclusion();
        return;
    }
    else if(j==0)
    {
        cout<<"Are you sure?\n";
        cout<<"Final call!";
        delay(500);
        cout<<"One to create a new playlist, zero to go!\n";
        cin >> k;
        if(k==1)
        {
            cout<<"Continue Enjoying!\n";
            head=NULL;
            intro();
            songlist();
            body();
            display();
            conclusion();
            return;
        }
        else if(k==0)
        {
            cout<<"Okay Bye";
            return;
        }
        else
        {
            cout<<"Select a proper number\n";
            delay(500);
            cout<<"-__-";
            conclusion();
        }
    }
    else if(j==2)
    {
        display();
        conclusion();
    }
    else
    {
        cout<<"Select a proper number\n";
        delay(500);
        cout<<"-__-";
        conclusion();
    }
}

int main()
{
    intro();
    songlist();
    body();
    display();
    conclusion();
    return 0;
}
