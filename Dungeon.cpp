/****************************************
* Environment: visual studio 2019 
* Author: 翟睿辰(Malones)
* Date: 2021/5/19
*****************************************/
/*概述：
*地牢闯关，每层有不同怪物，最终50层有最终boss
* 注：使用EasyX图形库
**/
/*更新日志：
* 5/19 
* 构思框架
* 写Human类
* Monster类
* 
* 5/20
* 写Hero类
* 构思框架
* 写Shield类
* Sword类
* Backpacking类框架
* 
* 5/22
* 写Shield类
* Sword类
* Backpacking类
* Boss类
* 
* 5/23
* 写Dungeon框架
* 
* 5/24
* 写Dungeon框架
* 
* 5/25
* 写Dungeon框架
* 
* 5/26
* 绘制所需图片，
* 写drawGraphDisplayPhotograph函数，
* 写普通层框架
* 
* 5/28
* 写普通层框架
* 写newFloorInformation函数
* 
* 5/29
* 写changeThisFloodMonsterInformation函数
* 写普通层框架及内容
* 
* 5/30
* 写普通层框架和内容,
* 写goToTheShop函数
* 
* 5/31
* 改进Hero类
* 写hitTheMonster函数
* 改进普通层内容
* 改进main函数中monster变量
* 
* 6/1
* 写普通层内容
* 删除写drawGraphDisplayPhotograph函数，
* 改进普通层显示方法
* 
* 6/2
* 绘制图片
* 更新普通层显示
* boos层显示
* 写checkPlayer函数
* 
* 6/5
* 构思显示细节
* 写showAttribute函数
* 写clickBackpacking函数
* 
* 6/6
* 把商店和背包展示物品合并为一个shopAndBackpackingShowMoneyAndGoods函数
* 
* 6/10
* 写showMonsterInformation函数
* 完成普通层
* 构思boss层
* 
* 6/11
* 写boss层,
* 写showBoss函数
* 写hitBoss函数
* 
* 6/13
* 完善boss层
* 写游戏结尾
* 调试改错
* 
***/
#include<iostream>
#include"Backpacking.h"
#include"Boss.h"
#include"Hero.h"
#include"Human.h"
#include"Monster.h"
#include"Shield.h"
#include"Sword.h"
#include"HealthPot.h"
#include<graphics.h>
#include<string>
#include<Windows.h>
using namespace std;

const int X0 = 0;
const int Y0 = 0;
const int Width = 300;   //图整体宽度
const int Hight = 650;   //图整体高度

const int sideLength1 = 100;   //小方框边长, 小怪等图片边长

//初始界面开始退出坐标
const int beginLeftX = 100;			const int beginHighY = 350;
const int beginRightX = 200;		const int beginLowY = 425;
const int outLeftX = 100;			const int outHighY = 450;
const int outRightX = 100;			const int outLowY = 525;

//普通层坐标
//横向排列，从1到12
const int graphDisplay1X = 0;				const int graphDisplay2X = 100;			const int graphDisplay3X = 200;
const int graphDisplay1Y = 0;				const int graphDisplay2Y = 0;				const int graphDisplay3Y = 0;

const int graphDisplay4X = 0;				const int graphDisplay5X = 100;			const int graphDisplay6X = 200;
const int graphDisplay4Y = 100;			const int graphDisplay5Y = 100;			const int graphDisplay6Y = 100;

const int graphDisplay7X = 0;				const int graphDisplay8X = 100;			const int graphDisplay9X = 200;
const int graphDisplay7Y = 200;			const int graphDisplay8Y = 200;			const int graphDisplay9Y = 200;

const int graphDisplay10X = 0;			const int graphDisplay11X = 100;		const int graphDisplay12X = 200;
const int graphDisplay10Y = 300;		const int graphDisplay11Y = 300;		const int graphDisplay12Y = 300;

//商店和背包界面显示金钱
POINT moneyPolygon [4] = { { 225, 25 }, { 299, 25 }, { 299, 55 }, { 225, 55 } };

//属性文字显示等，长宽50
const int sideLength2 = 50;
const int bloodX = 75;							const double bloodY = 437.5;
const int attackX = 50;						const int attackY = 487.5;
const int defenceX = 50;						const int defenceY = 537.5;
const int expX = 75;							const int expY = 612.5;
const int floorLevelX = 250;				const int floorLevelY = 437.5;
const int levelX = 250;							const int levelY = 487.5;
const int backpackingX = 175;			const int backpackingY = 525;
const int backpackingWidth = 75;		const int backpackingHight = 50;

//商店、背包界面，长宽100
const int shopAndBackpackingGoodsX = 100;							const int shopAndBackpackingSwordY = 50;
const int shopAndBackpackingShieldY = 150;							const int shopAndBackpackingHealthPotY = 250;
const int shopAndBackpackingButtonX = 25;							const int shopAndBackpackingButtonY = 300;
const int shopAndBackpackingButtonWidth = 25;						const int shopAndBackpackingButtonHight = 50;
const int shopAndBackpackingShowMoneyX = 225;					const int shopAndBackpackingShowMoneyY = 25;
const int shopAndBackpackingGoodsNumberX = 150;
const int shopAndBackpackingSwordNumberY = 125;
const int shopAndBackpackingShieldNumberY = 225;
const int shopAndBackpackingHealthPotNumberY = 325;

