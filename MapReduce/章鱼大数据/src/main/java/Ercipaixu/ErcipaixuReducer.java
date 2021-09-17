package Ercipaixu;

import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class ErcipaixuReducer extends Reducer<Goods, NullWritable, Object, NullWritable> {
	@Override
	protected void reduce(Goods key, Iterable<NullWritable> values, Reducer<Goods, NullWritable, Object, NullWritable>.Context context) throws IOException, InterruptedException {
		context.write("------------------------------------------------", NullWritable.get());
		for (NullWritable value : values) {
			context.write(key, value);
		}
	}
}
