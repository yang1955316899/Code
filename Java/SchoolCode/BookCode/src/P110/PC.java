package P110;

public class PC {
	CPU tem_c = null;
	HardDisk tem_h = null;

	void setCPU(CPU C) {
		tem_c = C;
	}

	void setHardDisk(HardDisk h) {
		tem_h = h;
	}

	void show() {
		if (tem_h != null && tem_c != null)
			System.out.println("当前电脑的CPU速度为：" + tem_c.getSpeed() + "MHz，硬盘容量为：" + tem_h.getAmount() + "GB!");
		else
			System.out.println("Wrong");
	}
}
