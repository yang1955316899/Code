import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import com.alibaba.fastjson.*;

import java.io.IOException;


public class LogMapper_1 extends Mapper<LongWritable, Text, Text, NullWritable> {
    Text v = new Text();

    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
        JSONObject jsonObject = JSON.parseObject(value.toString());
        JSONObject common = jsonObject.getJSONObject("common");
        if (common.containsKey("uid") && common.containsKey("platform") && common.
                containsKey("app_version") && common.containsKey("pid")) {
            if (common.containsKey("locationcity")) {
                if (Integer.parseInt(common.getString("locationcity")) == 0) {
                    common.put("locationcity", 1);
                }
            }
            v.set(String.valueOf(jsonObject));
            context.write(value, NullWritable.get());
        }
    }
}
