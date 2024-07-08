#include <iostream>

using namespace std;

void VSpace(int num = 10)
{
    for (int i=0; i < num; i++)
    {
        cout << endl;
    }
}

void Clear()
{
    cout << "\033[2J\033[1;1H";
}

void Pause()
{
    cout << "Press Enter to continue...";
    cin.ignore();
}

int ClampedInput(int min = 0, int max = 4, string prompt="Enter: ")
{

        int choice;
        cout << prompt;
        cin >> choice;
        //cin.ignore();

        if (cin.fail())
        {
            cin.ignore();
            cout << "Invalid input.\n";
            //Pause();
            return -2;
        }

        if (choice >= min && choice <= max)
        {
            return choice;
        }
        else
        {
            cout << "Out of bounds.\n";
            return -1;
        }
    

}

struct node
{
    string data;
    node* next;
};

class LinkedList
{
    public:
    node* head = nullptr;
    node* tail = nullptr;
    int size=0;

    public:

    bool DeleteValue(string value)
    {
        if (size == 0)
        {
            return false;
        }

        int counter = 0;
        node* pre = nullptr;
        node* curr = head;

        bool found = false;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                //cout << "value found at index " << counter;
                found = true;
                size--;
                break;
                
            }
            counter++;
            pre = curr;
            curr = curr->next;
        }
        if (counter == 0)
        {
            head = head->next;
        }
        else if (counter == size-1)
        {
            tail = pre;
            pre -> next = nullptr;
        }
        else if (found)
        {
            pre->next=curr->next;
        }

        return found;

    }

    void InsertNode(string n, int index)
    {
        node* temp = new node;
        temp->data = n;

        node* curr = head;

        if (index < 0 || index > size)
        {
            cout << "Error.";
            //Pause();
            return;
        }

        if (index == 0)
        {
            PrependNode(n);
            return;
        }

        if (index == size)
        {
            AppendNode(n);
            return;
        }

        size++;
        
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            for (int i=0;i<index-1;i++)
            {
                curr = curr->next;
            }
            temp -> next = curr -> next;
            curr->next = temp;

        }

    }

    void DisplayNode()
    {
        node* curr = head;

        while(curr != nullptr)
        {
            cout << "[" <<curr->data << "] ";
            curr = curr->next;
            
        }
    }

    void PrependNode(string n)
    {
        node* temp = new node;
        temp->data = n;
 
        size++;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            
        }
        else
        {
            temp-> next = head;
            head = temp;
        }
    }

    void AppendNode(string n)
    {
        node* temp = new node;
        temp->data = n;
        temp-> next = nullptr;

        size++;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
};

int main()
{
    LinkedList list;

    int choice;

    while (true)
    {
        Clear();

        list.DisplayNode();

        VSpace(2);

        cout 
        << "1. Prepend\n"
        << "2. Append\n"
        << "3. Insert\n"
        << "4. Delete\n\n";

        choice = ClampedInput(1, 4);
        Clear();

        string entry;

        switch (choice)
        {
            case 1: 
            cout << "Enter what you'll add to the start of the list: ";
            cin >> entry;
            list.PrependNode(entry);
            break;

            case 2: 
            cout << "Enter what you'll add to the end of the list: ";
            cin >> entry;
            list.AppendNode(entry);
            break;

            case 3: 
            cout << "Enter the index you'll insert your entry (0, " << list.size << "): ";
            int i; cin >> i;
            cout << "Enter what you'll add to the list: ";
            cin >> entry;
            list.InsertNode(entry, i);
            break;

            case 4: 
            cout << "Enter the value you want to try and delete: ";
            string entry; cin >> entry;
            if(list.DeleteValue(entry))
            {
                cout << "No such value found.\n";
                //Pause();
                Pause();
            }
            break;
        }
    }
}
