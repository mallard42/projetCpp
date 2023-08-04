#include "../include/person.h"

Person::Person(const std::string& _nom,const std::string& _prenom,const std::string & _email,const int& _age)
:nom(_nom),prenom(_prenom),email(_email),age(_age)
{

}

Client::Client(const std::string& _nom,const std::string& _prenom,const std::string & _email,const int& _age)
:Person(_nom,_prenom,_email,_age)
{

}

void Client::print()
{
    std::cout <<"Hello! i'm"<< prenom<< std::endl;
}

