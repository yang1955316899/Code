import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class Order_2Mapper_2 extends Mapper<LongWritable, Text, Order_2, NullWritable> {
	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Order_2, NullWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split("\t");
		context.write(new Order_2(split[0], Double.parseDouble(split[1]), Double.parseDouble(split[2])), NullWritable.get());
	}
}
