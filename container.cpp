#include "container.h"
#include "plant.h"
#include <iostream>

plant* in(std::ifstream &ifst);
bool compare(plant *a, plant *b);
int consonant_count(plant &p);
void out(plant &p, std::ofstream &ofst);

void init(container &c)//������������� ����������(���������� ���������� ���������)
{
	c.head = NULL;
	clear(c);
}

void clear(container &c)//�������� �������� � ��������� � ��������� ���������
{
	while (c.head != NULL)
	{
		container::element* tmp = c.head->next;
		delete c.head->p;
		delete c.head;
		c.head = tmp;
	}
	c.head = NULL;
	c.tail = NULL;
	c.len = 0;
}

void sort(container &c)
{
	container::element* a = c.head;
	container::element* prevA = NULL;
	while (a != NULL)
	{
		container::element* b = a->next;
		container::element* prevB = a;
		while (b != NULL)
		{
			if (compare(a->p, b->p))
			{
				container::element *tmp = a;
				container::element *tmp_next = a->next;
				if (!prevA)
					c.head = b;
				else
					prevA->next = b;
				prevB->next = a;
				a->next = b->next;
				if (tmp_next != b)
					b->next = tmp_next;
				else
					b->next = a;
				a = b;
				b = tmp;
			}
			c.tail = b;
			prevB = b;
			b = b->next;
		}
		prevA = a;
		a = a->next;
	}
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
		elem->next = NULL;
		if (c.head == NULL)
			c.head = c.tail = elem;
		else
		{
			c.tail->next = elem;
			c.tail = c.tail->next;
		}
		c.len++;
	}
}


void out(container &c, std::ofstream &ofst)//����� ����������� ���������� � �������� �������� �����
{
	ofst << "Container contains " << c.len << " elements." << std::endl;
	container::element* current = c.head;
	while (current != NULL)
	{
		out(*current->p, ofst);
		current = current->next;
	}

}

void outTrees(container &c, std::ofstream &ofst)
{
	ofst << "Container contains " << c.len << " elements." << std::endl;
	ofst << "Output only trees." << std::endl;
	container::element* current = c.head;
	while (current != NULL)
	{
		if (current->p->k == plant::TREE)
			out(*current->p, ofst);
		current = current->next;
	}
}
//����� �������� ����������, �������������� ������ ���� �������
void multimethod(container &c, std::ofstream &ofst)
{
	ofst << "Multimethod" << std::endl;
	container::element* i = c.head;
	while(i != NULL && i->p != NULL)
	{
		container::element* j = i->next;
		while(j != NULL && j->p != NULL)
		{
			switch (i->p->k)
			{
				case plant::TREE:
					switch (j->p->k) {
						case plant::TREE:
							ofst << "Tree and Tree" << std::endl;
							break;
						case plant::BUSH:
							ofst << "Tree and Bush" << std::endl;
							break;
						case plant::FLOWER:
							ofst << "Tree and Flower" << std::endl;
							break;
						default:
							ofst << "Unknown type" << std::endl;
							break;
					}
					break;
				case plant::BUSH:
					switch (j->p->k) {
						case plant::TREE:
							ofst << "Bush and Tree" << std::endl;
							break;
						case plant::BUSH:
							ofst << "Bush and Bush" << std::endl;
							break;
						case plant::FLOWER:
							ofst << "Bush and Flower" << std::endl;
							break;
						default:
							ofst << "Unknown type" << std::endl;
							break;
					}
					break;
				case plant::FLOWER:
					switch (j->p->k) {
						case plant::TREE:
							ofst << "Flower and Tree" << std::endl;
							break;
						case plant::BUSH:
							ofst << "Flower and Bush" << std::endl;
							break;
						case plant::FLOWER:
							ofst << "Flower and Flower" << std::endl;
							break;
						default:
							ofst << "Unknown type" << std::endl;
							break;
					}
					break;
				default:
					ofst << "Unknown type" << std::endl;
					break;
			}
			out(*(i->p), ofst);
			out(*(j->p), ofst);
			j = j->next;
		}
		i  = i->next;
	}
}
