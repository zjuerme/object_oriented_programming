#include "src/binary.h"
#include "src/xml.h"
#include "src/UserDefinedType.h"
#include "src/util.h"

void test_string() {
	std::string str = "This is the OOP project by 3210103790 in Zhejiang University";
	std::string str_b,str_x;
	//binary
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(str,"test/string.data");
	Binary::Binary_Deserialize(str_b,"test/string.data");
	AssertEqual(str,str_b);
	//xml
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(str,"std_str","test/string.xml");
	Xml::XML_Deserialize(str_x,"std_str","test/string.xml");
	AssertEqual(str,str_x);
}
void test_pair() {
	std::pair<int,double> pair(3,7.90);
	std::pair<int,double> pair_b,pair_x;
	//binary_test
	Binary::Binary_Serialize(pair,"test/pair.data");
	Binary::Binary_Deserialize(pair_b,"test/pair.data");
	AssertEqual(pair.first,pair_b.first);
	AssertEqual(pair.second,pair_b.second);
	//xml_test
	Xml::XML_Serialize(pair,"std_pair","test/pair.xml");
	Xml::XML_Deserialize(pair_x,"std_pair","test/pair.xml");
	AssertEqual(pair.first,pair_x.first);
	AssertEqual(pair.second,pair_x.second);
}
void test_vector() {
	std::vector<std::string> vec;
	std::vector<std::string> vec_b,vec_x;
	vec.push_back("zhe");
	vec.push_back("jiang");
	vec.push_back("university");
	vec.push_back("cs department");
	//binary
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(vec,"test/vector.data");
	Binary::Binary_Deserialize(vec_b,"test/vector.data");
	std::cout << "size check";
	AssertEqual(vec.size(),vec_b.size());
	std::cout << "value check";
	for (size_t i = 0;i < vec.size();++i){
		AssertEqual(vec[i],vec_b[i]);
	}
	//xml
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(vec,"std_vector","test/vector.xml");
	Xml::XML_Deserialize(vec_x,"std_vector","test/vector.xml");
	std::cout << "xml_vector_test\n";
	std::cout << "size check";
	AssertEqual(vec.size(),vec_x.size());
	std::cout << "value check";
	for (size_t i = 0;i < vec.size();++i){
		AssertEqual(vec[i],vec_x[i]);
	}
}
void test_list() {
	std::list<std::string> lis;
	std::list<std::string> lis_b,lis_x;
	std::list<std::string>::iterator iterator_a,iterator_b;
	lis.push_back("zhe");
	lis.push_back("jiang");
	lis.push_back("university");
	lis.push_back("cs department");
	//binary_test
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(lis,"test/list.data");
	Binary::Binary_Deserialize(lis_b,"test/list.data");
	std::cout << "size check\n";
	AssertEqual(lis.size(),lis_b.size());
	std::cout << "value check\n";
	for (iterator_a = lis.begin(),iterator_b = lis_b.begin();iterator_a != lis.end() && iterator_b != lis_b.end();++iterator_a,++iterator_b){
		AssertEqual((*iterator_a),(*iterator_b));
	}
	//xml_test
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(lis,"std_list","test/list.xml");
	Xml::XML_Deserialize(lis_x,"std_list","test/list.xml");
	std::cout << "size check\n";
	AssertEqual(lis.size(),lis_x.size());
	std::cout << "value check\n";
	for (iterator_a = lis.begin(),iterator_b = lis_x.begin();iterator_a != lis.end() && iterator_b != lis_x.end();++iterator_a,++iterator_b){
		AssertEqual((*iterator_a),(*iterator_b));
	}
}
void test_set() {
	std::set<std::string> set;
	std::set<std::string> set_b,set_x;
	std::set<std::string>::iterator iterator_a,iterator_b;
	set.insert("zhejiang");
	set.insert("university");
	set.insert("computer science");
	set.insert("department");
	//binary_test
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(set,"test/set.data");
	Binary::Binary_Deserialize(set_b,"test/set.data");
	std::cout << "size check\n";
	AssertEqual(set.size(),set_b.size());
	std::cout << "value check\n";
	for (iterator_a = set.begin(),iterator_b = set_b.begin();iterator_a != set.end() && iterator_b != set_b.end();++iterator_a,++iterator_b){
		AssertEqual((*iterator_a),(*iterator_b));
	}
	//xml_test
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(set,"std_set","test/set.xml");
	Xml::XML_Deserialize(set_x,"std_set","test/set.xml");
	std::cout << "size check\n";
	AssertEqual(set.size(),set_x.size());
	std::cout << "value check\n";
	for (iterator_a = set.begin(),iterator_b = set_x.begin();iterator_a != set.end() && iterator_b != set_x.end();++iterator_a,++iterator_b){
		AssertEqual((*iterator_a),(*iterator_b));
	}
}
void test_map() {
	std::map<std::string,int> map;
	std::map<std::string,int> map_b,map_x;
	std::map<std::string,int>::const_iterator iterator_a,iterator_b;
	map["zhe"] = 1;
	map["jiang"] = 2;
	map["university"] = 3;
	//binary_test
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(map,"test/map.data");
	Binary::Binary_Deserialize(map_b,"test/map.data");
	std::cout << "size check\n";
	AssertEqual(map.size(),map_b.size());
	std::cout << "value check\n";
	for (iterator_a = map.begin(),iterator_b = map_b.begin();iterator_a != map.end() && iterator_b != map_b.end();++iterator_a,++iterator_b){
		AssertEqual(iterator_a->first,iterator_b->first);
		AssertEqual(iterator_a->second,iterator_b->second);
	}
	//xml_test
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(map,"std_map","test/map.xml");
	Xml::XML_Deserialize(map_x,"std_map","test/map.xml");
	std::cout << "size check\n";
	AssertEqual(map.size(),map_x.size());
	std::cout << "value check\n";
	for (iterator_a = map.begin(),iterator_b = map_x.begin();iterator_a != map.end() && iterator_b != map_x.end();++iterator_a,++iterator_b){
		AssertEqual(iterator_a->first,iterator_b->first);
		AssertEqual(iterator_a->second,iterator_b->second);
	}
}
void test_int(){
	int i = 1;
	int i_b,i_x;
	//binary
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(i,"test/int.data");
	Binary::Binary_Deserialize(i_b,"test/int.data");
	AssertEqual(i,i_b);
	//xml
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(i,"int","test/int.xml");
	Xml::XML_Deserialize(i_x,"int","test/int.xml");
	AssertEqual(i,i_x);
}
void test_char(){
	char c = 'z';
	char c_b,c_x;
	//binary
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(c,"test/char.data");
	Binary::Binary_Deserialize(c_b,"test/char.data");
	AssertEqual(c,c_b);
	//xml
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(c,"char","test/char.xml");
	Xml::XML_Deserialize(c_x,"char","test/char.xml");
	AssertEqual(c,c_x);
}
void test_float() {
	float f = 1.30;
	float f_b,f_x;
	//binary
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(f,"test/float.data");
	Binary::Binary_Deserialize(f_b,"test/float.data");
	AssertEqual(f,f_b);
	//xml
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(f,"float","test/float.xml");
	Xml::XML_Deserialize(f_x,"float","test/float.xml");
	AssertEqual(f,f_x);
}
void test_double() {
	double f = 1.3001;
	double f_b,f_x;
	//binary
	std::cout << "binary_serialize & deserialize\n";
	Binary::Binary_Serialize(f,"test/double.data");
	Binary::Binary_Deserialize(f_b,"test/double.data");
	AssertEqual(f,f_b);
	//xml
	std::cout << "xml_serialize & deserialize\n";
	Xml::XML_Serialize(f,"double","test/double.xml");
	Xml::XML_Deserialize(f_x,"double","test/double.xml");
	AssertEqual(f,f_x);
}
void test_UserDefined() {
	//binary
	std::cout << "binary_serialize & deserialize\n";
	std::vector<double> data = {1.0,1.2,2.8};
	UserDefinedType_Binary B_xml1(7,data,"Hello World");
	UserDefinedType_Binary B_xml2;
	Binary::Binary_Serialize(B_xml1,"test/UserDefined.data");
	Binary::Binary_Deserialize(B_xml2,"test/UserDefined.data");
	AssertEqual(B_xml1,B_xml2);
	//xml
	std::cout << "xml_serialize & deserialize\n";
	UserDefinedType_Xml U_xml1(7,data,"Hello World");
	UserDefinedType_Xml U_xml2;
	U_xml1.XML_Serialize("userdefined","test/UserDefined.xml");
	U_xml2.XML_Deserialize("userdefined","test/UserDefined.xml");
	AssertEqual(U_xml1,U_xml2);
}

