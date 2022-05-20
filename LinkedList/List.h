#pragma once
#include "Node.h"							// ��������� ����� ���� ������

template <typename T>
class List									// ��������� ����� ��� �������� ������
{
protected:									// ������ ������ ������������ �������, ������������ �� ����� � ��� ������, �� � ���. �� � LinkedList
	
	void add_first(Node<T>*& h, T& temp)	// ���������� ������ ������
	{
		h = new Node<T>(temp);				// �������� ������ ��� h = ���� ������. ��������� ���� data = temp

	}


	void add_end(Node<T>*& h, T& temp)		// ���������� ��������, ���� ������ ��� ����
	{
		Node<T>* ptr = h;					// ����� head �� ���������

		while (ptr->get_next() != nullptr)	// ������� �� ���������� ��������� ������
		{
			ptr = ptr->get_next();
		}

		Node<T>* t = new Node<T>(temp);		/*	������ ����. ����
												�������������� ��������� �� ��������� ����� ����
												�������� ��� ���� ������
												� ���� data ���������� temp	*/
		t->set_prev(ptr);					// ��� ������ ���� ���������� - ��������
		ptr->set_next(t);					// ��� ���������� ��������� - �����
	}


public:
	void add(Node<T>*& h, T& temp)			// ���������� ��������� � ������
	{
		if (h == nullptr)					// ���� ������ ����, �� ��������� ������ ��������
		{
			add_first(h, temp);
		}
		else								// ���� ������ �� ���� ��������� � �����
		{
			add_end(h, temp);
		}
	}


	void del(Node<T>*& h)					// ������� ������
	{
		delete h;							// ��������� ���������� Node
	}

};