import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

public class Order_2 implements WritableComparable {
	private String province;
	private double salesVolume;
	private double profit;

	public Order_2() {
	}

	public Order_2(String province, double salesVolume, double profit) {
		this.province = province;
		this.salesVolume = salesVolume;
		this.profit = profit;
	}

	@Override
	public int compareTo(Object o) {
		Order_2 o1 = (Order_2) o;
		if (salesVolume > o1.getSalesVolume()) {
			return -1;
		} else if (salesVolume != o1.getSalesVolume()) {
			return 1;
		} else {
			return 0;
		}
	}

	@Override
	public void write(DataOutput out) throws IOException {
		out.writeUTF(province);
		out.writeDouble(salesVolume);
		out.writeDouble(profit);
	}

	@Override
	public void readFields(DataInput in) throws IOException {
		province = in.readUTF();
		salesVolume = in.readDouble();
		profit = in.readDouble();
	}

	public String getProvince() {
		return province;
	}

	public void setProvince(String province) {
		this.province = province;
	}

	public Double getSalesVolume() {
		return salesVolume;
	}

	public void setSalesVolume(Double salesVolume) {
		this.salesVolume = salesVolume;
	}

	public Double getProfit() {
		return profit;
	}

	public void setProfit(Double profit) {
		this.profit = profit;
	}

	@Override
	public String toString() {
		return province + '\t' + salesVolume + "\t" + profit;
	}
}
