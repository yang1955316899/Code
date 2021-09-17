import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;


public class LogMapper_2 extends Mapper<LongWritable, Text, Text, NullWritable> {
    Text v = new Text();

    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
        JSONObject jsonObject = JSON.parseObject(value.toString());
        JSONObject common = jsonObject.getJSONObject("common");
        if (common.containsKey("uid") && common.containsKey("platform") && common.
                containsKey("app_version") && common.containsKey("pid") && common.containsKey("cityid")) {
            v.set("\"uid\":\"" + common.getString("uid") + "\",\"platform\":\"" + common.getString("platform") + "\",\"app_version\":\"" + common.
                    getString("app_version") + "\",\"pid\":\"" + common.getString("pid") + "\",\"cityid\":\"" + common.getString("cityid") + "\"");
            context.write(v, NullWritable.get());
        }
    }
}
