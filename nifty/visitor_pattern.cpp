#include <iostream>
#include <memory>
#include <vector>

// We forward declare our Elements
class ConcreteElementA;
class ConcreteElementB;

/*
 * The Visitor Interface declares a set of visiting methods that correspond to
 * component classes. The signature of a visiting method allows the visitor to
 * identify the exact class of the component that it's dealing with.
 * This is an abstract base class that demonstrates downstream polymorphism.
 */

class Visitor {
  public:
    virtual void visitConcreteElementA(ConcreteElementA &element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB &element) = 0;
};

/*
 * The Element interface declares an `accept` method that should take the base
 * visitor interface as an argument.
 * This is an abstract base class that demonstrates downstream polymorphism.
 */

class Element {
  public:
    virtual void accept(Visitor &visitor) = 0;
};

/*
 * Each Concrete Component must implement the `Accept` method in such a way that
 * it calls the visitor's method corresponding to the component's class.
 * The Concrete Components must also inherit Element Publicly
 */

class ConcreteElementA : public Element {
  public:
    void accept(Visitor &visitor) override {
        /*
         * Note that we're calling `visitConcreteElementA`, which matches the
         * current class name. This way we let the visitor know the class of the
         * component it works with.
         */
        visitor.visitConcreteElementA(*this);
    }
    // Each ConcreteElement can have their own exclusive methods
    std::string ExclusiveMethodOfConcreteElementA() const {
        return "A";
    }
};

class ConcreteElementB : public Element {
  public:
    void accept(Visitor &visitor) override {
        visitor.visitConcreteElementB(*this);
    }
    std::string ExclusiveMethodOfConcreteElementB() const {
        return "B";
    }
};

/*
 * Concrete Visitors implement several versions of the same algorithm, which can
 * work with all concrete component classes.
 *
 * You can experience the biggest benefit of the Visitor pattern when using it
 * with a complex object structure, such as a Composite tree. In this case, it
 * might be helpful to store some intermediate state of the algorithm while
 * executing visitor's methods over various objects of the structure.
 */

class ConcreteVisitor1 : public Visitor {
  public:
    void visitConcreteElementA(ConcreteElementA &element) override {
        std::cout << element.ExclusiveMethodOfConcreteElementA() << " ConcreteVisitor1."
                  << std::endl;
    }
    void visitConcreteElementB(ConcreteElementB &element) override {
        std::cout << element.ExclusiveMethodOfConcreteElementB() << " ConcreteVisitor1."
                  << std::endl;
    }
};

class ConcreteVisitor2 : public Visitor {
  public:
    void visitConcreteElementA(ConcreteElementA &element) override {
        std::cout << element.ExclusiveMethodOfConcreteElementA() << " ConcreteVisitor2."
                  << std::endl;
    }
    void visitConcreteElementB(ConcreteElementB &element) override {
        std::cout << element.ExclusiveMethodOfConcreteElementB() << " ConcreteVisitor2."
                  << std::endl;
    }
};

int main() {
    ConcreteElementA a;
    ConcreteElementB b;

    // It is important to note that most data containers can not store
    // references, pointers are more common

    // We need to initalize an array of Element pointers
    Element *array_items[] = {&a, &b};
    // We can do the same with a vector of pointers
    std::vector<Element *> vect_items{&a, &b};
    ConcreteVisitor1       v1;
    ConcreteVisitor2       v2;

    // Will pick the correct visit method at runtime
    for (Element *e : array_items)
        e->accept(v1);

    for (Element *e : array_items)
        e->accept(v2);

    for (Element *e : vect_items)
        e->accept(v1);

    for (Element *e : vect_items)
        e->accept(v2);
    return 0;
}