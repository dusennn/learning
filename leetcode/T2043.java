import java.util.*;

/**
 * 2043. 简易银行系统（线程安全）
 */
class T2043 {
    private long[] balance;

    public Bank(long[] balance) {
        this.balance = new long[balance.length+1];
        for (int i = 0; i < balance.length; i++) {
            this.balance[i+1] = balance[i];
        }
    }
    
    public boolean transfer(int account1, int account2, long money) {
    	synchronized(this.balance) {
    		// 账号不存在
	        if (!this.exists(account1) || !this.exists(account2)) return false;
	        
	        // 钱不够
	        if (this.balance[account1] < money) return false;

	        // 开始转账
	        this.balance[account1] -= money;
	        this.balance[account2] += money;
	        
	        return true;	
    	}
    }
    
    public boolean deposit(int account, long money) {
        synchronized(this.balance) {
        	// 账号不存在
	        if (!this.exists(account)) return false;
	        
	        // 开始存款
	        this.balance[account] += money;

	        return true;	
        }
    }
    
    public boolean withdraw(int account, long money) {
    	synchronized(this.balance) {
    		// 账号不存在
	        if (!this.exists(account)) return false;

	        // 钱不够
	        if (this.balance[account] < money) return false;

	        // 开始取款
	        this.balance[account] -= money;

	        return true;	
    	}
    }

    // 账号是否存在
    private boolean exists(int account) {
        if (account < 1 || account > this.balance.length) {
            return false;
        }
        return true;
    }
}
