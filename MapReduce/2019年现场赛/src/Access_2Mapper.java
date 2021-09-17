import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URI;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;

public class Access_2Mapper extends Mapper<LongWritable, Text, Text, NullWritable> {
	HashMap ip = new HashMap<String, String>();
	Text k = new Text();

	@Override
	protected void setup(Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
		// 1 获取缓存的文件
		URI[] cacheFiles = context.getCacheFiles();
		// 这里是对缓存文件进行读取,只缓存了一个文件所以读第0个文件
		String path = cacheFiles[0].getPath();
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(path), StandardCharsets.UTF_8));
		String s = "";
		while (((s = reader.readLine()) != null)) {
			String[] split = s.split("\t");
			ip.put(split[0], split[1] + "\t" + split[2]);
		}
	}

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
		String[] split = value.toString().split("\t");
		k.set(split[0] + "\t" + split[1] + "\t" + ip.get(split[1]));
		context.write(k, NullWritable.get());
	}
}
