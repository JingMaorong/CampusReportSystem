#include <iostream>
using namespace std;

struct Ticket
{

    //associating with algorithm 
    int TicketID;
    string ReportName;
    int Priority;

    //information only
    string Location;
    string Category;
    string Description;
    string CreatedTime;


};

//define node
struct Node
{
    Ticket data;
    Node* next = nullptr;


};


class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;//initialize head ptr empty
    }


    //----------------------------上面代码都不要动，DONT NOT change above code------------------------------


    void TestDataSet()//方便测试用的数据，最后可保留，也可不保留
    {
        Ticket t1;
        t1.TicketID = 6;
        t1.ReportName = "Alice";
        t1.Priority = 3;
        t1.Location = "Lab3";
        t1.Category = "Network";
        t1.Description = "Internet connection unstable";
        t1.CreatedTime = "2025-01-01";
        InsertSorted(t1);

        Ticket t2;
        t2.TicketID = 1;
        t2.ReportName = "Bob";
        t2.Priority = 5;
        t2.Location = "Library";
        t2.Category = "Facilities";
        t2.Description = "Air-conditioner not working";
        t2.CreatedTime = "2025-01-02";
        InsertSorted(t2);

        Ticket t3;
        t3.TicketID = 7;
        t3.ReportName = "Carol";
        t3.Priority = 2;
        t3.Location = "LectureHall";
        t3.Category = "Equipment";
        t3.Description = "Projector flickering";
        t3.CreatedTime = "2025-01-03";
        InsertSorted(t3);

        Ticket t4;
        t4.TicketID = 4;
        t4.ReportName = "David";
        t4.Priority = 4;
        t4.Location = "Office";
        t4.Category = "Network";
        t4.Description = "Cannot access system";
        t4.CreatedTime = "2025-01-04";
        InsertSorted(t4);
    }

    //2. For new ticket insertion, insert ticket in sorted order by Ticket ID(ascending).  
    //根据ID升序排序

    void InsertSorted(Ticket newTicket)//finished , DO NOT modify，  已经完成,非必要不修改
    {
        Node* newNode = new Node;
        newNode->data = newTicket;


        //empty head or ID smaller than head ,  use head insert
        // 头指针为空 或者小于node里的元素
        if (head == nullptr || newTicket.TicketID <= head->data.TicketID)
        {
            newNode->next = head;
            head = newNode;
            return;
        }


        //双指针比较插入，two ptrs insert
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && newTicket.TicketID > curr->data.TicketID)
        {
            prev = curr;
            curr = curr->next;

        }

        //change ptrs
        newNode->next = curr;
        prev->next = newNode;


    }



    // 3. For ticket deletion, remove by Ticket ID
    //根据ID来删除
    void Delete(int targetID) //-----------已经完成,非必要不要修改
    {

        //head empty
        if (head == nullptr)
        {
            cout << "The linked list is empty.\n" << endl;
            return;
        }


        //if head is to be deleted
        if (targetID == head->data.TicketID)
        {
            Node* temp = head;//temp存储head
            head = head->next;
            delete temp;

            cout << "Head node is deleted, the deleted Ticket ID is " << targetID << endl;
            return;

        }

        //-------------delete middle node------------

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data.TicketID != targetID)//不空，不同直接往后找
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)//没找到
        {
            cout << "The ticket is not found." << endl;
            return;

        }

        //找到了，删除节点
        prev->next = curr->next;
        delete curr;

        cout << "The deleted ticket ID is " << targetID << endl;
    }


    //Part B:  search by Ticket ID or reporter name
    //Part B:  search by Ticket ID or reporter name
    void SearchByID(int targetID) //sequential search  已经完成，不要修改
    {
        Node* temp = head;

        while (temp != nullptr && temp->data.TicketID != targetID)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "This ticket does not exist.";
            return;
        }

        if (temp->data.TicketID == targetID)
        {
            cout << "The ticket is founded.\n";

            cout << "The Ticket ID is: " << targetID << endl;
            cout << "The reporter name is: " << temp->data.ReportName << endl;
            cout << "Priority: " << temp->data.Priority << endl;
            cout << "The location is: " << temp->data.Location << endl;
            cout << "The Problem Category is: " << temp->data.Category << endl;
            cout << "Problem Description: " << temp->data.Description << endl;
            cout << "Ticket Created Time: " << temp->data.CreatedTime << endl;
        }

    }


    void SearchByName(string reportName)//sequential search  已经完成，不要修改
    {
        Node* temp = head;


        while (temp != nullptr && temp->data.ReportName != reportName)
        {
            temp = temp->next;

        }


        if (temp == nullptr)
        {
            cout << "This ticket does not exist.";
            return;

        }

        if (temp->data.ReportName == reportName)
        {
            cout << "The ticket is founded.\n";
            cout << "The reporter name is: " << reportName << endl;
            cout << "The Ticket ID is: " << temp->data.TicketID << endl;
            cout << "Priority: " << temp->data.Priority << endl;
            cout << "The location is: " << temp->data.Location << endl;
            cout << "The Problem Category is: " << temp->data.Category << endl;
            cout << "Problem Description: " << temp->data.Description << endl;
            cout << "Ticket Created Time: " << temp->data.CreatedTime << endl;


        }
    }


    //Part C: 1. Sort tickets by Priority (descending)  数字越大越重要   2. Sort tickets by Reporter Name (ascending)
    //Part C: 1. Sort tickets by Priority (descending)  数字越大越重要   2. Sort tickets by Reporter Name (ascending)
    void SortByPriority() //Desc     
    {
        Node* temp = head;
        //foreach


    }


    void SortByName()//Asc
    {


    }



    //Part D: Undo Feature(Stack)

    //Action type for actions that are undoable
    enum ActionType {
        ADD,
        DELETE,
        UPDATE
    };

    //Action structure with action types and backup ticket
    struct Action {
        ActionType type;
        Ticket ticketBackup;
    };

    // Linked List Implementation of STACK
    class StackNode {
    public:
        Action data;
        StackNode* next;
    };

    class ActionStack {
    private:
        StackNode* top;

    public:
        ActionStack() {
            top = nullptr;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        void push(Action a) {
            StackNode* newNode = new StackNode;
            if (newNode == nullptr)
                cout << "Cannot allocate memory.\n";
            else {
                newNode->data = a;
                newNode->next = top;
                top = newNode;
            }
        }

        Action pop() {

            StackNode* temp = top;
            Action a = temp->data;
            top = temp->next;
            delete temp;
            return a;
        }
    };

    ActionStack undoStack; //Undo Stack that stack action objects

    //Add action被UNDO的时候, 就是delete被添加的ticket
    //所以 AddTicketUndo function把这个action type存进stack
    //When undo function run, action type = ADD, lead to delete ticket
    void AddTicketUndo(Ticket t) //push add action into undo stack
    {
        InsertSorted(t);

        Action add_act; //create an action object for add action
        add_act.type = ADD;
        add_act.ticketBackup = t;

        undoStack.push(add_act);
    }

    //Delete action被UNDO的时候, 就是把删掉的ticket加回去
    //所以 DeleteTicketUndo function把这个action type存进stack
    //When undo function run, action type = DELETE, lead to add ticket WITH backup ticket data

    bool BackupTicket(int id, Ticket& backup) //备份ticket data, when undo, copy to add back
    {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.TicketID == id) {
                backup = temp->data;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void DeleteTicketUndo(int id) //push delete action into undo stack
    {
        Ticket backup;
        //backup deleted ticket
        if (!BackupTicket(id, backup)) {
            cout << "Ticket not found. Backup unsuccessful.\n";
            return;
        }

        Delete(id);
        Action d_act;       //create an action object for delete action
        d_act.type = DELETE;
        d_act.ticketBackup = backup; //copy backup data 
        undoStack.push(d_act);
    }

    void Undo() {

        if (undoStack.isEmpty()) {
            cout << "No action to undo.\n";
            return;
        }

        Action last = undoStack.pop();

        if (last.type == ADD)
        {
            Delete(last.ticketBackup.TicketID); // Undo Add Ticket = Delete added Ticket
            cout << "Successfully undo Add action.\n";
        }
        else if (last.type == DELETE)
        {
            InsertSorted(last.ticketBackup);    // Undo Delete Ticket = Add back Ticket
            cout << "Successfully undo Delete action.\n";
        }

    }






    void Display()//Finished , DON NOT  modify,完成,可能后续要修改
    {

        Node* temp = head;

        cout << "-----------Information---------" << endl;

        if (head == nullptr)
        {
            cout << "There is no information." << endl;
        }

        while (temp != nullptr)//输出ID和名字
        {
            cout << "Ticket ID: " << temp->data.TicketID << endl;
            cout << "Name: " << temp->data.ReportName << endl;
            cout << "Priority: " << temp->data.Priority << endl;
            cout << "The location is: " << temp->data.Location << endl;
            cout << "The Problem Category is: " << temp->data.Category << endl;
            cout << "Problem Description: " << temp->data.Description << endl;
            cout << "Ticket Created Time: " << temp->data.CreatedTime << endl;
            temp = temp->next;
            cout << "------------------------------" << endl;

        }

    }


};


int main()//部分功能被我打了注释，如果要用取消注释,且功能不全,

{
    LinkedList system;

    system.TestDataSet();//测试集数据

    int choice;

    do
    {
        cout << "\n===== Campus Report System =====\n";
        cout << "1. Add ticket\n";
        cout << "2. Delete ticket\n";
        cout << "3. Search ticket\n";
        cout << "4. Update ticket status\n";
        cout << "5. Display all tickets\n";
        cout << "6. Generate report(Sort)\n";
        cout << "7. Undo last action\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
            // ================= ADD =================
        case 1:
        {
            int sub;
            do {
                cout << "\n[Add Ticket]\n";
                cout << "1. Add new ticket\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    Ticket t;
                    cout << "Enter Ticket ID: ";
                    cin >> t.TicketID;
                    cout << "Enter Reporter Name: ";
                    cin >> t.ReportName;
                    cout << "Enter the Prioriry:";
                    cin >> t.Priority;

                    //从InsertSorted()换成这个因为要记录add action in undo stack
                    system.AddTicketUndo(t);
                    system.Display();
                }

            } while (sub != 0);
            break;
        }

        // ================= DELETE =================
        case 2:
        {
            int sub;
            do {
                cout << "\n[Delete Ticket]\n";
                cout << "1. Delete by Ticket ID\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    int id;
                    cout << "Enter Ticket ID to delete: ";
                    cin >> id;

                    //从Delete()换成这个因为要记录delete action in undo stack & backup ticket data
                    system.DeleteTicketUndo(id);
                    system.Display();
                }

            } while (sub != 0);
            break;
        }

        // ================= SEARCH =================
        case 3:
        {
            int sub;
            do {
                cout << "\n[Search Ticket]\n";
                cout << "1. Search by Ticket ID\n";
                cout << "2. Search by Report Name\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    int id;
                    cout << "Enter Ticket ID to search: ";
                    cin >> id;

                    system.SearchByID(id);

                }

                if (sub == 2) {
                    string name;
                    cout << "Enter Report Name to search: ";
                    cin >> name;

                    system.SearchByName(name);
                }


            } while (sub != 0);
            break;
        }

        // ================= UPDATE STATUS =================
        case 4:
        {
            int sub;
            do {
                cout << "\n[Update Ticket Status]\n";
                cout << "1. Update status by Ticket ID\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    int id;
                    string status;
                    cout << "Enter Ticket ID: ";
                    cin >> id;
                    cout << "Enter new status: ";
                    cin >> status;

                    // 可先只改 status，不接 stack
                   // system.UpdateStatusByID(id, status);//功能被注释了

                    system.Display();
                }

            } while (sub != 0);
            break;
        }

        // ================= DISPLAY =================
        case 5:
        {
            int sub;
            do {
                cout << "\n[Display Tickets]\n";
                cout << "1. Display all tickets\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    system.Display();
                }

            } while (sub != 0);
            break;
        }

        // ================= REPORT =================
        case 6:
        {
            int sub;
            do {
                cout << "\n[Generate Report]\n";
                cout << "1. Sort by Priority (Top urgent tickets)\n";
                cout << "2. Sort by Requester name\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {             //这边要加入排序功能
                    // TODO: 队友实现
                    // system.ReportByPriority();
                    cout << "[Report by Priority not implemented yet]\n";
                }
                else if (sub == 2) {
                    // TODO: 队友实现        //这边要加入排序功能
                    // system.ReportByRequesterName();
                    cout << "[Report by Requester Name not implemented yet]\n";
                }

            } while (sub != 0);

            break;
        }


        // ================= UNDO =================
        case 7:
        {
            int sub;
            do {
                cout << "\n[Undo Last Action]\n";
                cout << "1. Undo\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    system.Undo(); //Undo last action in the stack

                }

            } while (sub != 0);
            break;
        }

        case 0:
            cout << "Exit system.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}



