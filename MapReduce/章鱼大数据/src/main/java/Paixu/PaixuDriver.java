package Paixu;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

public class PaixuDriver {
    public static void main(String[] args) throws IOException, InterruptedException, ClassNotFoundException {
        args = new String[]{
                "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Paixu\\datas\\goods_visit1.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Paixu\\result"
        };
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf);
        job.setJarByClass(PaixuDriver.class);
        job.setMapperClass(PaixuMapper.class);
        job.setReducerClass(PaixuReducer.class);
        job.setMapOutputKeyClass(Goods.class);
        job.setMapOutputValueClass(NullWritable.class);
        job.setOutputKeyClass(Goods.class);
        job.setOutputValueClass(NullWritable.class);
        FileInputFormat.setInputPaths(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        boolean b = job.waitForCompletion(true);
        System.exit(b ? 0 : 1);

    }
}
