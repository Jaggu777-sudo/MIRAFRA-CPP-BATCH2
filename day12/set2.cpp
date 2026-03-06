#include <iostream>
#include <set>
#include <string>

class Task {
public:
    std::string name;
    int priority;
    int tid;

    Task(const std::string& name, int priority, int tid) : name(name), priority(priority), tid(tid) {}

    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << "Task: " << task.name << ", Priority: " << task.priority << ", TID: " << task.tid;
        return os;
    }
};

struct compare {
    bool operator()(const Task& left, const Task& right) const {
        if (left.priority == right.priority) {
            return left.tid < right.tid; 
        }
        return left.priority < right.priority; 
    }
};

int main() {
    std::set<Task,compare> taskQueue;

    taskQueue.insert(Task("Task1", 1, 1));
    taskQueue.insert(Task("Task2", 3, 1));
    taskQueue.insert(Task("Task3", 3, 2));

    for (const auto& t : taskQueue) {
        std::cout << t << std::endl;
    }

    return 0;
}

