/*	

������� ����� �� �������

������� ����������� �����: 10819

1 ����� ����� 1
2 ����� ����� 0
3 ����� ����� 8
4 ����� ����� 1
5 ����� ����� 9

*/

#include "ParseNum.h";

void ParseNum::parse()
{
	string num;
	
	logMessage();
	cin >> num;
	while(num.size()!=5)
	{
		cout << "������: ����� �� �����������" << endl;
		logMessage();
		cin >> num;
	}

	for(size_t i = 1;i<6;++i)
	{
		cout << i << " ����� ����� "<< num[i-1] << endl;
	}

};

void ParseNum::logMessage()
{
	cout << "������� ����������� �����:" << endl;
}


/*
			������������� ����������� � �++

*
**
***
****
*****
******
*******

*/

void DrawTriangle::drawA()
{
	int len = 7;
	for(int i=0;i<len;++i)
	{
		for(int j=0;j <= i;++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void DrawTriangle::drawB()
{
	int len = 7;
	for(int i=0;i<len;++i)
	{
		string foo =  string(i+1,'*');
		cout << foo <<endl;
	}
}


/* �������� ���������, ������������� ���, �������, �������� � ����� ������ �������� � ��������� �������� ������ � ��������� ����:
			   ********************************
			   * ������������ ������ � 1      *
			   * ��������(�): ��. ��. ��-123  *
			   * ������ ������ ��������       *
			   ******************************** 
����������, ����� ��������� ���� ���������� ������ ����� �����. ���� �� ������ ����� ������� �� ������ ���������� ������ ������ �����. ��������� ����� for ����� ����� ��������� ������� �����.*/

FrameDraw::FrameDraw(): longest_str(0),lab_str("������������ ������ � 1"),done_str("��������(�): ��. ��."),tabs_str("\t\t"){ setlocale(LC_ALL,"");};

void FrameDraw::handleMessage(std::string student_prop,std::string& val)
{
	cout << "������� " << student_prop << " ��������:";
	cin>>val;
	cout << endl;
}

void FrameDraw::addPadding(std::string& checked)
{
	int num_pads = longest_str - checked.size();
	checked = " " + checked  + std::string(num_pads,' ') + " ";
}

void FrameDraw::updateLongest(std::string& checked)
{
	if(longest_str < checked.size() ) longest_str = checked.size();
}

void FrameDraw::updateLongestStringSize()
{
	updateLongest(lab_str);
	updateLongest(done_str);
	updateLongest(full_name);
}

void FrameDraw::padStrings()
{
	addPadding(lab_str);
	addPadding(done_str);
	addPadding(full_name);
}

void FrameDraw::handleAllMessages()
{
	handleMessage("���",name);
	handleMessage("�������",surname);
	handleMessage("��������",second_name);
	handleMessage("����� ������",group);
}

void FrameDraw::logFramed(std::string& val)
{
	cout<<'*'<<val<<'*'<<endl;
}

void FrameDraw::init()
{
	handleAllMessages();

	done_str = done_str + " " + group;
	full_name = name + " " + surname + " " + second_name;

	updateLongestStringSize();
	padStrings();
	horizontal_border_frame = std::string(longest_str+2,'*');
	
	logFramed(horizontal_border_frame);
	logFramed(lab_str);
	logFramed(done_str);
	logFramed(full_name);
	logFramed(horizontal_border_frame);
}