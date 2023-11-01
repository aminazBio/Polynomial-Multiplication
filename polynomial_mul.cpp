#include <iostream>
using namespace std;

class Node
{
	public: 
    int coefficient;
	int power;
	Node *next;

	Node(int coefficient, int power)
	{
		this -> coefficient = coefficient;
		this -> power = power;
		this -> next = nullptr;
	}
	
	void Update(int coefficient, int power)
	{
		this -> coefficient = coefficient;
		this -> power = power;
	}
};

class PolyMul
{
	public: 
    Node *head;
	PolyMul()
	{
		this -> head = nullptr;
	}
	
	void insert(int coefficient, int power)
	{
		if (this -> head == nullptr)
		{
			this -> head = new Node(coefficient, power);
		}
		else
		{
			Node *node = nullptr;
			Node *temp = this -> head;
			Node *location = nullptr;
			
			while (temp != nullptr && temp -> power >= power)
			{
				location = temp;
				temp = temp -> next;
			}
			if (location != nullptr && location -> power == power)
			{
				location -> coefficient = location -> coefficient + coefficient;
			}
			else
			{
				node = new Node(coefficient, power);
				if (location == nullptr)
				{
					node -> next = this -> head;
					this -> head = node;
				}
				else
				{
					node -> next = location -> next;
					location -> next = node;
				}
			}
		}
	}
	
	PolyMul *multiplyPolynomials(PolyMul *other)
	{
		PolyMul *result = new PolyMul();
		
		Node *poly1 = this -> head;
		Node *temp = other -> head;
		int power_value = 0;
		int COefficient = 0;
		
		while (poly1 != nullptr)
		{
			temp = other -> head;
			while (temp != nullptr)
			{
				power_value = poly1 -> power + temp -> power;
				COefficient = poly1 -> coefficient *temp -> coefficient;
				result -> insert(COefficient, power_value);
				
				temp = temp->next;
			}
			
			poly1 = poly1 -> next;
		}
		
		return result;
	}
	
	void display()
	{
		if (this->head == nullptr)
		{
			cout << 0 << " ";
		}

		Node *temp = this -> head;
		while (temp != nullptr)
		{
			cout << temp -> coefficient <<" ";
			temp = temp -> next;
		}
	}
};

int main()
{
	PolyMul *a = new PolyMul();
	PolyMul *b = new PolyMul();

	int x,y;
    cin >> x;
    cin.ignore();
    cin >> y;
	cin.ignore();

	for(int i = x; i > -1; i--)
	{
		int f;
		cin >> f; 
		a -> insert(f, i);
        cin.ignore();
	}

    for(int j = y; j > -1; j--)
	{
		int s;
		cin >> s; 
		b -> insert(s, j);
        cin.ignore();
	}
	
	PolyMul *result = a -> multiplyPolynomials(b);
	result -> display();

	return 0;
}