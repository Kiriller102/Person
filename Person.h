//
// Created by Kirill on 15.11.2021.
//

#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H

#include <string>

enum class Gender {male, female};

class Person {
private:
    static int next_ID;
    const int ID;
    const Gender gender_;
    char* name_;
    Person* mother_;
    Person* father_;
    void Erase();
    void Clone(const Person&);
public:
    Person(const Person&);
    Person& operator =(const Person&);
    Person(const char*, Gender aGender); // конструктор, в который передается имя
    virtual ~Person(); // деструктор
    int GetID();
    const char* GetName() const;
    std::string GetGender();
    char* GetMother();
    char* GetFather();
    void SetName (const char *);
    Person* GiveBirth(char *aName, Person *aFather, Gender aGender);
    friend std::ostream &operator<<(std::ostream&, Person Pers);
};

#endif //PERSON_PERSON_H

