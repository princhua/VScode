#include "workermanager.h"
#include"employee.h"
#include "manager.h"
#include "boss.h"
workermanager::workermanager(){

 
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
           this->m_emparray = NULL;
               //初始化属性
        this->m_empnum = 0;
        this->m_fileisnull = true;
        ifs.close();
        return;
    }
    //存在数据为空
    char ch;
    ifs >> ch;//读走一个字符
    if(ifs.eof())//此函数为真代表数据已读完
    {
        cout << "文件为空" << endl;
                  this->m_emparray = NULL;
               //初始化属性
        this->m_empnum = 0;
        this->m_fileisnull = true;
        ifs.close();
        return;
    }
    //存在且不为空
    int num = this->get_empnum();
    cout << "职工人数为" << num << endl;
    //初始化类中数据！！！很重要，避免指针访问越界
    //cout << "未初始化的人数：" << this->m_empnum << endl;
    this->m_empnum = num;
    this->m_emparray = new worker *[this->m_empnum];
    this->init_emp();
    this->m_fileisnull = false;
    //测试代码
    // for (int i = 0; i < this->m_empnum;i++){
    //     cout << "职工编号：" << this->m_emparray[i]->m_id
    //          << "姓名：" << this->m_emparray[i]->m_name 
    //          << "部门编号：" << this->m_emparray[i]->deptid<< endl;
    // }
}
workermanager::~workermanager(){
    if(this->m_emparray!=NULL){
        delete[] this->m_emparray;
        this->m_emparray = NULL;
    }
}
void workermanager::show_menu(){
    cout << "*****************************" << endl;
    cout << "*****   1.添加员工     *****" << endl;
    cout << "*****   2.显示员工     *****" << endl;
    cout << "*****   3.删除员工     *****" << endl;
    cout << "*****   4.修改员工     *****" << endl;
    cout << "*****   5.查找员工     *****" << endl;
    cout << "*****   6.按照编号排序  *****" << endl;
    cout << "*****   7.清空系统     *****" << endl;
    cout << "*****   0.退出系统     *****" << endl;
    cout << "*****************************" << endl;
}
int workermanager::exitsys(){
    cout << "欢迎下次使用" << endl;
    exit( 0);//exit退出当前程序
}

