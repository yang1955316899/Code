public class Message {
    /**
     * 取消关注（remove)
     * a、在微博用户关系表中，对当前主动操作的用户删除对应取关的好友
     * b、在微博用户关系表中，对被取消关注的人删除粉丝（当前操作人）
     * c、从收件箱中，删除取关的人的微博的 rowkey
     */
    /**
     * 获取微博实际内容
     * a、从微博收件箱中获取所有关注的人的发布的微博的 rowkey
     * b、根据得到的 rowkey 去微博内容表中得到数据
     * c、将得到的数据封装到 Message 对象中
     */
    /**
     * 发布微博内容
     * 添加关注
     * 取消关注
     * 展示内容
     */
    public void testPublishContent(WeiBo wb){
        wb.publishContent("0001", "今天买了一包空气，送了点薯片，非常开心！！ ");
        wb.publishContent("0001", "今天天气不错。 ");
    }
    public void testAddAttend(WeiBo wb){
        wb.publishContent("0008", "准备下课！ ");
        wb.publishContent("0009", "准备关机！ ");
        wb.addAttends("0001", "0008", "0009");
    }
    public void testRemoveAttend(WeiBo wb){
        wb.removeAttends("0001", "0008");
    }
    public void testShowMessage(WeiBo wb){
        List<Message> messages = wb.getAttendsContent("0001");
        for(Message message : messages){
            System.out.println(message);
        }
    }
    public static void main(String[] args) {
        WeiBo weibo = new WeiBo();
        weibo.initTable();
        weibo.testPublishContent(weibo);
        weibo.testAddAttend(weibo);
        weibo.testShowMessage(weibo);
        weibo.testRemoveAttend(weibo);
        weibo.testShowMessage(weibo);
    }
}