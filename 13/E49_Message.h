#ifndef E49_H
#define E49_H

#include <string>
using std::string;

#include <set>
using std::set;

class Folder;
class Message{
	friend class Folder;
private:
	explicit Message(const string&s = ""):contents(s) {}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message &&) noexcept ;
	Message& operator=(Message&&) noexcept ;
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;
	set<Folder*> folders;
	void add_to_folder(const Message&);	
	void remove_from_folder();
};


class Folder{
	friend class Message;
public:
	explicit Folder(const string&s = ""):name(s) {}
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	Folder(Folder&&);
	Folder& operator=(Folder&&);

	const string& fldr() { return name; }
	void print_debug();
private:
	string name;
	set<Message*> msgs;

	void add_to_message(const Folder&);
	void remove_from_message();

	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
};


void Message::add_to_folder(const Message&m){
	for(auto f : m.folders){
		f->addMsg(this);
	}
}

Message::Message(const Message& m):contents(m.contents), folders(m.folders){
	add_to_folder(m);
}

void Message::remove_from_folder(){
	for(auto f : folders){
		f->remMsg(this);
	}
}

Message::~Message(){
	remove_from_folder();
}

void Message::save(Folder& f){
	folders.insert(&f);   // updata the Message class
	f.addMsg(this);		// update the Folder class
}

Message& Message::operator=(const Message& m){
	remove_from_folder();
	contents = m.contents;
	folders = m.folders;
	add_to_folder(m);
	return *this;
}

Message::Message(Message&& m) noexcept {
	contents = std::move(m.contents);
	folders = std::move(m.folders);
}

Message& Message::operator=(Message&& m) noexcept{
	remove_from_folder();
	contents = std::move(m.contents);
	folders = std::move(m.folders);
	return *this;
}

#endif