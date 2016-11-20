#include "E19_3.h"

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}

int main(){
	return 0;
}