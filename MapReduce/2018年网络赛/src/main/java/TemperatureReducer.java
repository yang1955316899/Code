import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class TemperatureReducer extends Reducer<Text, Text, Text, Text> {
	Text v = new Text();

	@Override
	protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, Text>.Context context) throws IOException, InterruptedException {
		int MaxTemperature = -300;
		for (Text value : values) {
			int s = Integer.parseInt(value.toString());
			MaxTemperature = Math.max(MaxTemperature, s);
		}
		v.set(MaxTemperature + "");
		context.write(key, v);
	}
}
