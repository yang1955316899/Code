package Paixu;

import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

public class Goods implements WritableComparable<Goods> {
    int id;
    int count;

    public Goods() {
    }

    public Goods(int id, int count) {
        this.id = id;
        this.count = count;
    }

    @Override
    public int compareTo(Goods o) {
        return count > o.getCount() ? (count == o.getCount() ? 0 : 1) : -1;
    }

    @Override
    public void write(DataOutput out) throws IOException {
        out.writeInt(id);
        out.writeInt(count);
    }

    @Override
    public void readFields(DataInput in) throws IOException {
        id = in.readInt();
        count = in.readInt();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return count + "\t" + id;
    }
}
