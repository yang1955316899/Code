import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class Order_3Mapper extends Mapper<LongWritable, Text, Order_3, NullWritable> {
	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Order_3, NullWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split(",");
		//CN-2018-4162714,2018/10/13,广东,办公用-标签-10000026,办公用品,96.32,2,0,22.96
		//订单ID	订单日期 	省/自治区 产品ID 类别 销售额	数量	折扣	利润
		Order_3 order_3 = new Order_3(split[1], split[3], split[4], Double.parseDouble(split[5]), Double.parseDouble(split[split.length - 1]));
		context.write(order_3, NullWritable.get());
	}
}

