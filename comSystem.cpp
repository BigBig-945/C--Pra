//��ĿҪ��
//1�������ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ����(�������Ա����䡢��ϵ�绰����ͥסַ)������1000��
//2����ʾ��ϵ�ˣ���ʾͨ��¼��������ϵ����Ϣ
//3��ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
//4��������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
//5���޸���ϵ�ˣ��������������޸�ָ����ϵ��
//6�������ϵ�ˣ����ͨ��¼��������Ϣ
//7���˳�ͨ��¼���Ƴ���ǰʹ�õ�ͨѶ¼

#include<iostream>
using namespace std;
#include<string>
#define Max 1000

//��ϵ�˽ṹ��
struct People
{
	string p_Name; //����
	int p_Sex; //�Ա� ���ж� 1���� 2��Ů
	int p_Age; // ����
	string p_Phonum; // �绰
	string p_Addr; // סַ
};

struct Communlet
{
	struct People peopleArray[Max];
	int c_Size;

};

//�˵�����
void showMenu() {
	for (int i = 0; i < 25; ++i) 
{
		cout << "*" ;
	}

	cout << "\n" ;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨ��¼ *****" << endl;

	for (int i = 0; i < 25; ++i) {
		cout << "*";
	}
	cout << endl ;
}

//�����ϵ��
void addPeople(Communlet * clet) {

	//�ж�ͨѶ¼�Ƿ��Ѿ��ﵽ�洢�����ֵ
	if (clet->c_Size == Max)
	{
		cout << "ͨѶ¼�����������ѡ��ɾ����ϵ�˻������ͨѶ¼" << endl;
		return;
	}
	else {
		//��������
		string name;
		cout << "����������" << endl;
		cin >> name;
		clet->peopleArray[clet->c_Size].p_Name = name;

		//�����Ա�
		int sex = 0;
		cout << "�������Ա�(1�����У�2����Ů)" << endl;
		
		while(true)
		{
			cin >> sex;
			//�ж������Ƿ��ڷ�Χ�ڣ�1��2д�벢����ѭ���������ظ�ѭ��
			if (sex == 1 || sex == 2)
			{
				clet->peopleArray[clet->c_Size].p_Sex = sex;
				break;
			}else{
				cout << "��������" << endl;
			}
		}

		//��������
		int age = 0;
		cout << "����������" << endl;
		
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
				cout << "���������������䷶Χ" << endl;
			}
		}
		
		//����绰
		string phonenum;
		cout << "������绰" << endl;
		
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
				cout << "��������ȷ�ĵ绰����" << endl;
			}
		}

		//����סַ
		string addres;
		cout << "������סַ" << endl;

		cin >> addres;
		clet->peopleArray[clet->c_Size].p_Addr = addres;

		//����ͨѶ¼����
		clet->c_Size++;
		cout << "��ӳɹ�" <<  endl;

		system("pause");
		system("cls");
	
	}
	
}

//��ʾ��ϵ��
void showPeople(Communlet* clet)
{
	string sexs;
	if(clet->c_Size != 0)
	{
		for (int i = 0; i < clet->c_Size; ++i) {
			if (clet->peopleArray[i].p_Sex == 1)
			{
				sexs = "��";
			}
			else
			{
				sexs = "Ů";
			}
			//�Ա��ת������������Ŀ�����(clet->peopleArray[i].p_Sex == 1 ��"��":"Ů")

			cout << "����: " << clet->peopleArray[i].p_Name << " �Ա�: " << sexs << " ����: " << clet->peopleArray[i].p_Age << " �绰: " << clet->peopleArray[i].p_Phonum << " סַ: " << clet->peopleArray[i].p_Addr << endl;
		}
	}
	else 
	{
		cout << "ͨѶ¼����Ϊ0" << endl;
	}
	system("pause");
	system("cls");
	return;
}

