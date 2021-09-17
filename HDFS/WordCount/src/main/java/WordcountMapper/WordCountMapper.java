package WordcountMapper;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WordCountMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
	// �������ֱ�ӽ��и�ֵ,Ҳ����ͨ������.set()��ֵ���и�ֵ
	IntWritable v = new IntWritable(1);
	Text k = new Text();
	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, IntWritable>.Context context)
			throws IOException, InterruptedException {
		// ��ȡһ������,ͨ��toString��������Text����ת��,ͨ��split���зִ�
		String[] words = value.toString().split(" ");
		// ѭ������ÿһ����
		for (String word : words) {
			// ���ص�ֵ��Text,ͨ���������ַ�ʽ�Ը�ʽ����ת��
			k.set(word);
			v.set(1);
			// д������
			context.write(k, v);
		}
	}
}
