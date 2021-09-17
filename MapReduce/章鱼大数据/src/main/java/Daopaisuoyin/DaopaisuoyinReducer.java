package Daopaisuoyin;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class DaopaisuoyinReducer extends Reducer<Text, Text, Text, Text> {
	Text v = new Text();

	@Override
	protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, Text>.Context context) throws IOException, InterruptedException {
		HashMap count = new HashMap<String, Integer>();
		for (Text value : values) {
			if (count.get(value.toString()) == null) {
				count.put(value.toString(), 1);
			} else {
				count.put(value.toString(), (int) count.get(value.toString()) + 1);
			}
		}
		Set set = count.keySet();
		Iterator iter = set.iterator();
		String s = "";
		while (iter.hasNext()) {
			String it = iter.next().toString();
			s += it + ":" + count.get(it) + ";";
		}
		v.set(s);
		context.write(key, v);
	}
}
