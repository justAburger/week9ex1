#include "BSNode.h"
#define ERROR -1

BSNode::BSNode(std::string data)
{
	this->_data = data;
	this->_left = NULL;
	this->_right = NULL;
	this->_count = 1;
}

BSNode::BSNode(const BSNode& other)
{
	this->_data = other.getData();
	this->_left = NULL;
	this->_right = NULL;
	this->_count = 0;
}

BSNode::~BSNode()
{
}

void BSNode::insert(std::string value)
{
	BSNode* curr;
	if (value != this->getData())
	{
		if(value > this->getData())
		{
			if (this->_right == nullptr)
			{
				this->_right = new BSNode(value);
			}
			else
			{
				curr = this->_right;
				curr->insert(value);
			}
		}
		else
		{
			if (this->_left == nullptr)
			{
				this->_left = new BSNode(value);
			}
			else
			{
				curr = this->_left;
				curr->insert(value);
			}
		}
	}
	else
	{
		this->_count++;
	}
}

BSNode& BSNode::operator=(const BSNode& other)
{
	BSNode *s = new BSNode(other);
	return *s;
}

bool BSNode::isLeaf() const
{
	if (this->getLeft() == nullptr && this->getRight() == nullptr)
		return true;
	return false;
}

std::string BSNode::getData() const
{
	return this->_data;
}

BSNode* BSNode::getLeft() const
{
	return this->_left;
}

BSNode* BSNode::getRight() const
{
	return this->_right;
}

bool BSNode::search(std::string val) const
{
	if (this->getData() == val)
	{
		return true;
	}
	if (this->isLeaf() && this->getData() != val)
	{
		return false;
	}
	return this->getLeft()->search(val) || this->getRight()->search(val);
}

int BSNode::getHeight() const
{
	int leftHeight = 0, rightheight = 0;
	if (this->_left != nullptr)
	{
		leftHeight = this->getLeft()->getHeight();
	}
	else if (this->_right != nullptr)
	{
		rightheight = this->getRight()->getHeight();
	}
	if (leftHeight > rightheight)
		return 1 + leftHeight;
	return rightheight + 1;
}

int BSNode::getDepth(const BSNode& root) const
{
	return 0;
}

void BSNode::printNodes() const
{

}