//普通层显示怪物信息
const int monsterInformationX = 110;					const int monsterInformationBloodY = 100;
const int monsterInformationAttackY = 150;			const int monsterInformationDefenceY = 200;

//boss
const int bossX = 25;							const int bossY = 2;
const int bossWidth = 175;					const int bossHigh = 225;
const int bossBloodX = 50;					const int bossBloodY = 225;
const int bossBeHittedTimesX = 50;		const int bossBeHittedTimesY = 250;

POINT clearBlood [4] = { { 75, 425 }, { 175, 425 }, { 175, 475 }, { 75, 475 } };
POINT clearFloorLevel [4] = { { 250, 425 }, { 294, 425 }, { 294, 475 }, { 250, 475 } };
POINT clearAttack [4] = { { 50, 475 }, { 150, 475 }, { 150, 525 }, { 50, 525 } };
POINT clearLevel [4] = { { 250, 475 }, { 294, 475 }, { 294, 525 }, { 250, 525 } };
POINT clearDefence [4] = { { 50, 525 }, { 150, 525 }, { 150, 575 }, { 50, 575 } };
POINT clearExp [4] = { { 100, 600 }, { 225, 600 }, { 225, 647 }, { 100, 647 } };
POINT clearBossBlood [4] = { { 50, 225 }, { 200, 225 }, { 200, 250 }, { 20, 250 } };
POINT clearBossBeHittedTimes [4] = { { 25, 250 }, { 100, 250 }, { 100, 275 }, { 25, 275 } };

//四角坐标
POINT displayPoint [4] = { { X0, Y0 }, { Width, Y0 }, { Width, Hight }, { X0, Hight } };

//显示页面四个顶角坐标（围住12个格子的顶角）
POINT displayFourPoint [4] = { { X0, Y0 }, { Width, Y0 }, { Width, 4 * sideLength1 }, { X0, 4 * sideLength1 } };

//普通层每个格子的四角坐标
POINT displayEachGridPoint [4][3][4] = {
	//第1行
	{
		{ { X0, Y0 }, { X0 + sideLength1, Y0 }, { X0 + sideLength1, Y0 + sideLength1 }, { X0, Y0 + sideLength1 } },			//第1格
		{ { X0 + sideLength1, Y0 }, { X0 + 2 * sideLength1, Y0 }, { X0 + 2 * sideLength1 , Y0 + sideLength1 }, { X0 + sideLength1, Y0 + sideLength1 } },			//第2格
		{ { X0 + 2 * sideLength1, Y0 }, { X0 +3 * sideLength1, Y0 }, { X0 + 3 * sideLength1, Y0 + sideLength1 }, { X0 + 2 * sideLength1, Y0 + sideLength1 } },			//第3格
	},
	//第2行
	{
		{ { X0, Y0 + sideLength1 }, { X0 + sideLength1, Y0 + sideLength1 }, { X0 + sideLength1, Y0 + 2 * sideLength1 }, { X0, Y0 + 2 * sideLength1 } },			//第1格
		{ { X0 + sideLength1, Y0 + sideLength1 }, { X0 + 2 * sideLength1, Y0 + sideLength1 }, { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + sideLength1, Y0 + 2 * sideLength1 } },			//第2格
		{ { X0 + 2 * sideLength1, Y0 + sideLength1 }, { X0 + 3 * sideLength1, Y0 + sideLength1 }, { X0 + 3 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 } },			//第3格
	},
	//第3行
	{
		{ { X0, Y0 + 2 * sideLength1 }, { X0 + sideLength1, Y0 + 2 * sideLength1 }, { X0 + sideLength1, Y0 + 3 * sideLength1 }, { X0, Y0 + 3 * sideLength1 } },			//第1格
		{ { X0 + sideLength1, Y0 + 2 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + sideLength1, Y0 + 3 * sideLength1 } },			//第2格
		{ { X0 + 2 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 2 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 } },			//第3格
	},
	//第4行
	{
		{ { X0, Y0 + 3 * sideLength1 }, { X0 + sideLength1, Y0 + 3 * sideLength1 }, { X0 + sideLength1, Y0 + 4 * sideLength1 }, { X0, Y0 + 4 * sideLength1 } },			//第1格
		{ { X0 + sideLength1, Y0 + 3 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 4 * sideLength1 }, { X0 + sideLength1, Y0 + 4 * sideLength1 } },			//第2格
		{ { X0 + 2 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 3 * sideLength1 }, { X0 + 3 * sideLength1, Y0 + 4 * sideLength1 }, { X0 + 2 * sideLength1, Y0 + 4 * sideLength1 } },			//第3格
	}
};

//boss属性
POINT bossInformationPoint [4] = { { 50, 225 }, { 200, 225 }, { 200, 275 }, { 50, 275 } };

//初始化普通层小怪、物品等信息
void newFloorInformation ( int graphInformation [ ][4] );

//本层小怪的属性信息
void changeThisFloorMonsterInformation ( Monster* monster, int level, int monsterKind );

//玩家攻击
void hitTheMonster ( Hero* hero, Monster* monster );

//检查玩家是否升级，更新数据
void checkPlayer ( Hero* player, int floorLevel );

//去商店
void goToTheShop ( Backpacking* backpacking, HealthPot* healthPot, Shield* shield, Sword* sword );

//点击背包按钮
void clickBackpacking ( Hero* hero, Backpacking* backpacking, Sword* sword, Shield* shield, HealthPot* healthPot );
//商店和背包展示金钱和物品
void shopAndBackpackingShowMoneyAndGoods ( Backpacking* backpacking );

