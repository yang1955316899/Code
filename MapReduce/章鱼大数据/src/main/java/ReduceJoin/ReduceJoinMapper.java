package ReduceJoin;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;

import java.io.IOException;

public class ReduceJoinMapper extends Mapper<LongWritable, Text, Text, Text> {
    @Override
    protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, Text>.Context context) throws IOException, InterruptedException {
        String filePath = ((FileSplit) context.getInputSplit()).getPath().toString();
        if (filePath.contains("orders1")) {
            String line = value.toString();
            String[] arr = line.split("\t");
            context.write(new Text(arr[0]), new Text("1+" + arr[2] + "\t" + arr[3]));
        } else {
            String line = value.toString();
            String[] arr = line.split("\t");
            context.write(new Text(arr[1]), new Text("2+" + arr[2]));
        }
    }
}