void workermanager::add_emp(){
    cout << "输入要添加的数量" << endl;
    int addnum;
    cin >> addnum;
    if(addnum>0){
        int newsize = this->m_empnum + addnum;
         worker**newspace= new worker *[newsize]; // worker是抽象类不能实例化数组，所以用worker*的数组
        if( this->m_emparray!=NULL){
            for (int i = 0; i < this->m_empnum;i++)
            {
                newspace[i] = this->m_emparray[i];
            }
        }
        for (int i = 0; i < addnum;i++){
            int id;
            string name;
            int dept;
            cout << "请输入第" << i + 1 << "个员工编号" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个员工姓名" << endl;
            cin >> name;
            cout << "请选择该员工岗位" << endl;
            cout << "1.垃圾" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dept;
            worker *aworker = NULL;
            switch (dept)
            {
            case 1:
                aworker = new employee(id, name, dept);
                break;
            case 2:
                aworker = new manager(id, name, dept);
                break;
            case 3:
                aworker = new boss(id, name, dept);
                break;
            
            default:
                break;
            }
            newspace[this->m_empnum + i] = aworker;
        }
            //释放原来空间delete[]
        delete[] this->m_emparray;
        //更新人数
        this->m_empnum = newsize;
        this->m_emparray = newspace;
        cout << "添加成功" << endl;
        this->save();
        this->m_fileisnull = false;
    }
    else{
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}
void workermanager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_empnum;i++)
    {
        ofs << this->m_emparray[i]->m_id << "\t"
            << this->m_emparray[i]->m_name << "\t"
            << this->m_emparray[i]->deptid << "\t" <<endl;
    }
    ofs.close();
}
int workermanager::get_empnum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dnum;
    int num = 0;
    while(ifs>>id&&ifs>>name&&ifs>>dnum)
    {
        num++;
    }
    return num;
}
    //初始化员工
    void workermanager::init_emp(){
        ifstream ifs;
        ifs.open(FILENAME, ios::in);
        int id;
        string name;
        int dept;
        int index = 0;
        while(ifs>>id&&ifs>>name&&ifs>>dept)
        {
            worker *a_worker;
            if(dept==1){
                a_worker = new employee(id, name, dept);
            }
            else if(dept==2){
                a_worker = new manager(id, name, dept);
            }
            else 
            {
                a_worker=new boss(id, name, dept);
            }
            this->m_emparray[index] = a_worker;
            index++;
        }
        ifs.close();
    }
    void workermanager::show_emp()
    {
        //判断文件
        if(this->m_fileisnull)
        {
            cout << "文件为空或不存在" << endl;
        }
        else
        {
            for (int i = 0; i < this->m_empnum;i++)
            {
                this->m_emparray[i]->showinfo();
                cout << endl;
            }
        }
        system("pause");
        system("cls");
    }
    int workermanager::is_exist(int id){
        int index = -1;
        for (int i = 0; i < this->m_empnum;i++)
        {
            if(this->m_emparray[i]->m_id==id){
                index = i;
                break;
            }

        }
        return index;
    }
        void workermanager::del_emp(){
            if(this->m_fileisnull){
                cout << "文件为空或不存在" << endl;
            }
            else{
                int id = 0;
                cout << "请输入要删除的员工编号:" << endl;
                cin >> id;
                int index = this->is_exist(id);
                if(index>-1){
                    for (int i = index; i < this->m_empnum-1;i++){
                        this->m_emparray[i] = this->m_emparray[i + 1];
                    }
                    this->m_empnum--;
                    this->save();
                    cout << "删除成功" << endl;
                }
                else
                {
                    cout << "删除失败,员工不存在" << endl;
                }
            }
        }
        void workermanager::alter_emp(){
            if(this->m_fileisnull){
                cout << "文件为空或不存在" << endl;
            }
            else{
                int id = 0;
                cout << "请输入要修改的员工编号:" << endl;
                cin >> id;
                int index = this->is_exist(id);
                if(index>-1){
                    delete this->m_emparray[index];
                    int newid=0;
                    string name = "";
                    int dept = 0;
                    cout << "查到" << id << "号员工";
                    cout << "输入新编号" << endl;
                    cin >> newid;
                    cout << "输入名字" << endl;
                    cin >> name;
                    cout << "请选择该员工岗位" << endl;
                    cout << "1.垃圾" << endl;
                    cout << "2.经理" << endl;
                    cout << "3.老板" << endl;
                    cin >> dept;
                    worker *worker = NULL;
                    switch (dept)
                    {
                    case 1:
                        worker = new employee(newid, name, dept);
                        break;
                    case 2:
                        worker = new manager(newid, name, dept);
                        break;
                    case 3:
                        worker = new boss(newid, name, dept);
                        break;
                    
                    default:
                        break;
                    }
                    this->m_emparray[index] = worker;
                    cout << "修改成功" << endl;
                    //!!!保存到文件
                    this->save();
                }
                else{
                    cout << "查无此人，修改失败" << endl;
                }
            }
            system("pause");
            system("cls");
        }
    void workermanager::find_emp(){
        if(this->m_fileisnull){
                cout << "文件为空或不存在" << endl;
            }
            else{
                cout << "输入查找的方式：" << endl;
                cout << "1.编号\t2.姓名\t" << endl;
                int select = 0;
                cin >> select;
                switch(select)
                {
                    case 1:
                    {    
                        int id = 0;
                        cout << "请输入要查找的员工编号:" << endl;
                        cin >> id;
                        int index = this->is_exist(id);
                        if(index>-1){
                            cout << "查到的员工信息：" << endl;
                            this->m_emparray[index]->showinfo();
                            cout << endl;
                        }
                        else{
                            cout << "查无此人" << endl;
                        }
                    }
                    break;
                    //按姓名查找
                    case 2:
                    {
                        string name="";
                        cout << "请输入要查找的员工姓名:" << endl;
                        cin >> name;
                        //bool flag = true;
                        for (int i = 0; i < this->m_empnum;i++){
                            if(this->m_emparray[i]->m_name == name){
                                cout << "查找成功，信息如下：" << endl;
                                this->m_emparray[i]->showinfo();
                                cout << endl;
                                system("pause");
                                system("cls");
                                // flag = false;
                                return;
                            }
                            
                        }
                        cout << "查无此人" << endl;
                    }
                    break;
                    default:
                        cout << "输入有误" << endl;
                        break;
                }
            }
            system("pause");
            system("cls");
    }

    void workermanager::sort_emp(){
        if(this->m_fileisnull)
        {
            cout << "文件不存在或为空" << endl;
            system("pause");
            system("cls");
        }
        else
        {
            cout << "选择排序方式:" << endl;
            cout << "1.按工号升序" << endl;
            cout << "2.按工号降序" << endl;
            int select = 0;
            cin >> select;
            for (int i = 0; i < m_empnum;i++)
            {
                int minormax = i;
                for (int j = i + 1; j < m_empnum;j++)
                {
                    if (select == 2)//降序
                    {
                        if(this->m_emparray[minormax]->m_id<this->m_emparray[j]->m_id){
                            minormax = j;
                        }
                    }
                    else{
                        if(this->m_emparray[minormax]->m_id>this->m_emparray[j]->m_id){
                            minormax = j;
                        }
                    }
                }
                worker *temp = this->m_emparray[minormax];
                this->m_emparray[minormax] = this->m_emparray[i];
                this->m_emparray[i] = temp;
            }
        }
        cout << "排序成功！排序后结果为：" << endl;
        save();
        show_emp();
        }
void workermanager::clean(){
    cout << "确定清空？" << endl;
    int select = 0;
    cout << "1.确认\t" << "2.退出" << endl;
    cin >> select;
    if(select==1){
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc); // ios::trunc删除文件然后重新创建相当于清空
        ofs.close();
        if(this->m_emparray!=NULL){
            for (int i = 0; i < m_empnum;i++){
                delete this->m_emparray[i];
                this->m_emparray[i] = NULL;
            }
            delete[] this->m_emparray;
            this->m_emparray = NULL;
            m_empnum = 0;
            m_fileisnull = true;
        }
        cout << "清空成功" << endl;
    }
    system("pause");
    system("cls");
}