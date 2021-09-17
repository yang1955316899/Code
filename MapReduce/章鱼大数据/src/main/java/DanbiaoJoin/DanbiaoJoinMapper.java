package DanbiaoJoin;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class DanbiaoJoinMapper extends Mapper<LongWritable, Text, Text, Text> {
    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context) throws IOException, InterruptedException {
        String line = value.toString();
        String[] arr = line.split("\t");   //按行截取
        String mapkey = arr[0];
        String mapvalue = arr[1];
        String relationtype = "";  //左右表标识
        relationtype = "1";  //输出左表
        context.write(new Text(mapkey), new Text(relationtype + "+" + mapvalue));
        relationtype = "2";  //输出右表
        context.write(new Text(mapvalue), new Text(relationtype + "+" + mapkey));
    }
}
