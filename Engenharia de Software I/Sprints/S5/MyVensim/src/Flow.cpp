// Felipe Braz Marques - 22.1.4030

#include "Flow.h"
#include "AbstractSystem.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

Flow::Flow(){
    origin = NULL;
    destiny = NULL;
    name = "";
}

Flow::Flow(AbstractSystem *origin = NULL, AbstractSystem *destiny = NULL, string name = ""){
    this->origin = origin;
    this->destiny = destiny;
    this->name = name;
}

Flow::Flow(const Flow& f){
    origin = f.origin;
    destiny = f.destiny;
    value = f.value;
    name = f.name;
}

Flow::~Flow(){
}

Flow& Flow::operator= (const Flow& f) {
	if (this == &f)
		return *this;

	origin = f.origin;
	destiny = f.destiny;
	value= f.value;
    name = f.name;

	return *this;
}

void Flow::setOrigin(AbstractSystem *origin){
    this->origin = origin;
}
AbstractSystem* Flow::getOrigin(void) const{
    return this->origin;
}

void Flow::setDestiny(AbstractSystem *destiny){
    this->destiny = destiny;
}
AbstractSystem* Flow::getDestiny(void) const{
    return this->destiny;
}

void Flow::setValue(double value){
    this->value = value;
}
double Flow::getValue(void) const{
    return this->value;
}

void Flow::setName(string name){
    this->name = name;
}
string Flow::getName(void) const{
    return this->name;
}

void Flow::execute(){
    this->setValue(this->origin, this->destiny);
}

void Flow::output(ostream& out) const{
    out << "Origem: " << getOrigin() << endl
        << "Destino :" << getDestiny() << endl 
        << "Value :" << getValue() << endl
        << "Name :" << getName() << endl;
}
ostream& operator << (ostream& out, const Flow& flow){
    flow.output(out);
    return out;
} 