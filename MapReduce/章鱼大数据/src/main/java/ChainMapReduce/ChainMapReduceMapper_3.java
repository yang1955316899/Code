package ChainMapReduce;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class ChainMapReduceMapper_3 extends Mapper<Text, DoubleWritable, Text, DoubleWritable> {
	@Override
	protected void map(Text key, DoubleWritable value, Mapper<Text, DoubleWritable, Text, DoubleWritable>.Context context) throws IOException, InterruptedException {
		if (key.toString().length() <= 2) {
			context.write(key, value);
		}
	}
}
