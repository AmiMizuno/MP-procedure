#include "Container.h"
#include "plant.h"
#include <iostream>

Plant* in(std::ifstream &ifst);
bool compare(Plant *a, Plant *b);
int consonant_count(Plant &p);
void out(Plant &p, std::ofstream &ofst);

void init(Container &c)
{
	c.head = NULL;
	clear(c);
}

void clear(Container &c)
{
    while (c.head != NULL) {
        Container::element* tmp = c.head->next;
		delete c.head->p;
		delete c.head;
		c.head = tmp;
	}
	c.head = NULL;
	c.tail = NULL;
	c.len = 0;
}

void sort(Container &c)
{
    Container::element* a = c.head;
    Container::element* prevA = NULL;
	while (a != NULL)
	{
        Container::element* b = a->next;
        Container::element* prevB = a;
        while (b != NULL) {
            if (compare(a->p, b->p)) {
                Container::element *tmp = a;
                Container::element *tmp_next = a->next;
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

void in(Container &c, std::ifstream &ifst)
{
    while (!ifst.eof()) {
        Plant* p = in(ifst);
        if (p == NULL) {
			break;
		}
        Container::element* elem = new Container::element;
		elem->p = p;
		elem->next = NULL;
		if (c.head == NULL)
			c.head = c.tail = elem;
        else {
			c.tail->next = elem;
			c.tail = c.tail->next;
		}
		c.len++;
	}
}

void out(Container &c, std::ofstream &ofst)
{
    ofst << "Container contains " << c.len << " elements." << std::endl;
    Container::element* current = c.head;
	while (current != NULL){
		out(*current->p, ofst);
		current = current->next;
	}

}

void out_trees(Container &c, std::ofstream &ofst)
{
    ofst << "Container contains " << c.len << " elements." << std::endl;
	ofst << "Output only trees." << std::endl;
    Container::element* current = c.head;
    while (current != NULL) {
        if (current->p->k == Plant::TREE)
			out(*current->p, ofst);
		current = current->next;
	}
}
