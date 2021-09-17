package ReduceJoin;

import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.Vector;

public class ReduceJoinReducer extends Reducer<Text, Text, Text, NullWritable> {
    Text k = new Text();

    @Override
    protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
        String order = "";
        Vector orderMap = new Vector<String>();
        for (Text val : values) {
            String str = val.toString();
            if (str.startsWith("1+")) {
                order = str.substring(2);
            } else if (str.startsWith("2+")) {
                orderMap.add(str.substring(2));
            }
        }
        for (int i = 0; i < orderMap.size(); i++) {
            k.set(key + "\t" + order + "\t" + orderMap.get(i));
            context.write(k, NullWritable.get());
        }

    }
}