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

    void Remove(const string& name) {
        int f = -1;
        for (int i = 0; i < studentCount; i++) {
            if (student[i] == name) {
                f = i;
                break;
            }
        }
        if (f != -1) {
            for (int i = f; i < studentCount - 1; i++) {
                swap(student[i], student[i + 1]);
            }
            studentCount--;
        }
    }

    vector<string> GetAllStudentNames() const {
        vector<string> names;
        for (int j = 0; j < studentCount; j++) {
            names.push_back(student[j]);
        }
        return names;
    }
};


TEST(StudentManagerTest, AddStudents) {
    StudentManager sm;
    sm.Add("Tonmoy");
    sm.Add("Fahim");

    vector<string> expected = {"Tonmoy", "Fahim"};
    EXPECT_EQ(sm.GetAllStudentNames(), expected);
}

TEST(StudentManagerTest, RemoveStudent) {
    StudentManager sm;
    sm.Add("Tonmoy");
    sm.Add("Fahim");
    sm.Add("Karim");

    sm.Remove("Fahim");

    vector<string> expected = {"Tonmoy", "Karim"};
    EXPECT_EQ(sm.GetAllStudentNames(), expected);
}

TEST(StudentManagerTest, RemoveNonExistentStudent) {
    StudentManager sm;
    sm.Add("Tonmoy");

    sm.Remove("NotInList");

    vector<string> expected = {"Tonmoy"};
    EXPECT_EQ(sm.GetAllStudentNames(), expected);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
