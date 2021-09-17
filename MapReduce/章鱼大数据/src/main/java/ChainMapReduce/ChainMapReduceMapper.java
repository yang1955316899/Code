package ChainMapReduce;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class ChainMapReduceMapper extends Mapper<LongWritable, Text, Text, DoubleWritable> {
	Text k = new Text();
	DoubleWritable v = new DoubleWritable();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, DoubleWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split("\t");
		k.set(split[0]);
		double tem = Double.parseDouble(split[1]);
		if (tem <= 600) {
			v.set(tem);
			context.write(k, v);
		}
	}
}
