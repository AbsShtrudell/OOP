#include "Traveller.h"

Traveller::Traveller()
{
	passportID = 1;
}

Traveller::~Traveller()
{
}

int Traveller::getPassportID()
{
	return passportID;
}

void Traveller::setPassportID(int _passportId)
{
	passportID = abs(_passportId);
}

void Traveller::addBorderData(char* _country, char* _date)
{
	Border t;
	strcpy_s(t.date, 20, _date);
	strcpy_s(t.country, 20, _country);
	borderData.push_back(t);
}

void Traveller::writeToFile(char* path)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("persons.xml"))
	{
		tinyxml2::XMLElement* root = doc.NewElement("persons");
		doc.InsertFirstChild(root);

		tinyxml2::XMLElement* child = doc.NewElement("person");
		child->SetAttribute("type", "traveller");
		root->InsertEndChild(child);

		tinyxml2::XMLElement* name = doc.NewElement("name");
		name->SetText(this->getName());
		child->InsertEndChild(name);

		tinyxml2::XMLElement* surename = doc.NewElement("surename");
		surename->SetText(this->getSurename());
		child->InsertEndChild(surename);

		tinyxml2::XMLElement* year = doc.NewElement("year");
		year->SetText(this->getYearBirth());
		child->InsertEndChild(year);

		tinyxml2::XMLElement* passport = doc.NewElement("passport");
		passport->SetText(this->passportID);
		child->InsertEndChild(passport);

		tinyxml2::XMLElement* borders = doc.NewElement("borders");
		for (int i = 0; i < borderData.size(); i++)
		{
			tinyxml2::XMLElement* border = doc.NewElement("border");
			tinyxml2::XMLElement* date = doc.NewElement("date");
			tinyxml2::XMLElement* country = doc.NewElement("country");
			date->SetText(this->borderData[i].date);
			country->SetText(this->borderData[i].country);
			border->InsertEndChild(date);
			border->InsertEndChild(country);
			borders->InsertEndChild(border);
		}
		child->InsertEndChild(borders);

		doc.SaveFile(path);
	}
	else
	{
		tinyxml2::XMLNode* root = doc.FirstChild();;
		doc.InsertFirstChild(root);

		tinyxml2::XMLElement* child = doc.NewElement("person");
		child->SetAttribute("type", "traveller");
		root->InsertEndChild(child);

		tinyxml2::XMLElement* name = doc.NewElement("name");
		name->SetText(this->getName());
		child->InsertEndChild(name);

		tinyxml2::XMLElement* surename = doc.NewElement("surename");
		surename->SetText(this->getSurename());
		child->InsertEndChild(surename);

		tinyxml2::XMLElement* year = doc.NewElement("year");
		year->SetText(this->getYearBirth());
		child->InsertEndChild(year);

		tinyxml2::XMLElement* passport = doc.NewElement("passport");
		passport->SetText(this->passportID);
		child->InsertEndChild(passport);

		tinyxml2::XMLElement* borders = doc.NewElement("borders");
		for (int i = 0; i < borderData.size(); i++)
		{
			tinyxml2::XMLElement* border = doc.NewElement("border");
			tinyxml2::XMLElement* date = doc.NewElement("date");
			tinyxml2::XMLElement* country = doc.NewElement("country");
			date->SetText(this->borderData[i].date);
			country->SetText(this->borderData[i].country);
			border->InsertEndChild(date);
			border->InsertEndChild(country);
			borders->InsertEndChild(border);
		}
		child->InsertEndChild(borders);

		doc.SaveFile(path);
	}
}
