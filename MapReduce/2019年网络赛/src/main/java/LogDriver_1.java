import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

import java.io.IOException;

public class LogDriver_1 {
	public static void main(String[] args) throws IOException, InterruptedException, ClassNotFoundException {
		BasicConfigurator.configure();
		args = new String[]{"C:\\Code\\MapReduce\\2019年网络赛\\src\\main\\java\\datas\\Log.log", "C:\\Code\\MapReduce\\2019年网络赛\\src\\main\\java\\result\\1"};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		job.setJarByClass(LogDriver_1.class);
		job.setMapperClass(LogMapper_1.class);
		job.setReducerClass(Reducer.class);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(NullWritable.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(NullWritable.class);
		FileInputFormat.setInputPaths(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		boolean b = job.waitForCompletion(true);
		System.exit(b ? 0 : 1);
	}
}
