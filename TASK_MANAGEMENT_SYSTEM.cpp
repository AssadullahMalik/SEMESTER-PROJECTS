#include <iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class Assignee {
public:
    string id;
      string name;
     string email;
    string phone;
};
class Task {
public:
    string id;
     string name;
     string status;
};
const int MAX_ASSIGNEES = 100;
const int MAX_TASKS = 100;
Assignee assignees[MAX_ASSIGNEES];
 Task tasks[MAX_TASKS];
int assigneeCount = 0;
int taskCount = 0;
void addAssignee() {
    if (assigneeCount >= MAX_ASSIGNEES) {
        cout << "Maximum number of assignees reached.\n";
        return;
    }
    Assignee a;
    cout << "Enter Assignee ID: "; cin >> a.id;
    cout << "Enter Name: ";
	 cin.ignore();
	 getline(cin, a.name);
    cout << "Enter Email: "; cin >> a.email;
    cout << "Enter Phone: "; cin >> a.phone;
    assignees[assigneeCount] = a;
    assigneeCount++;
    cout << "Assignee added successfully!\n";
    cout<<"press any key to continue \n";getch();system("CLS");
}
void viewAssignees() {
    for (int i = 0; i < assigneeCount; ++i) {
        cout << "ID: " << assignees[i].id<<endl;
            cout << "Name: " << assignees[i].name<<endl;
            cout << "Email: " << assignees[i].email<<endl;
            cout << "Phone: " << assignees[i].phone << endl;
}
    cout<<"press any key to continue \n";getch();system("CLS");
}
void updateAssignee() {
    string id;
    cout << "Enter Assignee ID to update: "; cin >> id;
    for (int i = 0; i < assigneeCount; ++i) {
        if (assignees[i].id == id) {
            cout << "Enter new details:\n";
            cout << "Name: "; cin.ignore(); getline(cin, assignees[i].name);
            cout << "Email: "; cin >> assignees[i].email;
            cout << "Phone: "; cin >> assignees[i].phone;
            cout << "Assignee updated successfully!\n";
            cout<<"press any key to continue \n";getch();system("CLS");
            return;
        }
    }
    cout << "Assignee not found!\n";
    cout<<"press any key to continue \n";getch();system("CLS");
}
void deleteAssignee() {
    string id;
    cout << "Enter Assignee ID to delete: "; cin >> id;
    for (int i = 0; i < assigneeCount; ++i) {
        if (assignees[i].id == id) {
            for (int j = i; j < assigneeCount - 1; ++j) {
                assignees[j] = assignees[j + 1]; 
            }
            assigneeCount--;
            cout << "Assignee deleted successfully!\n";
            cout<<"press any key to continue \n";getch();system("CLS");
            return;
        }
    }
    cout << "Assignee not found!\n";
    cout<<"press any key to continue \n";getch();system("CLS");
}
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Maximum number of tasks reached.\n";
        cout<<"press any key to continue \n";getch();system("CLS");
        return;
    }

    Task t;
    cout << "Enter Task ID: "; cin >> t.id;
    cout << "Enter Task Name: "; cin.ignore(); getline(cin, t.name);
    cout << "Enter Task Status (Pending/In Progress/Completed): "; getline(cin, t.status);
    tasks[taskCount] = t;
    taskCount++;
    cout << "Task added successfully!\n";
    cout<<"press any key to continue \n";getch();system("CLS");
}
void viewTasks() {
    for (int i = 0; i < taskCount; ++i) {
        cout << "Task ID: " << tasks[i].id;
          cout << ", Name: " << tasks[i].name;
           cout << ", Status: " << tasks[i].status << endl;
           cout<<"press any key to continue \n";getch();system("CLS");
    }
}
void updateTask() {
    string taskID;
    cout << "Enter Task ID to update: "; cin >> taskID;
    for (int i = 0; i < taskCount; ++i) {
        if (tasks[i].id == taskID) {
            cout << "Enter new Task Name: "; cin.ignore(); getline(cin, tasks[i].name);
            cout << "Enter new Task Status: "; getline(cin, tasks[i].status);
            cout << "Task updated successfully!\n";
            cout<<"press any key to continue \n";getch();system("CLS");
            return;
        }
    }
    cout << "Task not found!\n";
    cout<<"press any key to continue \n";getch();system("CLS");
}

void deleteTask() {
    string taskID;
    cout << "Enter Task ID to delete: "; cin >> taskID;
    for (int i = 0; i < taskCount; ++i) {
        if (tasks[i].id == taskID) {
            for (int j = i+1; j < taskCount; ++j) {
                tasks[j] = tasks[j + 1];  
            }
            taskCount--;
            cout << "Task deleted successfully!\n";
            cout<<"press any key to continue \n";getch();system("CLS");
            return;
        }
    }
        cout << "Task not found!\n";
        cout<<"press any key to continue \n";getch();system("CLS");
}
void generateReport() {
    for (int i = 0; i < assigneeCount; ++i) {
        cout << "Assignee ID: " << assignees[i].id << endl;
        cout << "Name: " << assignees[i].name << endl;
        cout << "Email: " << assignees[i].email << endl;
        cout << "Phone: " << assignees[i].phone << endl;
        cout << "Tasks:\n";
        for (int j = 0; j < taskCount; ++j) {
            cout << "  Task ID: " << tasks[j].id<<endl;
              cout   << " Name: " << tasks[j].name<<endl;
                cout << "  B Status: " << tasks[j].status << endl;
        }
    }
    cout<<"press any key to continue \n";getch();system("CLS");
}
int main() {
    int choice;
    do {
        cout << "\nTask Management System\n";
        cout << "1. Add Assignee\n";
        cout << "2. View Assignees\n";
        cout << "3. Update Assignee\n";
        cout << "4. Delete Assignee\n";
        cout << "5. Add Task\n";
        cout << "6. View Tasks\n";
        cout << "7. Update Task\n";
        cout << "8. Delete Task\n";
        cout << "9. Generate Reports\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			system("CLS");
			addAssignee();
			 break;
            case 2:
			system("CLS");
			viewAssignees();
			cout<<"PRESS ANY KEY TO CONTINUE ";getch();system("CLS"); 
			 break;
            case 3:
			system("CLS");
			 updateAssignee();
			 break;
            case 4:
			system("CLS");
			 deleteAssignee();
			 break;
            case 5:
			system("CLS");
			 addTask();
			 break;
            case 6: 
           	system("CLS");
			viewTasks();
			 break;
            case 7:
			system("CLS");
			 updateTask();
			 break;
            case 8:
			system("CLS");
			 deleteTask();
			 break;
            case 9:
			system("CLS");
			 generateReport();
			 break;
            case 0: cout << "Exiting...\n";
			 break;
            default: cout << "Invalid choice. Try again.\n"; 
        }
    } while (choice != 0);

    return 0;
}
