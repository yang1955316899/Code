import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class Order_2Reducer extends Reducer<Text, Text, Order_2, NullWritable> {

	@Override
	protected void reduce(Text key, Iterable<Text> values, Reducer<Text, Text, Order_2, NullWritable>.Context context) throws IOException, InterruptedException {
		double sumSalesVolume = 0;
		double sumProfit = 0;
		for (Text value : values) {
			String[] s = value.toString().split("\t");
			double salesVolume = Double.parseDouble(s[0]);
			sumSalesVolume += salesVolume;
			double profit = Double.parseDouble(s[1]);
			sumProfit += profit;
		}
		context.write(new Order_2(key.toString(), sumSalesVolume, sumProfit), NullWritable.get());
	}
}