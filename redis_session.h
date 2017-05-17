#ifndef REDIS_SESSION_H
#define REDIS_SESSION_H
#ifdef PHP_SESSION
#include "ext/session/php_session.h"

typedef struct {
    zend_bool is_locked;
    char *session_key;
	smart_string lock_key;
    smart_string lock_secret;
} redis_session_lock_status;

void lock_acquire(RedisSock *redis_sock, redis_session_lock_status *lock_status);
void lock_release(RedisSock *redis_sock, redis_session_lock_status *lock_status);
void upload_lock_release_script(RedisSock *redis_sock);
void calculate_lock_secret(redis_session_lock_status *lock_status);

PS_OPEN_FUNC(redis);
PS_CLOSE_FUNC(redis);
PS_READ_FUNC(redis);
PS_WRITE_FUNC(redis);
PS_DESTROY_FUNC(redis);
PS_GC_FUNC(redis);

PS_OPEN_FUNC(rediscluster);
PS_CLOSE_FUNC(rediscluster);
PS_READ_FUNC(rediscluster);
PS_WRITE_FUNC(rediscluster);
PS_DESTROY_FUNC(rediscluster);
PS_GC_FUNC(rediscluster);

#endif
#endif
