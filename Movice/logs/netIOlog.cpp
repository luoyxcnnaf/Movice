#include "stdafx.h"
#include <windows.h>
#include "netIOlog.h"
#include "Shlwapi.h"

char _dbgtemp[102400];
char _xmltemp[1024];
int _CX;
int _CY;
char _Ticket[1024];
int memprice;
int pricecost;
CStringArray as;

//支付结构
char _sTc[16];
char _sID[32];
char _sfsn[32];
char _sPl[64];

char _OrderNo[1024];
char _sMobile[1024];
char _Coupon[1024];

char _BLCard[1024];
char _BLPWD[1024];
char _TempBookingId[1024];
char _WorkstationId[1024];
char _sCinemaIdLinkID[1024];
char _sShowDate[256];
char _sFilmId[128];
char _sShowTime[128];
char _sHallId[128];
char _sSectionId[128];
char _sTicketTypes[256];
double _lBookingFee = 5.00;

char _sLanbookingId[64];
char _sticket_no[128];
char _sFpLogs[1024];


int HFHWclose;

//兑换券返回的值
CString _Cresult;
CString  _Cmessage;
CString _bookingId;
CString _confirmationId;
CString _Csale_value;
CString  _Cused_amount;
CString  _Cprint_value;
CString _Cis_User;
CString _Remain_value;//剩余张数
CString _TicketNo;

char _MessBox[1024];

SYSTEMTIME LastTime;
SYSTEMTIME QuitTime;
SYSTEMTIME NowTime;



/*
	测试文件打开是否超时
*/
int openNetFileTest(const int limitTime,const char* remoteFile)
{
	int nFile;
	int oldMilSecond,newMilSecond;
	SYSTEMTIME sysTime;

	GetSystemTime(&sysTime);
	oldMilSecond = (sysTime.wMinute*60 + sysTime.wSecond)*1000 
					+ sysTime.wMilliseconds;
	
	// for debug
	//std::cout << oldMilSecond << std::endl;

	nFile = _open(remoteFile,_O_RDONLY);
	if (-1 == nFile)
	{	
		return ERROR_OPEN_FILE;
	}
	
	GetSystemTime(&sysTime);
	newMilSecond = (sysTime.wMinute*60 + sysTime.wSecond)*1000 
					+ sysTime.wMilliseconds;
	// for debug
	//std::cout << newMilSecond << std::endl;
	
	// 超时，返回文档打开时间
	if ( (newMilSecond-oldMilSecond) > limitTime)
	{
		return newMilSecond-oldMilSecond;
	}
	

	return SATISFY_OPEN_FILE;
}



void writeLog(const char* logContent,bool newRow)
{
	CTime t = CTime::GetCurrentTime();
	CString m_LogFileName;
	m_LogFileName+=t.Format("%y%m%d");
	CString TheFileName="logs/"+m_LogFileName+_T("_sys.log");
		
	std::ofstream tfile(TheFileName,std::ios::app);
	if (newRow)
	{
		char dateBuf[9],timeBuf[9];
		_strdate(dateBuf);
		_strtime( timeBuf );
		tfile << "\n" << dateBuf[6] << dateBuf[7];
		tfile << "-" << dateBuf[0] << dateBuf[1];
		tfile << "-" << dateBuf[3] << dateBuf[4];
		tfile << " " << timeBuf << "   ";
		
		/*
			// ? SYSTEMTIME 的时间不同于OS的时间？
		SYSTEMTIME sysTime;
		GetSystemTime(&sysTime);
			
		tfile << "\n" ;
		tfile << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " ";
		tfile << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond ;
		tfile << "   " ;
		*/
	}
	tfile << logContent ;
	
	tfile.close();
	
	return;
}

