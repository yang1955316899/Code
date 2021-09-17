package DanbiaoJoin;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.log4j.BasicConfigurator;

public class DanbiaoJoinDriver {
	public static void main(String[] args) throws Exception {
		BasicConfigurator.configure();
		args = new String[]{
				"C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\DanbiaoJoin\\datas\\buyser1.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\DanbiaoJoin\\result"
		};
		Configuration conf = new Configuration();
		Job job = Job.getInstance(conf);
		job.setJarByClass(DanbiaoJoinDriver.class);
		job.setMapperClass(DanbiaoJoinMapper.class);
		job.setReducerClass(DanbiaoJoinReducer.class);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(Text.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
		FileInputFormat.setInputPaths(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		boolean b = job.waitForCompletion(true);
		System.exit(b ? 0 : 1);
	}
}
