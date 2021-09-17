package Daopaisuoyin;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;

import java.io.IOException;

public class DaopaisuoyinMapper extends Mapper<LongWritable, Text, Text, Text> {
	Text k = new Text();
	Text v = new Text();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context) throws IOException, InterruptedException {
		String filePath = ((FileSplit) context.getInputSplit()).getPath().toString();
		if (filePath.contains("goods")) {
			String[] val = value.toString().split("\t");
			int splitIndex = filePath.indexOf("goods");
			k.set(val[0]);
			v.set(filePath.substring(splitIndex));
		} else if (filePath.contains("order")) {
			String[] val = value.toString().split("\t");
			int splitIndex = filePath.indexOf("order");
			k.set(val[2]);
			v.set(filePath.substring(splitIndex));
		}
		context.write(k, v);
	}
}
