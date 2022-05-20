#pragma once

#include "List.h"					// ����� ��� �������� �������
#include "Node.h"                   // ��������� ����� ���� ������
#include <time.h>					// ����� ������� � ���. ��� ��������� ���������� �����
#include <iostream>					// ����������� ������ ����� / ������

template <typename T>				/*	��������� ����� ��� ������� �� ��������	
										�.�. ����� ����������� �� Node � List � �� ����� ���� �� ����������
									*/
class LinkedList : public Node<T>, public List<T>
{
private:
	Node<T>* head;					// ��������� �� �������� ����

public:	
	LinkedList() {					// �����. �� �����.
		set_head(nullptr);
	}


	LinkedList(Node<T>*& h) {		// �����. � ���������� �� ������
		set_head(h);
	}


	void add(Node<T>*& h, T& temp)		// ��������������� (���������� head)
	{
		if (h == nullptr)				// ���� ������ ����, �� ��������� ������ ��������
		{
			this->add_first(h, temp);	// ��������� � ������ (�.� ����� protected � ���� ��� ������������ � ����������, �� ������ � ��������)
		}
		else							// ���� ������ �� ���� ��������� � �����
		{
			this->add_end(h, temp);		// ��������� � ������ (�.� ����� protected � ���� ��� ������������ � ����������, �� ������ � ��������)
		}

		if (head == nullptr)			// ���� ������ ������ �� �����������
			set_head(searc_head(h));	// ���� � ���������� ������ �������� (������ ������)
	}


	Node<T>*& get_head()				// ��������� ��������� �� ������
	{
		return head;
	}


	void set_head(Node<T>* h)			// ��������� ��������� �� ������
	{
		head = h;
	}


	void sort()										// ���������� ������ �� �����������
	{
		if (empty())								// �������� ������� �� �������
			throw std::invalid_argument("List is empty");

		Node<T>* temp;								// ��������� �� ������� ����
		Node<T>* a;									// ��������� �� ����. ����

		bool flag = true;

		while (flag)								// ���� ������� ���������� ������ �������� (���� �� ������������)
		{
			temp = head;							// ������� ����
			a = temp->get_next();					// ����. ����

			flag = false;

			while (a)								// ���� �� ����� �� �����
			{
				if (temp->get_data() > a->get_data())
				{									// ���� ���� - ������ ������ � ����� �������
					swap(temp, a);					// ������ �������� ����� �������
					flag = true;					// ����������, ��� �������� �������
				}

				temp = temp->get_next();			// ��������� � ����. �����
				a = a->get_next();
			}
		}
	}


	void swap(Node<T>*& _1, Node<T>*& _2)		// ����������� ������ � ����� _1, _2 �������
	{
		T temp = _1->get_data();				// ��� �� ����������
		_1->set_data(_2->get_data());
		_2->set_data(temp);
	}


	Node<T>* del_ellement(Node<T>*& ptr)		// �������� ptr - ���� ������
	{	
		// a / ptr / b	- �������� ����, ��� �����������
		// ����� ��������� a � b � �������� ������ ptr

		Node<T>* a = ptr->get_prev();			// �������� ����� ptr
		Node<T>* b = ptr->get_next();			// �������� ����� ptr

		if (a)
			a->set_next(b);
		else									// ���� ����� ������� �������� ����
			set_head(b);						// ��������� �� ������ ��������� � ����. ����
		
		if (b)									// ���� ������� �����, ����� ���������� ����
			b->set_prev(a);

		return b;								// ���������� ��������� �� ����, ��������� �� ��������
		
		ptr->set_next(nullptr);					// �������� ��������� ���� �� ������
		ptr->set_prev(nullptr);

		delete ptr;								// ������� ������
	}


	void remove_dupl()							// �������� ����������
	{
		if (empty())							// �������� �� ������� ������
			throw std::invalid_argument("List is empty");

		Node<T>* ptr = get_head();
		bool b = false;							// ���� �������� ����

		while (ptr->get_next() != nullptr)		// �������� ����. ���� �� �������������
		{
			b = false;							// ��������� �����

			if (ptr->get_data() == (ptr->get_next())->get_data())
			{
				del_ellement(ptr->get_next());	// �������� ����
				b = true;						// ����������, ��� ������� ����
			}
			if (!b)								// ���� �������� �� ����
				ptr = ptr->get_next();			// ptr ��������� �� ����. ����, ����� ������� �� �������
		}

	}


	Node<int>* searc_head(Node<T>*& ptr)		// ����� ������ ������ ptr - ��������� �� ����� ���� ������
	{
		if (ptr == nullptr)
			throw std::invalid_argument("NULL pointer");

		Node<T>* h = ptr;						// ����� ptr �� ���� ��������� �� ������ (����� �� �������)

		while (h->get_prev())					// ��� �� ������� ��������� (������ ������)
		{
			h = h->get_prev();
		}

		return h;								// ���������� ��������� �� ������
	}


	void add(int n)								/*	���������� n-�� ���-�� ����� ���������� �������
													����������� ��������� �� ������ ������ */
	{
		int r = 0;								// ����. �����

		srand(time(NULL));						// ��� �������

		for (int i = 0; i < n; i++)				// n ��� ��������� ����� ����
		{
			r = (-25 + rand() % (50 - 0 + 1));	// ������ [-25 ; 25]
			this->add(head, r);
		}
	}


	bool empty()								// �������� �� ������� ������ (true, ���� �����)
	{
		return head == nullptr;
	}

};