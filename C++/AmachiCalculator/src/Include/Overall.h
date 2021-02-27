# pragma once
# ifndef __AMI_OVA__
# define __AMI_OVA__
# include <math.h>
# include <unordered_map>
# include <string>
# include <utility>
# include <set>
# include <iostream>
# include <float.h>
# include <algorithm>
# include <deque>
# include <vector>
# include <stack>
# include <cmath>

# ifndef AMIC_NAMESPACE_START
#   define AMIC_NAMESPACE_START namespace __AmiCal_base {
# endif

# ifndef AMIC_NAMESPACE
#   define AMIC_NAMESPACE __AmiCal_base
# endif

# ifndef AMIC_NAMESPACE_END
#   define AMIC_NAMESPACE_END };
# endif

AMIC_NAMESPACE_START

class AMICAL_ERROR {
private:
    int __error_code;
    unsigned int __error_loca;
public:
    explicit AMICAL_ERROR(int code, unsigned int location = 0) :
        __error_code(code), __error_loca(location) { }
    inline int get_ecode() const { return __error_code; }
    inline int get_eloca() const { return __error_loca; }
};

AMIC_NAMESPACE_END

# endif