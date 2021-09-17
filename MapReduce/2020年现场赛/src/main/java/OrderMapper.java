import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;

import java.io.IOException;

public class OrderMapper extends Mapper<LongWritable, Text, Text, Text> {
	Text k = new Text();
	Text v = new Text();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context) throws IOException, InterruptedException {
		String name = ((FileSplit) context.getInputSplit()).getPath().getName();
		if (name.contains("Order")) {
			String[] split = value.toString().split(",");
			String[] split1 = split[1].split("/");
			for (int i = 0; i < 3; i++) {
				if (split1[i].length() == 1) {
					split1[i] = "0" + split1[i];
				}
			}
			split[1] = split1[0] + "," + split1[1] + "," + split1[2];
			String s = "";
			for (String s1 : split) {
				s += s1 + ",";
			}
			k.set(split[0]);
			v.set("1+" + s);
			context.write(k, v);
		} else if (name.contains("return")) {
			String[] split = value.toString().split(",");
			k.set(split[0]);
			v.set("2+" + split[1]);
			context.write(k, v);
		}
	}
}
