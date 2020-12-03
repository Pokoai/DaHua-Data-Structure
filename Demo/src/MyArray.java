/**
 * 创建数组类
 * @author Guyuehu
 *
 */
public class MyArray {
	private int[] array;
	private int size;
	
	public MyArray(int capacity) {
		this.array = new int[capacity];
		this.size = 0;
	}
	
	/**
	 * 从数组中间插入元素
	 * @param  index 	插入元素位置
	 * @param  element 	插入的元素
	 */
	public void insert(int index, int element) throws Exception {
		//超出数组范围抛出异常
		//若index > size 插入的元素就不是顺序放在数组中了
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException("超出数组实际元素范围！");
		}
		//从后往前直到inedex位置依次往后移一位
		for(int i = size - 1; i >= index; i--) {
			array[i+1] = array[i];
		}
		//插入
		array[index] = element;
		size++;
	}
	
	/**
	 *超范围插入
	 */
	public void insertOutBounds(int index, int element) throws Exception {
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException("超出数组实际元素范围！");
		}
		//数组已满，则对数组扩容
		if(size >= array.length) {
			resize();
		}
		//插入
		for(int i = size - 1; i >= index; i--) {
			array[i+1] = array[i];
		}
		//插入
		array[index] = element;
		size++;
	}
	
	/**
	 * 数组扩容
	 */
	public void resize() {
		int[] arrayNew = new int[2 * array.length];
		System.arraycopy(array, 0, arrayNew, 0, array.length);
		array = arrayNew;
	}
	
	/**
	 * 数组删除元素
	 * @param  index	删除元素位置
	 */
	public int delete(int index) throws Exception {
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException("超出数组实际元素范围！");
		}
		int deleteElement = array[index];
		for(int i = index; i < size - 1; i++) {
			array[i] = array[i+1];
		}
		//size-- 很重要，时刻保持与现存数组元素个数等长  
		size--;
		return deleteElement;
	}
	
	/**
	 * 输出数组
	 */
	public void output() {
		for(int i = 0; i < size; i++) {
			System.out.println(array[i]);
		}
	}
	
}