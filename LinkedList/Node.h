#pragma once
template <typename T>
class Node							// ��������� ����� ���� ������
{
private:
	T data;							// ������ ���� ������
	Node* prev;						// ��������� �� ����. ����
	Node* next;						// ��������� �� ����. ����

public:
	Node()							// ������. �� �����
	{
		set_prev(nullptr);
		set_next(nullptr);
	}


	Node(T& temp)					// ������. �� �����
	{
		set_data(temp);
		set_prev(nullptr);
		set_next(nullptr);
	}


	~Node()							// ����������
	{
		if (next != nullptr)		// ���� �� ����� �� ���������� ���������
		{
			delete next;			// ������� ����. ��������
			next = nullptr;			// �� ������ ������ (����� �������� �� ���. ��������� ������)
			prev = nullptr;			// �� ������ ������ (����� �������� �� ���. ��������� ������)
		}
	}


	void set_data(T& temp)			// ������������� ������ (�� ������, ��� �������� ������)
	{
		data = temp;
	}


	T& get_data()					// ���������� ������
	{
		return data;
	}


	void set_prev(Node* temp)		// ������������� ��������� �� ����. ����
	{
		prev = temp;
	}


	Node* get_prev()				// ���������� ��������� �� ����. ����
	{
		return prev;
	}


	void set_next(Node* temp)		// ������������� ��������� �� ����. ����
	{
		next = temp;
	}


	Node*& get_next()					// ���������� ��������� �� ���� ����.
	{
		return next;
	}

};