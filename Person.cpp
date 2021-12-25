////
//// Created by Kirill on 15.11.2021.
////

#include "Person.h"
#include <exception>
#include <iostream>

int Person::next_ID = 0;

Person::Person(const char* aname, Gender aGender) : ID(++next_ID), gender_(aGender),
                                                    mother_(nullptr), father_(nullptr) {
    SetName(aname);
}

void Person::SetName(const char* aName) {
    if (aName == NULL)
        throw std::runtime_error("Invalid parameter (NULL)");
    if (aName[0] == '\0')
        throw std::runtime_error("Invalid name_ length");
    name_ = new char [strlen(aName) + 1];
    strcpy(name_, aName);
}

const char* Person::GetName() const {
    return name_;
}

int Person::GetID() {
    return ID;
}

void Person::Erase() {
    delete [] name_;
}

void Person::Clone(const Person& p){
    name_ = new char[strlen(p.name_) + 1];
    strcpy(name_, p.name_);
    mother_ = p.mother_;
    father_ = p.father_;
}

Person:: ~Person() {
    Erase();
}

Person::Person(const Person& p): ID(++next_ID), gender_(p.gender_) {
    Clone(p);
}

Person& Person::operator =(const Person& p){
    if (this != &p) {
        Erase();
        Clone(p);
    }
    return *this;
}

Person *Person::GiveBirth( char *aName, Person *aFather, Gender aGender) {
    if (gender_ == Gender::male) {
        throw std::runtime_error("Invalid mother's gender \n");
    }
    if (aFather != nullptr && (*aFather).gender_ == Gender::female) {
        throw std::runtime_error("Invalid father's gender \n");
    }
    Person* children(new Person(aName, aGender));
    (*children).father_ = aFather;
    (*children).mother_ = this;
    return children;
}

std::string Person::GetGender() {
    if (gender_ == Gender::male)
        return "male";
    if (gender_ == Gender::female)
        return "female";
}

char* Person::GetMother() {
    return mother_->name_;
}

char* Person::GetFather() {
    return father_->name_;
}

std::ostream &operator<<(std::ostream &out, Person Pers) {
    out << "Name: " << Pers.GetName() << '\n'
              << "ID: " << Pers.GetID() << '\n'
              << "Gender: " << Pers.GetGender() << '\n';
    if (Pers.GetMother() != nullptr) {
        out  << "Mother: "<< Pers.GetMother() << '\n';
    }
    if (Pers.GetFather() != nullptr) {
        out << "Father: " << Pers.GetFather() << '\n';
    }
    out << std::endl;
    return out;
}
