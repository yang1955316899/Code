import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

public class Order_3 implements WritableComparable {
	private String date;
	private String id;
	private String type;
	private double salesVolume;
	private double profit;

	public Order_3() {
	}

	public Order_3(String date, String id, String type, double salesVolume, double profit) {
		this.date = date;
		this.id = id;
		this.type = type;
		this.salesVolume = salesVolume;
		this.profit = profit;
	}

	@Override
	public int compareTo(Object o) {
		Order_3 o1 = (Order_3) o;
		if (type.compareTo(o1.getType()) > 0) {
			return 1;
		} else if (type.compareTo(o1.getType()) < 0) {
			return -1;
		} else {
			if (profit > o1.getProfit()) {
				return -1;
			} else if (profit != o1.getProfit()) {
				return 1;
			} else {
				return 0;
			}
		}
	}

	@Override
	public void write(DataOutput out) throws IOException {
		out.writeUTF(date);
		out.writeUTF(id);
		out.writeUTF(type);
		out.writeDouble(salesVolume);
		out.writeDouble(profit);
	}

	@Override
	public void readFields(DataInput in) throws IOException {
		date = in.readUTF();
		id = in.readUTF();
		type = in.readUTF();
		salesVolume = in.readDouble();
		profit = in.readDouble();
	}

	public String getDate() {
		return date;
	}

	public void setDate(String data) {
		this.date = data;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public double getSalesVolume() {
		return salesVolume;
	}

	public void setSalesVolume(double salesVolume) {
		this.salesVolume = salesVolume;
	}

	public double getProfit() {
		return profit;
	}

	public void setProfit(double profit) {
		this.profit = profit;
	}

	//订单日期，产品id，类别，销售额，利润
	@Override
	public String toString() {
		return date + "," + id + "," + type + "," + salesVolume + "," + profit;
	}
}
