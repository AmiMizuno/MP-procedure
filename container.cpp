#include "container.h"
#include "plant.h"
#include <iostream>

namespace flora
{

plant* in(std::ifstream &ifst);
void out(plant &p, std::ofstream &ofst);

void init(container &c)//������������� ����������(���������� ���������� ���������)
{
	c.head = NULL;
	clear(c);
}


void clear(container &c)//�������� �������� � ��������� � ��������� ���������
{
	container::element* cur = c.head;
	container::element* prev;
	while(cur != NULL && cur->p != NULL)
	{
		delete cur->p;
		prev = cur;
		cur = cur->next;
		delete prev;
	}
	c.head = NULL;
	c.tail = NULL;
	c.len = 0;
}


void in(container &c, std::ifstream &ifst)//���� ��������� � ���������
{
	while (!ifst.eof())
	{
		plant* p = in(ifst);
		if (p == NULL)
		{
			
			break;
		}
		container::element* elem = new container::element;
		elem->p = p;
		if (c.head == NULL)
			c.head = c.tail = elem;
		else
		{
			c.tail->next = elem;
			c.tail = c.tail->next;
		}
		c.len++;
	}
	container::element* sh = new container::element;
			sh->p = NULL;
			sh->next = NULL;
			c.tail->next = sh;
}


void out(container &c, std::ofstream &ofst)//����� ����������� ���������� � �������� �������� �����
{
	ofst << "Container contains " << c.len << " elements." << std::endl;
	container::element* current = c.head;
	int i = 0;
	while(current != NULL && current->p != NULL)
	{
		ofst << ++i << ": ";
		out(*current->p, ofst);
		current = current->next;
	}

}

}