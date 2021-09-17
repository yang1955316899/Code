import org.apache.hadoop.io.WritableComparable;
import org.apache.hadoop.io.WritableComparator;

public class Order_3GC extends WritableComparator {
	protected Order_3GC(){
		super(Order_3.class,true);
	}
	@Override
	public int compare(WritableComparable a, WritableComparable b) {
		Order_3 aBean = (Order_3) a;
		Order_3 bBean = (Order_3) b;
		int result = 1;
		if (aBean.getType().equals(bBean.getType())) {
			result = 0;
		}
		return result;
	}
}
