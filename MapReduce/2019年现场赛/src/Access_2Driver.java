import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

import java.net.URI;

public class Access_2Driver {
	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{"C:\\Code\\MapReduce\\2019年现场赛\\src\\datas\\access.log", "C:\\Code\\MapReduce\\2019年现场赛\\src\\result\\2"};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		URI uri = new URI("file:///C://Code//MapReduce//2019年现场赛//src//datas//ip.data.txt");
		job.addCacheFile(uri);
		job.setJarByClass(Access_2Driver.class);
		job.setMapperClass(Access_2Mapper.class);
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
