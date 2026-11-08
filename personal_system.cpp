//第一次代码修改与提交测试
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class people {
protected:
    string name;
    string id;
    string sex;
    string IDcard;
    int total_hours;
    int week_hours;

public:
    people() :total_hours(0), week_hours(0) {}
    virtual ~people(){}
    virtual void input() {
        cout << "请输入姓名：";cin >> name;
        cout << "请输入编号：";cin >> id;
        cout << "请输入性别：";cin >> sex;
        cout << "请输入身份证号：";cin >> IDcard;
        cout << "请输入总学时数：";cin >> total_hours;
        cout << "请输入每周固定学时数：";cin >> week_hours;
    }
    virtual void display() {
        cout << "姓名：" << name<<"|编号："<<id<<"|性别："<<sex<<"|身份证号："<<IDcard<<"|总学时数："<<total_hours<<"|每周固定学时数："<<week_hours;
    }
};

class student :virtual public people {
public:
    virtual void display() {
        cout << "[本科生]";
        people::display();
        cout << endl;
    }
};

class teacher :virtual public people {
protected:
    int teaching_hours;

public:
    teacher() :people(),teaching_hours(0) {}
    virtual void input() {
        people::input();
        cout << "请输入每周教学时数：";cin >> teaching_hours;
    }
    virtual void display() {
        cout << "[教师]";
        people::display();
        cout << "|教学时数" << teaching_hours << endl;
    }
};

class graduate :public student {
protected:
    int research_hours;

public:
    graduate():people(),research_hours(0){}
    virtual void input() {
        people::input();
        cout << "请输入每周研究时数：";cin >> research_hours;
    }
    virtual void display() {
        cout << "[研究生]";
        people::display();
        cout << "|研究时数：" << research_hours << endl;
    }
};

class TA :public graduate, public teacher {
public:
    virtual void input() {
        cout << "---请输入助教信息---" << endl;
        people::input();
        cout << "请输入每周教学时数：";cin >> teaching_hours;
        cout << "请输入每周研究时数：";cin >> research_hours;
    }
    virtual void display() {
        cout << "[助教]";
        people::display();
        cout << "|教学时数：" << teaching_hours << "|研究时数：" << research_hours << endl;
    }
};

int main()
{ 
    vector<people*>personneList;
    int choice;
    while (true) {
        cout << "\n==========校园人员信息管理系统==========\n";
        cout << "1.录入本科生\n";
        cout << "2.录入教师\n";
        cout << "3.录入研究生\n";
        cout << "4.录入助教\n";
        cout << "5.显示所有人员信息\n";
        cout << "0.退出系统\n";
        cout << "请选择操作：";
        cin >> choice;

        if (choice == 0) break;
        
        people* p = nullptr;

        switch (choice) {
        case 1:
            p = new student();
            cout << "---请输入本科生信息---" << endl;
            p->input();
            break;
        case 2:
            p = new teacher();
            cout << "---请输入教师信息---" << endl;
            p->input();
            break;
        case 3:
            p = new graduate();
            cout << "---请输入研究生信息---" << endl;
            p->input();
            break;
        case 4:
            p = new TA();
            cout << "---请输入助教信息---" << endl;
            p->input();
            break;
        case 5:
            cout << "\n==========人员信息列表==========\n";
            if (personneList.empty())
                cout << "当前没有人员信息\n";
            else {
                for(people*person:personneList){
                    person->display();
                }
                cout<<endl;
            }
            break;
        default:
            cout << "无效选择，请重试\n";
            break;
        }
        if (choice >= 1 && choice <= 4 && p != nullptr) {
            personneList.push_back(p);
            cout << "录入成功！\n";
        }
    }
    for (people* person : personneList) {
        delete person;
    }
    cout << "系统已退出\n";
    return 0;
}

