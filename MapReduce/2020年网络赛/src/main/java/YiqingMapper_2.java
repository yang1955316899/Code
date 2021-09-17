import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class YiqingMapper_2 extends Mapper<LongWritable, Text, Text, NullWritable> {

    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
        String s = value.toString();
        String[] split = s.split(",");
        if (split[1].equals("湖北")) {
            String tem = "";
            for (int i = 0; i < 5; i++) {
                tem += split[i] + ",";
            }
            Text k = new Text();
            k.set(tem);
            context.write(k, NullWritable.get());
        }
    }
}
