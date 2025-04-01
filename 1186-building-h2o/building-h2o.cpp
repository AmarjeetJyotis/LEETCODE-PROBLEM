#include <barrier>

class H2O {
private:
    barrier<> syncMolecule{3};
    counting_semaphore<2> semH{2};
    counting_semaphore<1> semO{1};

public:
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        semH.acquire();
        syncMolecule.arrive_and_wait();
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        semH.release();
    }

    void oxygen(function<void()> releaseOxygen) {
        semO.acquire();
        syncMolecule.arrive_and_wait();
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        semO.release();
    }
};