
#include <iostream>
#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {


		testcase.setname("range-test")
		.CHECK_EQUAL(range(5,9),"5,6,7,8")
		.CHECK_EQUAL(range(6.6,7.6),"6.6")
		.CHECK_EQUAL(range('a','d'),"a,b,c")
		.CHECK_EQUAL(range(':','?'),":,;,<,=,>")
	  .CHECK_EQUAL(range(1,5),"1,2,3,4")
		.CHECK_EQUAL(range(5.2,9.2),"5.2,6.2,7.2,8.2")
		.CHECK_EQUAL(range('c','d'),"c")
		.CHECK_EQUAL(range(':','>'),":,;,<,=")
	  .CHECK_EQUAL(range(10,13),"10,11,12")
		.CHECK_EQUAL(range(1.4,3.4),"1.4,2.4")
		.CHECK_EQUAL(range('t','x'),"u,v,w")
		.CHECK_EQUAL(range('h','k'),"i,j")
		.CHECK_EQUAL(range(58,59),"58")
		.CHECK_EQUAL(range(15.2,19.2),"15.2,16.2,17.2,18.2")
		.CHECK_EQUAL(range('a','f'),"a,b,c,d,e")
		.CHECK_EQUAL(range(':','<'),":,;,<,=,>")
    .CHECK_EQUAL(range(76,79),"76,77,78")
		.CHECK_EQUAL(range(1.2,10.2),"1.2,2.2,3.2,4.2,5.2,6.2,7.2,8.2,9.2")
		.CHECK_EQUAL(range('u','z'),"v,w,x,y")
		.CHECK_EQUAL(range(':','='),":,;,<")
		.CHECK_EQUAL(range(45,49),"45,46,47,48")
		.CHECK_EQUAL(range(20.3,23.3),"20.3,21.3,22.3")
		.CHECK_EQUAL(range('d','d'),"d")
		.CHECK_EQUAL(range(':',';'),":");

		testcase.setname("chin-test")
		.CHECK_EQUAL(chain(range(1,4),range(5,9)),"1,2,3,5,6,7,8")
		.CHECK_EQUAL(chain(range(-1.3,4.3),range(5,9)),"-1.3,0.3,1.3,2.3,3.3,5,4,3,6,7,8")
		.CHECK_EQUAL(chain(range('a','d'),string("hello")),"a,b,c,h,e,l,l,o")	
		.CHECK_EQUAL(chain(range(':','?'),string("hello")),":,;,<,=,>,h,e,l,l,o")
		.CHECK_EQUAL(chain(range(20,24),range(35,39)),"20,21,22,23,35,36,37,38")
		.CHECK_EQUAL(chain(range(-0.3,3.3),range(1,5)),"-0.3,0.3,1.3,2.3,1,2,3,4")
		.CHECK_EQUAL(chain(range('a','d'),string("C++")),"a,b,c,C,+")	
		.CHECK_EQUAL(chain(range(':','?'),string("C++")),":,;,<,=,>,C,+")
		.CHECK_EQUAL(chain(range(10,11),range(100,101)),"10,100")
		.CHECK_EQUAL(chain(range(-100.1,-98.1),range(5,7)),"-100.1,-99.1,5,6")
		.CHECK_EQUAL(chain(range('b','d'),string("C++")),"b,c,C,+")	
		.CHECK_EQUAL(chain(range(':',';'),string("C++")),":,C,+")
		.CHECK_EQUAL(chain(range(86,91),range(5,9)),"86,87,88,89,90,5,6,7,8")
		.CHECK_EQUAL(chain(range(-1.3,4.3),range(5,9)),"-1.3,0.3,1.3,2.3,3.3,5,4,3,6,7,8")
		.CHECK_EQUAL(chain(range('c','d'),string("C++")),"c,C,+")	
		.CHECK_EQUAL(chain(range(':','='),string("C++")),":,;,<,C,+")
		.CHECK_EQUAL(chain(range(11,12),range(5,9)),"11,5,6,7,8")
		.CHECK_EQUAL(chain(range(-1.3,4.3),range(5,9)),"-1.3,0.3,1.3,2.3,3.3,5,4,3,6,7,8")
		.CHECK_EQUAL(chain(range('y','z'),string("C++")),"y,C,+")	
		.CHECK_EQUAL(chain(range(':','<'),string("C++")),":,;,C,+");
		
		testcase.setname("zip-test")
		.CHECK_EQUAL(zip(range(1,6),string("C++")),"1,h 2,e 3,l 4,l 5,o")
		.CHECK_EQUAL(zip(chain(range(':','?'),string("C++"))),range(0,10),":,0 ;,1 <,2 =,3 >,4 h,5 e,6 l,7 l,8 o,9")
		.CHECK_EQUAL(zip(range(-9,-5),range(5,9),"-9,5 -8,6 -7,7 -6,8")
		.CHECK_EQUAL(zip(chain(range(1,4),range('a','f'))),(chain(range(G,L),range(4,7))),"1,G 2,H 3,I a,J b,K c,4 d,5 e,6")  
		.CHECK_EQUAL(zip(range(1,6),string("C++")),"1,h 2,e 3,l 4,l 5,o")
		.CHECK_EQUAL(zip(chain(range(':','?'),string("C++"))),range(0,10),":,0 ;,1 <,2 =,3 >,4 h,5 e,6 l,7 l,8 o,9")
		.CHECK_EQUAL(zip(range(-9,-5),range(5,9),"-9,5 -8,6 -7,7 -6,8")
		.CHECK_EQUAL(zip(chain(range(1,4),range('a','f'))),(chain(range(G,L),range(4,7))),"1,G 2,H 3,I a,J b,K c,4 d,5 e,6") 
		.CHECK_EQUAL(zip(range(1,6),string("C++")),"1,h 2,e 3,l 4,l 5,o")
		.CHECK_EQUAL(zip(chain(range(':','?'),string("C++"))),range(0,10),":,0 ;,1 <,2 =,3 >,4 h,5 e,6 l,7 l,8 o,9")
		.CHECK_EQUAL(zip(range(-9,-5),range(5,9),"-9,5 -8,6 -7,7 -6,8")
		.CHECK_EQUAL(zip(chain(range(1,4),range('a','f'))),(chain(range(G,L),range(4,7))),"1,G 2,H 3,I a,J b,K c,4 d,5 e,6") 
		.CHECK_EQUAL(zip(range(1,6),string("C++")),"1,h 2,e 3,l 4,l 5,o")
		.CHECK_EQUAL(zip(chain(range(':','?'),string("C++"))),range(0,10),":,0 ;,1 <,2 =,3 >,4 h,5 e,6 l,7 l,8 o,9")
		.CHECK_EQUAL(zip(range(-9,-5),range(5,9),"-9,5 -8,6 -7,7 -6,8")
		.CHECK_EQUAL(zip(chain(range(1,4),range('a','f'))),(chain(range(G,L),range(4,7))),"1,G 2,H 3,I a,J b,K c,4 d,5 e,6") 
		.CHECK_EQUAL(zip(range(1,6),string("C++")),"1,h 2,e 3,l 4,l 5,o")
		.CHECK_EQUAL(zip(chain(range(':','?'),string("C++"))),range(0,10),":,0 ;,1 <,2 =,3 >,4 h,5 e,6 l,7 l,8 o,9")
		.CHECK_EQUAL(zip(range(-9,-5),range(5,9),"-9,5 -8,6 -7,7 -6,8")
		.CHECK_EQUAL(zip(chain(range(1,4),range('a','f'))),(chain(range(G,L),range(4,7))),"1,G 2,H 3,I a,J b,K c,4 d,5 e,6") ;



		testcase.setname("product-test")
		.CHECK_EQUAL(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
		.CHECK_EQUAL(product(range('a',c),chain(range(1,4),range(0,2))),"a,1 a,2 a,3 a,0 a,1 b,1 b,2 b,3 b,0 b,1")
		.CHECK_EQUAL(product(range(:,<),zip(string("hlool"),string("elwrd"))),":,h,e :,l,l :,o,w :,o,r :,l,d ;,h,e ;,l,l ;,o,w ;,o,r ;,l,d")   
		.CHECK_EQUAL(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
		.CHECK_EQUAL(product(range('a',c),chain(range(1,4),range(0,2))),"a,1 a,2 a,3 a,0 a,1 b,1 b,2 b,3 b,0 b,1")
		.CHECK_EQUAL(product(range(:,<),zip(string("hlool"),string("elwrd"))),":,h,e :,l,l :,o,w :,o,r :,l,d ;,h,e ;,l,l ;,o,w ;,o,r ;,l,d")
    .CHECK_EQUAL(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
		.CHECK_EQUAL(product(range('a',c),chain(range(1,4),range(0,2))),"a,1 a,2 a,3 a,0 a,1 b,1 b,2 b,3 b,0 b,1")
		.CHECK_EQUAL(product(range(:,<),zip(string("hlool"),string("elwrd"))),":,h,e :,l,l :,o,w :,o,r :,l,d ;,h,e ;,l,l ;,o,w ;,o,r ;,l,d")
		.CHECK_EQUAL(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
		.CHECK_EQUAL(product(range('a',c),chain(range(1,4),range(0,2))),"a,1 a,2 a,3 a,0 a,1 b,1 b,2 b,3 b,0 b,1")
		.CHECK_EQUAL(product(range(:,<),zip(string("hlool"),string("elwrd"))),":,h,e :,l,l :,o,w :,o,r :,l,d ;,h,e ;,l,l ;,o,w ;,o,r ;,l,d")
		.CHECK_EQUAL(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
		.CHECK_EQUAL(product(range('a',c),chain(range(1,4),range(0,2))),"a,1 a,2 a,3 a,0 a,1 b,1 b,2 b,3 b,0 b,1")
		.CHECK_EQUAL(product(range(:,<),zip(string("hlool"),string("elwrd"))),":,h,e :,l,l :,o,w :,o,r :,l,d ;,h,e ;,l,l ;,o,w ;,o,r ;,l,d")
		.CHECK_EQUAL(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
		.CHECK_EQUAL(product(range('a',c),chain(range(1,4),range(0,2))),"a,1 a,2 a,3 a,0 a,1 b,1 b,2 b,3 b,0 b,1")
		.CHECK_EQUAL(product(range(:,<),zip(string("hlool"),string("elwrd"))),":,h,e :,l,l :,o,w :,o,r :,l,d ;,h,e ;,l,l ;,o,w ;,o,r ;,l,d");
		
		
		
		testcase.setname("powerset-test")
		.CHECK_EQUAL(powerset(string("abc")),"{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
    .CHECK_EQUAL(powerset(string("bcd")),"{},{b},{c},{b,c},{d},{b,d},{c,d},{b,c,d}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
		.CHECK_EQUAL(powerset(string("cde")),"{},{c},{d},{c,d},{e},{c,e},{d,e},{c,d,e}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
    .CHECK_EQUAL(powerset(string("efg")),"{},{e},{f},{e,f},{g},{e,g},{f,g},{e,f,g}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
    .CHECK_EQUAL(powerset(string("ghi")),"{},{g},{h},{g,h},{i},{g,i},{h,i},{g,h,i}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
    .CHECK_EQUAL(powerset(string("ijk")),"{},{i},{j},{i,j},{k},{i,k},{j,k},{i,j,k}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
    .CHECK_EQUAL(powerset(string("klm")),"{},{k},{l},{k,l},{m},{k,m},{l,m},{k,l,m}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
		.CHECK_EQUAL(powerset(string("mno")),"{},{m},{n},{m,n},{o},{m,o},{n,o},{m,n,o}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
		.CHECK_EQUAL(powerset(string("opq")),"{},{o},{p},{o,p},{q},{o,q},{p,q},{o,p,q}")
		.CHECK_EQUAL(powerset(chain(range(1,3),range(S,U))),"{},{1},{2},{1,2},{S},{1,S},{2,S},{T},{1,T},{2,T},{S,T},{1,2,S},{1,2,T},{1,S,T},{2,S,T},{1,2,S,T}")
		grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	if(grade>95)
	cout<< "Your grade is: "<<grade<<" great! :-)"<<endl;
	else
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
