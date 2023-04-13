#include <iostream> 

using namespace std;

typedef int Info;



struct Elem

{

	Elem* next,

		* prev;

	Info info;

};



void enqueue(Elem*& first, Elem*& last, Info value);

int dequeue(Elem*& first, Elem*& last);

void print(Elem* first);

int Sum(Elem* L);



void enqueue(Elem*& first, Elem*& last, Info value)

{

	Elem* tmp = new Elem;

	tmp->info = value;

	tmp->next = NULL;

	if (last != NULL)

		last->next = tmp;

	tmp->prev = last;

	last = tmp;

	if (first == NULL)

		first = tmp;

}

Info dequeue(Elem*& first, Elem*& last)

{

	Elem* tmp = first->next; // 1 

	Info value = first->info; // 2 

	delete first; // 3 

	first = tmp; // 4 

	if (first == NULL)

		last = NULL; // 5 

	else

		first->prev = NULL; // 6 

	return value; // 7 

}

void print(Elem* first) {



	if (first != NULL) {

		cout << first->info << " ";

		print(first->next);

	}

	else {

		cout << endl;

	}

}

int Sum(Elem* L)

{

	if (L == NULL) {

		return 0;

	}

	else {

		int S = Sum(L->next);



		if (L->info % 2 == 0) {

			S += L->info;

		}

		return S;

	}

}

int main()

{

	Elem* first = NULL,

		* last = NULL;



	for (int i = 8; i <= 10; i++)

	{

		enqueue(first, last, i);

	}

	cout << "list: ";

	print(first);

	cout << Sum(first) << endl;

	while (first != NULL)

		dequeue(first, last);

	return 0;

}