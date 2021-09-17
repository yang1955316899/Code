package top.jsjkxyjs.hdfs;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;

public class HDFSClient {
	public static void main(String[] args) {
		Configuration conf = new Configuration();
//		conf.set("fs.defaultFS", "hdfs://hadoop101:9000");
//		FileSystem fs;
		try {
//			fs = FileSystem.get(conf);
			FileSystem fs =FileSystem.get(new URI("hdfs://hadoop101:9000"), conf, "root");
			fs.mkdirs(new Path("/Yangjianwen/66"));
			fs.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 

		System.out.println("over");
	}
}