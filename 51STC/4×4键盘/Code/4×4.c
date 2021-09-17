#include <reg51.h>                                // 定义8051暂存器之标头档
#define KEYP P2                                   // 扫瞄输出端口(高位元)及键盘输入端口(低位元)
#define SEG7P P0                                  // 7节显示器(g~a)输出埤
unsigned char code TAB[17] =                      // 共阳7节显示器(g~a)编码
    {0xc0, 0xf9, 0xa4, 0xb0, 0x99,                // 数字0-4
     0x92, 0x82, 0xf8, 0x80, 0x98,                // 数字5-9
     0xa0, 0x83, 0xa7, 0xa1, 0x84,                // 字母a-e(10-14)
     0x8e, 0xbf};                                 // 字母F(15),负号(-)
unsigned char disp[4] = {0xbf, 0xbf, 0xbf, 0xbf}; // 显示阵列初值为负号(-)
unsigned char scan[4] = {0xef, 0xdf, 0xbf, 0x7f}; // 7显示器及键盘之扫瞄码
void delay1ms(int);                               // 声明延迟函数
void scanner(void);                               // 声明扫瞄函数
//==主程序================================================
main() // 主程序开始
{
    while (1)      // 无穷回圈,程序一直跑
        scanner(); // 扫瞄键盘及显示7段显示器
} // 主程序结束
// === 延迟函数,延迟约x*1ms ================================
void delay1ms(int x) // 防弹跳函数开始
{
    int i, j;               // 声明整数变数i
    for (i = 0; i < x; i++) // 计数x次,延迟约*1ms
        for (j = 0; j < 120; j++)
            ; // 计数120次,延迟约1ms
} // 防弹跳函数结束
// ======= 扫瞄4*4键盘及4个7节显示器函数 ================
void scanner(void) // 扫瞄函数开始
{
    unsigned char col, row;       // 声明变数(col:行,row:列,dig:颢示位)
    unsigned char rowkey, kcode;  // 声明变数(rowkey:列键值,kcode:按键码)
    for (col = 0; col < 4; col++) // for回圈,扫瞄第col行
    {
        KEYP = scan[col];  // 高4位输出扫瞄信号,低4位元输入列值
        SEG7P = disp[col]; // 输出第col行数字

        rowkey = ~KEYP & 0x0f;
        // 读入KEYP低4位，反相再清除高4位求出列键值
        if (rowkey != 0) // 若有按键
        {
            if (rowkey == 0x01)
                row = 0; // 若第0列被按下
            else if (rowkey == 0x02)
                row = 1; // 若第1列被按下
            else if (rowkey == 0x04)
                row = 2; // 若第2列被按下
            else if (rowkey == 0x08)
                row = 3;           // 若第3列被按下
            kcode = 4 * col + row; // 算出按键之号码
            if (kcode < 0x0a)
            //	for(dig =0; dig <3 ; dig++)	// 显示阵列之左3字
            {
                disp[3] = disp[2];
                disp[2] = disp[1];
                disp[1] = disp[0];

                //		disp[dig]=disp[dig+1];		// 将右侧编码左移1位
                disp[0] = TAB[kcode]; // 键值编码後，写入最右侧
            }
            switch (kcode)
            {
            case 0x0a:
            {
                disp[3] = disp[2] = disp[1] = disp[0] = 0xbf;
                KEYP = 0x0f;
                break;
            }
            case 0x0b:
            {
                disp[0] = disp[1];
                disp[1] = disp[2];
                disp[2] = disp[3];
                disp[3] = 0xbf;
                break;
            }
            case 0x0c: //倒置
            {
                unsigned char i, j;
                i = disp[0];
                disp[0] = disp[3];
                disp[3] = i;
                j = disp[1];
                disp[1] = disp[2];
                disp[2] = j;
                break;
            }
            case 0x0d: //数字与第一个数相同
            {
                int i;
                for (i = 0; i < 4; i++)
                    disp[i] = disp[3];
                ;
                break;
            }
            case 0x0e: //后两位与前两位对称
            {
                for (j = 0; j < 4; j++)
                    disp[j] = 0xff|;
                break;
            }
            case 0x0f:
            {
                int j;
                for (j = 0; j < 4; j++)
                    disp[j] = 0x00;
                break;
            }
            }
        }                          //	if叙述(有按键时)结束
        while (rowkey != 0)        // 当按钮未放开
            rowkey = ~KEYP & 0x0f; // 再读入列键值
        delay1ms(4);               //	延迟4ms

    } //	for回圈结束(扫瞄col行)
} //	扫瞄函数scanner()结束
