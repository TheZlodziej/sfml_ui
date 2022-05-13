#pragma once

#include <vector>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace sf::UI
{
	///<summary>
	///A base class for every UI component. Implements a parent-children tree.
	///</summary>
	class Node
	{
	protected:
		Node* m_parent;
		std::vector<Node*> m_children;

	public: Node(Node* = nullptr);
	public: virtual ~Node();

	///<summary>
	///Gets node's parent dynamicly casted to type T or nullptr if the cast is impossible or node has no parent.
	///</summary>
	public: template<typename T = Node> T* getParent() const;

	///<summary>
	///Returns child of given index dynamicly casted to type T or nullptr if the cast is impossible or node with given index doesnt exist.
	///</summary>
	///<param name="index">of child in children vector</param>
	public: template<typename T = Node> T* getChild(size_t) const;

	///<summary>
	///Specifies what happens on node update. Gets called by update. Doesn't affect (update) any of the children by default.
	///</summary>
	///<param name="render window">reference for calculating relative (to given window) positions</param>
	///<param name="delta time"></param>
	protected: virtual void internalUpdate(const sf::RenderWindow&, const sf::Time&);

	///<summary>
	///Calls internalUpdate on itself and update on every child node.
	///</summary>
	///<param name="render window">reference for calculating relative (to given window) positions</param>
	///<param name="delta time"/>
	public: void update(const sf::RenderWindow&, const sf::Time&);

	///<summary>
	///Returns number of element in children vector.
	///</summary>
	public: size_t getChildrenCount() const;

	///<summary>
	///Creates a new child of given type and specified constructor parameters, adds it to children vector and returns newly created node.
	///</summary>
	///<param name="T constructor arguments"/>
	public: template<typename T, typename... Args> T* addChild(Args&&... args);
	};

	template<typename T>
	T* Node::getParent() const
	{
		if (auto* derived = dynamic_cast<T*>(m_parent))
		{
			return derived;
		}

		return nullptr;
	}

	template<typename T>
	T* Node::getChild(size_t index) const
	{
		if (auto* derived = dynamic_cast<T*>(m_children.at(index)))
		{
			return derived;
		}

		return nullptr;
	}

	template<typename T, typename ...Args>
	T* Node::addChild(Args && ...args)
	{
		auto newChild = new T(std::forward<Args>(args)...);
		newChild->m_parent = this;
		m_children.emplace_back(newChild);
		return newChild;
	}
}