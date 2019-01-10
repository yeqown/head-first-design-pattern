/**
 * State
 */
abstract class State {
    public void insertQuarter() throws Exception {
        throw new Exception("insertQuarter");
    }

    public void ejectQuarter() throws Exception {
        throw new Exception("ejectQuarter");
    }

    public void turnCrank() throws Exception {
        throw new Exception("turnCrank");
    }

    public void dispense() throws Exception {
        throw new Exception("dispense");
    }
}

/**
 * NoQuarterState
 */
class NoQuarterState extends State {
    GumballMachine gumball;

    public NoQuarterState(GumballMachine gumball) {
        this.gumball = gumball;
    }

    @Override
    public void insertQuarter() {
        gumball.setState(this.gumball.getHasQuarterState());
    }
}

/**
 * HasQuarterState
 */

class HasQuarterState extends State {
    GumballMachine gumball;

    public HasQuarterState(GumballMachine gumball) {
        this.gumball = gumball;
    }

    @Override
    public void ejectQuarter() {
        System.out.println("quarter returned!");
        this.gumball.setState(this.gumball.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("sold ball");
        this.gumball.setState(this.gumball.getSoldState());
    }
}

/**
 * SoldState
 */

class SoldState extends State {
    GumballMachine gumball;

    public SoldState(GumballMachine gumball) {
        this.gumball = gumball;
    }

    @Override
    public void turnCrank() {
        System.out.println("only one ball will be release");
    }

    @Override
    public void dispense() {
        this.gumball.releaseBall();
        if (this.gumball.getCount() <= 0) {
            this.gumball.setState(this.gumball.getSoldOutState());
        } else {
            this.gumball.setState(this.gumball.getNoQuarterState());
        }
    }
}

/**
 * SoldOutState ...
 */
class SoldOutState extends State {
    GumballMachine gumball;

    public SoldOutState(GumballMachine gumball) {
        this.gumball = gumball;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Sold out! Do not insert anymore!");
    }
}

/**
 * GumballMachine means Context class
 */
class GumballMachine {
    private State noquarterState;
    private State soldOutState;
    private State hasQuarterState;
    private State soldState;
    private State state;
    private int ballCount = 100;

    public GumballMachine() {
        this.noquarterState = new NoQuarterState(this);
        this.soldOutState = new SoldOutState(this);
        this.hasQuarterState = new HasQuarterState(this);
        this.soldState = new SoldState(this);
        this.state = noquarterState;
    }

    public void insertQuarter() {
        try {
            this.state.insertQuarter();
        } catch (Exception e) {
        }
    }

    public void ejectQuarter() {
        try {
            this.state.ejectQuarter();
        } catch (Exception e) {
        }
    }

    public void turnCrank() {
        try {
            this.state.turnCrank();
            this.state.dispense();
        } catch (Exception e) {
        }
    }

    public void setState(State s) {
        this.state = s;
    }

    public State getNoQuarterState() {
        return this.noquarterState;
    }

    public State getSoldOutState() {
        return this.soldOutState;
    }

    public State getHasQuarterState() {
        return this.hasQuarterState;
    }

    public State getSoldState() {
        return this.soldState;
    }

    public void releaseBall() {
        System.out.println("a ball released, rest: " + this.ballCount);
        this.ballCount--;
    }

    public int getCount() {
        return this.ballCount;
    }
}

public class Testcase {
    public static void main(String[] args) {
        GumballMachine machine = new GumballMachine();

        System.out.println("machine working");
        
        int i = 10;
        while (i > 0) {
            machine.insertQuarter();
            machine.insertQuarter();
            machine.turnCrank();
            // wrong op, but should not bother the machine working
            machine.turnCrank();
            machine.ejectQuarter();
            machine.insertQuarter();
            machine.ejectQuarter();
            i--;
        }
    }
}