//显示属性信息
void showAttribute ( Hero* hero, int level );

//本层剑、盾和血瓶的属性
void changeShieldSwordAndHealthPot ( Shield* shield, Sword* sword, HealthPot* healthPot, int level );

//展示怪物的详细信息
void showMonsterInformation ( IMAGE monsterImage, Monster* monster );

//攻击boss
void hitBoss ( Hero* hero, Boss* boss );

//展示boss属性
void showBoss ( Boss* boss );

int main ( ) {
	initgraph ( Width, Hight );   
	setbkcolor ( WHITE );
	settextcolor ( BLACK );
	cleardevice ( );
	settextstyle ( 25, 0, _T("黑体") );
	int graphInformation [3][4] = { 0 };			// 0为空 1代表怪1, 2代表怪2, 3代表怪3，4血，5经验，6剑/盾(11)，7通道/商店(10)，8下一层，9陷阱（减少10%血）
																	// 通道（10%出现）可以直接前往第51层（5%）或者后退10层（95%）
																	// 商店（90%出现和通道互斥）
																	// 5个小怪，2个血瓶，1个经验瓶，1个下一层，1个装备，1个陷阱，1个通道/商店
																	//1怪1，2怪2，2怪3

	//图片变量


	IMAGE firstPhotograph;				//初始进入游戏界面
	IMAGE storyPhotograph;			//游戏故事说明画面
	IMAGE winPhotography;				//胜利画面
	IMAGE losePhotography;			//失败画面

	IMAGE unOpenFloorPhotograph;		//未点开的地板
	IMAGE monsterPhotograph[4];				//小怪1,2,3,4
	IMAGE shopPhotograph;					//商店
	IMAGE shieldPhotograph;					//盾牌
	IMAGE swordPhotograph;					//剑
	IMAGE healthPotPhotograph;				//血瓶
	IMAGE expPotPhotograph;					//经验瓶
	IMAGE travelPhotograph;					//通道
	IMAGE trapPhotograph;						//陷阱
	IMAGE nextFloorPhotograph;				//下一层

	IMAGE graphDisplayPhotograph;		//普通层显示界面   
	IMAGE shopDisplayPhotograph;			//商店层显示界面
	IMAGE bossDisplayPhotograph;			//boss层显示界面
	IMAGE backpackingPhotograph;		//背包显示界面

	//对象
	Boss boss ( 1500, 1500, 500, 100 );
	Backpacking backpacking ( 0, 0, 0, 0 );
	HealthPot healthPot ( 15, 2 );
	Hero hero ( 100, 100, 10, 3, 0, 100, 1 );
	//怪物1攻击上涨0.2，怪物2攻击的50%变为守，怪物3血上涨0.5
	Monster monster [4];										//monster[0]弃用
	Shield shield ( 0, 0, 1 );
	Sword sword ( 0, 0, 1 );

	//常用变量
	int floorLevel = 0;							//层数
	int playerAttack;						//玩家本层攻击
	int playerDefence;					//玩家本层防御
	int playerImmediateBlood;		//玩家即时血量
	int playerImmediateExp;			//玩家即时经验，只有前往下一层时可以升级	

	//鼠标
	MOUSEMSG mouse;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//读入图片   图片文件在D:\DungeonPhotograph下D:\\DungeonPhotograph\\ .png
	loadimage ( &firstPhotograph, _T ( "D:\\DungeonPhotograph\\firstPhotograph.png" ), Width, Hight );
	loadimage ( &storyPhotograph, _T ( "D:\\DungeonPhotograph\\storyPhotograph.png" ), Width, Hight );
	loadimage ( &winPhotography, _T ( "D:\\DungeonPhotograph\\winPhotography.png" ), Width, Hight );
	loadimage ( &losePhotography, _T ( "D:\\DungeonPhotograph\\losePhotography.png" ), Width, Hight );
	loadimage ( &unOpenFloorPhotograph, _T ( "D:\\DungeonPhotograph\\unOpenFloorPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &monsterPhotograph[1], _T ( "D:\\DungeonPhotograph\\monster1Photograph.png" ), sideLength1, sideLength1 );
	loadimage ( &monsterPhotograph[2], _T ( "D:\\DungeonPhotograph\\monster2Photograph.png" ), sideLength1, sideLength1 );
	loadimage ( &monsterPhotograph[3], _T ( "D:\\DungeonPhotograph\\monster3Photograph.png" ), sideLength1, sideLength1 );
	loadimage ( &shopPhotograph, _T ( "D:\\DungeonPhotograph\\shopPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &shieldPhotograph, _T ( "D:\\DungeonPhotograph\\shieldPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &swordPhotograph, _T ( "D:\\DungeonPhotograph\\swordPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &healthPotPhotograph, _T ( "D:\\DungeonPhotograph\\healthPotPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &expPotPhotograph, _T ( "D:\\DungeonPhotograph\\expPotPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &travelPhotograph, _T ( "D:\\DungeonPhotograph\\travelPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &trapPhotograph, _T ( "D:\\DungeonPhotograph\\trapPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &nextFloorPhotograph, _T ( "D:\\DungeonPhotograph\\nextFloorPhotograph.png" ), sideLength1, sideLength1 );
	loadimage ( &graphDisplayPhotograph, _T ( "D:\\DungeonPhotograph\\graphDisplayPhotograph.png" ), Width, Hight );
	loadimage ( &shopDisplayPhotograph, _T ( "D:\\DungeonPhotograph\\shopDisplayPhotograph.png" ), Width, Hight );
	loadimage ( &bossDisplayPhotograph, _T ( "D:\\DungeonPhotograph\\bossDisplayPhotograph.png" ), Width, Hight );
	loadimage ( &backpackingPhotograph, _T ( "D:\\DungeonPhotograph\\backpackingPhotograph.png" ), Width, Hight );
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
	putimage ( 0, 0, &firstPhotograph );		//展示初始化界面画面
 
	//判断鼠标是否点击到初始开始
	

	//bool nextYes = false;
	//while ( 1 ) {
	//	mouse = GetMouseMsg ( );
	//	if ( mouse.mkLButton ) {
	//		if ( mouse.x >= beginLeftX && mouse.x <= beginRightX && mouse.y <= beginLowY && mouse.y >= beginHighY ) {
	//			nextYes = true;
	//			break;
	//		} else if ( mouse.x >= outLeftX && mouse.x <= outRightX && mouse.y <= outLowY && mouse.y >= outHighY ) {
	//			nextYes = false;
	//			break;
	//		}
	//	}
	//}
	//if ( nextYes == false )		//点击"退出"直接退出程序
	//	return 0;
	

	//游戏开始
	putimage ( X0, Y0, &storyPhotograph );						//展示故事画面
	bool playerDead = false;
	int mouseX, mouseY;
	do {

		playerImmediateBlood = hero.getImmediateBlood ( );
		playerAttack = hero.getBasicAttack ( );
		playerDefence = hero.getBasicDefence ( );
		playerImmediateExp = hero.getImmeditateExp ( );
		floorLevel++;
		checkPlayer ( &hero, floorLevel );
		changeShieldSwordAndHealthPot ( &shield, &sword, &healthPot, floorLevel );
		Sleep ( 2000 );
		clearpolygon ( displayPoint, 4 );

		if ( floorLevel < 50 ) {
			putimage ( X0, Y0, &graphDisplayPhotograph );		//普通层展示
			showAttribute ( &hero, floorLevel );
			changeThisFloorMonsterInformation ( &monster [1], floorLevel, 1 );
			changeThisFloorMonsterInformation ( &monster [2], floorLevel, 2 );
			changeThisFloorMonsterInformation ( &monster [3], floorLevel, 3 );

			bool clickNextFloor = false;   //检测是否点击“下一层”
			bool firstClickGraph [4][3] = { 0 };
			int graphNumberX, graphNumberY;		//用于保存鼠标坐标位于普通曾界面的哪个格子
			newFloorInformation ( graphInformation );

			while ( clickNextFloor == false ) {
				clearpolygon ( displayFourPoint, 4 );
				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 0; j < 3; j++ ) {
						if ( firstClickGraph [i][j] == 0 ) {		//还没翻开 
							putimage ( X0 + sideLength1 * j, Y0 + sideLength1 * i, &unOpenFloorPhotograph );
						} else {
							if ( graphInformation [i][j] < 4 && graphInformation [i][j] > 0 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &monsterPhotograph [graphInformation [i][j]] );
							} else if ( graphInformation [i][j] == 4 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &healthPotPhotograph );
							} else if ( graphInformation [i][j] == 5 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &expPotPhotograph );
							} else if ( graphInformation [i][j] == 6 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &swordPhotograph );
							} else if ( graphInformation [i][j] == 7 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &travelPhotograph );
							} else if ( graphInformation [i][j] == 8 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &nextFloorPhotograph );
							} else if ( graphInformation [i][j] == 10 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &shopPhotograph );
							} else if ( graphInformation [i][j] == 11 ) {
								putimage ( X0 + sideLength1 * i, Y0 + sideLength1 * j, &shieldPhotograph );
							}
						}
					}
				}
				do {
					mouse = GetMouseMsg ( );
					mouseX = mouse.x;
					mouseY = mouse.y;
				} while ( !mouse.mkLButton && !mouse.mkRButton );
				if ( mouse.mkLButton ) {
					graphNumberX = mouseX / 100;
					graphNumberY = mouseY / 100;
					showAttribute ( &hero, floorLevel );		//每次刷新玩家属性值
					if ( mouseY < 400 ) {							//鼠标点击的在12格子内部
						if ( firstClickGraph [graphNumberX][graphNumberY] == 0 ) {
							firstClickGraph [graphNumberX][graphNumberY] = 1;
							Sleep ( 100 );
							clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );	//清除点击的格子上的图片
							if ( graphInformation [graphNumberX][graphNumberY] > 0 && graphInformation [graphNumberX][graphNumberY] < 4 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &monsterPhotograph [graphInformation [graphNumberX][graphNumberY]] );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 4 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &healthPotPhotograph );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 5 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &expPotPhotograph );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 6 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &swordPhotograph );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 7 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &travelPhotograph );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 8 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &nextFloorPhotograph );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 9 ) {   //碰到陷阱立即扣血
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &trapPhotograph );
								playerImmediateBlood -= ( hero.getBasicTotalBlood ( ) * 0.9 );
								hero.newImmediateBlood ( playerImmediateBlood );
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
								graphInformation [graphNumberX][graphNumberY] = 0;
							} else if ( graphInformation [graphNumberX][graphNumberY] == 10 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &shopPhotograph );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 11 ) {
								putimage ( X0 + sideLength1 * graphNumberX, Y0 + sideLength1 * graphNumberY, &shieldPhotograph );
							}

						} else {

							if ( graphInformation [graphNumberX][graphNumberY] < 4 && graphInformation [graphNumberX][graphNumberY] > 0 ) {		//打怪
								hitTheMonster ( &hero, &monster [graphInformation [graphNumberX][graphNumberY]] );
								playerImmediateBlood = hero.getImmediateBlood ( );
								if ( monster [graphInformation [graphNumberX][graphNumberY]].getImmediateBlood ( ) <= 0 ) {			//玩家击败怪物
									hero.changeImmeditateExp ( monster [graphInformation [graphNumberX][graphNumberY]].getExp ( ) );
									graphInformation [graphNumberX][graphNumberY] = 0;				//这个格子变为空
									Sleep ( 100 );
									clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
									if ( monster [graphInformation [graphNumberX][graphNumberY]].getDeadLeft ( ) == 1 ) {					//可放入背包的血瓶
										Sleep ( 10 );
										putimage ( sideLength1 * graphNumberX, sideLength1 * graphNumberY, &healthPotPhotograph );
										Sleep ( 1000 );
										clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
										backpacking.changeHealthPotNumber ( 1 );
									} else {
										int randNumber = 0;
										randNumber = rand ( ) % 2;
										if ( randNumber == 1 ) {									//剑
											Sleep ( 10 );
											putimage ( sideLength1 * graphNumberX, sideLength1 * graphNumberY, &swordPhotograph );
											Sleep ( 1000 );
											clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
											backpacking.changeSwordNumber ( 1 );
										} else {																//盾
											Sleep ( 10 );
											putimage ( sideLength1 * graphNumberX, sideLength1 * graphNumberY, &shieldPhotograph );
											Sleep ( 1000 );
											clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
											backpacking.changeShieldNumber ( 1 );
										}
									}
									changeThisFloorMonsterInformation ( &monster [graphInformation [graphNumberX][graphNumberY]], floorLevel, graphInformation [graphNumberX][graphNumberY] );
								} else if ( playerImmediateBlood <= 0 ) {				//玩家死亡
									playerDead = true;
									break;
								}
							} else if ( graphInformation [graphNumberX][graphNumberY] == 4 ) {						//直接加血
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
								playerImmediateBlood += healthPot.getBlood ( );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 5 ) {						//直接加经验
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
								playerImmediateExp += monster [1].getExp ( );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 6 ) {						//剑
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
								backpacking.changeSwordNumber ( 1 );
							} else if ( graphInformation [graphNumberX][graphNumberY] == 7 ) {						//通道
								int randNumber = 0;
								randNumber = rand ( ) % 100;
								if ( randNumber > 5 ) {   //后退10层
									if ( floorLevel > 10 ) {
										floorLevel -= 11;
										clickNextFloor = true;
									} else {
										floorLevel = 0;
										clickNextFloor = true;
									}
								} else {								//直达50层
									floorLevel = 50;
									clickNextFloor = true;
								}
							} else if ( graphInformation [graphNumberX][graphNumberY] == 8 ) {					//下一层
								clickNextFloor = true;
							} else if ( graphInformation [graphNumberX][graphNumberY] == 10 ) {					//商店
								clearpolygon ( displayPoint, 4 );			
								putimage ( X0, Y0, &shopPhotograph );
								showAttribute ( &hero, floorLevel );
								goToTheShop ( &backpacking, &healthPot, &shield, &sword );

								clickNextFloor = true;
							} else if ( graphInformation [graphNumberX][graphNumberY] == 11 ) {					//盾
								Sleep ( 100 );
								clearpolygon ( displayEachGridPoint [graphNumberX][graphNumberY], 4 );
								backpacking.changeShieldNumber ( 1 );
							}
						}

					} else if ( mouseX >= backpackingX && mouseX <= backpackingX + backpackingWidth&& mouseY >= backpackingY && mouseY <= backpackingY + backpackingHight ) {
					
						clearpolygon ( displayPoint, 4 );
						putimage ( X0,Y0, &backpackingPhotograph );
						showAttribute ( &hero, floorLevel );
						clickBackpacking ( &hero, &backpacking, &sword, &shield, &healthPot );
					
					}

				} else if ( mouse.mkRButton ) {					//查看2s怪物的详细信息

					graphNumberX = mouseX / 100;
					graphNumberY = mouseY / 100;
					if ( mouseY < 400 ) {			//鼠标在12个格子范围内
						if ( graphInformation [graphNumberX][graphNumberY] < 4 && graphInformation [graphNumberX][graphNumberY] > 0 ) {		//鼠标停留在怪物上
							clearpolygon ( displayFourPoint, 4 );
							showMonsterInformation ( monsterPhotograph [graphInformation [graphNumberX][graphNumberY]], &monster [graphInformation [graphNumberX][graphNumberY]] );
							clearpolygon ( displayFourPoint, 4 );
						}
					}

				}

			}


		} else if ( floorLevel == 50 ) {    //最终商店

			goToTheShop ( &backpacking, &healthPot, &shield, &sword );
			
		}else	{   //boss
			//const int bossX = 25;							const int bossY = 2;
			//const int bossWidth = 175;					const int bossHigh = 225;
			//const int bossBloodX = 50;					const int bossBloodY = 225;
			//const int bossBeHittedTimesX = 50;		const int bossBeHittedTimesY = 250;
			bool bossDead = false;
			clearpolygon ( displayPoint, 4 );
			putimage ( X0, Y0, &bossDisplayPhotograph );
			
			while ( ( bossDead == false ) && ( playerDead == false ) ) {
				
				mouse = GetMouseMsg ( );
				mouseX = mouse.x;
				mouseY = mouse.y;
				if ( mouseX > bossX && mouseX < bossX + bossWidth && mouseY > bossY && mouseY < bossY + bossHigh ) {		//打boss
					hitBoss ( &hero, &boss );
					playerDead = ( hero.getImmediateBlood ( ) > 0 ) ? false : true;
					bossDead = ( boss.getImmediateBlood ( ) > 0 ) ? false : true;
				}else if ( mouseX >= backpackingX && mouseX <= backpackingX + backpackingWidth && mouseY >= backpackingY && mouseY <= backpackingY + backpackingHight ) {

					clearpolygon ( displayPoint, 4 );
					putimage ( X0, Y0, &backpackingPhotograph );
					showAttribute ( &hero, floorLevel );
					clickBackpacking ( &hero, &backpacking, &sword, &shield, &healthPot );
					clearpolygon ( displayPoint, 4 );
					putimage ( X0, Y0, &bossDisplayPhotograph );
				}
			}

		}
	} while ( ( playerDead == false ) && floorLevel < 52 );
	clearpolygon ( displayPoint, 4 );
	if ( playerDead == false )
		putimage ( X0, Y0, &winPhotography );
	else
		putimage ( X0, Y0, &losePhotography );
	Sleep ( 3000 );
	closegraph ( );
	return 0;
}

