import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class NumMapper extends Mapper<LongWritable, Text, Text, NullWritable> {
	Text k = new Text();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split(",");
		String tem = "";
		for (String s : split) {
			if (!s.startsWith("2")) {
				tem += s + ",";
			}
		}
		k.set(tem);
		context.write(k, NullWritable.get());
	}
}
