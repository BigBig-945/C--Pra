//项目要求
//1、添加联系人：向通讯录中添加新人，信息包括(姓名、性别、年龄、联系电话、家庭住址)、上限1000人
//2、显示联系人：显示通信录中所有联系人信息
//3、删除联系人：按照姓名进行删除指定联系人
//4、查找联系人：按照姓名查看指定联系人信息
//5、修改联系人：按照姓名重新修改指定联系人
//6、清空联系人：清空通信录中所有信息
//7、退出通信录：推出当前使用的通讯录

#include<iostream>
using namespace std;
#include<string>
#define Max 1000

//联系人结构体
struct People
{
	string p_Name; //姓名
	int p_Sex; //性别 接判断 1、男 2、女
	int p_Age; // 年龄
	string p_Phonum; // 电话
	string p_Addr; // 住址
};

struct Communlet
{
	struct People peopleArray[Max];
	int c_Size;

};

//菜单界面
void showMenu() {
	for (int i = 0; i < 25; ++i) 
{
		cout << "*" ;
	}

	cout << "\n" ;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通信录 *****" << endl;

	for (int i = 0; i < 25; ++i) {
		cout << "*";
	}
	cout << endl ;
}

//添加联系人
void addPeople(Communlet * clet) {

	//判度通讯录是否已经达到存储的最大值
	if (clet->c_Size == Max)
	{
		cout << "通讯录已满，你可以选择删除联系人或者清空通讯录" << endl;
		return;
	}
	else {
		//输入姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		clet->peopleArray[clet->c_Size].p_Name = name;

		//输入性别
		int sex = 0;
		cout << "请输入性别(1代表男，2代表女)" << endl;
		
		while(true)
		{
			cin >> sex;
			//判度输入是否在范围内，1或2写入并跳出循环，其他重复循环
			if (sex == 1 || sex == 2)
			{
				clet->peopleArray[clet->c_Size].p_Sex = sex;
				break;
			}else{
				cout << "输入有误" << endl;
			}
		}

		//输入年龄
		int age = 0;
		cout << "请输入年龄" << endl;
		
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 200) 
			{
				clet->peopleArray[clet->c_Size].p_Age = age;
				break;
			}
			else
			{
				cout << "请输入正常的年龄范围" << endl;
			}
		}
		
		//输入电话
		string phonenum;
		cout << "请输入电话" << endl;
		
		while (true)
		{
			cin >> phonenum;
			if ( phonenum.length() == 11)
			{
				clet->peopleArray[clet->c_Size].p_Phonum = phonenum;
				break;
			}
			else
			{
				cout << "请输入正确的电话号码" << endl;
			}
		}

		//输入住址
		string addres;
		cout << "请输入住址" << endl;

		cin >> addres;
		clet->peopleArray[clet->c_Size].p_Addr = addres;

		//更新通讯录人数
		clet->c_Size++;
		cout << "添加成功" <<  endl;

		system("pause");
		system("cls");
	
	}
	
}

//显示联系人
void showPeople(Communlet* clet)
{
	string sexs;
	if(clet->c_Size != 0)
	{
		for (int i = 0; i < clet->c_Size; ++i) {
			if (clet->peopleArray[i].p_Sex == 1)
			{
				sexs = "男";
			}
			else
			{
				sexs = "女";
			}
			//性别的转化还可以用三目运算符(clet->peopleArray[i].p_Sex == 1 ？"男":"女")

			cout << "姓名: " << clet->peopleArray[i].p_Name << " 性别: " << sexs << " 年龄: " << clet->peopleArray[i].p_Age << " 电话: " << clet->peopleArray[i].p_Phonum << " 住址: " << clet->peopleArray[i].p_Addr << endl;
		}
	}
	else 
	{
		cout << "通讯录人数为0" << endl;
	}
	system("pause");
	system("cls");
	return;
}

