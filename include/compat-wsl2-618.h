/* WSL2 6.18 compat shim — injected via -include before any TU header.
 * Сборка против НАСТОЯЩИХ исходников ядра WSL2 6.18 (не патченые Ubuntu 6.8). */
#ifndef _RTW_COMPAT_WSL2_618_H_
#define _RTW_COMPAT_WSL2_618_H_
#include <linux/version.h>
/* ядро 6.15+ удалило del_timer/del_timer_sync -> timer_delete* */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6, 15, 0))
#ifndef del_timer_sync
#define del_timer_sync(t) timer_delete_sync(t)
#endif
#ifndef del_timer
#define del_timer(t) timer_delete(t)
#endif
#endif
/* 6.16+ переименовал from_timer -> timer_container_of (та же сигнатура) */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6, 15, 0))
#ifndef from_timer
#define from_timer(var, callback_timer, timer_fieldname) 	timer_container_of(var, callback_timer, timer_fieldname)
#endif
#endif

#endif /* _RTW_COMPAT_WSL2_618_H_ */
