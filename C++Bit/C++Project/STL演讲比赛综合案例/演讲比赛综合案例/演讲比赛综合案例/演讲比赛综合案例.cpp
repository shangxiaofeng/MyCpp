#include<iostream>
#include"vector"
#include"list"
#include"queue"
#include"deque"
#include"set"
#include"algorithm"
#include"functional"
#include"numeric"
#include"iterator"
#include"string"
#include"map"
using namespace std;

class Speaker{
public:
	string m_name;
	int m_score[3];
protected:
private:
};

//产生选手
int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v){
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//定义名字的代号
	random_shuffle(str.begin(),str.end());
	//for循环实现选手+代号   每一位选手实现编号加名字代号
	for (int i = 0; i < 24; i++){
		Speaker tmp;
		tmp.m_name = "选手";
		tmp.m_name = tmp.m_name + str[i]; 
		mapSpeaker.insert(pair<int, Speaker>(100+i, tmp));
	}
	//把24位选手放入v容器中
	for (int i = 0; i < 24; i++){
		v.push_back(100 + i);//参加比赛的人员	
	}
	return 0;
}

//选手抽签
int speech_contest_draw(vector<int> v){
	random_shuffle(v.begin(), v.end());
	return 0;
}

//第一个参数表示第几轮，v1表示参赛名单，第三个参数表示比赛的得分情况，第四个参数表示结果
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2){
	//遍历模型
	//小组的比赛得分 记录下来 求出前三名 后三名
	//小组得分可能是重复的
	multimap<int, int, greater<int>> multimapGroup;//小组成绩
	int tmpCount = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		tmpCount++;
		//打分
			{
				deque<int> dscore;
				//10个评委打分
				for (int j = 0; j < 10; j++){
					int score = 50 + rand() % 50;
					dscore.push_back(score);
				 } 
				sort(dscore.begin(), dscore.end());//排序
				//去除最低分 最高分 
				dscore.pop_front();
				dscore.pop_back();

				//求平均分
				int scorenum = accumulate(dscore.begin(), dscore.end(), 0);
				int scoreaverage = scorenum / dscore.size();
				mapSpeaker[*it].m_score[index] = scoreaverage;//选手得分存入容器中
				multimapGroup.insert(pair<int, int>(scoreaverage, *it));
			}
		//处理分组
		if (tmpCount % 6 == 0){
			cout << "小组的比赛成绩" << endl;
			for (multimap<int, int,greater<int>>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++){
				//  编号  姓名 得分
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name << "\t" << mit->first << endl;
			}
			//前三名晋级
			while (multimapGroup.size() > 3){
				multimap<int, int, greater<int>>::iterator it1 = multimapGroup.begin();
				v2.push_back(it1->second);//把前三名放入V2中，v2为晋级的下一次名单
				multimapGroup.erase(it1);
			}
			multimapGroup.clear();//清空本小组的比赛成绩
		}
	}
	return 0;
}

//查看比赛结果
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker){
	printf("第%d 轮晋级名单\n", index + 1);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "参赛编号：" << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}
	return 0;
}
int main(){
	//容器的设计
	map<int, Speaker> mapSpeaker;//参加比赛的选手 
	vector<int>  v1;//第一轮演讲比赛的名单
	vector<int>  v2;//第二轮演讲比赛的名单
	vector<int>  v3;//第三轮演讲比赛的名单
	vector<int>  v4;//第四轮演讲比赛的名单

	//产生选手 得到第一轮比赛的名单
	GenSpeaker(mapSpeaker, v1);
	
	//第一轮选手抽签，选手比赛，查看比赛结果
	cout << " \n\n\n任意键，开始第1轮比赛" << endl;
	cin.get();
	speech_contest_draw(v1);
	speech_contest(0, v1, mapSpeaker, v2);
	speech_contest_print(0, v2, mapSpeaker);//查看比赛结果
	//第二轮选手抽签，选手比赛，查看比赛结果
	cout << " \n\n\n任意键，开始第2轮比赛" << endl;
	cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_print(1, v3, mapSpeaker);//查看比赛结果
	//第三轮选手抽签，选手比赛，查看比赛结果
	cout << " \n\n\n任意键，开始第3轮比赛" << endl;
	cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_print(2, v4, mapSpeaker);//查看比赛结果

	return 0;
}


