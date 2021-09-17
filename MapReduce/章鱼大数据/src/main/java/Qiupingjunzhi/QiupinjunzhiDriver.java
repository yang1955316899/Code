package Qiupingjunzhi;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class QiupinjunzhiDriver {
    public static void main(String[] args) throws Exception {
        args = new String[]{
                "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Qiupingjunzhi\\datas\\goods_click.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Qiupingjunzhi\\result"
        };
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf);
        job.setJarByClass(QiupinjunzhiDriver.class);
        job.setMapperClass(QiupingjunzhiMapper.class);
        job.setReducerClass(QiupingjunzhiReducer.class);
        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(IntWritable.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);
        FileInputFormat.setInputPaths(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        boolean b = job.waitForCompletion(true);
        System.exit(b ? 0 : 1);
    }
}
