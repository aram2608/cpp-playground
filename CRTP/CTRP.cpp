template <typename Derived> class Base {
    // Methods here can access members of the derived class using a static cast
  protected:
    Derived& underlying() {
        return static_cast<Derived&>(*this);
    }
    const Derived& underlying() const {
        return static_cast<const Derived&>(*this);
    }
};

class Derived : public Base<Derived> {
    // Derived class implementation
};
