#include "container.h"
#include "plant.h"
#include <iostream>



plant* in(std::ifstream &ifst);
void out(plant &p, std::ofstream &ofst);

void init(container &c)//инициализация контейнера(обнуляется количество элементов)
{
	c.head = NULL;
	clear(c);
}


void clear(container &c)//удаление объектов и установка в начальное состояние
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
	while(current != NULL && current->p != NULL)
	{
		out(*current->p, ofst);
		current = current->next;
	}

}

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


