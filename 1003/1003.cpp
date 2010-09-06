/* 真值表：
 * ========
 * 大数 小数 胜出
 * 真   真   大数
 * 真   假   大数
 * 假   真   小数
 * 假   假   大数
 *
 * 条件：
 * ======
 * 每个气球只能被踩一次。
 * 小数大数均能除尽，则大数为真。
 * 小数能除尽，则小数为真。
 *
 * 优化：
 * ======
 * 大的因子有更多的可能性，例如64=2*32=4*16=16*4。
 * 所以先除以大的因子，可以去除更多的可能性。
 * 如果让你来抢，你也会先抢号码大的球。
 */

// #include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

bool big_number_is_true=false, small_number_is_true=false;
void divide_numbers(int big_number, int small_number, int divisor);

int main()
{
//    ifstream cin("test.txt");

    int big_number=0, small_number=0;
    while (cin>>big_number>>small_number)
    {
	// 确保第一个是大数，第二个是小数
	if ( big_number < small_number ) swap(big_number, small_number);

	big_number_is_true=false, small_number_is_true=false;

	divide_numbers(big_number, small_number, 100);

	// 真值表第三行
	if ( big_number_is_true == false && small_number_is_true == true )
	    cout<<small_number<<endl;
	// 真值表其他行
	else
	    cout<<big_number<<endl;
    }

    return 0;
}

void divide_numbers(int big_number, int small_number, int divisor)
{
    // 小数大数均能除尽，则大数为真。
    if ( big_number == 1 && small_number == 1 )
	big_number_is_true=true;

    // 小数能除尽，则小数为真。
    if ( small_number == 1 )
	small_number_is_true=true;

    // 除到1结束，1不用除。1号球可抢可不抢。
    if ( divisor == 1)
	return;

    // 如果报大数者抢到球，将原数字除以球上的号码，继续抢下一球
    if ( big_number % divisor == 0 )
	divide_numbers(big_number/divisor, small_number, divisor-1);

    // 如果报小数者抢到球，将原数字除以球上的号码，继续抢下一球
    if ( small_number % divisor == 0 )
	divide_numbers(big_number, small_number/divisor, divisor-1);

    // 如果两人都没抢到此球，继续抢下一球
    divide_numbers(big_number, small_number, divisor-1);
}
