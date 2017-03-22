#include "container.h"
#include "plant.h"
#include <iostream>

namespace flora
{

plant* in(std::ifstream &ifst);
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

}
