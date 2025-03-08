#ifndef XPRESS_OSAL_THREAD_HPP_INCLUDED
#define XPRESS_OSAL_THREAD_HPP_INCLUDED

#include <cstdint>
#include <string>

namespace xpress::osal {
template <class __user_defined_class,
          class __xpress_osal_target_thread = xpress::osal::target::thread>
class thread final : public __user_defined_class {
private:
  __user_defined_class　 m_user_class;
  __xpress_osal_target_thread m_osal_class;

  /**
   * @brief
   *
   * @arg ap_args
   *
   * @return
   */
  static void *main(void *ap_args) {
    xpress::osal::thread<__user_defined_class, __xpress_osal_target_thread>
        *ptr = static_cast<xpress::osal::thread<__user_defined_class,
                                                __xpress_osal_target_thread>>(
            ap_args);

    ptr->m_user_class.main();

    return nullptr;
  }

public:
  /**
   * @brief
   *
   * @arg a_name
   */
  thread(const std::string a_name) : m_user_class(a_name), m_osal_class() {}

  /**
   * @brief
   */
  ~thread() {}

  int32_t priority(uint32_t a_priority) {
    return m_osal_class.priority(a_priority);
  }

  /**
   * @brief
   *
   * @return
   */
  int32_t priority(void) { return m_osal_class.priority(); }

  /**
   * @brief
   *
   * @arg a_stack_size
   *
   * @return
   */
  int32_t stack_size(uint64_t a_stack_size) {
    return m_osal_class.stack_size(a_stack_size);
  }

  /**
   * @brief
   *
   * @return
   */
  int32_t stack_size(void) { return m_osal_class.stack_size(); }

  /**
   * @brief
   *
   * @return
   */
  int32_t create(void) {
    return m_osal_class.create(
        xpress::osal::thread<__user_defined_class,
                             __xpress_osal_target_thread>::main);
  }

  /**
   * @brief
   *
   * @return
   */
  int32_t destroy(void) { return m_osal_class.destroy(); }

  /**
   * @brief
   *
   * @return
   */
  int32_t join(void) { return m_osal_class.join(); }
};
} // namespace xpress::osal

#endif /* XPRESS_OSAL_THREAD_HPP_INCLUDED */
