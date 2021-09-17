import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class YiqingMapper_1 extends Mapper<LongWritable, Text, Text, NullWritable> {


    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
        String string = "";
        String s = value.toString();
        String[] split = s.split(",");
        split[0] = "2020年" + split[0];
        for (int i = 0; i < split.length; i++) {
            string += split[i] + ",";
        }
        Text k = new Text();
        k.set(string);
        context.write(k, NullWritable.get());
    }
}
