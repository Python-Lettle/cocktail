#include <string>
using namespace std;


//Token
/**
 * Token 类型规则
 * 0	保留的未知类型
 * 1	string	字符串
 * 2	int	整数
 * 3	Object	普通对象
 * 4	bool	布尔型
 * 5 	void	空类型
 * 6	+
 * 7	-
 * 8	*
 * 9	/
 * 10	%	取余
 * 20	.
 * 21	//	注释
 * 22	(
 * 23	)
 * 24	[
 * 25	]
 * 26	{
 * 27	}
 * 28	@
 * 29	#
 * 30	?
 * 31	<
 * 32	>
 * 40	&&	和
 * 41	||	或
 * 42	!	非
 * 43	==	判等
 * 44	!=	判不等
 * 45	<=	小于等于
 * 46	>=	大于等于
 * 50	"
 * 51	'
 */

struct Token
{
	int line;	//代码行号
	int ch;		//词位置
	string type;
	string source;
};

const char HELP_MSG[] = "Parameters:\n \
	1. -o filename\tSet your output filename(The next arg must be filename)\n \
	2. -S filename\tOutput as asm file\n \
	3. --tokens\tToken only\n \
	4. --help / -h\tShow help\n";
