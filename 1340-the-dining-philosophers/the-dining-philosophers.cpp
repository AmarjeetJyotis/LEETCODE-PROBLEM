class DiningPhilosophers {
public:

    condition_variable cv[5] ;
    mutex mtx ;
    bool isFork[5] ;

    DiningPhilosophers() {

        for(int i=0;i<5;i++)
        {
            isFork[i]=true ;
        }

    }

    void wantsToEat(int i,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        unique_lock<mutex> lc1(mtx);

       

        if(isFork[i]==false)
        {
            cv[i].wait(lc1);
        }

        if(isFork[(i+1)%5]==false)
            cv[(i + 1) % 5].wait(lc1);

        pickLeftFork();
        pickRightFork();
        isFork[i]=false ;
        isFork[(i+1)%5]=false ;

        eat();

        isFork[i]=true ;
        isFork[(i+1)%5]=true ;
        
        putLeftFork();
        putRightFork();

        lc1.unlock();

        cv[i].notify_all();
        cv[(i + 1) % 5].notify_all();
    }
};