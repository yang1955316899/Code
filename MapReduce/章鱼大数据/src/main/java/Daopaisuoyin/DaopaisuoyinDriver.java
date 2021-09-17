package Daopaisuoyin;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

public class DaopaisuoyinDriver {
	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{
				"C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Daopaisuoyin\\datas\\goods3.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Daopaisuoyin\\datas\\goods_visit3.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Daopaisuoyin\\datas\\order_items3.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Daopaisuoyin\\result"
		};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		job.setJarByClass(DaopaisuoyinDriver.class);
		job.setMapperClass(DaopaisuoyinMapper.class);
		job.setReducerClass(DaopaisuoyinReducer.class);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(Text.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileInputFormat.addInputPath(job, new Path(args[1]));
		FileInputFormat.addInputPath(job, new Path(args[2]));
		FileOutputFormat.setOutputPath(job, new Path(args[3]));
		boolean b = job.waitForCompletion(true);
		System.exit(b ? 0 : 1);
	}
}
