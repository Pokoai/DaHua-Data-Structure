/**
 * 数组 - 基本操作
 * @author Guyuehu
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		MyArray arrayTest = new MyArray(4);
		arrayTest.insert(0, 6);
		arrayTest.insert(1, 10);
		arrayTest.insert(2, 0);
		arrayTest.insert(3, 7);
		//arrayTest.insert(1, 100);
		arrayTest.insertOutBounds(1, 100);
		arrayTest.delete(2);
		arrayTest.delete(3);
		arrayTest.output();
	}
}



