#include <iostream>
#include <fstream>
#include <time.h>
#include <io.h>

#include <FCNTL.H>

#define LOG_FILE "logs/20060215_movice.log"

#define ERROR_OPEN_FILE -1
#define SATISFY_OPEN_FILE 0

int openNetFileTest(const int limitTime,const char* remoteFile);
void writeLog(const char* logContent,bool newRow);
void httpLog(const char* logContent,bool newRow);
void PrintlnLog(const char* logContent,bool newRow);
void FYLog(const char* logContent,bool newRow);
void DBLog(const char* logContent,bool newRow);
void getTicketLog(const char* logContent,bool newRow);
long TimeDiff(SYSTEMTIME  left);



extern char _dbgtemp[102400];
extern char _xmltemp[1024];
extern int _CX;
extern int _CY;
extern char _Ticket[1024];
extern char _sMobile[1024];
extern int memprice;
extern int pricecost;
extern CStringArray as;

extern  char _sTc[16];
extern	char _sID[32];
extern	char _sfsn[32];
extern	char _sPl[64];

extern	char _OrderNo[1024];
extern	char _Coupon[1024];

//¶Ò»»È¯·µ»ØµÄÖµ
extern CString _Cresult;
extern CString  _Cmessage;
extern CString _bookingId;
extern CString _confirmationId;
extern CString _Csale_value;
extern CString  _Cused_amount;
extern CString  _Cprint_value;
extern CString _Cis_User;
extern CString _Remain_value;
extern CString _TicketNo;
extern char _MessBox[1024];

extern char _BLCard[1024];
extern char _BLPWD[1024];
extern char _TempBookingId[1024];
extern char _WorkstationId[1024];
extern char _sCinemaIdLinkID[1024];
extern char _sShowDate[256];
extern char _sFilmId[128];
extern char _sShowTime[128];
extern char _sHallId[128];
extern char _sSectionId[128];
extern char _sTicketTypes[256];
extern double _lBookingFee;
extern char _sLanbookingId[64];
extern char _sticket_no[128];
extern char _sFpLogs[1024];

extern int HFHWclose;