//�����ϵ���Ƿ���ڣ��߼���������ڷ��ظ����������λ��(������)����������ھͷ���-1��Ϊʲôд�������Ϊ��������ɾ����ϵ��
//������ϵ�˻����޸���ϵ�ˣ���Ҫ�ж���ϵ���Ƿ����
int detectPeople(Communlet * clet,string name) {//�з���ֵ�ˣ��������Ͳ�����void��

	for (int i = 0; i < clet->c_Size;++i) {
		if (name == clet->peopleArray[i].p_Name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void removePeople(Communlet * clet) {

	cout << "������Ҫɾ������ϵ��" <<endl;
	string name;
	cin >> name;

	int retu = detectPeople(clet, name);
	//�ж��߼����������ֵ��-1������޴��ˣ��������ֵ ��= -1�����ɾ����ϵ��
	if (retu != -1) 
	{
		//ɾ�����߼����ú��������������ǰ�ݽ�һλ������array[3]������ȡ��array[2]�����ݣ�����ȡ�����߼���ɾ����ͬʱ������Ԫ�صĸ�����һ
		for (int i = retu; i < clet->c_Size; i++)
		{
			//ͨѶ¼��Ա����ǰ��һλ
			clet->peopleArray[i] = clet->peopleArray[i + 1];
		}
		//ͨѶ¼��Ա��һ
		--clet->c_Size;
		cout << "ɾ���ɹ�" <<endl;
	}
	else
	{
		cout << "û�в鵽Ҫɾ������ϵ��" << endl;
	}
	system("pause");
	system("cls");
	return;

}

//������ϵ��
void findPeople(Communlet * clet) {
	cout << "������Ҫ������ϵ�˵�����" <<endl;
	string name;
	cin >> name;

	int retu = detectPeople(clet, name);
	//�ж��߼�ͬ��һ��removePeople()���һ�������б���ϵ���Ƿ����
	if ( retu != -1)
	{
		cout << "�Ѳ�ѯ������" << endl;
		cout << "����: " << clet->peopleArray[retu].p_Name << " �Ա�: " << ((clet->peopleArray[retu].p_Sex == 1) ? "��" : "Ů") << " ����: " << clet->peopleArray[retu].p_Age << " �绰: " << clet->peopleArray[retu].p_Phonum << " סַ: " << clet->peopleArray[retu].p_Addr << endl;
	}
	else 
	{
		cout << "û�в鵽����" <<endl;
	}

	system("pause");
	system("cls");
	return;
}

//�޸���ϵ��
void modifInform(Communlet * clet) {
	cout << "��������Ҫ�޸ĵ���ϵ��" <<endl;
	string name;
	cin >> name;

	int retu = detectPeople(clet, name);

	if (retu != -1) //�ҵ���ϵ��
	{
		//����
		string name;
		cout << "������Ҫ�޸ĵ�����" <<endl;
		cin >> name;
		clet->peopleArray[retu].p_Name = name;
		//�Ա�
		cout << "������Ҫ�޸ĵ��Ա�" << endl;
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
				cout << "������ȷ�ķ�Χ��ѡ������" <<endl;
			}
		}
		//����
		int age = 0;
		cout << "������Ҫ�޸ĵ�����" << endl;
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
				cout << "���������������䷶Χ" << endl;
			}
		}
		//�绰����
		cout << "������Ҫ�޸ĵĵ绰����" << endl;
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
				cout << "��������ȷ�ĵ绰����" << endl;
			}
		}
		//סַ
		string homeadd;
		cout << "������Ҫ�޸ĵ�סַ" << endl;
		cin >> homeadd;
		clet->peopleArray[retu].p_Addr = homeadd;
		
	}
	else
	{
		cout << "���޴���" <<endl;
	}
	system("pause");
	system("cls");
	return;
}

//�����ϵ��
void cleanPeople(Communlet* clet) {
	clet->c_Size = 0;
	cout << "ͨѶ¼�����" <<endl;
	system("pause");
	system("cls");
}

int main() 
{
	//����ͨѶ¼����
	Communlet clet;
	//��ʼ��ͨѶ¼�е�ǰ����
	clet.c_Size = 0;
	int select = 0;
	string name;

	while (true)
	{
		showMenu();
		
		cin >> select;

		switch (select)
		{
			case 1:	//1�������ϵ��
				addPeople(&clet); //���ݽṹ��ĵ�ַ�������������޸��Ѿ�������ͨѶ¼����
				break;
			case 2:	//2����ʾ��ϵ��
				showPeople(&clet);
				break;
			case 3:	//3��ɾ����ϵ��
			{
				//���Լ����ϵ�˺���
				/*string name;
				cout << "������Ҫɾ��������" << endl;
				cin >> name;

				
				if (detectPeople(&clet, name) == -1) {
					cout << "���޴���" << endl;
				}
				else
				{
					cout << "�Ѿ��鵽" <<endl;
				}*/
				removePeople(&clet);
				break;
			}
			case 4:	//4��������ϵ��
				findPeople(&clet);
				break;
			case 5:	//5���޸���ϵ��
				modifInform(&clet);
				break;
			case 6:	//6�������ϵ��
				cleanPeople(&clet);
				break;
			case 0:	//0���˳�ͨ��¼
				cout << "��ӭ�´�ʹ��ͨѶϵͳ" << endl;
				system("pause");
				return 0;
				break;
			default :
				cout << "������涨ѡ��" << endl;
				break;
		}


	}

	system("pause");
	return 0;
}