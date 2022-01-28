#include <stdio.h>

typedef struct person
{
    char *name;
    int age;
    double height;
} person;

#define CLASS_SIZE 40

typedef struct class
{
    char *name;
    person student[CLASS_SIZE];
} class;

void construct_class(class *this)
{
    this->name = "";
    person newPerson;
    newPerson.name = "";
    newPerson.age = 0;
    newPerson.height = 0.0;

    for (int i = 0; i < CLASS_SIZE; i++) this->student[i] = newPerson;
}
void setName(person *this, char *n)
{
    this->name = n;
}

char *getName(person *this)
{
    return this->name;
}

void setAge(person *this, int a)
{
    this->age = a;
}

int getAge(person *this)
{
    return this->age;
}

void setHeight(person *this, double h)
{
    this->height = h;
}

double getHeight(person *this)
{
    return this->height;
}
int testPerson()
{
    person testPerson;
    setName(&testPerson, "Michael");
    setAge(&testPerson, 46);
    setHeight(&testPerson, 124.2);

    printf("Hello, my name is %s, I am %d years old and I am %.2f cm tall.\n", getName(&testPerson),
           getAge(&testPerson), getHeight(&testPerson));

    class testClass;
    construct_class(&testClass);
    testClass.name = "Class Number One";
    testClass.student[0] = testPerson;

    for (int i = 0; i < CLASS_SIZE; i++) printf("Student at index %d is: %s\n", i, testClass.student[i].name);

    return 0;
}