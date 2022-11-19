#include "m.h"
void TestE::d_to_string(TestDD & d) {
	std::cout << "d_to_string" << d.address << "#" << d.age << std::endl;
	d.to_String();
}
int TestF::f_to_string(TestDD& d,int) {
	//std::cout << "f_to_string" << d.address << "#" << d.age << std::endl;
	d.to_String();
	return 0;
}
int  outFunP(TestDD& d) {
	std::cout << "outFunP" << d.address << "#" << d.age << std::endl;
	return 0;
}