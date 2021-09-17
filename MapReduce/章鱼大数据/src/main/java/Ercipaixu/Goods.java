package Ercipaixu;

import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

public class Goods implements WritableComparable<Goods> {
	private int goods_id;
	private int click_num;

	public Goods() {
	}

	public Goods(int goods_id, int click_num) {
		this.goods_id = goods_id;
		this.click_num = click_num;
	}

	@Override
	public int compareTo(Goods o) {
		int flag;
		if (click_num > o.getClick_num()) {
			flag = -1;
		} else if (click_num != o.getClick_num()) {
			flag = 1;
		} else {
			if (goods_id > o.getGoods_id()) {
				flag = 1;
			} else if (goods_id != o.getGoods_id()) {
				flag = -1;
			} else {
				flag = 0;
			}
		}
		return flag;
	}

	@Override
	public void write(DataOutput out) throws IOException {
		out.writeInt(goods_id);
		out.writeInt(click_num);
	}

	@Override
	public void readFields(DataInput in) throws IOException {
		this.goods_id = in.readInt();
		this.click_num = in.readInt();
	}

	public int getGoods_id() {
		return goods_id;
	}

	public void setGoods_id(int goods_id) {
		this.goods_id = goods_id;
	}

	public int getClick_num() {
		return click_num;
	}

	public void setClick_num(int click_num) {
		this.click_num = click_num;
	}

	public void set(int goods_id, int click_num) {
		this.goods_id = goods_id;
		this.click_num = click_num;
	}

	@Override
	public String toString() {
		return click_num + "\t" + goods_id;
	}
}
