#include <iostream>
using namespace std;

struct Student {
	int num;
	char name[20];
	char classname[20];
	float score[3];
	float aver_score;
};

void input(Student stu[] ,int stu_number) {
	for (int i = 0; i < stu_number; i++)
	{
		cout << "please enter NO. " << i+1<< " student info : num name class score1 score2 score3:  ";
		cin >> stu[i].num >> stu[i].name >> stu[i].classname;
		cin >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
	}
}

void averagescore( Student stu[], int stu_number){
	for (int i = 0; i <= stu_number; i++) {
		stu[i].aver_score = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
	} 
}

int avermax(Student stu[], int number){
	int    k = 0; //�������ƽ���ֲ���¼�������е��±�ֵ
	float max = 0;
	for( int i = 0; i< number; i++){
		if (max < stu[i].aver_score) {
			max = stu[i].aver_score;
			k = i;
		}
	}
	return k;        //�������ƽ��������Ԫ�ص��±�
}

int main()
{
	Student stu[20];
	int stu_number = 0;        //ѧ������
	cout << "please enter student number:";
	cin >> stu_number;                  //����ѧ������
	input(stu, stu_number);
	averagescore(stu, stu_number);
	int k=avermax(stu, stu_number);

	cout << "ѧ��ƽ���֣�" << endl;
	for (int i = 0; i < stu_number; i++) {
		cout << stu[i].num << " " << stu[i].name << " " << stu[i].classname << " " << stu[i].aver_score << endl;
	}
	cout << "���ƽ���֣�" << endl;
	cout << stu[k].num << " " << stu[k].name << " " << stu[k].classname << " " << stu[k].aver_score << endl;

	return 0;
}	
