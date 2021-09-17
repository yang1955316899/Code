import com.google.common.collect.ImmutableTable;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.hbase.client.Scan;
import org.apache.hadoop.hbase.mapreduce.TableMapReduceUtil;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class FruitDriver implements Tool {
    private Configuration configuration = null;

    public static void main(String[] args) throws Exception {
        Configuration configuration = new Configuration();
        int run = ToolRunner.run(configuration, new FruitDriver(), args);
        System.exit(run);
    }

    @Override
    public int run(String[] args) throws Exception {
        // 获取Job对象
        Job job = Job.getInstance(configuration);
        // 设置驱动类路径
        job.setJarByClass(FruitDriver.class);
        // 设置Mapper&Mapper输出的KV类型,一次性输入完成
        TableMapReduceUtil.initTableMapperJob(args[0], new Scan(), FruitMapper.class,
                ImmutableTable.class, Put.class, job);
        // 设置Reducer类
        TableMapReduceUtil.initTableReducerJob(args[1], FruitReducer.class, job);
        // 设置输入/输出参数
        FileInputFormat.setInputPaths(job, new Path(args[0]));
        // 提交任务
        boolean result = job.waitForCompletion(true);
        return result ? 0 : 1;
    }

    @Override
    public Configuration getConf() {
        return configuration;
    }

    @Override
    public void setConf(Configuration configuration) {
        this.configuration = configuration;
    }
}