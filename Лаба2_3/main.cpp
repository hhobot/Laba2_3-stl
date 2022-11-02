#include "Student.h"
using namespace std;

void write_ball(int& ball)
{
    string s;
    try
    {
        cin >> s;
        ball = stoi(s);
        if (ball < 0)
            throw exception("The mark must be greater than zero\n");
    }
    catch (const std::invalid_argument&)
    {
        cout << "Incorrect value\n";
        write_ball(ball);
    }
    catch (const std::exception& e)
    {
        cout << e.what();
        write_ball(ball);
    }
}

int main()
{
    int count;
    string name;

    cout << "Write how many students you have\n";

    cin >> count;
    Student* temp_student;
    map<string, int>* temp_mark_book;
    map<int, Student> book_marks;
    int temp_ball_dif = 0, temp_ball_nach = 0, temp_ball_oop = 0, temp_number = 0;
    for (int i = 0; i < count; i++)
    {
        temp_mark_book = new map<string, int>();
        cout << "Write name of student\n";
        cin >> name;
        cout << "Write mark on diffusions\n";
        write_ball(temp_ball_dif);
        temp_mark_book->insert(map<string, int>::value_type("diffusions", temp_ball_dif));
        cout << "Write mark on nachert\n";
        write_ball(temp_ball_nach);
        temp_mark_book->insert(map<string, int>::value_type("nachert", temp_ball_nach));
        cout << "Write mark on OOP\n";
        write_ball(temp_ball_oop);
        temp_mark_book->insert(map<string, int>::value_type("OOP", temp_ball_oop));
        temp_student = new Student(name, *temp_mark_book);
        cout << "Write number of markbook\n";
        cin >> temp_number;
        book_marks.insert(map<int, Student>::value_type(temp_number, *temp_student));
    }

    for (auto it = book_marks.begin(); it != book_marks.end(); it++) {
        cout <<'\n' << "Name:\t" << it->second.getName() << '\n';
        cout << "Number on student's markbook:\t" << it->first << "\n";
        it->second.printMark();
    }



}
