#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <cstddef>
#include <stdexcept>

template<typename K, typename D>
class redblack_node{

public:
	K key;
	D data;
	bool color; // 0 for black, 1 for red
	redblack_node<K,D>* parent;
	redblack_node<K,D>* left;
	redblack_node<K,D>* right;
		
	redblack_node(){
	}

	redblack_node(const K& key, const D& data, redblack_node<K,D>* parent,
		redblack_node<K,D>* left, redblack_node<K,D>* right, bool color) :
		key(key),
		data(data),
		color(color),
		parent(parent), left(left), right(right)
	{
	}

	~redblack_node(){
	}
};

template<typename K, typename D>
class redblack_tree {

DISABLE_COPY(redblack_tree);

private:
	redblack_node<K,D>* root;
	redblack_node<K,D>* nil; //Ghost leaf

public:

	redblack_tree();
	~redblack_tree();
	redblack_node<K,D>* getRoot() const;
	void insertNode(redblack_node<K,D>* new_node);
	const D& at(const K &key);
	D& operator[](const K &key);
	size_t size();

private:
	void destroyRedBlackTree(redblack_node<K,D>* node);
	void balancetree(redblack_node<K,D>* node);
	void rotate(redblack_node<K,D>* node, bool direction);
	D& private_at(const K &key);
	size_t getsize(redblack_node<K,D>* node);

};

template<typename K, typename D>
redblack_tree<K,D>::redblack_tree(){
	//Root is a black ghost leaf aka: nil
	this->root = new redblack_node<K,D>(0,0,NULL,NULL,NULL, 0);
	this->nil = this->root;
};

template<typename K, typename D>
redblack_tree<K,D>::~redblack_tree(){
	redblack_tree<K,D>::destroyRedBlackTree(this->root);
	delete(this->nil);
};

template<typename K, typename D>
redblack_node<K,D>* redblack_tree<K,D>::getRoot() const {
	return this->root;
};

template<typename K, typename D>
void redblack_tree<K,D>::insertNode(redblack_node<K,D>* new_node){
	redblack_node<K,D>* current = this->root;
	redblack_node<K,D>* aux = this->nil;

	while(current != nil){
		aux = current;
		if(new_node->key > current->key){
			current = current->right;
		} else {
			current = current->left;
		}
	}
	new_node->parent = aux;
	if(aux == nil){
		this->root = new_node;
	} else {
		if(aux->key > new_node->key){
			aux->left = new_node;
		} else {
			aux->right = new_node;
		}
	}
	//
	new_node->left = new_node->right = nil;
	balancetree(new_node);
};

template<typename K, typename D>
const D& redblack_tree<K,D>::at(const K& key){
	return private_at(key); 
};

template<typename K, typename D>
D& redblack_tree<K,D>::operator[](const K& key){
	try{
		return private_at(key);
	} catch (const std::exception& e){
		redblack_node<K,D>* new_node = new redblack_node<K,D>(key,0,NULL,NULL,NULL, 1);
		insertNode(new_node);
		return new_node->data;
	}
};

template<typename K, typename D>
size_t redblack_tree<K,D>::size(){
	return getsize(this->root);
};

template<typename K, typename D>
void redblack_tree<K,D>::destroyRedBlackTree(redblack_node<K,D>* node){
	if(node != nil){
		if(node->left != NULL){
			destroyRedBlackTree(node->left);
		}
		if(node->right != NULL){
			destroyRedBlackTree(node->right);
		}
		delete node;
	}
};

template<typename K, typename D>
void redblack_tree<K,D>::balancetree(redblack_node<K,D>* node){
	redblack_node<K,D>* aux;
	bool direction = 0;

	while ( node->parent != nil && node->parent->color == 1) {
		//Check the direction of the grand parent
		direction = (node->parent->parent->left == node->parent);

		if(direction){
			aux = node->parent->parent->right;
		} else {
			aux = node->parent->parent->left;
		}

		// Case I Red Parent + Red Uncle
		if (aux->color == 1) {
			node->parent->parent->color = 1;
			node->parent->color = aux->color = 0;
			node = node->parent->parent;
		} else {
			// Case II Black Uncle Grand Parent in Zig-Zag
			if (node == (direction ? node->parent->right : node->parent->left)) {
				node = node->parent;
				rotate(node, !direction);
			}
			// Case III Black Uncle Grand Parent in straight line
			node->parent->parent->color = 1;
			node->parent->color = 0;
			rotate(node->parent->parent, direction);
		}
	}
	this->root->color = 0;
};

template<typename K, typename D>
void redblack_tree<K,D>::rotate(redblack_node<K,D>* node, bool direction){
	redblack_node<K,D>* aux;
	if(direction){
		aux = node->left;
	} else {
		aux = node->right;
	}

	(direction ? node->left : node->right) = (direction ? aux->right : aux->left);

	if ((direction ? aux->right : aux->left) != nil){
		(direction ? aux->right->parent : aux->left->parent) = node;
	}
	aux->parent = node->parent;

	if (node->parent == nil){
		this->root = aux;
	} else {
		if (node == (direction ? node->parent->right : node->parent->left))
			(direction ? node->parent->right : node->parent->left) = aux;
		else
			(direction ? node->parent->left : node->parent->right) = aux;
	}

	(direction ? aux->right : aux->left) = node;
	node->parent = aux;
};

template<typename K, typename D>
size_t redblack_tree<K,D>::getsize(redblack_node<K,D>* node){
	size_t sum = 0;
	if(node != nil){
		++sum;
		if(node->left != NULL){
			sum += getsize(node->left);
		}
		if(node->right != NULL){
			sum += getsize(node->right);
		}
	}
	return sum;
};

template<typename K, typename D>
D& redblack_tree<K,D>::private_at(const K& key){

	redblack_node<K,D>* current = this->root;

	while(current != nil && current->key != key){

		if(current->key > key){
			current = current->left;
		} else {
			current = current->right;
		}
	}

	if(current == nil){
		throw std::out_of_range ("Out of Range");
	}

	return current->data;
};

#endif	// RED_BLACK_TREE