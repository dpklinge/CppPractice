#pragma once
template<typename T>
class TreeNode {
	T value;
	std::vector<TreeNode<T>> subNodes;
public:
	TreeNode(T value) :value(value) {}
	T getValue()  const{
		return value;
	}
	void addSubNode(T value) {
		std::cout << "Adding subnode " << value << " to " << this->value << "\n";
		subNodes.push_back(TreeNode(value));
	}
		
	std::vector<TreeNode<T>>& getSubNodes() {
		return subNodes;
	}
};