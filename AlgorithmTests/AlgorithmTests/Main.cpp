
#include "LinkedListNode.h"
#include <string>
#include <iostream>
#include <vector>
#include "User.h"
#include "TreeNode.h"

std::vector<User> getUsers() {
	std::vector<User> users;
	users.push_back(User("username1", "password1"));
	users.push_back(User("username2", "password2"));
	users.push_back(User("username3", "password3"));
	return users;
}
template <typename T>
int getMaxDepth(TreeNode<T> node, int currentDepth) {
	int newDepth =++currentDepth;
	std::cout << "Depth at value " << node.getValue() << " : " << currentDepth << "\n";
	for (TreeNode<T> subNode : node.getSubNodes()) {
		std::cout << "Examining subnode " << subNode.getValue() << "\n";
		int depth = getMaxDepth(subNode, currentDepth);
		if (depth > newDepth) {
			newDepth = depth;
		}
	}
	return newDepth;
}
int main() {

	LinkedListNode<std::string>* list(new LinkedListNode<std::string>("First"));
	std::cout << "Created one" << std::endl;
	list->insertAfter("Third");
	std::cout << "Created third" << std::endl;
	list->getNext()->insertBefore("Second");
	std::cout << "Created second" << std::endl;
	while (true) {
		std::cout << list->getValue() << std::endl;
		list = list->getNext();
		if (!list) {
			break;
		}
	}

	std::vector<User> users = getUsers();
	for (User user : users) {
		std::cout << "User: " << user <<std::endl;
	}

	TreeNode<int> root(1);
	root.addSubNode(2);
	root.addSubNode(3);
	root.getSubNodes()[0].addSubNode(4);
	root.getSubNodes()[0].addSubNode(5);
	root.getSubNodes()[1].addSubNode(6);
	root.getSubNodes()[1].getSubNodes()[0].addSubNode(7);
	for (TreeNode<int> nodes : root.getSubNodes()) {
		std::cout << "Node " << nodes.getValue() << "\n";
		for (TreeNode<int> subNodes : nodes.getSubNodes()) {
			std::cout  << " subnode " << subNodes.getValue() << "\n";
		}
	}
	std::cout << "Tree maxDepth: "<<getMaxDepth(root, 0) << "\n";




}