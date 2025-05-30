#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h."
#include "../main-project/internet_protocol.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{



	internet_protocol* build_subscription(int beg_h, int beg_m, int beg_s, int end_h, int end_m, int end_s,int byterecived, int bytesend, char* fileway)
	{
		internet_protocol* subscription = new internet_protocol;
		subscription->begin.hours = beg_h;
		subscription->begin.minutes = beg_m;
		subscription->begin.seconds = beg_s;
		subscription->end.hours = end_h;
		subscription->end.minutes = end_m;
		subscription->end.seconds = end_s;
		subscription->byterecived = byterecived;
		subscription->bytesend = bytesend;
		strcpy_s( subscription->fileway, fileway);
		return subscription;
	}

	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)	
		{
			internet_protocol* subscriptions[4];
			subscriptions[0] = build_subscription(00, 0, 19, 1, 0, 55, 3145728, 1572864, "C:\\Program Files\\Thunderbird\\thunderbird.exe");
			subscriptions[1] = build_subscription(0, 4, 20, 1, 05, 40, 1048576 ,524288 ,"C:\\Program Files\\CCleaner\\ccleaner.exe");
			subscriptions[2] = build_subscription(0, 12, 45, 7, 23, 55, 2097152, 786432 ,"C:\\Program Files\\Notepad++\\notepad++.exe");
			subscriptions[3] = build_subscription(0, 55, 50, 2, 10, 50, 5242880, 2621440, "C:\\Program Files\\WinRAR\\winrar.exe");
			Assert::AreEqual(3636, process(subscriptions, 4, "C:\\Program Files\\Thunderbird\\thunderbird.exe"));


		}
		TEST_METHOD(TestMethod2)
		{
			internet_protocol* subscriptions[5];
			subscriptions[0]= build_subscription(0,0,0, 0, 0, 1, 5242880, 1048576, "C:\\Program Files\\Firefox\\Firefox.exe");
			subscriptions[1]= build_subscription(0, 0, 0, 0, 0, 1, 1572864, 786432, "C:\\Program Files\\Telegram\\Telegram.exe");
			subscriptions[2]= build_subscription(0, 0, 0, 0, 0, 1, 2097152, 524288, "C:\\Program Files\\Steam\\Steam.exe");
			subscriptions[3]= build_subscription(0, 0, 0, 0, 0, 1, 7864320, 2621440, "C:\\Program Files\\Chrome\\Chrome.exe");
			subscriptions[4]= build_subscription(0, 0, 0, 1, 0, 1, 3145728, 1572864, "C:\\Program Files\\Steam\\Steam.exe");
		////	delete_subscription(subscriptions, 5);
			Assert::AreEqual(3602, process(subscriptions, 5, "C:\\Program Files\\Steam\\Steam.exe"));
		}
		TEST_METHOD(TestMethod3)
		{
			internet_protocol* subscriptions[4];
			subscriptions[0]= build_subscription(0,0 , 10 ,0 , 30 , 55, 2621440, 1310720, "C:\\Program Files\\Outlook\\outlook.exe");
			subscriptions[1]= build_subscription(0,0 , 20 ,0 , 05 , 40, 1048576, 524288, "C:\\Program Files\\Zoom\\zoom.exe");
			subscriptions[2]= build_subscription(0,0 , 45 ,0 , 1 , 10, 4194304, 2097152, "C:\\Program Files\\Discord\\discord.exe");
			subscriptions[3]= build_subscription(0,0 , 50 ,0 , 2 , 30, 3145728, 1048576, "C:\\Program Files\\Discord\\discord.exe");
			Assert::AreEqual(125, process(subscriptions, 4, "C:\\Program Files\\Discord\\discord.exe"));
		}
		TEST_METHOD(TestMethod4)
		{
			internet_protocol* subscriptions[5];/////////////////////////////////////////
			subscriptions[0] = build_subscription(0,0 , 15, 0, 1 , 40, 1048576 ,524288, "C:\\Windows\System32\\svchost.exe");
			subscriptions[1] = build_subscription(8,45 , 20, 9 , 30 , 10, 2097152 ,1048576 ,"C:\\Program Files\\VSCode\\code.exe");
			subscriptions[2] = build_subscription(11,20 , 35 ,12 , 15 , 25, 3145728 ,1572864 ,"C:\\Program Files\\Adobe\\acrobat.exe");
			subscriptions[3] = build_subscription(14,0 , 50 ,14 , 05 , 51, 5242880, 2621440 ,"C:\\Windows\System32\\svchost.exe");
			subscriptions[4] = build_subscription(17,20 , 15 ,17 , 25 , 15, 786432, 393216 ,"C:\\Windows\System32\\svchost.exe");
			Assert::AreEqual(686, process(subscriptions, 5, "C:\\Windows\System32\\svchost.exe"));

		}
		TEST_METHOD(TestMethod5)
		{
			internet_protocol* subscriptions[4];
			subscriptions[0] = build_subscription(00, 0, 10, 0, 0, 55, 2621440, 1310720, "C:\Program Files\Discord\discord.exe");
			subscriptions[1] = build_subscription(0, 0, 20, 0, 05, 40, 1048576, 524288, "C:\Program Files\Discord\discord.exe");
			subscriptions[2] = build_subscription(0, 0, 45, 0, 0, 55, 4194304, 2097152, "C:\Program Files\Discord\discord.exe");
			subscriptions[3] = build_subscription(0, 00, 50, 0, 10, 50, 3145728, 1048576, "C:\Program Files\Discord\discord.exe");
			Assert::AreEqual(975, process(subscriptions, 4, "C:\Program Files\Discord\discord.exe"));

		}
		//TEST_METHOD(TestMethod6)
		//{
		//	internet_protocol* subscriptions[5];
		//	subscriptions[0] = build_subscription(07, 45, 10, 8, 30, 55, 2621440, 1310720, "C:\Program Files\Outlook\outlook.exe");
		//	subscriptions[1] = build_subscription(9, 15, 20, 10, 05, 40, 1048576, 524288, "C:\Program Files\Zoom\zoom.exe");
		//	subscriptions[2] = build_subscription(12, 30, 45, 13, 45, 10, 4194304, 2097152, "C:\Program Files\Discord\discord.exe");
		//	subscriptions[3] = build_subscription(18, 05, 50, 19, 15, 30, 3145728, 1048576, "C:\Program Files\Discord\discord.exe");
		//}
	};
}
