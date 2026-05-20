#include <iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
//下面我将规定 1->真，0->未赋值，-1->假
//选择运用DPLL算法
struct Clause {
	vector<int> literals;
};//子句结构体
bool ifpos(int a)
{
	return a > 0;
}//判断真假

bool if_repeatedB(int x, vector<int>v) {
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]== x) return true;
	}
	return false;
}
bool if_same(vector<int>v1, vector<int>v2) 
{
	if (v1.empty() && v2.empty())  return true;
	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i]) return false;
	}
	return true;
}
bool if_repeatedA(Clause x, vector<Clause> v) {
	for (int i = 0; i < v.size(); i++)
	{
		if (if_same(v[i].literals,x.literals)) return true;
	}
	return false;
}
bool input_fatal(int*arr,int n) {
	if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) return true;
	for (int i = 0; i < 3; i++)
	{
		if (abs(arr[i]) > n || arr[i] == 0) return true;
	}
	return false;
}
/*vector<Clause> creclauses(int n, int m) {
	Clause C;
	vector<Clause> V;
	int *num = new int[3];
	for (int i = 0; i < m; i++)
	{
		cout << "请输入第" << i + 1 << "个表达式" << endl;
		cin >> num[0] >> num[1] >> num[2];
			if (input_fatal(num,n)) throw"Invailed Input";
			for (int j = 0; j < 3; j++)
			{
				C.literals.push_back(num[j]);
			}
		
		cout <<"第" <<i+1<<"个表达式输入完毕"<<endl;
		V.push_back(C);
		C.literals.clear();

	}
	delete[]num;
	return V;
}//创建初始范式,one by one
*/
vector<Clause> simplify(const vector<Clause>& clauses, const vector<int>& assignment)
{
	vector<Clause> new_clauses;
	for (int i = 0; i < clauses.size(); i++)
	{
		Clause new_clause;
		bool if_ClauseReal = false;
		for (int j = 0; j < clauses[i].literals.size(); j++)
		{
			int literal = clauses[i].literals[j];
			int var_index = abs(literal) - 1;
			int var_value = assignment[var_index];
			if ((literal > 0 && var_value == 1) || (literal < 0 && var_value == -1))
			{
				if_ClauseReal = true;
				break;
			}
			else if ((literal > 0 && var_value == -1) || (literal < 0 && var_value == 1))
			{
				continue;
			}
			else if (var_value == 0)
			{
				new_clause.literals.push_back(literal);
			}
			}
		if (!if_ClauseReal && !new_clause.literals.empty())
		{
			new_clauses.push_back(new_clause);//未被满足且非空
		}
		else if (!if_ClauseReal && new_clause.literals.empty()) {
			new_clauses.push_back(new_clause);//未被满足但已空，说明有矛盾，加入空子句
		}
	}
	
	return new_clauses;
};//简化范式
int find_variable(const vector<Clause>&simplified_clauses,const vector<int>& assignment,int n) {
	vector<int>frequency(n, 0);
	for (int i = 0; i < simplified_clauses.size(); i++) 
	{
		for (int j = 0; j < simplified_clauses[i].literals.size(); j++)
		{
			if (assignment[abs(simplified_clauses[i].literals[j]) - 1] == 0)
			{
				frequency[abs(simplified_clauses[i].literals[j]) - 1]++;
			}
		}
	}
	int maxTndex = -1, maxfrenquency = -1;
	for (int i = 0; i < n; i++)
	{
		if (assignment[i] == 0) {
			if (frequency[i] > maxfrenquency)
			{
				maxfrenquency = frequency[i];
				maxTndex = i;
			}
		}
	}
	//如果有子句中没有出现过的未赋值变量，选取任意没赋值的变量
	if (maxTndex == -1) {
		for (int i = 0; i < n; i++) {
			if (assignment[i] == 0) {
				maxTndex = i;
				break;
			}
		}
	}
	return maxTndex;
}//查找未被赋值的变量
bool DPLL(vector<Clause>& clauses, vector<int>& assignment, int n) {
	while (true) {
		vector<Clause> simplified_clauses = simplify(clauses, assignment);
		bool progress = false;
		for (int i = 0; i < simplified_clauses.size(); i++) {
			if (simplified_clauses[i].literals.empty()) {
				return false;//空子句，无解
			}
		}
		if (simplified_clauses.empty()) {
			return true;
		}
		//处理单子句
		for (int i = 0; i < simplified_clauses.size(); i++) {
			if (simplified_clauses[i].literals.size() == 1) {  // 单子句
				int literal = simplified_clauses[i].literals[0];
				int varIndex = abs(literal) - 1;
				assignment[varIndex] = (literal > 0) ? 1 : -1;
				progress = true;
				break;  // 重新开始简化过程
			}
		}
		//选一个变量进行分支
		if (!progress) {  // 没有更多单子句可以处理
			int var_index = find_variable(simplified_clauses, assignment, n);
			if (var_index == -1) {
				bool all_assigned = true;
				for (int i = 0; i < n; i++) {
					if (assignment[i] == 0) {
						var_index = i;
						all_assigned = false;
						break;
					}
				}
				if (all_assigned)
				{
					return false;//所有变量都被赋值但仍有子句未被满足
				}
			}



			// 尝试赋值为真
			vector<int>temp_assignment = assignment;
			temp_assignment[var_index] = 1;
			if (DPLL(clauses, temp_assignment, n)) {
				assignment = temp_assignment;
				return true;
			}
			temp_assignment = assignment;
			temp_assignment[var_index] = -1;  // 尝试赋值为假
			if (DPLL(clauses, temp_assignment, n)) {
				assignment = temp_assignment;
				return true;
			}
			return false;
		}
	}
}

bool if_wellpro(int m, vector<Clause> clauses) 
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (clauses[i].literals[j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}//检查表达式是否完好生成
vector<Clause> generate_clauses(int n, int m) {
	Clause C;
	vector<Clause> V;
	int* num = new int[3];
	for (int i = 0; i < m; i++)
	{
		cin >> num[0] >> num[1] >> num[2];
		if (input_fatal(num, n)) throw"Invailed Input";
		for (int j = 0; j < 3; j++)
		{
			C.literals.push_back(num[j]);
		} 
		V.push_back(C);
		C.literals.clear();

	}
	delete[]num;
	return V;
	}
vector<Clause> gen_bycopy_clauses(int n, int m,int**matrix) {
	Clause C;
	vector<Clause> V;
	for (int i = 0; i < m; i++)
	{
		int num[3] = { matrix[i][0], matrix[i][1], matrix[i][2] };
			if (input_fatal(num, n)) throw"Invailed Input";
			for (int j = 0; j < 3; j++)
			{
				C.literals.push_back(num[j]);
			}
			V.push_back(C);
			C.literals.clear();
	}
	return V;
}


void test() 
{
	int m, n = 0;
	cin >> n;
	cin >> m;
	vector<int>assignment(n,0);
	int** matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[3];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> matrix[i][j]; // 输入矩阵元素
		}
	}
	vector<Clause> clauses = gen_bycopy_clauses(n,m,matrix);
	bool solution = DPLL(clauses, assignment, n);
	if (solution)
	{
		for (int i = 0; i < n; i++)
		{
			if (assignment[i] == -1)cout << 0 << " ";
			else cout << assignment[i] << " ";
		}
	}
	else { throw"wrong input!"; }
	for (int i = 0; i < m; i++) {
		delete[]matrix[i];
	}
	delete[] matrix;
}

int main() {
	test();
	return 0;
}


