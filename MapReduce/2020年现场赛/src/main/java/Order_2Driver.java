import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

public class Order_2Driver {

	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{
				"C:\\Code\\MapReduce\\2020年现场赛\\src\\main\\java\\datas\\Order.csv", "C:\\Code\\MapReduce\\2020年现场赛\\src\\main\\java\\result\\2_1", "C:\\Code\\MapReduce\\2020年现场赛\\src\\main\\java\\result\\2_2"
		};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		job.setJarByClass(Order_2Driver.class);
		job.setMapperClass(Order_2Mapper.class);
		job.setReducerClass(Order_2Reducer.class);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(Text.class);
		job.setOutputKeyClass(Order_2.class);
		job.setOutputValueClass(NullWritable.class);
		FileInputFormat.setInputPaths(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		job.waitForCompletion(true);
		Job job2 = Job.getInstance(conf);
		job2.setJarByClass(Order_2Driver.class);
		job2.setMapperClass(Order_2Mapper_2.class);
		job2.setReducerClass(Order_2Reducer_2.class);
		job2.setMapOutputKeyClass(Order_2.class);
		job2.setMapOutputValueClass(NullWritable.class);
		job2.setOutputKeyClass(Order_2.class);
		job2.setOutputValueClass(NullWritable.class);
		FileInputFormat.setInputPaths(job2, new Path(args[1]));
		FileOutputFormat.setOutputPath(job2, new Path(args[2]));
		boolean b = job2.waitForCompletion(true);
		System.exit(b ? 0 : 1);
	}
}
