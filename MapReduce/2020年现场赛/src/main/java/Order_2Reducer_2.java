import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class Order_2Reducer_2 extends Reducer<Order_2, NullWritable, Order_2, NullWritable> {
	@Override
	protected void reduce(Order_2 key, Iterable<NullWritable> values, Reducer<Order_2, NullWritable, Order_2, NullWritable>.Context context) throws IOException, InterruptedException {
		context.write(key, NullWritable.get());
	}
}
