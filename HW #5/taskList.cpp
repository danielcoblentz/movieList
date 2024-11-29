#include <iostream>
#include <string>
using namespace std;

// Define the structure for a task node
struct Task {
    string name;
    Task* next;

    Task(string n) : name(n), next(nullptr) {}
};


//create TaskList class (public)
class TaskList {
public:
    Task* head;

    TaskList() : head(nullptr) {}

    // Add task at the Start
    void addTaskFromFirst(string taskName) {
        Task* newTask = new Task(taskName);
        newTask->next = head;
        head = newTask;
        cout << "Added task at start: " << taskName << endl;
    }

    // Add task at the End
    void addTaskFromLast(string taskName) {
        Task* newTask = new Task(taskName);
        if (!head) {
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newTask;
        }
        cout << "Task added at the end: " << taskName << endl;
    }

    // Add task at a specific Position
    void addTask(int position, string taskName) {
        Task* newTask = new Task(taskName);
        if (position == 0) {
            newTask->next = head;
            head = newTask;
        } else {
            Task* temp = head;
            for (int i = 0; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (!temp) {
                cout << "Position out of range: " << position << endl;
                delete newTask;
                return;
            }
            newTask->next = temp->next;
            temp->next = newTask;
        }
        cout << "Task added at the specified position " << position << ": " << taskName << endl;
    }



    // Delete the first task in the LL
    void deleteFirstTask() {
        if (!head) {
            cout << "no tasks to delete!" << endl;
            return;
        }
        Task* temp = head;
        head = head->next;
        cout << "deleted task: " << temp->name << endl;
        delete temp;
    }


    // Delete the last task in LL
    void deleteLastTask() {
        if (!head) {
            cout << "No tasks to delete!" << endl;
            return;
        }

        if (!head->next) {
            cout << "Deleted task: " << head->name << endl;
            delete head;
            head = nullptr;
            return;
        }
        Task* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        cout << "Deleted task: " << temp->next->name << endl;
        delete temp->next;
        temp->next = nullptr;
    }


    //Remove a task by task name
    void removeTask(string taskName) {
        if (!head) {
            cout << "Task list is empty!" << endl;
            return;
        }
        if (head->name == taskName) {
            Task* temp = head;
            head = head->next;
            cout << "Task removed: " << taskName << endl;
            delete temp;
            return;
        }
        Task* temp = head;
        while (temp->next && temp->next->name != taskName) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Task not found: " << taskName << endl;
            return;
        }
        Task* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "Task removed: " << taskName << endl;
        delete toDelete;
    }



    // Swap two tasks by task names
    void swapTasks(string taskName1, string taskName2) {
        if (taskName1 == taskName2) {
            cout << "Task names are the same; no need to swap!" << endl;
            return;
        }
        Task *prev1 = nullptr, *curr1 = head;
        while (curr1 && curr1->name != taskName1) {
            prev1 = curr1;
            curr1 = curr1->next;
        }
        Task *prev2 = nullptr, *curr2 = head;
        while (curr2 && curr2->name != taskName2) {
            prev2 = curr2;
            curr2 = curr2->next;
        }
        if (!curr1 || !curr2) {
            cout << "One or both tasks not found" << endl;
            return;
        }
        if (prev1) prev1->next = curr2;
        else head = curr2;

        if (prev2) prev2->next = curr1;
        else head = curr1;

        Task* temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
        cout << "Tasks swapped: " << taskName1 << " and " << taskName2 << endl;
    }



    // reverse the task list
    void reverseList() { //(new feature 1. reverse task list)

        Task* prev = nullptr;
        Task* current = head;
        Task* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "Reversed the task list." << endl;
    }

    // find task position by name
    int findTaskPosition(string taskName) { // (new feature 2. find task position by name)
        Task* current = head;
        int position = 0;
        while (current) {
            if (current->name == taskName) {
                cout << "Task \"" << taskName << "\" found at position " << position << endl;
                return position;
            }
            current = current->next;
            position++;
        }
        cout << "Task \"" << taskName << "\" not found." << endl;
        return -1;
    }

    // Display the list of tasks
    void displayTasks() {
        if (!head) {
            cout << "Task list is empty." << endl;
            return;
        }
        cout << "Task list:" << endl;
        Task* current = head;
        while (current) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

//main  for testing

int main() {
    TaskList taskList;

    // ddd tasks
    taskList.addTaskFromFirst("task1");
    taskList.addTaskFromLast("task2");
    taskList.addTaskFromLast("task3");
    taskList.displayTasks();


    // reverse the list
    taskList.reverseList();
    taskList.displayTasks();



    //find task position
    int position = taskList.findTaskPosition("task1");
    if (position != -1)
        cout << "Task position " << position << " found." << endl;

    else
        cout << "Task position " << position << " not found." << endl;


// find task position of another task
    position = taskList.findTaskPosition("task3");
    if (position != -1)
        cout << "Task position " << position << " found." << endl;
    else
        cout << "Task position " << position << " not found." << endl;



    // swap tasks
    taskList.swapTasks("task1", "task2");
    taskList.displayTasks();

    //deleting tasks
    taskList.deleteFirstTask();
    taskList.displayTasks();


    //test reversing an empty list
    TaskList emptyTaskList;
    cout << " reversing an empty list:" << endl;
    emptyTaskList.reverseList();
    emptyTaskList.displayTasks();


    //reversing a single-node list
    TaskList singleTaskList;
    singleTaskList.addTaskFromFirst("Only Task");
    cout << "\nTesting reversing a single-node list:" << endl;
    singleTaskList.displayTasks();
    singleTaskList.reverseList();
    singleTaskList.displayTasks();



    return 0;
}