void newFloorInformation ( int graphInformation [3][4] ) {
	// 0为空 1代表怪1, 2代表怪2, 3代表怪3，4血，5经验，6剑/盾(11)，7通道/商店(10)，8下一层，9陷阱（减少10%血）
	// 通道（10%出现）可以直接前往第51层（5%）或者后退10层（95%）
	// 商店（90%出现和通道互斥）
	// 5个小怪，2个血瓶，1个经验瓶，1个下一层，1个装备，1个陷阱，1个通道/商店
	//1怪1，2怪2，2怪3
	int information [10] = { 0, 1, 2, 2, 2, 1, 1, 1, 1, 1 };
	int total = 12;
	int i = 0;
	int r = 0;
	int c = 0;
	for ( ; total; ) {
		i = rand ( ) % 9 + 1;
		if ( information [i] > 0 ) {
			graphInformation [r++][c] = i;
			information [i]--;
			if ( i == 6 ) { 
				i = rand ( ) % 2;
				if( i ==1 )
					graphInformation [r - 1][c] = 11;
			} else if ( i == 7 ) {			//判断是通道还是商店
				i = rand ( ) % 100;
				if ( i > 4 )
					graphInformation [r - 1][c] = 10;
			}
			if ( r == 3 ) {
				r = 0;
				c++;
			}
			total--;
		}
	}
}
void changeThisFloorMonsterInformation ( Monster* monster, int level, int monsterKind ) {
	monster->newBasicDefence ( 0 );
	int randNumber = 0;
	randNumber = rand ( ) % 4 - 2;
	double blood = ( level / 10 + 1 ) * 1.5 * ( 100 + randNumber );
	if ( monsterKind == 3 )
		blood *= 1.5;
	monster->newBasicTotalBlood ( blood );
	monster->newImmediateBlood ( monster->getBasicTotalBlood ( ) );
	randNumber = rand ( ) % 20 - 10;
	double attack = ( level / 10 + 1 ) * 0.1 * ( 100 + randNumber );
	if ( monsterKind == 1 ) 
		attack *= 1.2;
	else if ( monsterKind == 2 ) {
		attack *= 0.5;
		monster->newBasicDefence ( attack );
	}
	monster->newBasicAttack ( attack );
	monster->newExp ( level / 10 + 10 );
	randNumber = rand ( ) % 2 + 1;
	monster->newDeadLeft ( randNumber );
}

