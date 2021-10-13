#include "Trader.h"

Trader::Trader()
{
}

Trader::~Trader()
{
}

void Trader::addOfferData(char* _date, int _offerID)
{
	offer t;
	strcpy_s(t.date, 20, _date);
	t.offerID = _offerID;
	offerData.push_back(t);
}

void Trader::writeToFile(char* path)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(path))
	{
		tinyxml2::XMLElement* root = doc.NewElement("persons");
		doc.InsertFirstChild(root);

		tinyxml2::XMLElement* child = doc.NewElement("person");
		child->SetAttribute("type", "trader");
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

		tinyxml2::XMLElement* offers = doc.NewElement("offers");
		for (int i = 0; i < offerData.size(); i++)
		{
			tinyxml2::XMLElement* offer = doc.NewElement("offer");
			tinyxml2::XMLElement* date = doc.NewElement("date");
			tinyxml2::XMLElement* offerID = doc.NewElement("offerID");
			date->SetText(this->offerData[i].date);
			offerID->SetText(this->offerData[i].offerID);
			offer->InsertEndChild(date);
			offer->InsertEndChild(offerID);
			offers->InsertEndChild(offer);
		}
		child->InsertEndChild(offers);

		doc.SaveFile(path);
	}
	else
	{
		tinyxml2::XMLNode* root = doc.FirstChild();;
		doc.InsertFirstChild(root);

		tinyxml2::XMLElement* child = doc.NewElement("person");
		child->SetAttribute("type", "trader");
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

		tinyxml2::XMLElement* taxes = doc.NewElement("taxes");
		for (int i = 0; i < offerData.size(); i++)
		{
			tinyxml2::XMLElement* tax = doc.NewElement("tax");
			tinyxml2::XMLElement* date = doc.NewElement("date");
			tinyxml2::XMLElement* offer = doc.NewElement("offerID");
			date->SetText(this->offerData[i].date);
			offer->SetText(this->offerData[i].offerID);
			tax->InsertEndChild(date);
			tax->InsertEndChild(offer);
			taxes->InsertEndChild(tax);
		}
		child->InsertEndChild(taxes);

		doc.SaveFile(path);
	}
}
