#include <string>
using namespace std;
/* 内置函数 */
string asm_print()
{
	string print_asm = 
		"\t.globl print\n"
		"print:\n"
    	"\tstp x29, x30, [sp, #-16]!\n"
		"\tmov x29, sp\n"
		"\tbl  puts\n"
		"\tldp x29, x30, [sp], #16\n"
		"\tret";
	return	print_asm;
}

/* 变量类型 */
string asm_string(string str)
{
	string string_asm =
		".helstr:\n"
		"\t.asciz\t"+str+"\n"
		"\t.size\t.helstr, 6";
	return string_asm;
}


string asm_main()
{
	string main_asm =
	"main:\n"
    "\tstp x29, x30, [sp, #-16]!\n"
    "\tadrp    x0, .helstr\n"
    "\tadd x0, x0, :lo12:.helstr\n"
	"\tmov x29, sp\n"
    "\tbl  puts\n"
	"\tmov w0, wzr\n"
	"\tldp x29, x30, [sp], #16\n"
	"\tret\n";
	return main_asm;
}

string asm_head()
{
	string head_asm =
		"\t.globl main\n";
	return head_asm;
}
