package Quchong;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class QuchongDriver {
    public static void main(String[] args) throws Exception {
        args = new String[]{
                "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Quchong\\datas\\buyer_favorite1.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\Quchong\\result"
        };
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf);
        job.setJarByClass(QuchongDriver.class);
        job.setMapperClass(QuchongMapper.class);
        job.setReducerClass(QuchongReducer.class);
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
