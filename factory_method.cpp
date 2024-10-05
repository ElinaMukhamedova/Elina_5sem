#include <iostream>
#include <string>
#include <vector>

class Shape
{
public:
	virtual std::string getName() = 0;
};

class Triangle : public Shape
{
public:
	std::string getName() { return "Triangle"; }
};

class Square : public Shape
{
public:
	std::string getName() { return "Square"; }
};

class Circle : public Shape
{
public:
	std::string getName() { return "Circle"; }
};

enum Type{ TRIANGLE, SQUARE, CIRCLE};

// responsible for creating and returning Shape objects on demand...
class Factory
{
public:
	Shape* create(Type t)  // factory method
	{
		switch(t)
		{
			case TRIANGLE:
				return new Triangle();
			case SQUARE:
				return new Square();
			case CIRCLE:
				return new Circle();
		}
	}
};

int main() {
	std::vector <Shape*> shapes;

	// Our factory is responsible for creating Shape objects on demand
	Factory f;
	
	// Let's create 3 different shape objects and assign their memory addresses to our shapes vector
	shapes.push_back(f.create(TRIANGLE));
	shapes.push_back(f.create(SQUARE));
	shapes.push_back(f.create(CIRCLE));

	// Iterate over each shape object, calling it's getName method using its pointer
	for (Shape*& s : shapes)
		std::cout << s->getName() << std::endl;

	// clean-up
	for (Shape*& s : shapes)
		delete s;

    shapes.clear();
	return 0;
}