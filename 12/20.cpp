#include "E19_3.h"
#include <fstream>
#include <vector>

using std::ifstream;
using std::vector;
using std::getline;

// auto StrBlobPtr::begin() { return StrBlobPtr(*this);}
// auto StrBlobPtr::end(){
// 	auto ret = StrBlobPtr(*this, data->size());
// 	return ret;
// }

int main(){
	ifstream in("../data/book.txt");
	string line;
	// vector<StrBlobPtr> sbp;
	StrBlob sb;
	while(getline(in, line)){
		// StrBlob sb(initializer_list<string>(line));
		// sbp.push_back(StrBlobPtr(sb));
		sb.push_back(line);
	}

	// cout << sb.front() << " ---> " << sb.back() << endl;
	// cout << sb.size() << endl;
	// StrBlobPtr sbp(sb);
	// for(int i = 0; i < sb.size(); ++i){
	// 	cout << sbp.deref() << endl;
	// 	sbp.incr();
	// }

	// for (StrBlobPtr pbeg(sb.begin()), pend(sb.end()); pbeg != pend; pbeg.incr())
 //        std::cout << pbeg.deref() << std::endl;
}