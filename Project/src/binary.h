#ifndef _BINARY_HEADER_H_
#define _BINARY_HEADER_H_
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <iostream>

namespace Binary{
	//Arithmetic Type
	template<typename T>
	typename std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T,std::string>::value,std::string>::type
	serialize(T& b){
    	std::string res;
    	res.append((const char*)&b,sizeof(T));
    	return res;
	}
	template<typename T>
	typename std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T,std::string>::value,int>::type
	deserialize(std::string& str,T& temp){
    	memcpy(&temp,str.data(),sizeof(T));
    	return sizeof(T);
	}
	template<typename T>
	typename std::enable_if<!std::is_arithmetic<T>::value,std::string>::type
	serialize(T& temp) {
    	return temp.serialize();
	}
	template<typename T>
	typename std::enable_if<!std::is_arithmetic<T>::value,int>::type
	deserialize(std::string &str,T& temp) {
    	return temp.deserialize(str);
	}

	std::string serialize(int& len){
    	std::string res;
    	res.append((const char*)&len,sizeof(int));
    	return res;
	}
	int deserialize(std::string& str,int& len){
   		memcpy(&len,str.data(),sizeof(int));
    	return sizeof(int);
	}
	std::string serialize(std::string& str){
    	int len = str.size();
    	std::string res;
    	res.append(serialize(len));
    	res.append(str.data(),len);
    	return res;
	}
	int deserialize(std::string &str,std::string& s){
    	int len;
    	deserialize(str,len);
    	s = str.substr(sizeof(len),len);
    	return sizeof(int) + len;
	}

	class OutStream{
		public:
			OutStream() : os(std::ios::binary){	}
			//Arithmetic Type
			template<typename T>
			OutStream& operator << (T& arith){
				std::string ss = Binary::serialize(arith);
				os.write(ss.data(),ss.size());
				return *this;
			}
			template<typename ArithmeticType>
			OutStream& operator << (std::vector<ArithmeticType>& arith){
				int len = arith.size();
				std::string ss = Binary::serialize(len);
				os.write(ss.data(),ss.size());
				for (int i=0;i < len;++i){
					std::string item = Binary::serialize(arith[i]);
					os.write(item.data(),item.size());
				}
				return *this;
			}
			template<typename ArithmeticType>
			OutStream& operator << (std::list<ArithmeticType>& arith){
				std::vector<ArithmeticType> temp;
				std::copy(arith.begin(),arith.end(),std::back_inserter(temp));
				return this->operator << (temp);
			}
			template<typename ArithmeticType>
			OutStream& operator << (std::set<ArithmeticType>& arith){
				std::vector<ArithmeticType> temp;
				std::copy(arith.begin(),arith.end(),std::back_inserter(temp));
				return this->operator  << (temp);
			}
			template<typename ArithmeticTypeA,typename ArithmeticTypeB>
			OutStream& operator << (std::map<ArithmeticTypeA,ArithmeticTypeB>& arith){
				std::vector<ArithmeticTypeA> tempA;
				std::vector<ArithmeticTypeB> tempB;
				typename std::map<ArithmeticTypeA,ArithmeticTypeB>::const_iterator it;
				for (it = arith.begin();it != arith.end();++it) {
					tempA.push_back(it->first);
					tempB.push_back(it->second);
				}
				this->operator  << (tempA);
				return this->operator  << (tempB);
			}
			template<typename ArithmeticTypeA,typename ArithmeticTypeB>
			OutStream& operator << (std::pair<ArithmeticTypeA,ArithmeticTypeB>& arith){
				ArithmeticTypeA temp_a = arith.first;
				ArithmeticTypeB temp_b = arith.second;
				this->operator  << (temp_a);
				return this->operator  << (temp_b);
			}
			std::string str(){
				return os.str();
			}
			std::ostringstream os;
	};

	class InStream{
		protected:
			std::string str;
			int count;
		public:
			InStream(std::string &s) : str(s),count(s.size()){}
			//Arithmetic Type
			template<typename T>
			InStream& operator>> (T& arith){
				int res = Binary::deserialize(str,arith);
				str = str.substr(res);
				return *this;
			}
			//stl container
			template<typename ArithmeticTypeA,typename ArithmeticTypeB>
			InStream& operator>> (std::pair<ArithmeticTypeA,ArithmeticTypeB>& arith){
				ArithmeticTypeA temp_a, temp_b;
				this->operator>> (temp_a);
				InStream& res = this->operator>> (temp_b);
				arith=std::make_pair(temp_a,temp_b);
				return res;
			}
			template<typename ArithmeticType>
			InStream& operator>> (std::vector<ArithmeticType>& el){
				int len = 0;
				int res = Binary::deserialize(str,len);
				str = str.substr(res);
				for (int i = 0;i < len;++i){
					ArithmeticType arith;
					int size = Binary::deserialize(str,arith);
					el.push_back(arith);
					str = str.substr(size);
				}
				return *this;
			}
			template<typename ArithmeticType>
			InStream& operator>> (std::list<ArithmeticType>& arith){
				std::vector<ArithmeticType> temp;
				InStream& res = this->operator>> (temp);
				if (temp.size() > 0){
					std::copy(temp.begin(),temp.end(),std::back_inserter(arith));
				}
				return res;
			}
			template<typename ArithmeticType>
			InStream& operator>> (std::set<ArithmeticType>& arith){
				std::vector<ArithmeticType> temp;
				InStream& res = this->operator>> (temp);
				if (temp.size() > 0){
					for (size_t i = 0;i < temp.size();++i){
						arith.insert(temp[i]);
					}
				}
				return res;
			}
			template<typename ArithmeticTypeA,typename ArithmeticTypeB>
			InStream& operator>> (std::map<ArithmeticTypeA,ArithmeticTypeB>& el){
				std::vector<ArithmeticTypeA> tempA;
				std::vector<ArithmeticTypeB> tempB;
				this->operator>> (tempA);
				InStream& res = this->operator>> (tempB);
				if (tempA.size()>0 && tempB.size() == tempA.size()){
					for (size_t i = 0;i < tempA.size();++i){
						el.insert(std::make_pair(tempA[i],tempB[i]));
					}
				}
				return res;
			}
			int size(){
				return count-str.size();
			}
	};

	class UserDefinedType_Binary{
		public:
			virtual std::string serialize() = 0;
			virtual int deserialize(std::string&) = 0;
	};

	template<typename T>
	void Binary_Serialize(T& a,std::string filename) {
		OutStream ss;
		ss  << a;
		std::string str = ss.str();
		std::ofstream file(filename,std::ios_base::out | std::ios_base::binary);
		if (!file.is_open()) {
			throw std::runtime_error("File open error");
			return;
		}
		file.write(str.c_str(),str.size()+1);
		file.close();
	}

	template<typename T>
	void Binary_Deserialize(T& temp,std::string filename) {
		std::string output;
		std::ifstream file(filename,std::ios_base::binary|std::ios_base::in);
		if (!file.is_open()) {
			throw std::runtime_error("File open error");
			return;
		}
		std::ostringstream os;
		os  << file.rdbuf();
		file.close();
		output = os.str();
		InStream in(output);
		in >> temp;
	}
}
#endif