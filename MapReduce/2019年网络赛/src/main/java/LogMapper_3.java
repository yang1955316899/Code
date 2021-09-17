import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class LogMapper_3 extends Mapper<LongWritable, Text, Text, NullWritable> {
    HashMap map = new HashMap<Integer, String>();
    Text k = new Text();

    @Override
    protected void setup(Context context) throws IOException, InterruptedException {
        BufferedReader bf = new BufferedReader(new FileReader("C:\\Code\\MapReduce\\2019年网络赛\\src\\main\\java\\datas\\cityid.txt"));
        String tem = "";
        while ((tem = bf.readLine()) != null) {
            String[] split = tem.split("\\|");
            map.put(split[0], split[1]);
        }
        bf.close();
        System.out.println(map);
    }

    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, NullWritable>.Context context) throws IOException, InterruptedException {
        JSONObject jsonObject = JSON.parseObject(value.toString());
        JSONObject common = jsonObject.getJSONObject("common");
        common.put("cityid", map.get(common.getString("cityid")));
        k.set(jsonObject.toString());
        context.write(k, NullWritable.get());
    }
}
