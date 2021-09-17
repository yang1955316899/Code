import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class AccessMapper extends Mapper<LongWritable, Text, Text, NullWritable> {
	//	appid ip mid userid login_type request status http_referer user_agent time
	Text k = new Text();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split("\t");
		if (!"null".equals(split[2])) {
			k.set(split[0] + "\t"
					+ split[1] + "\t"
					+ split[2] + "\t"
					+ split[3] + "\t"
					+ ("1".equals(split[4]) ? "本系统登陆" : "第三方集成") + "\t"
					+ split[5] + "\t"
					+ split[6] + "\t"
					+ split[7] + "\t"
					+ split[8] + "\t"
					+ split[9]);
			context.write(k, NullWritable.get());
		}
	}
}