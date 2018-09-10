#ifndef _ESCOMMSERVER_H_
#define _ESCOMMSERVER_H_

#ifndef TCP_COMMUNICATION_TYPE
	#define TCP_COMMUNICATION_TYPE		0x00
#endif

#ifndef UDP_COMMUNICATION_TYPE
	#define UDP_COMMUNICATION_TYPE		0x01
#endif

#ifndef MAX_SEND_LEN
	#define MAX_SEND_LEN				0x8000
#endif

#ifndef EN_COMM_PARAM
	#define EN_COMM_PARAM
	typedef enum EnCommParam_Tag
	{
		ES_COMM_RECV_TIMEOUT = 0x01,	// 接收时间
		ES_COMM_SEND_TIMEOUT = 0x02,	// 发送时间
	}EnCommParam;
	typedef struct BlkConnectedInfoTag 
	{
		char*	m_pszIp;			// "192.168.0.1"格式
		u2		m_u2Port;
	}BlkConnectedInfo;
#endif

typedef struct BlkCommServerParamTag 
{
	char*	m_pszIp;			// "192.168.0.1"格式
	u2		m_u2Port;
	u4		m_u4MaxConnectCount;
}BlkCommServerParam;

#ifdef __cplusplus
extern "C"
{
#endif

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerInit
	// 函数功能
	//  初始化服务器
	// 参数说明： 
	//	u4Type:			[IN] 服务器类型，00:tcp, 01: udp；
	//	pvParam:		[IN] 服务器参数，IP, PORT, MAXCOUNT；参见 BlkCommServerParam
	//  phHandle:		[OUT] 服务器句柄；	
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerInit(u4 u4Type, const void* pvParam, ESHANDLE* phHandle);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerWaitConnect
	// 函数功能
	//		等待客户端连接服务器
	// 参数说明： 
	//	hHandle:					[IN] 服务器句柄；
	//	phClientHandle:				[OUT] 连接上客户端后的通讯句柄；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerWaitConnect(IN ESHANDLE hHandle, OUT ESHANDLE* phClientHandle);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerGetClientInfo
	// 函数功能
	//	 获取已连客户端的信息
	// 参数说明： 
	//	hHandle:					[IN] 通讯句柄；
	//	pblkConnectedInfo:			[OUT] 连接上的客户端的信息结构体；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerGetClientInfo(ESHANDLE hHandle, BlkConnectedInfo* pblkConnectedInfo);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerSetParam
	// 函数功能
	//	设置服务器通讯端口参数
	// 参数说明： 
	//	hHandle:			[IN] 服务器句柄；
	//	enType:				[IN] 参数类型：接收：0x01， 发送：0x02；
	//	pvParam:			[IN] 参数数据，目前支持超时参数，超时参数以秒为单位；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerSetParam(ESHANDLE hHandle, EnCommParam enType, const void* pvParam);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerGetParam
	// 函数功能
	//	获取服务器通讯端口参数
	// 参数说明： 
	//	hHandle:			[IN] 服务器句柄；
	//	enType:				[IN] 参数类型：接收：0x01， 发送：0x02；
	//	pvParam:			[OUT] 参数数据；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerGetParam(ESHANDLE hHandle, EnCommParam enType, void* pvParam);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerSendData
	// 函数功能
	//  服务端发送报文数据
	// 参数说明： 
	//  hHandle:		[IN] 服务器句柄；
	//	pvData:			[IN] 待发送数据；
	//	u4DataLen:		[IN] 待发送数据长度；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerSendData(ESHANDLE hHandle, const void* pvData, u4 u4DataLen);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerRecvData
	// 函数功能
	//  服务端接收报文数据
	// 参数说明： 
	//  hHandle:		[IN] 服务器句柄；	
	//	pvData:			[OUT] 接收数据；
	//	u4DataLen:		[IN/OUT] 接收数据长度；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerRecvData(ESHANDLE hHandle, void* pvData, u4* pu4DataLen);

	////////////////////////////////////////////////////
	// 函数名称：EsCommServerRelease
	// 函数功能
	//  关闭服务器
	// 参数说明： 
	//  phHandle:		[IN] 服务器句柄；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerRelease(ESHANDLE* phHandle);

#ifdef __cplusplus
}
#endif

#endif
