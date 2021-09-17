package Ercipaixu;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

public class ErcipaixuDriver {
	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{
				"C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Ercipaixu\\datas\\goods-visit2.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Ercipaixu\\result"
		};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		job.setJarByClass(ErcipaixuDriver.class);
		job.setMapperClass(ErcipaixuMapper.class);
		job.setReducerClass(ErcipaixuReducer.class);
		job.setMapOutputKeyClass(Goods.class);
		job.setMapOutputValueClass(NullWritable.class);
		job.setOutputKeyClass(Object.class);
		job.setOutputValueClass(NullWritable.class);
		FileInputFormat.setInputPaths(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		job.setGroupingComparatorClass(ErcipaixuGroupingComparator.class);
		boolean b = job.waitForCompletion(true);
		System.exit(b ? 0 : 1);
	}
}
