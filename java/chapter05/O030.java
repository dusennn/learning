import java.util.*;

/**
 * 030: 插入、删除和随机访问都是O(1)的容器
 */

class RandomizedSet {
	private List<Integer> data;
	private Map<Integer, Integer> map;

	public RandomizedSet() {
		this.data = new ArrayList<>();
		this.map = new HashMap<>();
	}

	public boolean insert(int val) {
		if (this.map.containsKey(val)) return false;

		this.map.put(val, this.data.size());
		this.data.add(val);
		return true;
	}

	public boolean remove(int val) {
		if (!this.map.containsKey(val)) return false;

		var index = this.map.get(val);
		var lastElement = this.data.get(this.data.size()-1);
		this.data.set(index, lastElement);
		this.map.put(lastElement, index);

		this.data.remove(this.data.size()-1);
		this.map.remove(val);
		return true;
	}

	public int getRandom() {
		Random r = new Random();
		var index = r.nextInt(this.data.size());
		return this.data.get(index);
	}

}