int main(){
	std::string line;
	std::cout << "#####################################################################\n";
	std::cout << "         Enter to test UserDefined Type            \n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);

	test_UserDefined();
	std::cout << "\n#####################################################################\n";
    std::cout << "		   Enter to test Arithmetic Types\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);
	std::cout << "int\n";
	test_int();
	std::cout << "char\n";
	test_char();
	std::cout << "float(double)\n";
	test_float();
	test_double();
	std::cout << "\n#####################################################################\n";
    std::cout << "			Enter to test String\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);
	
	test_string();
	std::cout << "\n#####################################################################\n";
	std::cout << "			Enter to test Vector\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);

	test_vector();
	std::cout << "\n#####################################################################\n";
	std::cout << "			Enter to test List\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);

	test_list();
	std::cout << "\n#####################################################################\n";
	std::cout << "			Enter to test Set\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);
	
	test_set();
	std::cout << "\n#####################################################################\n";
	std::cout << "			Enter to test Map\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);

	test_map();
	std::cout << "\n#####################################################################\n";
	std::cout << "			Enter to test Pair\n";
	std::cout << "#####################################################################\n";
    std::getline(std::cin,line);

	test_pair();
	std::cout << "\n#####################################################################\n\n";
	std::cout << "                    \\||/" << std::endl;
    std::cout << "                    |  @___oo" << std::endl;
    std::cout << "          /\\  /\\   / (__,,,,|" << std::endl;
    std::cout << "         ) /^\\) ^\\/ _)" << std::endl;
    std::cout << "         )   /^\\/   _)" << std::endl;
    std::cout << "         )   _ /  /" << std::endl;
    std::cout << "     /\\  )/\\/ ||" << std::endl;
    std::cout << "wWwWwWwWwWwWw||wWwWwWwWwWwWwWwW" << std::endl;
    std::cout << "^^^^^^^^^^^^^mm^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << "\n#####################################################################\n";

	std::getline(std::cin,line);
	return 0;
}