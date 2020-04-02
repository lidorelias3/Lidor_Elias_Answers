#include <windows.h>
#include <stdio.h>

int check = 0;
HHOOK keyboard;
KBDLLHOOKSTRUCT kbdHookStruct;

void send_str()
{
	wchar_t* str = L"זאזי בזאזי ";
	int i = 0;
	INPUT ip;
	HKL kbl = GetKeyboardLayout(0);
	
	check = 1;
	
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0;

	/*For each char in str*/
	for (i = 0; i < wcslen(str); ++i)
	{
		/*Send the keystroke*/
		ip.ki.dwFlags = KEYEVENTF_UNICODE;
		ip.ki.wScan = str[i];
		SendInput(1, &ip, sizeof(INPUT));

		/*Release the key*/
		ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
	}

	check = 0;
}


LRESULT __stdcall callBack(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		/*Get information about keyboard input*/
		kbdHookStruct = *((KBDLLHOOKSTRUCT*)lParam);
		if (wParam == WM_KEYDOWN && check == 0) {
			/*Convert to char*/
			char c = MapVirtualKey(kbdHookStruct.vkCode, MAPVK_VK_TO_CHAR);
			/*If char is printable*/
			if (32 <= c && c <= 156)
			{
				send_str();
			}
			else
			{
				/*Ignore and send it to the next hook*/
				return CallNextHookEx(keyboard, nCode, wParam, lParam);
			}
		}
	}
}


int main()
{
	MSG msg;
	/*Hook to keyboard*/
	keyboard = SetWindowsHookEx(WH_KEYBOARD_LL, callBack, NULL, 0);
	
	/*Retriving message from calling thread queue*/
	while (TRUE)
	{
		GetMessage(&msg, NULL, 0, 0);
	}
}