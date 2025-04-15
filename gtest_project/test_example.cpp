#include <gtest/gtest.h>
#include <bits/stdc++.h>
using namespace std;

class StudentManager {
private:
    string student[100];
    int studentCount = 0;

public:
    void Add(const string& name) {
        student[studentCount] = name;
        studentCount++;
    }

   

    vector<string> GetAllStudentNames() const {
        vector<string> names;
        for (int j = 0; j < studentCount; j++) {
            names.push_back(student[j]);
        }
        return names;
    }
};


