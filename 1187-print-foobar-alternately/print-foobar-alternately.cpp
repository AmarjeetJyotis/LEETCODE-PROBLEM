class FooBar {
private:
    int n;
    binary_semaphore smph1{1};
    binary_semaphore smph2{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            smph1.acquire();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            smph2.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            smph2.acquire();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            smph1.release();
        }
    }
};