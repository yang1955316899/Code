import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class YiqingDriver_2 {

    public static void main(String[] args) throws Exception {
        args = new String[]{"C:\\Code\\MapReduce\\2020年网络赛\\src\\main\\java\\疫情数据.csv", "C:\\Code\\MapReduce\\2020年网络赛\\src\\main\\java\\result"};
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf);
        job.setJarByClass(YiqingDriver_2.class);
        job.setMapperClass(YiqingMapper_2.class);
        job.setReducerClass(YiqingReducer_2.class);
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