void goToTheShop ( Backpacking* backpacking, HealthPot* healthPot, Shield* shield, Sword* sword ) {
	bool clickNext = false;
	MOUSEMSG mouse;
	int mouseX, mouseY;
	while ( clickNext == false ) {
		shopAndBackpackingShowMoneyAndGoods ( backpacking );
		mouse = GetMouseMsg ( );
		mouseX = mouse.x;
		mouseY = mouse.y;
		if ( mouseX >= shopAndBackpackingGoodsX && mouseX <= shopAndBackpackingGoodsX + sideLength1 ) {				//买卖剑、盾、血瓶
			if ( mouseY >= shopAndBackpackingSwordY && mouseY <= shopAndBackpackingSwordY + sideLength1 ) {
				if ( mouse.mkLButton ) {														//左键买
					if ( backpacking->getMoney ( ) >= 2 * sword->getValue ( ) ) {
						backpacking->changeMoney ( -2 * sword->getValue ( ) );
						backpacking->changeSwordNumber ( 1 );
					}
				} else if ( mouse.mkRButton ) {											//右键卖
					if ( backpacking->getSwordNumber ( ) > 0 ) {
						backpacking->changeSwordNumber ( -1 );
						backpacking->changeMoney ( sword->getValue ( ) );
					}
				}
			}else if ( mouseY >= shopAndBackpackingShieldY && mouseY <= shopAndBackpackingShieldY + sideLength1 ) {
				if ( mouse.mkLButton ) {
					if ( backpacking->getMoney ( ) >= shield->getValue ( ) * 2 ) {
						backpacking->changeMoney ( -2 * shield->getValue ( ) );
						backpacking->changeShieldNumber ( 1 );
					}
				} else if ( mouse.mkRButton ) {
					if ( backpacking->getSwordNumber ( ) > 0 ) {
						backpacking->changeShieldNumber ( -1 );
						backpacking->changeMoney ( shield->getValue ( ) );
					}
				}
			}else if ( mouseY >= shopAndBackpackingHealthPotY && mouseY <= shopAndBackpackingHealthPotY + sideLength1 ) {
				if ( mouse.mkLButton ) {
					if ( backpacking->getMoney ( ) > 3 ) {
						backpacking->changeMoney ( -4 );
						backpacking->changeHealthPotNumber ( 1 );
					}
				} else if ( mouse.mkRButton ) {
					if ( backpacking->getHealthPotNumber ( ) > 0 ) {
						backpacking->changeHealthPotNumber ( -1 );
						backpacking->changeMoney ( 2 );
					}
				}
			}
		} else if ( mouseX <= shopAndBackpackingButtonX && mouseX >= shopAndBackpackingButtonX + shopAndBackpackingButtonWidth
			&& mouseY >= shopAndBackpackingButtonY && mouseY <= shopAndBackpackingButtonY + shopAndBackpackingButtonHight && mouse.mkLButton )		
			//左键下一层
			clickNext = true;
	}
}

