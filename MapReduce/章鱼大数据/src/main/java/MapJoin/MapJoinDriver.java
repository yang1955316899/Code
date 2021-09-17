package MapJoin;

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

public class MapJoinDriver {
    @SuppressWarnings("UnstableApiUsage")
    public static void main(String[] args) throws Exception {
        BasicConfigurator.configure();
        args = new String[]{
                "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\MapJoin\\datas\\order_items1.txt", "C:\\Code\\MapReduce\\章鱼大数据\\src\\main\\java\\MapJoin\\reduce"
        };
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf);
        URI uri = new URI("file:///C://Code//MapReduce//章鱼大数据//src//main//java//MapJoin//datas//orders1.txt");
        job.addCacheFile(uri);
        job.setJarByClass(MapJoinDriver.class);
        job.setMapperClass(MapJoinMapper.class);
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
