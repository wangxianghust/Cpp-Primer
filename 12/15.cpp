#include <iostream>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::make_shared;
using std::shared_ptr;

struct destination{
	string ip;
	int port;
	destination(string ip_, int port_):ip(ip_), port(port_){};
};

struct connection{
	string ip;
	int port;
	connection(string ip_, int port_):ip(ip_), port(port_){};
};

connection connect(destination *dest){
	shared_ptr<connection> pConn(new connection(dest->ip, dest->port));
	cout << "creating connection( " << pConn.use_count() << ")" << endl;
	return *pConn;
}

// void disconnect(connection pConn){
// 	cout << "connection close " << pConn.ip << " : " << pConn.port << endl;
// }

// void end_connection(connection *pConn){
// 	disconnect(*pConn);
// }

void f(destination &d){
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *pConn){cout << "connection close " << pConn->ip << " : " << pConn->port << endl;});
}

int main(){
	destination dest("202.118.175.12", 8808);
	f(dest);
}