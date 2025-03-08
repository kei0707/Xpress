#pragma once

#include <pthread.h>
#include <cstdint>
#include "xpress_linux_misc.hpp"
#include "xpress_linux_oserror.hpp"

namespace xpress {
    /**
     * @brief
     */
    typedef enum {
        os_priority_min = 0,
        os_priority_low = 10,
        os_priority_mid = 50,
        os_priority_high = 80,
        os_priority_max = 99,
    } os_priority;
} // namespace xpress

namespace xpress::linux {
    /**
     * @brief
     *
     * @tparam __user_implimented_thread_class
     */
    template <class __user_implimented_thread_class>
        class thread final : public __user_implimented_thread_class,
                             public xpress::linux::oserror {
            private:
                __user_implimented_thread_class m_user_thread;

                /**
                 * @brief
                 *
                 * @param ap_args
                 *
                 * @return
                 */
                static void *thread_main_function(void *ap_args) {
                    /* cast to self obect */
                    xpress::linux::thread<__user_implimented_thread_class> self =
                        static_cast<xpress::linux::thread<__user_implimented_thread_class>>(
                                ap_args);

                    /* call user implimented class function "main" */
                    self->m_user_thread.main();

                    return nullptr;
                }

            protected:
                /* nothing */

            public:
                /**
                 * @brief
                 */
                enum error_t {
                    ERROR_NONE = 0x00,
                };

                /**
                 * @brief
                 */
                typedef enum {
                    wait = 0x00,
                } status_t;

                /**
                 * @brief
                 */
                thread() {}

                /**
                 * @brief
                 */
                virtual ~thread() {}

                /**
                 * @brief
                 * set thread priority
                 *
                 * @param a_priority_param
                 *
                 * @return
                 */
                int32_t priority(const xpress::os_priority a_priority_param) {
                    return ERROR_NONE;
                }

                /**
                 * @brief
                 *
                 * @return
                 */
                xpress::os_priority priority(void) { return os_priority_min; }

                /**
                 * @brief
                 *
                 * @param a_stack_size
                 *
                 * @return
                 */
                int32_t stack_size(const uint64_t a_stack_size) { return ERROR_NONE; }

                /**
                 * @brief
                 *
                 * @return
                 */
                int32_t create(void) { return ERROR_NONE; }

                /**
                 * @brief
                 *
                 * @return
                 */
                int32_t run(void) { return ERROR_NONE; }

                /**
                 * @brief
                 *
                 * @return
                 */
                int32_t join(void) { return pthread_join(); }

                /**
                 * @brief
                 *
                 * @return
                 */
                int32_t stop(void) { return ERROR_NONE; }

                /**
                 * @brief
                 *
                 * @return
                 */
                int32_t destroy(void) { return ERROR_NONE; }

                /**
                 * @brief
                 *
                 * @return
                 */
                status_t status(void) { return wait; }
        };
} // namespace xpress::linux
