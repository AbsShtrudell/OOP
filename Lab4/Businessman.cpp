#include "Businessman.h"

Businessman::Businessman()
{
	License = 0;
	ZeroMemory(RegAdress, 30);
}

Businessman::~Businessman()
{
}

int Businessman::getLicense()
{
	return License;
}

void Businessman::setLicense(int _license)
{
	if (_license < 1)
		License = 1;
	else License = _license;
}

char* Businessman::getRegAdress()
{
	return RegAdress;
}

void Businessman::setRegAdress(char* _regadress)
{
	strcpy_s(RegAdress, 30, _regadress);
}

void Businessman::AddTax(char* _date, float _amount)
{
	Taxes t;
	strcpy_s(t.Date, 20, _date);
	t.amount = _amount;
	TaxData.push_back(t);
}

void Businessman::writeToFile(char* path)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("persons.xml"))
	{
		tinyxml2::XMLElement* root = doc.NewElement("persons");
		doc.InsertFirstChild(root);

		tinyxml2::XMLElement* child = doc.NewElement("person");
		child->SetAttribute("type", "businessman");
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

		tinyxml2::XMLElement* lic = doc.NewElement("license");
		lic->SetText(this->License);
		child->InsertEndChild(lic);

		tinyxml2::XMLElement* regaddr = doc.NewElement("reg_addres");
		regaddr->SetText(this->RegAdress);
		child->InsertEndChild(regaddr);

		tinyxml2::XMLElement* taxes = doc.NewElement("taxes");
		for (int i = 0; i < TaxData.size(); i++)
		{
			tinyxml2::XMLElement* tax = doc.NewElement("tax");
			tinyxml2::XMLElement* date = doc.NewElement("date");
			tinyxml2::XMLElement* amount = doc.NewElement("amount");
			date->SetText(this->TaxData[i].Date);
			amount->SetText(this->TaxData[i].amount);
			tax->InsertEndChild(date);
			tax->InsertEndChild(amount);
			taxes->InsertEndChild(tax);
		}
		child->InsertEndChild(taxes);

		doc.SaveFile(path);
	}
	else
	{
		tinyxml2::XMLNode* root = doc.FirstChild();;
		doc.InsertFirstChild(root);

		tinyxml2::XMLElement* child = doc.NewElement("person");
		child->SetAttribute("type", "businessman");
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

		tinyxml2::XMLElement* lic = doc.NewElement("license");
		lic->SetText(this->License);
		child->InsertEndChild(lic);

		tinyxml2::XMLElement* regaddr = doc.NewElement("reg_addres");
		regaddr->SetText(this->RegAdress);
		child->InsertEndChild(regaddr);

		tinyxml2::XMLElement* taxes = doc.NewElement("taxes");
		for (int i = 0; i < TaxData.size(); i++)
		{
			tinyxml2::XMLElement* tax = doc.NewElement("tax");
			tinyxml2::XMLElement* date = doc.NewElement("date");
			tinyxml2::XMLElement* amount = doc.NewElement("amount");
			date->SetText(this->TaxData[i].Date);
			amount->SetText(this->TaxData[i].amount);
			tax->InsertEndChild(date);
			tax->InsertEndChild(amount);
			taxes->InsertEndChild(tax);
		}
		child->InsertEndChild(taxes);

		doc.SaveFile(path);
	}
}

