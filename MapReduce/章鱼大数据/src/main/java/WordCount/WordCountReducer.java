package WordCount;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class WordCountReducer extends Reducer<Text, Text, Text, LongWritable> {
    LongWritable l = new LongWritable();

    @Override
    protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, LongWritable>.Context context) throws IOException, InterruptedException {
        int count = 0;
        for (Text value : values) {
            count++;
        }
        l.set(count);
        context.write(key, l);
    }
}