void httpLog(const char* logContent,bool newRow)
{
	CTime t = CTime::GetCurrentTime();
	CString m_LogFileName;
	m_LogFileName+=t.Format("%y%m%d");
	CString TheFileName="logs/"+m_LogFileName+_T("_http.log");
		
	std::ofstream tfile(TheFileName,std::ios::app);
	if (newRow)
	{
		char dateBuf[9],timeBuf[9];
		_strdate(dateBuf);
		_strtime( timeBuf );
		tfile << "\n" << dateBuf[6] << dateBuf[7];
		tfile << "-" << dateBuf[0] << dateBuf[1];
		tfile << "-" << dateBuf[3] << dateBuf[4];
		tfile << " " << timeBuf << "   ";
		
		/*
			// ? SYSTEMTIME 的时间不同于OS的时间？
		SYSTEMTIME sysTime;
		GetSystemTime(&sysTime);
			
		tfile << "\n" ;
		tfile << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " ";
		tfile << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond ;
		tfile << "   " ;
		*/
	}
	tfile << logContent ;
	
	tfile.close();
	
	return;
}

void PrintlnLog(const char* logContent,bool newRow)
{
	CTime t = CTime::GetCurrentTime();
	CString m_LogFileName;
	m_LogFileName+=t.Format("%y%m%d");
	CString TheFileName="logs/"+m_LogFileName+_T("_print.log");
		
	std::ofstream tfile(TheFileName,std::ios::app);
	if (newRow)
	{
		char dateBuf[9],timeBuf[9];
		_strdate(dateBuf);
		_strtime( timeBuf );
		tfile << "\n" << dateBuf[6] << dateBuf[7];
		tfile << "-" << dateBuf[0] << dateBuf[1];
		tfile << "-" << dateBuf[3] << dateBuf[4];
		tfile << " " << timeBuf << "   ";
	}
	tfile << logContent ;
	
	tfile.close();
	
	return;
}

void FYLog(const char* logContent,bool newRow)
{
	CTime t = CTime::GetCurrentTime();
	CString m_LogFileName;
	m_LogFileName+=t.Format("%y%m%d");
	CString TheFileName="logs/"+m_LogFileName+_T("_FY.log");
		
	std::ofstream tfile(TheFileName,std::ios::app);
	if (newRow)
	{
		char dateBuf[9],timeBuf[9];
		_strdate(dateBuf);
		_strtime( timeBuf );
		tfile << "\n" << dateBuf[6] << dateBuf[7];
		tfile << "-" << dateBuf[0] << dateBuf[1];
		tfile << "-" << dateBuf[3] << dateBuf[4];
		tfile << " " << timeBuf << "   ";
	}
	tfile << logContent ;
	
	tfile.close();
	
	return;
}

void getTicketLog(const char* logContent,bool newRow){

	CTime t = CTime::GetCurrentTime();
	CString m_LogFileName;
	m_LogFileName+=t.Format("%y%m%d");
	CString TheFileName="logs/"+m_LogFileName+_T("_getTicket.log");
		
	std::ofstream tfile(TheFileName,std::ios::app);
	if (newRow)
	{
		char dateBuf[9],timeBuf[9];
		_strdate(dateBuf);
		_strtime( timeBuf );
		tfile << "\n" << dateBuf[6] << dateBuf[7];
		tfile << "-" << dateBuf[0] << dateBuf[1];
		tfile << "-" << dateBuf[3] << dateBuf[4];
		tfile << " " << timeBuf << "   ";
	}
	tfile << logContent ;
	
	tfile.close();
	
	return;
}

void DBLog(const char* logContent,bool newRow){

	CTime t = CTime::GetCurrentTime();
	CString m_LogFileName;
	m_LogFileName+=t.Format("%y%m%d");
	CString TheFileName="logs/"+m_LogFileName+_T("_DB.log");
		
	std::ofstream tfile(TheFileName,std::ios::app);
	if (newRow)
	{
		char dateBuf[9],timeBuf[9];
		_strdate(dateBuf);
		_strtime( timeBuf );
		tfile << "\n" << dateBuf[6] << dateBuf[7];
		tfile << "-" << dateBuf[0] << dateBuf[1];
		tfile << "-" << dateBuf[3] << dateBuf[4];
		tfile << " " << timeBuf << "   ";
	}
	tfile << logContent ;
	
	tfile.close();
	
	return;
}