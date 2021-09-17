import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

public class Order_3Driver {
	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{"C:\\Code\\MapReduce\\2020年现场赛\\src\\main\\java\\datas\\Order.csv", "C:\\Code\\MapReduce\\2020年现场赛\\src\\main\\java\\result\\3"};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		job.setJarByClass(Order_3Driver.class);
		job.setMapperClass(Order_3Mapper.class);
		job.setReducerClass(Order_3Reducer.class);
		job.setMapOutputKeyClass(Order_3.class);
		job.setMapOutputValueClass(NullWritable.class);
		job.setOutputKeyClass(Order_3.class);
		job.setOutputValueClass(NullWritable.class);
		job.setGroupingComparatorClass(Order_3GC.class);
		FileInputFormat.setInputPaths(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		boolean b = job.waitForCompletion(true);
		System.exit(b ? 0 : 1);
	}
}
