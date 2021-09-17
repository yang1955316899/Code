package ChainMapReduce;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.chain.ChainMapper;
import org.apache.hadoop.mapreduce.lib.chain.ChainReducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.log4j.BasicConfigurator;

public class ChainMapReduceDriver {
	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{
				"C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\ChainMapReduce\\datas\\goods_0.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\ChainMapReduce\\result"
		};
		Configuration conf = new Configuration();
		Job job = new Job(conf, ChainMapReduceDriver.class.getSimpleName());
		job.setInputFormatClass(TextInputFormat.class);
		ChainMapper.addMapper(job, ChainMapReduceMapper.class, LongWritable.class, Text.class, Text.class, DoubleWritable.class, conf);
		ChainMapper.addMapper(job, ChainMapReduceMapper_2.class, Text.class, DoubleWritable.class, Text.class, DoubleWritable.class, conf);
		ChainReducer.setReducer(job, ChainMapReducer.class, Text.class, DoubleWritable.class, Text.class, DoubleWritable.class, conf);
		ChainReducer.addMapper(job, ChainMapReduceMapper_3.class, Text.class, DoubleWritable.class, Text.class, DoubleWritable.class, conf);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(DoubleWritable.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(DoubleWritable.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		job.setOutputFormatClass(TextOutputFormat.class);
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}
