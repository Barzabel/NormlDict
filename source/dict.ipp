



template<class T>
NativeDict<T>::NativeDict() {
	this->arrlist = new LinkedList2<T>[size];


}


template<class T>
T &NativeDict<T>::operator[](string key) {
	size_t i = hash<string>{}(key);
	Node2<T> *H = arrlist[i%this->size].findkey(key);
	if (H != nullptr)
	{
		return H->value;
	}
	else 
	{
		Node2<T> *H1 = new Node2<T>();
		H1->key = key;
		arrlist[i%this->size].add_in_tail(H1);
		return arrlist[i%this->size].gettail()->value;
	}
	}




template<class T>
void NativeDict<T>::put(std::string key, T value) {
	size_t i = hash<string>{}(key);
	Node2<T> *H = arrlist[i%this->size].findkey(key);
	if (H != nullptr)
	{
		H->value=value;
		return;
	}
	Node2<T> *H1 = new Node2<T>(value);
	H1->key = key;
	arrlist[i%this->size].add_in_tail(H1);
	
}

template<class T>
T& NativeDict<T>::get(std::string key) {
	size_t i = hash<string>{}(key);
	Node2<T> *H = arrlist[i%this->size].findkey(key);
	if (H != nullptr)
	{
		return H->value;
	}
	else 
	{
		Node2<T> *H1 = new Node2<T>();
		H1->key = key;
		arrlist[i%this->size].add_in_tail(H1);
		return arrlist[i%this->size].gettail()->value;
	}
	
}




template<class T>
bool  NativeDict<T>::is_key(std::string key)
{
	size_t i = hash<string>{}(key);
	Node2<T> *H = arrlist[i%this->size].findkey(key);
	if (H != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}


template<class T>
NativeDict<T>::~NativeDict() {

	delete[] this->arrlist;
	
}