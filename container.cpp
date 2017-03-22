#include "container.h"
#include "plant.h"
#include <iostream>

namespace flora
{

plant* in(std::ifstream &ifst);
bool compare(plant *a, plant *b);
int consonant_count(plant &p);
void out(plant &p, std::ofstream &ofst);

void init(container &c)//инициализация контейнера(обнуляется количество элементов)
{
	c.head = NULL;
	clear(c);
}


void clear(container &c)//удаление объектов и установка в начальное состояние
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

void in(container &c, std::ifstream &ifst)//ввод элементов в контейнер
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


void out(container &c, std::ofstream &ofst)//вывод содержимого контейнера в заданный выходной поток
{
	ofst << "Container contains " << c.len << " elements." << std::endl;
	container::element* current = c.head;
	while (current != NULL)
	{
		out(*current->p, ofst);
		current = current->next;
	}

}

}
