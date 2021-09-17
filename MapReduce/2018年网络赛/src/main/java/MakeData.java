import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class MakeData {
	public static void main(String[] args) throws IOException {
		//放try里自动关流
		try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File("C:\\Code\\MapReduce\\2018年网络赛\\src\\main\\java\\datas\\num.txt")))) {
			for (int x = 0; x < 49999; x++) {
				bufferedWriter.write((int) (Math.random() * 100) + ",");
			}
			bufferedWriter.write((int) (Math.random() * 100) + "");
		}
	}
}