//检测联系人是否存在，逻辑：如果存在返回该姓名具体的位置(数组编号)，如果不存在就返回-1，为什么写这个是因为，不管是删除联系人
//查找联系人还是修改联系人，都要判断联系人是否存在
int detectPeople(Communlet * clet,string name) {//有返回值了，函数类型不能是void了

	for (int i = 0; i < clet->c_Size;++i) {
		if (name == clet->peopleArray[i].p_Name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void removePeople(Communlet * clet) {

	cout << "请输入要删除的联系人" <<endl;
	string name;
	cin >> name;

	int retu = detectPeople(clet, name);
	//判度逻辑：如果返回值是-1，则查无此人，如果返回值 ！= -1，则就删除联系人
	if (retu != -1) 
	{
		//删除的逻辑是让后面的数据依次向前递进一位，即让array[3]的数据取代array[2]的数据，依次取代，逻辑上删除。同时数组中元素的个数减一
		for (int i = retu; i < clet->c_Size; i++)
		{
			//通讯录人员整体前移一位
			clet->peopleArray[i] = clet->peopleArray[i + 1];
		}
		//通讯录成员减一
		--clet->c_Size;
		cout << "删除成功" <<endl;
	}
	else
	{
		cout << "没有查到要删除的联系人" << endl;
	}
	system("pause");
	system("cls");
	return;

}

//查找联系人
void findPeople(Communlet * clet) {
	cout << "请输入要查找联系人的姓名" <<endl;
	string name;
	cin >> name;

	int retu = detectPeople(clet, name);
	//判度逻辑同上一个removePeople()里的一样，先判别联系人是否存在
	if ( retu != -1)
	{
		cout << "已查询到此人" << endl;
		cout << "姓名: " << clet->peopleArray[retu].p_Name << " 性别: " << ((clet->peopleArray[retu].p_Sex == 1) ? "男" : "女") << " 年龄: " << clet->peopleArray[retu].p_Age << " 电话: " << clet->peopleArray[retu].p_Phonum << " 住址: " << clet->peopleArray[retu].p_Addr << endl;
	}
	else 
	{
		cout << "没有查到此人" <<endl;
	}

	system("pause");
	system("cls");
	return;
}

//修改联系人
void modifInform(Communlet * clet) {
	cout << "请输入您要修改的联系人" <<endl;
	string name;
	cin >> name;

	int retu = detectPeople(clet, name);

	if (retu != -1) //找到联系人
	{
		//姓名
		string name;
		cout << "请输入要修改的姓名" <<endl;
		cin >> name;
		clet->peopleArray[retu].p_Name = name;
		//性别
		cout << "请输入要修改的性别" << endl;
		int sex = 0;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				clet->peopleArray[retu].p_Sex = sex;
				break;
			}
			else
			{
				cout << "请在正确的范围里选择数字" <<endl;
			}
		}
		//年龄
		int age = 0;
		cout << "请输入要修改的年龄" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 200)
			{
				clet->peopleArray[retu].p_Age = age;
				break;
			}
			else
			{
				cout << "请输入正常的年龄范围" << endl;
			}
		}
		//电话号码
		cout << "请输入要修改的电话号码" << endl;
		string num;
		while (true)
		{
			cin >> num;
			if (num.length() == 11)
			{
				clet->peopleArray[retu].p_Phonum = num;
				break;
			}
			else
			{
				cout << "请输入正确的电话号码" << endl;
			}
		}
		//住址
		string homeadd;
		cout << "请输入要修改的住址" << endl;
		cin >> homeadd;
		clet->peopleArray[retu].p_Addr = homeadd;
		
	}
	else
	{
		cout << "查无此人" <<endl;
	}
	system("pause");
	system("cls");
	return;
}

//清空联系人
void cleanPeople(Communlet* clet) {
	clet->c_Size = 0;
	cout << "通讯录已清空" <<endl;
	system("pause");
	system("cls");
}

int main() 
{
	//创建通讯录对象
	Communlet clet;
	//初始化通讯录中当前人数
	clet.c_Size = 0;
	int select = 0;
	string name;

	while (true)
	{
		showMenu();
		
		cin >> select;

		switch (select)
		{
			case 1:	//1、添加联系人
				addPeople(&clet); //传递结构体的地址，才能真正的修改已经创建的通讯录对象
				break;
			case 2:	//2、显示联系人
				showPeople(&clet);
				break;
			case 3:	//3、删除联系人
			{
				//测试检测联系人函数
				/*string name;
				cout << "请输入要删除的姓名" << endl;
				cin >> name;

				
				if (detectPeople(&clet, name) == -1) {
					cout << "查无此人" << endl;
				}
				else
				{
					cout << "已经查到" <<endl;
				}*/
				removePeople(&clet);
				break;
			}
			case 4:	//4、查找联系人
				findPeople(&clet);
				break;
			case 5:	//5、修改联系人
				modifInform(&clet);
				break;
			case 6:	//6、清空联系人
				cleanPeople(&clet);
				break;
			case 0:	//0、退出通信录
				cout << "欢迎下次使用通讯系统" << endl;
				system("pause");
				return 0;
				break;
			default :
				cout << "请输入规定选项" << endl;
				break;
		}


	}

	system("pause");
	return 0;
}