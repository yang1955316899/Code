package Ercipaixu;

import org.apache.hadoop.io.WritableComparable;
import org.apache.hadoop.io.WritableComparator;

public class ErcipaixuGroupingComparator extends WritableComparator {
	protected ErcipaixuGroupingComparator() {
		super(Goods.class, true);
	}

	@Override
	public int compare(WritableComparable a, WritableComparable b) {
		Goods aBean = (Goods) a;
		Goods bBean = (Goods) b;
		int result;
		if (aBean.getClick_num() > ((Goods) b).getClick_num()) {
			result = -1;
		} else if (aBean.getClick_num() == bBean.getClick_num()) {
			result = 0;
		} else {
			result = 1;
		}
		return result;
	}
}
