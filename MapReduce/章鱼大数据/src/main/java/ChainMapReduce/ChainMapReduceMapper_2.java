package ChainMapReduce;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class ChainMapReduceMapper_2 extends Mapper<Text, DoubleWritable, Text, DoubleWritable> {
	@Override
	protected void map(Text key, DoubleWritable value, Mapper<Text, DoubleWritable, Text, DoubleWritable>.Context context) throws IOException, InterruptedException {
		double tem = value.get();
		if (!(tem >= 100 && tem <= 600)) {
			context.write(key, value);
		}
	}
}
