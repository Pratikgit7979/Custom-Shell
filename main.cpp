#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    cout << "Custom Shell Ready > ";
    while (getline(cin, input)) {
        if (input == "exit") break;
        cout << "Executing: " << input << endl;
        vector<string> args;
        string token;
        stringstream ss(input);
        while (ss >> token) args.push_back(token);
        vector<char*> argv;
        for (auto &arg : args) argv.push_back(&arg[0]);
        argv.push_back(nullptr);
        pid_t pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv.data());
            perror("execvp failed");
            exit(1);
        } else {
            waitpid(pid, nullptr, 0);
        }
        cout << "Custom Shell Ready > ";
    }
    cout << "Shell exited." << endl;
    return 0;
}
