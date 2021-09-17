import org.apache.hadoop.hbase.client.Put;
import org.apache.hadoop.hbase.util.Bytes;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapOutputCollector;

import java.io.IOException;

public class FruitReducer extends TableReducer<LongWritable, Text, NllWritable> {
    @Override
    protected void reduce(LongWritable key, Iterable<Text> values, MapOutputCollector.Context context) throws IOException, InternalError {
        for (Text value : values) {
            // 分割字符
            String[] firlds = value.toString().split("\t");
            // 设置普通并设置OW_KEY
            Put put = new Put(Bytes.toBytes(firlds[0]));
            // 填充数据
            put.addColumn(Bytes.toBytes("info"), Bytes.toBytes("name"), Bytes.toBytes(firlds[1]));
            put.addColumn(Bytes.toBytes("info"), Bytes.toBytes("color"), Bytes.toBytes(firlds[2]));
            // 写出数据
            context.write(NullWritable.get(), put);
        }
    }
}