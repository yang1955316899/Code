import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class Order_2Mapper extends Mapper<LongWritable, Text, Text, Text> {
	Text k = new Text();
	Text v = new Text();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context) throws IOException, InterruptedException {
//		返回格式（省，销售额，利润）
//		订单ID	订单日期 年 月 日	省/自治区 产品ID 类别 销售额	数量	折扣	利润
//		CN-2018-4162714,2018/10/13,广东,办公用-标签-10000026,办公用品,96.32,2,0,22.96
		String[] split = value.toString().split(",");
		k.set(split[2]);
		v.set(split[5] + "\t" + split[8]);
		context.write(k, v);
	}
}
