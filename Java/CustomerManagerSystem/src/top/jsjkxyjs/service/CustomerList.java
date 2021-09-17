package top.jsjkxyjs.service;

import top.jsjkxyjs.bean.Customer;

public class CustomerList {
	private Customer[] customers;
	private int total = 0;

	public CustomerList(int totalCustomer) {
		customers = new Customer[totalCustomer];
	}

	public boolean addCustomer(Customer customer) {
		if (total >= customers.length)
			return false;
		else
			customers[total++] = customer;
		return true;
	}

	public boolean replaceCustomer(int index, Customer cust) {
		if (index <= 0 || index >= total)
			return false;
		customers[index] = cust;
		return true;
	}

	public boolean deleteCustomer(int index) {
		if (index <= 0 || index >= total)
			return false;
		System.arraycopy(customers, index + 1, customers, index, total - index);
		customers[--total] = null;
		return true;
	}

	public Customer[] getAllCustomers() {

		Customer temp[] = new Customer[total];
		System.out.println();
		for (int i = 0; i < total; i++)
			temp[i] = customers[i];

		return temp;
	}

	public Customer getCustomer(int index) {
		if (index < 0 || index >= total)
			return null;
		return customers[index];
	}

	public int getTotal() {
		return total;
	}
}
