/**
 * ����������
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
	 * �������м����Ԫ��
	 * @param  index 	����Ԫ��λ��
	 * @param  element 	�����Ԫ��
	 */
	public void insert(int index, int element) throws Exception {
		//�������鷶Χ�׳��쳣
		//��index > size �����Ԫ�ؾͲ���˳�������������
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException("��������ʵ��Ԫ�ط�Χ��");
		}
		//�Ӻ���ǰֱ��inedexλ������������һλ
		for(int i = size - 1; i >= index; i--) {
			array[i+1] = array[i];
		}
		//����
		array[index] = element;
		size++;
	}
	
	/**
	 *����Χ����
	 */
	public void insertOutBounds(int index, int element) throws Exception {
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException("��������ʵ��Ԫ�ط�Χ��");
		}
		//���������������������
		if(size >= array.length) {
			resize();
		}
		//����
		for(int i = size - 1; i >= index; i--) {
			array[i+1] = array[i];
		}
		//����
		array[index] = element;
		size++;
	}
	
	/**
	 * ��������
	 */
	public void resize() {
		int[] arrayNew = new int[2 * array.length];
		System.arraycopy(array, 0, arrayNew, 0, array.length);
		array = arrayNew;
	}
	
	/**
	 * ����ɾ��Ԫ��
	 * @param  index	ɾ��Ԫ��λ��
	 */
	public int delete(int index) throws Exception {
		if(index < 0 || index > size) {
			throw new IndexOutOfBoundsException("��������ʵ��Ԫ�ط�Χ��");
		}
		int deleteElement = array[index];
		for(int i = index; i < size - 1; i++) {
			array[i] = array[i+1];
		}
		//size-- ����Ҫ��ʱ�̱������ִ�����Ԫ�ظ����ȳ�  
		size--;
		return deleteElement;
	}
	
	/**
	 * �������
	 */
	public void output() {
		for(int i = 0; i < size; i++) {
			System.out.println(array[i]);
		}
	}
	
}