package Paixu;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class PaixuMapper extends Mapper<LongWritable, Text,Goods, NullWritable> {
    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Goods, NullWritable>.Context context) throws IOException, InterruptedException {
        String[] split = value.toString().split("\t");
        Goods goods = new Goods(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
        context.write(goods,NullWritable.get());
    }
}
