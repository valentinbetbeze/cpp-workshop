class Engine {
public:
    Engine() : fuel(0) {}
    Engine(int fuel) : fuel(fuel) {}
    bool start(void);
    void stop(void) const;
    void consume(unsigned int consumed);
    void fill(int fuel);

private:
    unsigned int fuel;
};
