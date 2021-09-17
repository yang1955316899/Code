package DanbiaoJoin;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.Vector;

public class DanbiaoJoinReducer extends Reducer<Text, Text, Text, Text> {
	Text k = new Text();
	Text v = new Text();

	@Override
	protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, Text>.Context context) throws IOException, InterruptedException {
		Vector vector_1 = new Vector();
		Vector vector_2 = new Vector();
		for (Text value : values) {
			if (value.toString().toCharArray()[0] == '1') {
				vector_1.add(value.toString().substring(2));
			} else {
				vector_2.add(value.toString().substring(2));
			}
		}
		int v_1 = vector_1.size();
		int v_2 = vector_2.size();
		for (int i = 0; i < v_1; i++) {
			for (int i1 = 0; i1 < v_2; i1++) {
				if (!vector_1.get(i).equals(vector_2.get(i1))) {
					k.set(vector_1.get(i) + "");
					v.set(vector_2.get(i1) + "");
					context.write(k, v);
				}
			}
		}
	}
}
