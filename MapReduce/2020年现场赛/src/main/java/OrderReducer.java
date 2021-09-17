import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.Vector;

public class OrderReducer extends Reducer<Text, Text, Text, NullWritable> {
	@Override
	protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
		Vector left = new Vector();
		Vector right = new Vector();
		for (Text value : values) {
			String s = value.toString();
			if (s.startsWith("1+")) {
				left.add(s.substring(2));
			} else {
				right.add(s.substring(2));
			}
		}
		int Lsize = left.size();
		int Rsize = right.size();
		for (int i = 0; i < Lsize; i++) {
			if (Rsize == 0) {
				context.write(new Text(left.get(i) + "否"), NullWritable.get());

			} else {
				context.write(new Text(left.get(i) + "是"), NullWritable.get());

			}
		}
	}
}
