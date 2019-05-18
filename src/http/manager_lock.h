#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_
 
#include <pthread.h>
 
//for test
#define  EPRINT  printf
#define  DPRINT  printf
 
 
/* MUTEX */
/*0表示成功，-1表示失败 */
 
class MutexLock
{
	
public:
	MutexLock();
	~MutexLock();
	
	//mutex加锁
	int lock();
	
	//mutex解锁
	int unlock();
	
private:
	//mutex初始化
	void mutexInit();
	
	//mutex释放
	void mutexDestroy();
	
private:
	//mutex
	pthread_mutex_t m_Mutex;
};
 
#endif 