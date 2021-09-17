package zookeeper;

import org.apache.zookeeper.*;
import org.apache.zookeeper.data.Stat;
import org.junit.Before;

import java.io.IOException;
import java.util.List;


public class Test {
	private String connectString = "hadoop101:2181,hadoop102:2181,hadoop103:2181";
	private int sessionTimeout = 2000;
	private ZooKeeper zkClient;

	@Before
	public void init() throws IOException {

		zkClient = new ZooKeeper(connectString, sessionTimeout, new Watcher() {

			public void process(WatchedEvent watchedEvent) {

				System.out.println("--------------------------------");
				List<String> children = null;
				try {
					children = zkClient.getChildren("/", true);
					for (String child : children) {
						System.out.println(child +"process");
					}
					System.out.println("--------------------------------------");
				} catch (KeeperException e) {
					e.printStackTrace();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}

			}
		});
	}


	public void getChildern() throws KeeperException, InterruptedException {

		Thread.sleep(Long.MAX_VALUE);
	}



	public static void main(String[] args) throws IOException, KeeperException, InterruptedException {
		 Test test = new Test();
		 test.init();
		 test.getChildern();
	}
}