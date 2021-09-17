package Ercipaixu;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class ErcipaixuMapper extends Mapper<LongWritable, Text, Goods, NullWritable> {
	Goods goods = new Goods();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Goods, NullWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split("\t");
		goods.set(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
		context.write(goods, NullWritable.get());
	}
}
