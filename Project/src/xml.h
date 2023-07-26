#ifndef _XML_HEADER_H_
#define _XML_HEADER_H_
#include "thirdpart/tinyxml2.h"
#include <cstring>

namespace Xml {
using namespace tinyxml2;
class XML {
	public:
		// Arithmetic type and others
		template<typename T>
        struct Type {
            template<typename U = T,
                    typename std::enable_if<std::is_arithmetic<U>::value && !std::is_same<U,bool>::value>::type* = nullptr>
            static void Loadin(XMLElement * temp,U & v) {
                std::stringstream ss(temp->GetText());
                ss >> v;
            }
            template<typename U = T,
                    typename std::enable_if<std::is_arithmetic<U>::value && !std::is_same<U,bool>::value>::type* = nullptr>
            static void Storein(XMLElement * temp,const std::string & name,const U & v) {
                tinyxml2::XMLElement * par = temp->GetDocument()->NewElement(name.c_str());
                par->SetText(v);
                temp->InsertEndChild(par);
            }
        };
		//std::pair<TA,TB>
		template<typename TA,typename TB>
		struct Type<std::pair<TA,TB>>{
			static void Loadin(XMLElement * temp,std::pair<TA,TB> &v){
				TA temp_a;
				TB temp_b;
				tinyxml2::XMLElement *child_a = temp->FirstChildElement();
				tinyxml2::XMLElement *child_b = child_a->NextSiblingElement();
				Type<TA>::Loadin(child_a,temp_a);
				Type<TB>::Loadin(child_b,temp_b);
				v=std::make_pair(temp_a,temp_b);
			}
			static void Storein(XMLElement * temp,const std::string & name,const std::pair<TA,TB> &v){
				TA temp_a = v.first;
				TB temp_b = v.second;
				tinyxml2::XMLElement * par = temp->GetDocument()->NewElement(name.c_str());
				Type<TA>::Storein(par,"first",temp_a);
				Type<TB>::Storein(par,"second",temp_b);
				temp->InsertEndChild(par);
			}
		};
		//std::vector<T>
		template<typename T>
		struct Type<std::vector<T>>{
			static void Loadin(XMLElement *temp,std::vector<T> &v){
				tinyxml2::XMLElement * child = temp->FirstChildElement();
				while (child){
					T v_child;
					Type<T>::Loadin(child,v_child);
					v.push_back(v_child);
					child = child->NextSiblingElement();
				}
			}
			static void Storein(XMLElement * temp,const std::string & name,const std::vector<T> & v){
				XMLElement * par = temp->GetDocument()->NewElement(name.c_str());
				for (auto &ref : v) {
					Type<T>::Storein(par,"item",ref);
				}
				temp->InsertEndChild(par);
			}
		};

		//std::list<T>
		template<typename T>
		struct Type<std::list<T>>{
			static void Loadin(XMLElement * set,std::list<T> &v){
				std::vector<T> temp;
				Type<std::vector<T>>::Loadin(set,temp);
				if (temp.size() > 0) {
					std::copy(temp.begin(),temp.end(),std::back_inserter(v));
				}
			}
			static void Storein(XMLElement * set,const std::string & name,const std::list<T> & v){
				std::vector<T> temp;
				std::copy(v.begin(),v.end(),std::back_inserter(temp));
				Type<std::vector<T>>::Storein(set,name,temp);
			}
		};

		//std::set<T>
		template<typename T>
		struct Type<std::set<T>>{
			static void Loadin(XMLElement * set,std::set<T> &v){
				std::vector<T> temp;
				Type<std::vector<T>>::Loadin(set,temp);
				if (temp.size() > 0) {
					for (size_t i = 0;i < temp.size();++i){
						v.insert(temp[i]);
					}
				}
			}
			static void Storein(XMLElement * set,const std::string & name,const std::set<T> & v){
				std::vector<T> temp;
				std::copy(v.begin(),v.end(),std::back_inserter(temp));
				Type<std::vector<T>>::Storein(set,name,temp);
			}
		};

		//std::map<TA,TB>
		template<typename TA,typename TB>
		struct Type<std::map<TA,TB>>{
			static void Loadin(XMLElement * map,std::map<TA,TB> &v){
				std::vector<TA> vet_a;
				std::vector<TB> vet_b;
				tinyxml2::XMLElement * xvet_a = map->FirstChildElement();
				tinyxml2::XMLElement * xvet_b = xvet_a->NextSiblingElement();
				if (xvet_a&&xvet_b) {
					Type<std::vector<TA>>::Loadin(xvet_a,vet_a);
					Type<std::vector<TB>>::Loadin(xvet_b,vet_b);
				}
				if (vet_a.size() > 0 && vet_b.size() == vet_a.size()){
					for (size_t i = 0;i < vet_a.size();++i){
						v.insert(std::make_pair(vet_a[i],vet_b[i]));
					}
				}
			}
			static void Storein(XMLElement * map,const std::string & name,const std::map<TA,TB> & v){
				typename std::map<TA,TB>::const_iterator iter;
				std::vector<TA> vet_a;
				std::vector<TB> vet_b;
				for (iter = v.begin();iter != v.end();++iter){
					vet_a.push_back(iter->first);
					vet_b.push_back(iter->second);
				}
				tinyxml2::XMLElement *temp = map->GetDocument()->NewElement(name.c_str());
				Type<std::vector<TA>>::Storein(temp,"Key",vet_a);
				Type<std::vector<TB>>::Storein(temp,"Val",vet_b);
				map->InsertEndChild(temp);
			}
		};
	};

	class UserDefinedType_Xml {
   		public:
        	virtual void XML_Deserialize(const std::string &name,const std::string &file) = 0;
        	virtual void XML_Serialize(const std::string &name,const std::string &file) = 0;
    };
	
	//std::string
	template<>
	struct XML::Type<std::string>{
		static void Loadin(tinyxml2::XMLElement * temp,std::string &v){
			v = temp->GetText();
		}
		static void Storein(tinyxml2::XMLElement * temp,const std::string & name,const std::string & v){
			tinyxml2::XMLElement * par = temp->GetDocument()->NewElement(name.c_str());
			par->SetText(v.c_str());
			temp->InsertEndChild(par);
		}
	};
		
	XMLDocument* Load(const std::string &file) {
		std::ifstream ss(file);
		if (!ss){
			throw std::runtime_error("open file error");
		}
		std::stringstream buffer;
		buffer << ss.rdbuf();
		XMLDocument *doc = new XMLDocument();
		doc->Parse(buffer.str().c_str());
		return doc;
	}

	template<typename T>
	void XML_Deserialize(T& a,const std::string &name,const std::string &file) {
		XMLDocument *doc = Load(file);
		XMLElement *temp = doc->RootElement()->FirstChildElement();
		if (temp) {
			XML::Type<T>::Loadin(temp,a);
		}
	}

	void Save(const XMLDocument *doc,const std::string &file) {
        tinyxml2::XMLPrinter print;
        doc->Print(&print);
        std::string buffer = std::string(print.CStr());
        std::ofstream ss(file);
        if (!ss) {
			throw std::runtime_error("open file error");
			return;
		}
        ss << buffer;
    }

	template<typename T>
	void XML_Serialize(T& a,const std::string &name,const std::string &file) {
		XMLDocument* doc = new XMLDocument();
		XMLDeclaration *def = doc->NewDeclaration();
		doc->InsertFirstChild(def);
		XMLElement * par = doc->NewElement("serialization");
		XML::Type<T>::Storein(par,name,a);
		doc->InsertEndChild(par);
		Save(doc,file);
	}
}
#endif