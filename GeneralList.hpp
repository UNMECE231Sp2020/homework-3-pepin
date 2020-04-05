#include <iostream>

template <class Data>
class List {
	private:
		struct _list {
			Data value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
			if(ptr) { // if(ptr != nullptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List() {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list) {
			_front=nullptr;
			_back=nullptr;
			_size=0;
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
			//while(_size > 0) {
				rm_frontnode();
			}
		}

		Data &front() const {
			return _front->value;
		}

		Data &back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		void push_front(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->prev = nullptr;

			if(_front==nullptr) {
				newNode->next= nullptr;
				_back=newNode;
			}
			else {
				newNode->next= nullptr;
				_front->back = newNode;
			}

			_front=newNode;
			_size++;
		}

		void push_back(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next = nullptr;

			if(_back!= nullptr) {
				_back->next=newNode;
				newNode->prev = _back;
			}

			if(_front==nullptr) {
				_front=newNode;
				newNode->prev = nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void rm_frontnode()  {
			Dlist *front_to_delete = _front;
			_front = _front->next;

			if(_front==nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size -= 1;
		}

		//CONVERT THIS FUNCTION
		void rm_backnode() {
			Dlist *back_to_remove = _back;
			_back = _back->prev;

			if(_back==nullptr) {
				_front = nullptr;
			}
			else {
				_back->next = nullptr;
			}

			delete back_to_remove;
			_size -= 1;
		}

		// leave this alone
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}

		//Modify this
		void print() {
			Dlist *temp;
			for(temp=_front; temp!=nullptr; temp=temp->next) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}

		void print_back() {
			Dlist *temp;
			for(temp = _back; temp!=nullptr; temp = temp->prev){
				std::cout<< temp->value << " ";
			}
			std::cout << std::endl;
		}

		List &operator=(const List &x){
			Dlist *temp;
			_size = x._size;
			temp = _front;
			for(temp = x._front; temp!=nullptr; temp = temp->next){
				push_back(temp->value);
			}

			return *this;
		}

		template<typename V> friend bool operator==(const List<V> &a, const List<V> &b);
		template<typename V> friend bool operator!=(const List<V> &a, const List<V> &b);
};

template<typename V> bool operator==(const List<V> &a, const List<V> &b){
	if(a._size == b._size){
		for(auto temp_a = a._front, temp_b = b._front; temp_a != nullptr || temp_b = nullptr; temp_a = temp_a->next, temp_b = temp_b->next){
			if(temp_a->value != temp_b->value){
				return false;
			}
			else{
				return true;
			}
		}
	}
	else{
		return false;
	}
}

template<typrename V> bool operator!=(const List<V> &a, const List<V> &b){
	if(a._size != b._size){
		return true;
	}

	else{
		for(auto temp_a = a._front, temp_b = b._front; temp_a != nullptr || temp_b != nullptr; temp_a = temp_a->next, temp_b = temp_b->next){
			if(temp_a->value != temp_b->value){
				return true;
			}
			else{
				return false;
			}
		}
	}
}

