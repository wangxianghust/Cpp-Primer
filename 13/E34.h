#ifndef E34_H
#define E34_H

#include <string>
using std::string;
#include <set>
using std::set;

class Folder;
class Message{
	friend class Folder;
public:
	explicit Message(const string& s = ""):contents(s){};
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folder *f) {folders.insert(f);}
	void remFldr(Folder *f) {folders.erase(f); }
};

class Folder{
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
private:
	set<Message*> message;
	void remMsg(Message*);
	void addMsg(Message*);

	void remove_to_Message();
	void add_to_Message(const Folder&);
};

void Message::add_to_Folders(const Message& m){  // put the message to now folder
	for(auto f : m.folders){
		f->addMsg(this);
	}
}

void Message::remove_from_Folders(){
	for(auto f : folders){
		f->remMsg(this);
	}
}

Message::Message(const Message& m):contents(m.contents), folders(m.folders){
	add_to_Folders(m);
}

Message::~Message(){
	remove_from_Folders();
}

Message& Message::operator=(const Message& m){
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}

void Message::save(Folder& f){
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f){
	folders.erase(&f);
	f.remMsg(this);
}

void Folder::add_to_Message(const Folder& f){
	for(auto m : f.message){
		m->addFldr(this);
	}
}

void Folder::remove_to_Message(){
	for(auto m : message){
		m->remFldr(this);
	}
	message.clear();
}

Folder::Folder(const Folder& f): message(f.message){
	add_to_Message(f);
}

Folder& Folder::operator=(const Folder& f){
	remove_to_Message();
	message = f.message;
	add_to_Message(f);
	return *this;
}

void Folder::addMsg(Message* m){
	message.insert(m);
}

void Folder::remMsg(Message* m){
	message.erase(m);
}


#endif