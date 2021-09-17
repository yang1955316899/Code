import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class Order_3Reducer extends Reducer<Order_3, NullWritable, Order_3, NullWritable> {
	@Override
	protected void reduce(Order_3 key, Iterable<NullWritable> values, Reducer<Order_3, NullWritable, Order_3, NullWritable>.Context context) throws IOException, InterruptedException {
		int tem = 3;
		for (NullWritable value : values) {
			context.write(key, value);
			if (--tem == 0) {
				break;
			}
		}
	}
}
