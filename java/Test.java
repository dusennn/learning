import java.util.*;


public class Test{
	public static void main(String[] args){
		HashSet<Character> set1 = new HashSet<>();
		set1.add('a');
		set1.add('c');
		HashSet<Character> set2 = new HashSet<>();
		set2.add('a');
		set2.add('b');

		System.out.println(set1);
		System.out.println(set2);
		HashSet<Character> resSet = new HashSet<>();
		resSet.addAll(set1);
		resSet.retainAll(set2);
		System.out.println(resSet.size());
		System.out.println(resSet);
		System.out.println(set1);
		System.out.println(set2);
	}
}