void changeShieldSwordAndHealthPot ( Shield* shield, Sword* sword, HealthPot* healthPot, int level ) {
	if ( level < 10 )
		healthPot->newBlood ( 15 );
	else if ( level < 20 )
		healthPot->newBlood ( 50 );
	else
		healthPot->changeBlood ( 50 );
	if ( level < 20 ) {
		shield->newAttack ( 6 );
		shield->newDefence ( 1 );
		shield->newAttack ( 1 );
		shield->newDefence ( 4 );
	} else if ( level < 40 ) {
		shield->newAttack ( 15 );
		shield->newDefence ( 2 );
		shield->newAttack ( 2 );
		shield->newDefence ( 10 );
	} else if ( level < 50 ) {
		shield->newAttack ( 30 );
		shield->newDefence ( 5 );
		shield->newAttack ( 5 );
		shield->newDefence ( 20 );
	} else {
		shield->newAttack ( 50 );
		shield->newDefence ( 10 );
		shield->newAttack ( 10 );
		shield->newDefence ( 30 );
	}
}

void hitTheMonster ( Hero* hero, Monster* monster ) {
	int decreaseBlood;
	decreaseBlood = monster->getBasicAttack ( ) - hero->getBasicDefence ( );
	hero->changeImmediateBlood ( -decreaseBlood );
	decreaseBlood = hero->getBasicAttack ( ) - monster->getBasicDefence ( );
	monster->changeImmediateBlood ( -decreaseBlood );
}
void checkPlayer ( Hero* player, int floorLevel ) {
	if ( player->getImmeditateExp ( ) >= player->getTotalExp ( ) ) {				//可以升级
		player->changeBasicAttack ( ( 1 + floorLevel / 20 ) * 5 );
		player->changeBasicDefence ( ( 1 + floorLevel / 20 ) * 2 );
		player->changeBasicTotalBlood ( ( 1 + floorLevel / 20 ) * 20 );
		player->newImmediateBlood ( player->getBasicTotalBlood ( ) );
		player->changeImmeditateExp ( player->getImmeditateExp ( ) - player->getTotalExp ( ) );
		player->newTotalExp ( );
	}
}
void clickBackpacking ( Hero* hero, Backpacking* backpacking, Sword* sword, Shield* shield, HealthPot* healthPot ) {
	MOUSEMSG mouse;
	bool clickReturn = false;
	shopAndBackpackingShowMoneyAndGoods ( backpacking );
	int mouseX, mouseY;
	while ( clickReturn == false ) {
		mouse = GetMouseMsg ( );
		mouseX = mouse.x;
		mouseY = mouse.y;
		if ( mouseX >= shopAndBackpackingGoodsX && mouseX <= shopAndBackpackingGoodsX + sideLength1 ) {
			if ( mouseY >= shopAndBackpackingSwordY && mouseY <= shopAndBackpackingSwordY + sideLength1 ) {
				if ( backpacking->getSwordNumber ( ) > 0 ) {						//剑的数量大于0
					if ( mouse.mkLButton ) {												//左键剑
						if ( hero->getWithSword ( ) == 0 ) {
							hero->changeBasicAttack ( sword->getAttack ( ) );
							hero->changeBasicDefence ( sword->getDefence ( ) );
							backpacking->changeSwordNumber ( -1 );
							hero->changeWithSword ( );
						}
					}
				}
			} else if ( mouseY >= shopAndBackpackingShieldY && mouseY <= shopAndBackpackingShieldY + sideLength1 ) { 
				if ( backpacking->getShieldNumber ( ) > 0 ) {
					if ( mouse.mkLButton ) {												//左键盾
						if ( hero->getWithShield ( ) == 0 ) {
							hero->changeBasicAttack ( shield->getAttack ( ) );
							hero->changeBasicDefence ( shield->getDefence ( ) );
							backpacking->changeShieldNumber ( -1 );
							hero->changeWithShield ( );
						}
					}
				}
			}else  if ( mouseY >= shopAndBackpackingShieldY && mouseY <= shopAndBackpackingShieldY + sideLength1 ) {
				if ( backpacking->getHealthPotNumber ( ) > 0 ) {
					if ( mouse.mkLButton ) {												//左键喝血瓶
						hero->changeImmediateBlood ( healthPot->getBlood ( ) );
					}
				}
			}
		} else if ( mouseX >= shopAndBackpackingButtonX && mouseX <= shopAndBackpackingButtonX + shopAndBackpackingButtonWidth ) 
			if ( mouseY >= shopAndBackpackingButtonY && mouseY <= shopAndBackpackingButtonY + shopAndBackpackingButtonHight ) 
				clickReturn = true;
	}
}

