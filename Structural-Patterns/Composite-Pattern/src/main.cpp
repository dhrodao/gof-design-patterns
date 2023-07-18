// The Composite Pattern

#include "../include/common.h"

// This Pattern is mainly used for object structures that could be
// represented in a tree form

//           Client
//             | uses
//             v
//          Component -----------
//          /   |   \           | 
//        Leaf ... Composite <>-- (has many components)

/*
 * Component
 * Defines the interface which the concrete components
 * must implement (leaf nodes and composite)
 */
struct Component
{
    virtual Component* getChild(const int index)
    {
        return nullptr;
    }

    virtual void addChild(Component* child) { /* ... */ }
    virtual void deleteChild(const int index) { /* ... */ }
    
    virtual void operation() = 0;
};

/*
 * 
 */
struct Leaf : public Component
{
    Leaf(const int auxId): id(auxId) {}

    void operation()
    {
        cout << "Leaf id: " << id << " operation" << endl;
    }
private:
    const int id;
};

struct Composite : public Component
{
    Composite(const int auxId): id(auxId) {}

    Component* getChild(const int index) override
    {
        if((size_t)index >= children.size() || index < 0)
            return nullptr;

        return children.at(index);
    }

    void addChild(Component* child) override
    {
        children.push_back(child);
    }

    void deleteChild(const int index)
    {
        if((size_t)index >= children.size() || index < 0)
            return;

        children.erase(children.begin() + index);
    }

    void operation()
    {
        cout << "Composite id: " << id << " operation" << endl;
        for(auto&& child : children)
        {
            child->operation();
        }
    }
private:
    const int id;
    std::vector<Component*> children;
};

int main()
{
    Leaf l0(0);
    Leaf l1(1);
    Leaf l2(2);
    Leaf l3(3);
    Leaf l4(4);

    Composite root(0);
    Composite c1(1);
    Composite c2(2);
    
    root.addChild(&l0);
    root.addChild(&c1);
    
    c1.addChild(&l1);
    c1.addChild(&l2);
    c1.addChild(&c2);

    c2.addChild(&l3);
    c2.addChild(&l4);

    root.operation();

    root.deleteChild(1); // delete c2

    cout << endl;

    root.operation();

    return 0;
}