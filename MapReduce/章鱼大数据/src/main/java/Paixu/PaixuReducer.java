package Paixu;

import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class PaixuReducer extends Reducer<Goods, NullWritable, Goods, NullWritable> {
    @Override
    protected void reduce(Goods key, Iterable<NullWritable> values, Reducer<Goods, NullWritable, Goods, NullWritable>.Context context) throws IOException, InterruptedException {
        context.write(key, NullWritable.get());
    }
}