void showAttribute ( Hero* hero, int level ) {
	clearpolygon ( clearBlood, 4 );
	clearpolygon ( clearAttack, 4 );
	clearpolygon ( clearDefence, 4 );
	clearpolygon ( clearExp, 4 );
	clearpolygon ( clearLevel, 4 );
	TCHAR number [20];
	swprintf_s ( number, _T ( "%d/%d" ), hero->getImmediateBlood ( ), hero->getBasicTotalBlood ( ) );
	outtextxy ( bloodX, bloodY, number );
	swprintf_s ( number, _T ( "%d" ), hero->getBasicAttack ( ) );
	outtextxy ( attackX, attackY, number );
	swprintf_s ( number, _T ( "%d" ), hero->getBasicDefence ( ) );
	outtextxy ( defenceX, defenceY, number );
	swprintf_s ( number, _T ( "%d/%d" ), hero->getImmeditateExp ( ), hero->getTotalExp ( ) );
	outtextxy ( expX, expY, number );
	swprintf_s ( number, _T ( "%d" ), level );
	outtextxy ( floorLevelX, floorLevelY, number );
	swprintf_s ( number, _T ( "%d" ), hero->getLevel ( ) );
	outtextxy ( levelX, levelY, number );
}

void shopAndBackpackingShowMoneyAndGoods ( Backpacking* backpacking ) {
	TCHAR s [20];
	clearpolygon ( moneyPolygon, 4 );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getMoney ( ) );
	outtextxy ( shopAndBackpackingShowMoneyX, shopAndBackpackingShowMoneyY, s );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getHealthPotNumber ( ) );
	outtextxy ( shopAndBackpackingGoodsNumberX, shopAndBackpackingHealthPotNumberY, s );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getShieldNumber ( ) );
	outtextxy ( shopAndBackpackingGoodsNumberX, shopAndBackpackingShieldNumberY, s );
	_stprintf_s ( s, _T ( "%d" ), backpacking->getSwordNumber ( ) );
	outtextxy ( shopAndBackpackingGoodsNumberX, shopAndBackpackingSwordNumberY, s );
}

