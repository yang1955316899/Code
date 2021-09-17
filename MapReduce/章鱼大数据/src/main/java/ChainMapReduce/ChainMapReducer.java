package ChainMapReduce;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class ChainMapReducer extends Reducer<Text, DoubleWritable, Text, DoubleWritable> {
	DoubleWritable v = new DoubleWritable();

	@Override
	protected void reduce(Text key, Iterable<DoubleWritable> values, Reducer<Text, DoubleWritable, Text, DoubleWritable>.Context context) throws IOException, InterruptedException {
		int count = 0;
		for (DoubleWritable value : values) {
			count += value.get();
		}
		v.set(count);
		context.write(key, v);
	}
}
