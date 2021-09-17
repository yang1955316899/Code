package WordcountMapper;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WordCountMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
	// 这里可以直接进行赋值,也可以通过对象.set()对值进行赋值
	IntWritable v = new IntWritable(1);
	Text k = new Text();
	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, IntWritable>.Context context)
			throws IOException, InterruptedException {
		// 获取一行数据,通过toString方法来对Text进行转换,通过split进行分词
		String[] words = value.toString().split(" ");
		// 循环遍历每一单词
		for (String word : words) {
			// 返回的值是Text,通过下面这种方式对格式进行转化
			k.set(word);
			v.set(1);
			// 写出数据
			context.write(k, v);
		}
	}
}