void showMonsterInformation ( IMAGE monsterImage, Monster* monster ){
	putimage ( 1, 1, &monsterImage );
	TCHAR s [20];
	_stprintf_s ( s, _T ( "血量：%d/%d" ), monster->getImmediateBlood ( ), monster->getBasicTotalBlood ( ) );
	outtextxy ( monsterInformationX, monsterInformationBloodY, s );
	_stprintf_s ( s, _T ( "攻击：%d" ), monster->getBasicAttack ( ) );
	outtextxy ( monsterInformationX, monsterInformationAttackY, s );
	_stprintf_s ( s, _T ( "防守：%d" ), monster->getBasicDefence ( ) );
	outtextxy ( monsterInformationX, monsterInformationDefenceY, s );
	Sleep ( 2000 );
}
void showBoss ( Boss* boss ) {
	//const int bossX = 25;							const int bossY = 2;
	//const int bossWidth = 175;					const int bossHigh = 225;
	//const int bossBloodX = 50;					const int bossBloodY = 225;
	//const int bossBeHittedTimesX = 50;		const int bossBeHittedTimesY = 250;
	TCHAR s [20];
	clearpolygon ( bossInformationPoint, 4 );
	_stprintf_s ( s, _T ( "%d/%d" ), boss->getImmediateBlood ( ), boss->getBasicTotalBlood ( ) );
	outtextxy ( bossBloodX, bossBloodY, s );
	_stprintf_s ( s, _T ( "%d" ), boss->getBeHatedTimes ( ) );
	outtextxy ( bossBeHittedTimesX, bossBeHittedTimesY, s );
}
void hitBoss ( Hero* hero, Boss* boss ) {
	boss->addBeHatedTimes ( );
	boss->changeImmediateBlood ( hero->getBasicAttack ( ) - boss->getBasicDefence ( ) );
	hero->changeImmediateBlood ( boss->getBasicAttack ( ) - hero->getBasicDefence ( ) );
	if ( boss->getBeHatedTimes ( ) == 5 ) {				//boss被攻击5次，自己攻击一次，减少玩家目前血量50%
		hero->newImmediateBlood ( 0.5 * ( hero->getImmediateBlood ( ) ) );
		boss->resetBeHatedTimes ( );
		if ( boss->getImmediateBlood ( ) < 200 )		//如果此时血量小于200则加血300
			boss->changeImmediateBlood ( 300 );
	}
}
