/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/


#if defined(DEFINE_IN_INTERFACE)
	#undef __BILLINGSYSTEM_INTERFACE_H__
#endif


#ifndef __BILLINGSYSTEM_INTERFACE_H__
#define __BILLINGSYSTEM_INTERFACE_H__

// common include	
#if defined(BILLINGSYSTEM)
#include "billingsystem.hpp"
#endif
#include "billingsystem_interface_macros.hpp"
#include "network/interface_defs.hpp"
//#define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif
	
namespace KBEngine{

/**
	BillingSystem��Ϣ�꣬  ����Ϊ���� ��Ҫ�Լ��⿪
*/

/**
	BillingSystem������Ϣ�ӿ��ڴ˶���
*/
NETWORK_INTERFACE_DECLARE_BEGIN(BillingSystemInterface)
	// ĳappע���Լ��Ľӿڵ�ַ����app
	BILLINGSYSTEM_MESSAGE_DECLARE_ARGS8(onRegisterNewApp,			MERCURY_VARIABLE_MESSAGE,
									int32,							uid, 
									std::string,					username,
									int8,							componentType, 
									uint64,							componentID, 
									uint32,							intaddr, 
									uint16,							intport,
									uint32,							extaddr, 
									uint16,							extport)

	// ĳ��app��app��֪���ڻ״̬��
	BILLINGSYSTEM_MESSAGE_DECLARE_ARGS2(onAppActiveTick,			MERCURY_FIXED_MESSAGE,
									COMPONENT_TYPE,					componentType, 
									COMPONENT_ID,					componentID)

	// loginapp���󴴽��˺š�
	BILLINGSYSTEM_MESSAGE_DECLARE_ARGS2(reqCreateAccount,			MERCURY_VARIABLE_MESSAGE,
									std::string,					accountName,
									std::string,					password)

	// ĳ��app��app��֪���ڻ״̬��
	BILLINGSYSTEM_MESSAGE_DECLARE_ARGS2(onAccountLogin,				MERCURY_VARIABLE_MESSAGE,
									std::string,					accountName,
									std::string,					password)

NETWORK_INTERFACE_DECLARE_END()

#ifdef DEFINE_IN_INTERFACE
	#undef DEFINE_IN_INTERFACE
#endif

}
#endif